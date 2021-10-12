// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/FeatureTableProperty.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonWriter/IntegerJsonHandler.h>
#include <CesiumJsonWriter/StringJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class FeatureTablePropertyJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = FeatureTableProperty;

  FeatureTablePropertyJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, FeatureTableProperty* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyFeatureTableProperty(
      const std::string& objectType,
      const std::string_view& str,
      FeatureTableProperty& o);

private:
  FeatureTableProperty* _pObject = nullptr;
  CesiumJsonWriter::IntegerJsonHandler<int32_t> _bufferView;
  CesiumJsonWriter::StringJsonHandler _offsetType;
  CesiumJsonWriter::IntegerJsonHandler<int32_t> _arrayOffsetBufferView;
  CesiumJsonWriter::IntegerJsonHandler<int32_t> _stringOffsetBufferView;
};
} // namespace CesiumGltf
