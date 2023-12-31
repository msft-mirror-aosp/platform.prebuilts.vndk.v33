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
namespace power {
namespace stats {
class State {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t id = 0;
  std::string name;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const State& rhs) const {
    return std::tie(id, name) != std::tie(rhs.id, rhs.name);
  }
  inline bool operator<(const State& rhs) const {
    return std::tie(id, name) < std::tie(rhs.id, rhs.name);
  }
  inline bool operator<=(const State& rhs) const {
    return std::tie(id, name) <= std::tie(rhs.id, rhs.name);
  }
  inline bool operator==(const State& rhs) const {
    return std::tie(id, name) == std::tie(rhs.id, rhs.name);
  }
  inline bool operator>(const State& rhs) const {
    return std::tie(id, name) > std::tie(rhs.id, rhs.name);
  }
  inline bool operator>=(const State& rhs) const {
    return std::tie(id, name) >= std::tie(rhs.id, rhs.name);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "State{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", name: " << ::android::internal::ToString(name);
    os << "}";
    return os.str();
  }
};
}  // namespace stats
}  // namespace power
}  // namespace hardware
}  // namespace android
}  // namespace aidl
