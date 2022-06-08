#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/media/audio/common/AudioSource.h>
#include <aidl/android/media/audio/common/AudioStreamType.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioPortMixExtUseCase {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    unspecified = 0,
    stream = 1,
    source = 2,
  };

  // Expose tag symbols for legacy code
  static const inline Tag unspecified = Tag::unspecified;
  static const inline Tag stream = Tag::stream;
  static const inline Tag source = Tag::source;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioPortMixExtUseCase>;

  AudioPortMixExtUseCase() : _value(std::in_place_index<static_cast<size_t>(unspecified)>, bool(false)) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioPortMixExtUseCase(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioPortMixExtUseCase(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioPortMixExtUseCase make(_Tp&&... _args) {
    return AudioPortMixExtUseCase(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioPortMixExtUseCase make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioPortMixExtUseCase(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
  }

  Tag getTag() const {
    return static_cast<Tag>(_value.index());
  }

  template <Tag _tag>
  const auto& get() const {
    if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
    return std::get<static_cast<size_t>(_tag)>(_value);
  }

  template <Tag _tag>
  auto& get() {
    if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
    return std::get<static_cast<size_t>(_tag)>(_value);
  }

  template <Tag _tag, typename... _Tp>
  void set(_Tp&&... _args) {
    _value.emplace<static_cast<size_t>(_tag)>(std::forward<_Tp>(_args)...);
  }

  binder_status_t readFromParcel(const AParcel* _parcel);
  binder_status_t writeToParcel(AParcel* _parcel) const;

  inline bool operator!=(const AudioPortMixExtUseCase& rhs) const {
    return _value != rhs._value;
  }
  inline bool operator<(const AudioPortMixExtUseCase& rhs) const {
    return _value < rhs._value;
  }
  inline bool operator<=(const AudioPortMixExtUseCase& rhs) const {
    return _value <= rhs._value;
  }
  inline bool operator==(const AudioPortMixExtUseCase& rhs) const {
    return _value == rhs._value;
  }
  inline bool operator>(const AudioPortMixExtUseCase& rhs) const {
    return _value > rhs._value;
  }
  inline bool operator>=(const AudioPortMixExtUseCase& rhs) const {
    return _value >= rhs._value;
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortMixExtUseCase{";
    switch (getTag()) {
    case unspecified: os << "unspecified: " << ::android::internal::ToString(get<unspecified>()); break;
    case stream: os << "stream: " << ::android::internal::ToString(get<stream>()); break;
    case source: os << "source: " << ::android::internal::ToString(get<source>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<bool, ::aidl::android::media::audio::common::AudioStreamType, ::aidl::android::media::audio::common::AudioSource> _value;
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioPortMixExtUseCase::Tag val) {
  switch(val) {
  case AudioPortMixExtUseCase::Tag::unspecified:
    return "unspecified";
  case AudioPortMixExtUseCase::Tag::stream:
    return "stream";
  case AudioPortMixExtUseCase::Tag::source:
    return "source";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::audio::common::AudioPortMixExtUseCase::Tag, 3> enum_values<aidl::android::media::audio::common::AudioPortMixExtUseCase::Tag> = {
  aidl::android::media::audio::common::AudioPortMixExtUseCase::Tag::unspecified,
  aidl::android::media::audio::common::AudioPortMixExtUseCase::Tag::stream,
  aidl::android::media::audio::common::AudioPortMixExtUseCase::Tag::source,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
