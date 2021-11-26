// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltfReader/AccessorSparseJsonHandler.h"
#include "CesiumGltfReader/NamedObjectJsonHandler.h"

#include <CesiumGltf/Accessor.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/BoolJsonHandler.h>
#include <CesiumJsonReader/DoubleJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltfReader {
class AccessorJsonHandler : public CesiumGltfReader::NamedObjectJsonHandler {
public:
  using ValueType = CesiumGltf::Accessor;

  AccessorJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, CesiumGltf::Accessor* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyAccessor(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::Accessor& o);

private:
  CesiumGltf::Accessor* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _bufferView;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _byteOffset;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _componentType;
  CesiumJsonReader::BoolJsonHandler _normalized;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _count;
  CesiumJsonReader::StringJsonHandler _type;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _max;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _min;
  AccessorSparseJsonHandler _sparse;
};
} // namespace CesiumGltfReader
