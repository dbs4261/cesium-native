// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "BoundingVolumeJsonHandler.h"
#include "ContentJsonHandler.h"

#include <Cesium3DTiles/Tile.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/DoubleJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace Cesium3DTiles {
class ExtensionReaderContext;

class TileJsonHandler : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = Tile;

  TileJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, Tile* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyTile(
      const std::string& objectType,
      const std::string_view& str,
      Tile& o);

private:
  Tile* _pObject = nullptr;
  BoundingVolumeJsonHandler _boundingVolume;
  BoundingVolumeJsonHandler _viewerRequestVolume;
  CesiumJsonReader::DoubleJsonHandler _geometricError;
  CesiumJsonReader::StringJsonHandler _refine;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _transform;
  ContentJsonHandler _content;
  CesiumJsonReader::ArrayJsonHandler<Tile, TileJsonHandler> _children;
};
} // namespace Cesium3DTiles
