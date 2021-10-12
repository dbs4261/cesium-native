// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ClassStatisticsJsonHandler.h"

#include <CesiumGltf/Statistics.h>
#include <CesiumJsonWriter/DictionaryJsonHandler.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class StatisticsJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = Statistics;

  StatisticsJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, Statistics* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyStatistics(
      const std::string& objectType,
      const std::string_view& str,
      Statistics& o);

private:
  Statistics* _pObject = nullptr;
  CesiumJsonWriter::
      DictionaryJsonHandler<ClassStatistics, ClassStatisticsJsonHandler>
          _classes;
};
} // namespace CesiumGltf
