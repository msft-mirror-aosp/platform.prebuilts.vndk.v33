#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace wifi {
namespace supplicant {
class MacAddress {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::vector<uint8_t> data;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const MacAddress& rhs) const {
    return std::tie(data) != std::tie(rhs.data);
  }
  inline bool operator<(const MacAddress& rhs) const {
    return std::tie(data) < std::tie(rhs.data);
  }
  inline bool operator<=(const MacAddress& rhs) const {
    return std::tie(data) <= std::tie(rhs.data);
  }
  inline bool operator==(const MacAddress& rhs) const {
    return std::tie(data) == std::tie(rhs.data);
  }
  inline bool operator>(const MacAddress& rhs) const {
    return std::tie(data) > std::tie(rhs.data);
  }
  inline bool operator>=(const MacAddress& rhs) const {
    return std::tie(data) >= std::tie(rhs.data);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "MacAddress{";
    os << "data: " << ::android::internal::ToString(data);
    os << "}";
    return os.str();
  }
};
}  // namespace supplicant
}  // namespace wifi
}  // namespace hardware
}  // namespace android
}  // namespace aidl