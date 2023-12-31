#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/android/hardware/automotive/occupant_awareness/IOccupantAwarenessClientCallback.h>
#include <aidl/android/hardware/automotive/occupant_awareness/OccupantAwarenessStatus.h>
#include <aidl/android/hardware/automotive/occupant_awareness/OccupantDetections.h>
#include <aidl/android/hardware/automotive/occupant_awareness/Role.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace automotive {
namespace occupant_awareness {
class IOccupantAwareness : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IOccupantAwareness();
  virtual ~IOccupantAwareness();

  enum : int32_t { CAP_NONE = 0 };
  enum : int32_t { CAP_PRESENCE_DETECTION = 1 };
  enum : int32_t { CAP_GAZE_DETECTION = 2 };
  enum : int32_t { CAP_DRIVER_MONITORING_DETECTION = 4 };
  static const int32_t version = 1;
  static inline const std::string hash = "3614b1c47ed7be85c1e77554e7f04966cf35b465";
  static constexpr uint32_t TRANSACTION_startDetection = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_stopDetection = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getCapabilityForRole = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getState = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_setCallback = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getLatestDetection = FIRST_CALL_TRANSACTION + 5;

  static std::shared_ptr<IOccupantAwareness> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IOccupantAwareness>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IOccupantAwareness>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IOccupantAwareness>& impl);
  static const std::shared_ptr<IOccupantAwareness>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus startDetection(::aidl::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus stopDetection(::aidl::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getCapabilityForRole(::aidl::android::hardware::automotive::occupant_awareness::Role in_occupantRole, int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getState(::aidl::android::hardware::automotive::occupant_awareness::Role in_occupantRole, int32_t in_detectionCapability, ::aidl::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setCallback(const std::shared_ptr<::aidl::android::hardware::automotive::occupant_awareness::IOccupantAwarenessClientCallback>& in_callback) = 0;
  virtual ::ndk::ScopedAStatus getLatestDetection(::aidl::android::hardware::automotive::occupant_awareness::OccupantDetections* out_detections) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IOccupantAwareness> default_impl;
};
class IOccupantAwarenessDefault : public IOccupantAwareness {
public:
  ::ndk::ScopedAStatus startDetection(::aidl::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) override;
  ::ndk::ScopedAStatus stopDetection(::aidl::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) override;
  ::ndk::ScopedAStatus getCapabilityForRole(::aidl::android::hardware::automotive::occupant_awareness::Role in_occupantRole, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getState(::aidl::android::hardware::automotive::occupant_awareness::Role in_occupantRole, int32_t in_detectionCapability, ::aidl::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) override;
  ::ndk::ScopedAStatus setCallback(const std::shared_ptr<::aidl::android::hardware::automotive::occupant_awareness::IOccupantAwarenessClientCallback>& in_callback) override;
  ::ndk::ScopedAStatus getLatestDetection(::aidl::android::hardware::automotive::occupant_awareness::OccupantDetections* out_detections) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace occupant_awareness
}  // namespace automotive
}  // namespace hardware
}  // namespace android
}  // namespace aidl
