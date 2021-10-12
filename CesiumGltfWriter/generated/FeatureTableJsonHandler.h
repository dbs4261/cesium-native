// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "FeatureTablePropertyJsonHandler.h"

#include <CesiumGltf/FeatureTable.h>
#include <CesiumJsonWriter/DictionaryJsonHandler.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonWriter/IntegerJsonHandler.h>
#include <CesiumJsonWriter/StringJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class FeatureTableJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = FeatureTable;

  FeatureTableJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, FeatureTable* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyFeatureTable(
      const std::string& objectType,
      const std::string_view& str,
      FeatureTable& o);

private:
  FeatureTable* _pObject = nullptr;
  CesiumJsonWriter::StringJsonHandler _classProperty;
  CesiumJsonWriter::IntegerJsonHandler<int64_t> _count;
  CesiumJsonWriter::DictionaryJsonHandler<
      FeatureTableProperty,
      FeatureTablePropertyJsonHandler>
      _properties;
};
} // namespace CesiumGltf
