#include "CesiumGeometry/IntersectionTests.h"
#include "CesiumGeometry/Ray.h"
#include "CesiumGltfContent/GltfUtilities.h"
#include "CesiumGltfReader/GltfReader.h"

#include <CesiumUtility/Math.h>

#include <catch2/catch.hpp>
#include <glm/glm.hpp>

#include <filesystem>
#include <fstream>

using namespace CesiumUtility;
using namespace CesiumGltf;
using namespace CesiumGeometry;
using namespace CesiumGltfReader;
using namespace CesiumGltfContent;

namespace {
std::vector<std::byte> readFile(const std::filesystem::path& fileName) {
  std::ifstream file(fileName, std::ios::binary | std::ios::ate);
  REQUIRE(file);

  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);

  std::vector<std::byte> buffer(static_cast<size_t>(size));
  file.read(reinterpret_cast<char*>(buffer.data()), size);

  return buffer;
}
} // namespace

void checkIntersection(
    const Ray& ray,
    const Model& model,
    bool cullBackFaces,
    const glm::dmat4x4& modelToWorld,
    bool shouldHit,
    const glm::dvec3& expectedHit) {
  std::optional<GltfUtilities::HitResult> hitResult =
      GltfUtilities::intersectRayGltfModel(
          ray,
          model,
          cullBackFaces,
          modelToWorld);

  if (shouldHit) {
    CHECK(hitResult.has_value());
    if (!hitResult.has_value())
      return;
  } else {
    CHECK(!hitResult.has_value());
    return;
  }

  // Validate hit point
  CHECK(glm::all(glm::lessThan(
      glm::abs(hitResult->worldPoint - expectedHit),
      glm::dvec3(CesiumUtility::Math::Epsilon6))));

  // Use results to dive into model
  CHECK(hitResult->meshId > -1);
  CHECK(static_cast<size_t>(hitResult->meshId) < model.meshes.size());
  const CesiumGltf::Mesh& mesh =
      model.meshes[static_cast<size_t>(hitResult->meshId)];

  CHECK(hitResult->primitiveId > -1);
  CHECK(static_cast<size_t>(hitResult->primitiveId) < mesh.primitives.size());
  const CesiumGltf::MeshPrimitive& primitive =
      mesh.primitives[static_cast<size_t>(hitResult->primitiveId)];

  bool modeIsValid =
      primitive.mode == CesiumGltf::MeshPrimitive::Mode::TRIANGLES ||
      primitive.mode == CesiumGltf::MeshPrimitive::Mode::TRIANGLE_STRIP ||
      primitive.mode == CesiumGltf::MeshPrimitive::Mode::TRIANGLE_FAN;
  CHECK(modeIsValid);

  // There should be positions
  auto positionAccessorIt = primitive.attributes.find("POSITION");
  CHECK(positionAccessorIt != primitive.attributes.end());

  // And a way to access them
  int positionAccessorID = positionAccessorIt->second;
  const Accessor* pPositionAccessor =
      Model::getSafe(&model.accessors, positionAccessorID);
  CHECK(pPositionAccessor);
}

void checkUnitCubeIntersections(const std::string& testModelName) {
  GltfReader reader;
  Model testModel =
      *reader
           .readGltf(readFile(
               std::filesystem::path(CesiumGltfContent_TEST_DATA_DIR) /
               testModelName))
           .model;

  // intersects the top side of the cube
  checkIntersection(
      Ray(glm::dvec3(0.0, 0.0, 2.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      true,
      glm::dmat4x4(1.0),
      true,
      glm::dvec3(0.0, 0.0, 0.5));

  // misses the top side of the cube to the right
  checkIntersection(
      Ray(glm::dvec3(0.6, 0.0, 2.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      true,
      glm::dmat4x4(1.0),
      false,
      {});

  // misses the top side of the cube because it's behind it (avoid backfaces)
  checkIntersection(
      Ray(glm::dvec3(0.0, 0.0, 0.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      true,
      glm::dmat4x4(1.0),
      false,
      {});

  // hits backface triangles
  checkIntersection(
      Ray(glm::dvec3(0.0, 0.0, 0.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      false,
      glm::dmat4x4(1.0),
      true,
      glm::dvec3(0.0, 0.0, -0.5));

  // tests against backfaces, and picks first hit (top)
  checkIntersection(
      Ray(glm::dvec3(0.0, 0.0, 2.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      false,
      glm::dmat4x4(1.0),
      true,
      glm::dvec3(0.0, 0.0, 0.5));

  // tests against backfaces, and picks first hit (bottom)
  checkIntersection(
      Ray(glm::dvec3(0.0, 0.0, -2.0), glm::dvec3(0.0, 0.0, 1.0)),
      testModel,
      false,
      glm::dmat4x4(1.0),
      true,
      glm::dvec3(0.0, 0.0, -0.5));

  // just misses the top side of a cube translated to the right
  glm::dmat4x4 translationMatrix(1.0);
  translationMatrix[3] = glm::dvec4(0.6, 0.0, 0.0, 1.0);
  checkIntersection(
      Ray(glm::dvec3(0.0, 0.0, 2.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      true,
      translationMatrix,
      false,
      {});

  // just hits the top side of a cube translated to the right
  checkIntersection(
      Ray(glm::dvec3(0.6, 0.0, 2.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      true,
      translationMatrix,
      true,
      glm::dvec3(0.6, 0.0, 0.5));

  // correctly hits a scaled cube
  glm::dmat4x4 scaleMatrix = glm::dmat4(
      glm::dvec4(2.0, 0.0, 0.0, 0.0),
      glm::dvec4(0.0, 2.0, 0.0, 0.0),
      glm::dvec4(0.0, 0.0, 2.0, 0.0),
      glm::dvec4(0.0, 0.0, 0.0, 1.0));
  checkIntersection(
      Ray(glm::dvec3(0.0, 0.0, 2.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      true,
      scaleMatrix,
      true,
      glm::dvec3(0.0, 0.0, 1.0));

  // just misses a scaled cube to the right
  checkIntersection(
      Ray(glm::dvec3(1.1, 0.0, 2.0), glm::dvec3(0.0, 0.0, -1.0)),
      testModel,
      true,
      scaleMatrix,
      false,
      {});
}

TEST_CASE("GltfUtilities::intersectRayGltfModel") {
  checkUnitCubeIntersections("cube.glb");

  checkUnitCubeIntersections("cubeIndexed.glb");

  checkUnitCubeIntersections("cubeStrip.glb");

  checkUnitCubeIntersections("cubeStripIndexed.glb");

  checkUnitCubeIntersections("cubeFan.glb");

  checkUnitCubeIntersections("cubeFanIndexed.glb");

  checkUnitCubeIntersections("cubeQuantized.glb");

  checkUnitCubeIntersections("cubeTranslated.glb");
}
