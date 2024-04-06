// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Library.h"

#include <CesiumUtility/ExtensibleObject.h>
#include <CesiumUtility/JsonValue.h>

#include <optional>
#include <string>
#include <unordered_map>

namespace CesiumGltf {
/**
 * @brief Structural metadata about a glTF element.
 */
struct CESIUMGLTF_API ExtensionNodeExtStructuralMetadata final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName =
      "ExtensionNodeExtStructuralMetadata";
  static inline constexpr const char* ExtensionName = "EXT_structural_metadata";

  /**
   * @brief The class that property values conform to. The value shall be a
   * class ID declared in the `classes` dictionary of the metadata schema.
   */
  std::optional<std::string> classProperty;

  /**
   * @brief A dictionary, where each key corresponds to a property ID in the
   * class' `properties` dictionary and each value contains the property values.
   * The type of the value shall match the property definition: For `BOOLEAN`
   * use `true` or `false`. For `STRING` use a JSON string. For numeric types
   * use a JSON number. For `ENUM` use a valid enum `name`, not an integer
   * value. For `ARRAY`, `VECN`, and `MATN` types use a JSON array containing
   * values matching the `componentType`. Required properties shall be included
   * in this dictionary.
   */
  std::unordered_map<std::string, CesiumUtility::JsonValue> properties;
};
} // namespace CesiumGltf
