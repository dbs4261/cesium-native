// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "BoundingVolumeJsonHandler.h"

#include <Cesium3DTiles/Content.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace Cesium3DTiles {
class ExtensionReaderContext;

class ContentJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = Content;

  ContentJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, Content* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyContent(
      const std::string& objectType,
      const std::string_view& str,
      Content& o);

private:
  Content* _pObject = nullptr;
  BoundingVolumeJsonHandler _boundingVolume;
  CesiumJsonReader::StringJsonHandler _uri;
};
} // namespace Cesium3DTiles
