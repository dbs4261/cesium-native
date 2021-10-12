// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "AnimationChannelTargetJsonHandler.h"

#include <CesiumGltf/AnimationChannel.h>
#include <CesiumJsonWriter/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonWriter/IntegerJsonHandler.h>

namespace CesiumJsonWriter {
class ExtensionWriterContext;
}

namespace CesiumGltf {
class AnimationChannelJsonHandler
    : public CesiumJsonWriter::ExtensibleObjectJsonHandler {
public:
  using ValueType = AnimationChannel;

  AnimationChannelJsonHandler(
      const CesiumJsonWriter::ExtensionWriterContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, AnimationChannel* pObject);

  virtual IJsonHandler* writeObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* writeObjectKeyAnimationChannel(
      const std::string& objectType,
      const std::string_view& str,
      AnimationChannel& o);

private:
  AnimationChannel* _pObject = nullptr;
  CesiumJsonWriter::IntegerJsonHandler<int32_t> _sampler;
  AnimationChannelTargetJsonHandler _target;
};
} // namespace CesiumGltf
