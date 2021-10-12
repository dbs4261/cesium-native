// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "FeatureIDAttributeJsonHandler.h"
#include "FeatureIDTextureJsonHandler.h"

#include <CesiumGltf/MeshPrimitiveEXT_feature_metadata.h>
#include <CesiumJsonWriter/ArrayJsonHandler.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonWriter/StringJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class MeshPrimitiveEXT_feature_metadataJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler,
      public CesiumJsonWriter::IExtensionJsonHandler {
public:
  using ValueType = MeshPrimitiveEXT_feature_metadata;

  static inline constexpr const char* ExtensionName = "EXT_feature_metadata";

  MeshPrimitiveEXT_feature_metadataJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(
      IJsonHandler* pParentHandler,
      MeshPrimitiveEXT_feature_metadata* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

  virtual void reset(
      IJsonHandler* pParentHandler,
      CesiumUtility::ExtensibleObject& o,
      const std::string_view& extensionName) override;

  virtual IJsonHandler* writeNull() override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeNull();
  };
  virtual IJsonHandler* writeBool(bool b) override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeBool(b);
  }
  virtual IJsonHandler* writeInt32(int32_t i) override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeInt32(i);
  }
  virtual IJsonHandler* writeUint32(uint32_t i) override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeUint32(i);
  }
  virtual IJsonHandler* writeInt64(int64_t i) override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeInt64(i);
  }
  virtual IJsonHandler* writeUint64(uint64_t i) override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeUint64(i);
  }
  virtual IJsonHandler* writeDouble(double d) override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeDouble(d);
  }
  virtual IJsonHandler* writeString(const std::string_view& str) override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeString(str);
  }
  virtual IJsonHandler* writeObjectStart() override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeObjectStart();
  }
  virtual IJsonHandler* writeObjectEnd() override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeObjectEnd();
  }
  virtual IJsonHandler* writeArrayStart() override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeArrayStart();
  }
  virtual IJsonHandler* writeArrayEnd() override {
    return CesiumJsonWriter::ExtensibleObjectJsonHandler::writeArrayEnd();
  }
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context =
          std::vector<std::string>()) override {
    CesiumJsonWriter::ExtensibleObjectJsonHandler::reportWarning(
        warning,
        std::move(context));
  }

protected:
  IJsonHandler* writeObjectKeyMeshPrimitiveEXT_feature_metadata(
      const std::string& objectType,
      const std::string_view& str,
      MeshPrimitiveEXT_feature_metadata& o);

private:
  MeshPrimitiveEXT_feature_metadata* _pObject = nullptr;
  CesiumJsonWriter::
      ArrayJsonHandler<FeatureIDAttribute, FeatureIDAttributeJsonHandler>
          _featureIdAttributes;
  CesiumJsonWriter::
      ArrayJsonHandler<FeatureIDTexture, FeatureIDTextureJsonHandler>
          _featureIdTextures;
  CesiumJsonWriter::
      ArrayJsonHandler<std::string, CesiumJsonWriter::StringJsonHandler>
          _featureTextures;
};
} // namespace CesiumGltf
