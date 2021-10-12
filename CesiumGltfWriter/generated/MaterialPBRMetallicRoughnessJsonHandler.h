// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "TextureInfoJsonHandler.h"

#include <CesiumGltf/MaterialPBRMetallicRoughness.h>
#include <CesiumJsonWriter/ArrayJsonHandler.h>
#include <CesiumJsonWriter/DoubleJsonHandler.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class MaterialPBRMetallicRoughnessJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = MaterialPBRMetallicRoughness;

  MaterialPBRMetallicRoughnessJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void
  reset(IJsonHandler* pParentHandler, MaterialPBRMetallicRoughness* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyMaterialPBRMetallicRoughness(
      const std::string& objectType,
      const std::string_view& str,
      MaterialPBRMetallicRoughness& o);

private:
  MaterialPBRMetallicRoughness* _pObject = nullptr;
  CesiumJsonWriter::
      ArrayJsonHandler<double, CesiumJsonWriter::DoubleJsonHandler>
          _baseColorFactor;
  TextureInfoJsonHandler _baseColorTexture;
  CesiumJsonWriter::DoubleJsonHandler _metallicFactor;
  CesiumJsonWriter::DoubleJsonHandler _roughnessFactor;
  TextureInfoJsonHandler _metallicRoughnessTexture;
};
} // namespace CesiumGltf
