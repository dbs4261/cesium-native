#include "JsonObjectWriter.h"
#include "AccessorWriter.h"
#include "AccessorSparseWriter.h"
#include <stdexcept>
#include <type_traits>
#include <magic_enum.hpp>

void CesiumGltf::writeAccessor(
    const std::vector<Accessor>& accessors,
    rapidjson::Writer<rapidjson::StringBuffer>& jsonWriter) {

    if (accessors.empty()) {
        return;
    }

    auto& j = jsonWriter;

    j.Key("accessors");
    j.StartArray();
    for (const auto& accessor : accessors) {
        j.StartObject();
        if (accessor.bufferView >= 0) {
            j.Key("bufferView");
            j.Int(accessor.bufferView);
        }

        if (accessor.byteOffset >= 0) {
            j.Key("byteOffset");
            j.Int64(accessor.byteOffset);
        }

        j.Key("componentType");
        j.Int(magic_enum::enum_integer(accessor.componentType));

        if (accessor.normalized) {
            j.Key("normalized");
            j.Bool(accessor.normalized);
        }

        j.Key("count");
        j.Uint(static_cast<unsigned int>(accessor.count));

        j.Key("type");
        j.String(AccessorSpec::typeToString(accessor.type).c_str());

        if (!accessor.max.empty()) {
            j.Key("max");
            j.StartArray();
            for (const auto channelMax : accessor.max) {
                j.Double(channelMax);
            }
            j.EndArray();
        }

        if (!accessor.min.empty()) {
            j.Key("min");
            j.StartArray();
            for (const auto channelMin : accessor.min) {
                j.Double(channelMin);
            }
            j.EndArray();
        }

        if (accessor.sparse) {
            writeAccessorSparse(*accessor.sparse, jsonWriter);
        }

        if (!accessor.name.empty()) {
            j.Key("name");
            j.String(accessor.name.c_str());
        }

        if (!accessor.extras.empty()) {
            j.Key("extras");
            writeJsonObject(accessor.extras, j);
        }

        if (!accessor.extensions.empty()) {
            throw std::runtime_error("Not implemented.");
        }
        j.EndObject();
    }
    j.EndArray();
}