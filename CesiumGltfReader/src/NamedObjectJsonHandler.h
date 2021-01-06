#pragma once

#include "ExtensibleObjectJsonHandler.h"
#include "StringJsonHandler.h"

namespace CesiumGltf {
    struct NamedObject;

    class NamedObjectJsonHandler : public ExtensibleObjectJsonHandler {
    protected:
        IJsonHandler* NamedObjectKey(const char* str, NamedObject& o);

    private:
        StringJsonHandler _name;
    };
}
