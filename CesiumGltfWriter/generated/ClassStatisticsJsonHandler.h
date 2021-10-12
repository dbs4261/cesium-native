// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "PropertyStatisticsJsonHandler.h"

#include <CesiumGltf/ClassStatistics.h>
#include <CesiumJsonWriter/DictionaryJsonHandler.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonWriter/IntegerJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class ClassStatisticsJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = ClassStatistics;

  ClassStatisticsJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, ClassStatistics* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyClassStatistics(
      const std::string& objectType,
      const std::string_view& str,
      ClassStatistics& o);

private:
  ClassStatistics* _pObject = nullptr;
  CesiumJsonWriter::IntegerJsonHandler<int64_t> _count;
  CesiumJsonWriter::
      DictionaryJsonHandler<PropertyStatistics, PropertyStatisticsJsonHandler>
          _properties;
};
} // namespace CesiumGltf
