// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <Cesium3DTiles/Tileset.h>
#include <CesiumJsonWriter/ExtensionWriterContext.h>
#include <CesiumJsonWriter/JsonWriter.h>

namespace Cesium3DTiles {

struct AssetWriter {
  using ValueType = Asset;

  static void write(
      const Asset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};
struct BoundingVolumeWriter {
  using ValueType = BoundingVolume;

  static void write(
      const BoundingVolume& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};
struct ContentWriter {
  using ValueType = Content;

  static void write(
      const Content& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};
struct TileWriter {
  using ValueType = Tile;

  static void write(
      const Tile& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};
struct PropertiesWriter {
  using ValueType = Properties;

  static void write(
      const Properties& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};
struct TilesetWriter {
  using ValueType = Tileset;

  static void write(
      const Tileset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

} // namespace Cesium3DTiles
