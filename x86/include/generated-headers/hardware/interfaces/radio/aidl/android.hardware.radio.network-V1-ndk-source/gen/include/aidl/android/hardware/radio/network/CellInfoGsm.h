#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/radio/network/CellIdentityGsm.h>
#include <aidl/android/hardware/radio/network/GsmSignalStrength.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace radio {
namespace network {
class CellInfoGsm {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::hardware::radio::network::CellIdentityGsm cellIdentityGsm;
  ::aidl::android::hardware::radio::network::GsmSignalStrength signalStrengthGsm;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const CellInfoGsm& rhs) const {
    return std::tie(cellIdentityGsm, signalStrengthGsm) != std::tie(rhs.cellIdentityGsm, rhs.signalStrengthGsm);
  }
  inline bool operator<(const CellInfoGsm& rhs) const {
    return std::tie(cellIdentityGsm, signalStrengthGsm) < std::tie(rhs.cellIdentityGsm, rhs.signalStrengthGsm);
  }
  inline bool operator<=(const CellInfoGsm& rhs) const {
    return std::tie(cellIdentityGsm, signalStrengthGsm) <= std::tie(rhs.cellIdentityGsm, rhs.signalStrengthGsm);
  }
  inline bool operator==(const CellInfoGsm& rhs) const {
    return std::tie(cellIdentityGsm, signalStrengthGsm) == std::tie(rhs.cellIdentityGsm, rhs.signalStrengthGsm);
  }
  inline bool operator>(const CellInfoGsm& rhs) const {
    return std::tie(cellIdentityGsm, signalStrengthGsm) > std::tie(rhs.cellIdentityGsm, rhs.signalStrengthGsm);
  }
  inline bool operator>=(const CellInfoGsm& rhs) const {
    return std::tie(cellIdentityGsm, signalStrengthGsm) >= std::tie(rhs.cellIdentityGsm, rhs.signalStrengthGsm);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "CellInfoGsm{";
    os << "cellIdentityGsm: " << ::android::internal::ToString(cellIdentityGsm);
    os << ", signalStrengthGsm: " << ::android::internal::ToString(signalStrengthGsm);
    os << "}";
    return os.str();
  }
};
}  // namespace network
}  // namespace radio
}  // namespace hardware
}  // namespace android
}  // namespace aidl