// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Library.h"
#include "CesiumGltf/NamedObject.h"
#include <cstdint>
#include <optional>
#include <string>

namespace CesiumGltf {
/**
 * @brief Image data used to create a texture. Image **MAY** be referenced by an
 * URI (or IRI) or a buffer view index.
 */
struct CESIUMGLTF_API ImageSpec : public NamedObject {
  static inline constexpr const char* TypeName = "Image";

  /**
   * @brief Known values for The image's media type. This field **MUST** be
   * defined when `bufferView` is defined.
   */
  struct MimeType {
    inline static const std::string image_jpeg = "image/jpeg";

    inline static const std::string image_png = "image/png";
  };

  /**
   * @brief The URI (or IRI) of the image.
   *
   * Relative paths are relative to the current glTF asset.  Instead of
   * referencing an external file, this field **MAY** contain a `data:`-URI.
   * This field **MUST NOT** be defined when `bufferView` is defined.
   */
  std::optional<std::string> uri;

  /**
   * @brief The image's media type. This field **MUST** be defined when
   * `bufferView` is defined.
   *
   * Known values are defined in {@link MimeType}.
   *
   */
  std::optional<std::string> mimeType = MimeType::image_jpeg;

  /**
   * @brief The index of the bufferView that contains the image. This field
   * **MUST NOT** be defined when `uri` is defined.
   */
  int32_t bufferView = -1;

private:
  /**
   * @brief This class is not meant to be instantiated directly. Use {@link Image} instead.
   */
  ImageSpec() = default;
  friend struct Image;
};
} // namespace CesiumGltf
