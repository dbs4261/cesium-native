// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <Cesium3DTiles/Extension3dTilesBoundingVolumeCylinder.h>
#include <Cesium3DTilesReader/Library.h>
#include <CesiumJsonReader/JsonReader.h>
#include <CesiumJsonReader/JsonReaderOptions.h>

#include <gsl/span>
#include <rapidjson/fwd.h>

#include <vector>

namespace Cesium3DTiles {
struct Extension3dTilesBoundingVolumeCylinder;
}

namespace Cesium3DTilesReader {

/**
 * @brief Reads {@link Extension3dTilesBoundingVolumeCylinder} instances from JSON.
 */
class CESIUM3DTILESREADER_API Extension3dTilesBoundingVolumeCylinderReader {
public:
  /**
   * @brief Constructs a new instance.
   */
  Extension3dTilesBoundingVolumeCylinderReader();

  /**
   * @brief Gets the options controlling how the JSON is read.
   */
  CesiumJsonReader::JsonReaderOptions& getOptions();

  /**
   * @brief Gets the options controlling how the JSON is read.
   */
  const CesiumJsonReader::JsonReaderOptions& getOptions() const;

  /**
   * @brief Reads an instance of Extension3dTilesBoundingVolumeCylinder from a
   * byte buffer.
   *
   * @param data The buffer from which to read the instance.
   * @return The result of reading the instance.
   */
  CesiumJsonReader::ReadJsonResult<
      Cesium3DTiles::Extension3dTilesBoundingVolumeCylinder>
  readFromJson(const gsl::span<const std::byte>& data) const;

  /**
   * @brief Reads an instance of Extension3dTilesBoundingVolumeCylinder from a
   * rapidJson::Value.
   *
   * @param data The buffer from which to read the instance.
   * @return The result of reading the instance.
   */
  CesiumJsonReader::ReadJsonResult<
      Cesium3DTiles::Extension3dTilesBoundingVolumeCylinder>
  readFromJson(const rapidjson::Value& value) const;

  /**
   * @brief Reads an array of instances of
   * Extension3dTilesBoundingVolumeCylinder from a rapidJson::Value.
   *
   * @param data The buffer from which to read the array of instances.
   * @return The result of reading the array of instances.
   */
  CesiumJsonReader::ReadJsonResult<
      std::vector<Cesium3DTiles::Extension3dTilesBoundingVolumeCylinder>>
  readArrayFromJson(const rapidjson::Value& value) const;

private:
  CesiumJsonReader::JsonReaderOptions _options;
};

} // namespace Cesium3DTilesReader