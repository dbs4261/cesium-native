// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/FeatureIDs.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonWriter/IntegerJsonHandler.h>
#include <CesiumJsonWriter/StringJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class FeatureIDsJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = FeatureIDs;

  FeatureIDsJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, FeatureIDs* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyFeatureIDs(
      const std::string& objectType,
      const std::string_view& str,
      FeatureIDs& o);

private:
  FeatureIDs* _pObject = nullptr;
  CesiumJsonWriter::StringJsonHandler _attribute;
  CesiumJsonWriter::IntegerJsonHandler<int64_t> _constant;
  CesiumJsonWriter::IntegerJsonHandler<int64_t> _divisor;
};
} // namespace CesiumGltf
