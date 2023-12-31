#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/android/hardware/power/Boost.h>
#include <aidl/android/hardware/power/IPowerHintSession.h>
#include <aidl/android/hardware/power/Mode.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace power {
class IPower : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IPower();
  virtual ~IPower();

  static const int32_t version = 3;
  static inline const std::string hash = "fd3434f993d791e75d959a042010dd6fca13e33c";
  static constexpr uint32_t TRANSACTION_setMode = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_isModeSupported = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_setBoost = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_isBoostSupported = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_createHintSession = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getHintSessionPreferredRate = FIRST_CALL_TRANSACTION + 5;

  static std::shared_ptr<IPower> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IPower>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IPower>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IPower>& impl);
  static const std::shared_ptr<IPower>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus setMode(::aidl::android::hardware::power::Mode in_type, bool in_enabled) = 0;
  virtual ::ndk::ScopedAStatus isModeSupported(::aidl::android::hardware::power::Mode in_type, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setBoost(::aidl::android::hardware::power::Boost in_type, int32_t in_durationMs) = 0;
  virtual ::ndk::ScopedAStatus isBoostSupported(::aidl::android::hardware::power::Boost in_type, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus createHintSession(int32_t in_tgid, int32_t in_uid, const std::vector<int32_t>& in_threadIds, int64_t in_durationNanos, std::shared_ptr<::aidl::android::hardware::power::IPowerHintSession>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getHintSessionPreferredRate(int64_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IPower> default_impl;
};
class IPowerDefault : public IPower {
public:
  ::ndk::ScopedAStatus setMode(::aidl::android::hardware::power::Mode in_type, bool in_enabled) override;
  ::ndk::ScopedAStatus isModeSupported(::aidl::android::hardware::power::Mode in_type, bool* _aidl_return) override;
  ::ndk::ScopedAStatus setBoost(::aidl::android::hardware::power::Boost in_type, int32_t in_durationMs) override;
  ::ndk::ScopedAStatus isBoostSupported(::aidl::android::hardware::power::Boost in_type, bool* _aidl_return) override;
  ::ndk::ScopedAStatus createHintSession(int32_t in_tgid, int32_t in_uid, const std::vector<int32_t>& in_threadIds, int64_t in_durationNanos, std::shared_ptr<::aidl::android::hardware::power::IPowerHintSession>* _aidl_return) override;
  ::ndk::ScopedAStatus getHintSessionPreferredRate(int64_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace power
}  // namespace hardware
}  // namespace android
}  // namespace aidl
