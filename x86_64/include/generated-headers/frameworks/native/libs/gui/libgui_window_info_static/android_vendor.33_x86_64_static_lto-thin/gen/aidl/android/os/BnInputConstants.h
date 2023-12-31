#pragma once

#include <binder/IInterface.h>
#include <android/os/IInputConstants.h>

namespace android {
namespace os {
class BnInputConstants : public ::android::BnInterface<IInputConstants> {
public:
  explicit BnInputConstants();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnInputConstants

class IInputConstantsDelegator : public BnInputConstants {
public:
  explicit IInputConstantsDelegator(::android::sp<IInputConstants> &impl) : _aidl_delegate(impl) {}

private:
  ::android::sp<IInputConstants> _aidl_delegate;
};  // class IInputConstantsDelegator
}  // namespace os
}  // namespace android
