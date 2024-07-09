// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <Cesium3DTiles/Padding.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class JsonReaderOptions;
}

namespace Cesium3DTilesReader {
class PaddingJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = Cesium3DTiles::Padding;

  PaddingJsonHandler(
      const CesiumJsonReader::JsonReaderOptions& options) noexcept;
  void reset(IJsonHandler* pParentHandler, Cesium3DTiles::Padding* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyPadding(
      const std::string& objectType,
      const std::string_view& str,
      Cesium3DTiles::Padding& o);

private:
  Cesium3DTiles::Padding* _pObject = nullptr;
  CesiumJsonReader::
      ArrayJsonHandler<int64_t, CesiumJsonReader::IntegerJsonHandler<int64_t>>
          _before;
  CesiumJsonReader::
      ArrayJsonHandler<int64_t, CesiumJsonReader::IntegerJsonHandler<int64_t>>
          _after;
};
} // namespace Cesium3DTilesReader
