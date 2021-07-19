#include "CesiumGeometry/CullingVolume.h"

#include <glm/glm.hpp>
#include <glm/trigonometric.hpp>
#include <glm/vec3.hpp>

namespace Cesium3DTiles {

CullingVolume createPerspectiveCullingVolume(
    const glm::dvec3& position,
    const glm::dvec3& direction,
    const glm::dvec3& up,
    const double fovx,
    const double fovy) noexcept {
  double t = glm::tan(0.5 * fovy);
  double b = -t;
  double r = glm::tan(0.5 * fovx);
  double l = -r;

  double n = 1.0;

  // TODO: this is all ported directly from CesiumJS, can probably be refactored
  // to be more efficient with GLM.

  glm::dvec3 right = glm::cross(direction, up);

  glm::dvec3 nearCenter = direction * n;
  nearCenter = position + nearCenter;

  // Left plane computation
  glm::dvec3 normal = right * l;
  normal = nearCenter + normal;
  normal = normal - position;
  normal = glm::normalize(normal);
  normal = glm::cross(normal, up);
  normal = glm::normalize(normal);

  CesiumGeometry::Plane leftPlane(normal, -glm::dot(normal, position));

  // Right plane computation
  normal = right * r;
  normal = nearCenter + normal;
  normal = normal - position;
  normal = glm::cross(up, normal);
  normal = glm::normalize(normal);

  CesiumGeometry::Plane rightPlane(normal, -glm::dot(normal, position));

  // Bottom plane computation
  normal = up * b;
  normal = nearCenter + normal;
  normal = normal - position;
  normal = glm::cross(right, normal);
  normal = glm::normalize(normal);

  CesiumGeometry::Plane bottomPlane(normal, -glm::dot(normal, position));

  // Top plane computation
  normal = up * t;
  normal = nearCenter + normal;
  normal = normal - position;
  normal = glm::cross(normal, right);
  normal = glm::normalize(normal);

  CesiumGeometry::Plane topPlane(normal, -glm::dot(normal, position));

  return CullingVolume({leftPlane, rightPlane, topPlane, bottomPlane});
}

CullingVolume createOrthographicCullingVolume(
    const glm::dvec3& position,
    const glm::dvec3& direction,
    const glm::dvec3& up,
    const double orthographicWidth,
    const double orthographicHeight) noexcept {

  double halfWidth = 0.5 * orthographicWidth;
  double halfHeight = 0.5 * orthographicHeight;

  glm::dvec3 right = glm::cross(direction, up);

  // Left Plane
  CesiumGeometry::Plane leftPlane(position - halfWidth * right, right);

  // Right Plane
  CesiumGeometry::Plane rightPlane(position + halfWidth * right, -right);

  // Top Plane
  CesiumGeometry::Plane topPlane(position + halfHeight * up, -up);

  // Bottom Plane
  CesiumGeometry::Plane bottomPlane(position - halfHeight * up, up);

  // Far Plane
  CesiumGeometry::Plane farPlane(
      glm::dvec3(0.0, 0.0, 0.0),
      glm::normalize(position));

  // Back Plane
  // CesiumGeometry::Plane backPlane(position, direction);

  return CullingVolume(
      {leftPlane, rightPlane, topPlane, bottomPlane, farPlane});
}

CullingVolume::CullingVolume(const std::vector<CesiumGeometry::Plane>& planes)
    : _planes(planes) {}
} // namespace Cesium3DTiles
