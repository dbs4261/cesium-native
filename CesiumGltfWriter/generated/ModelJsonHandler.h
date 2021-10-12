// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "AccessorJsonHandler.h"
#include "AnimationJsonHandler.h"
#include "AssetJsonHandler.h"
#include "BufferJsonHandler.h"
#include "BufferViewJsonHandler.h"
#include "CameraJsonHandler.h"
#include "ImageJsonHandler.h"
#include "MaterialJsonHandler.h"
#include "MeshJsonHandler.h"
#include "NodeJsonHandler.h"
#include "SamplerJsonHandler.h"
#include "SceneJsonHandler.h"
#include "SkinJsonHandler.h"
#include "TextureJsonHandler.h"

#include <CesiumGltf/Model.h>
#include <CesiumJsonWriter/ArrayJsonHandler.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonWriter/IntegerJsonHandler.h>
#include <CesiumJsonWriter/StringJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class ModelJsonHandler : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = Model;

  ModelJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, Model* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyModel(
      const std::string& objectType,
      const std::string_view& str,
      Model& o);

private:
  Model* _pObject = nullptr;
  CesiumJsonWriter::
      ArrayJsonHandler<std::string, CesiumJsonWriter::StringJsonHandler>
          _extensionsUsed;
  CesiumJsonWriter::
      ArrayJsonHandler<std::string, CesiumJsonWriter::StringJsonHandler>
          _extensionsRequired;
  CesiumJsonWriter::ArrayJsonHandler<Accessor, AccessorJsonHandler> _accessors;
  CesiumJsonWriter::ArrayJsonHandler<Animation, AnimationJsonHandler>
      _animations;
  AssetJsonHandler _asset;
  CesiumJsonWriter::ArrayJsonHandler<Buffer, BufferJsonHandler> _buffers;
  CesiumJsonWriter::ArrayJsonHandler<BufferView, BufferViewJsonHandler>
      _bufferViews;
  CesiumJsonWriter::ArrayJsonHandler<Camera, CameraJsonHandler> _cameras;
  CesiumJsonWriter::ArrayJsonHandler<Image, ImageJsonHandler> _images;
  CesiumJsonWriter::ArrayJsonHandler<Material, MaterialJsonHandler> _materials;
  CesiumJsonWriter::ArrayJsonHandler<Mesh, MeshJsonHandler> _meshes;
  CesiumJsonWriter::ArrayJsonHandler<Node, NodeJsonHandler> _nodes;
  CesiumJsonWriter::ArrayJsonHandler<Sampler, SamplerJsonHandler> _samplers;
  CesiumJsonWriter::IntegerJsonHandler<int32_t> _scene;
  CesiumJsonWriter::ArrayJsonHandler<Scene, SceneJsonHandler> _scenes;
  CesiumJsonWriter::ArrayJsonHandler<Skin, SkinJsonHandler> _skins;
  CesiumJsonWriter::ArrayJsonHandler<Texture, TextureJsonHandler> _textures;
};
} // namespace CesiumGltf
