// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/CameraPerspective.h>
#include <CesiumJsonWriter/DoubleJsonHandler.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class CameraPerspectiveJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = CameraPerspective;

  CameraPerspectiveJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, CameraPerspective* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyCameraPerspective(
      const std::string& objectType,
      const std::string_view& str,
      CameraPerspective& o);

private:
  CameraPerspective* _pObject = nullptr;
  CesiumJsonWriter::DoubleJsonHandler _aspectRatio;
  CesiumJsonWriter::DoubleJsonHandler _yfov;
  CesiumJsonWriter::DoubleJsonHandler _zfar;
  CesiumJsonWriter::DoubleJsonHandler _znear;
};
} // namespace CesiumGltf
