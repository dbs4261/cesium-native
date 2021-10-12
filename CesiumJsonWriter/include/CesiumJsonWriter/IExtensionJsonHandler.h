#pragma once

#include "IJsonHandler.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <any>
#include <string_view>

namespace CesiumJsonWriter {

class IExtensionJsonHandler : public IJsonHandler {
public:
  virtual void reset(
      IJsonHandler* pParentHandler,
      CesiumUtility::ExtensibleObject& o,
      const std::string_view& extensionName) = 0;
};

} // namespace CesiumJsonWriter
