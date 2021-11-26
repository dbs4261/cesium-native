// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltfReader/NamedObjectJsonHandler.h"

#include <CesiumGltf/BufferView.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltfReader {
class BufferViewJsonHandler : public CesiumGltfReader::NamedObjectJsonHandler {
public:
  using ValueType = CesiumGltf::BufferView;

  BufferViewJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, CesiumGltf::BufferView* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyBufferView(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::BufferView& o);

private:
  CesiumGltf::BufferView* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _buffer;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _byteOffset;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _byteLength;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _byteStride;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _target;
};
} // namespace CesiumGltfReader
