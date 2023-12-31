#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/light/LightType.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace light {
class HwLight {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t id = 0;
  int32_t ordinal = 0;
  ::aidl::android::hardware::light::LightType type = ::aidl::android::hardware::light::LightType(0);

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) != std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator<(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) < std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator<=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) <= std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator==(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) == std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator>(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) > std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator>=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) >= std::tie(rhs.id, rhs.ordinal, rhs.type);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "HwLight{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", ordinal: " << ::android::internal::ToString(ordinal);
    os << ", type: " << ::android::internal::ToString(type);
    os << "}";
    return os.str();
  }
};
}  // namespace light
}  // namespace hardware
}  // namespace android
}  // namespace aidl
