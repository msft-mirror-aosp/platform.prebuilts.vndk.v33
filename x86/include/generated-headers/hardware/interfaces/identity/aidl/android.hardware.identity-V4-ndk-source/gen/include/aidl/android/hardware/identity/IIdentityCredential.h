#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/android/hardware/identity/Certificate.h>
#include <aidl/android/hardware/identity/IWritableIdentityCredential.h>
#include <aidl/android/hardware/identity/RequestNamespace.h>
#include <aidl/android/hardware/identity/SecureAccessControlProfile.h>
#include <aidl/android/hardware/keymaster/HardwareAuthToken.h>
#include <aidl/android/hardware/keymaster/VerificationToken.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace identity {
class IIdentityCredential : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IIdentityCredential();
  virtual ~IIdentityCredential();

  static const int32_t version = 4;
  static inline const std::string hash = "2d63b17eb0f860c87b3564eda281342fb362e38d";
  static constexpr uint32_t TRANSACTION_deleteCredential = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_createEphemeralKeyPair = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_setReaderEphemeralPublicKey = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_createAuthChallenge = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_startRetrieval = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_startRetrieveEntryValue = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_retrieveEntryValue = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_finishRetrieval = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_generateSigningKeyPair = FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_setRequestedNamespaces = FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_setVerificationToken = FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_deleteCredentialWithChallenge = FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_proveOwnership = FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_updateCredential = FIRST_CALL_TRANSACTION + 13;

  static std::shared_ptr<IIdentityCredential> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IIdentityCredential>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IIdentityCredential>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IIdentityCredential>& impl);
  static const std::shared_ptr<IIdentityCredential>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus deleteCredential(std::vector<uint8_t>* _aidl_return) __attribute__((deprecated("use deleteCredentalWithChallenge() instead."))) = 0;
  virtual ::ndk::ScopedAStatus createEphemeralKeyPair(std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setReaderEphemeralPublicKey(const std::vector<uint8_t>& in_publicKey) = 0;
  virtual ::ndk::ScopedAStatus createAuthChallenge(int64_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus startRetrieval(const std::vector<::aidl::android::hardware::identity::SecureAccessControlProfile>& in_accessControlProfiles, const ::aidl::android::hardware::keymaster::HardwareAuthToken& in_authToken, const std::vector<uint8_t>& in_itemsRequest, const std::vector<uint8_t>& in_signingKeyBlob, const std::vector<uint8_t>& in_sessionTranscript, const std::vector<uint8_t>& in_readerSignature, const std::vector<int32_t>& in_requestCounts) = 0;
  virtual ::ndk::ScopedAStatus startRetrieveEntryValue(const std::string& in_nameSpace, const std::string& in_name, int32_t in_entrySize, const std::vector<int32_t>& in_accessControlProfileIds) = 0;
  virtual ::ndk::ScopedAStatus retrieveEntryValue(const std::vector<uint8_t>& in_encryptedContent, std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus finishRetrieval(std::vector<uint8_t>* out_mac, std::vector<uint8_t>* out_deviceNameSpaces) = 0;
  virtual ::ndk::ScopedAStatus generateSigningKeyPair(std::vector<uint8_t>* out_signingKeyBlob, ::aidl::android::hardware::identity::Certificate* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setRequestedNamespaces(const std::vector<::aidl::android::hardware::identity::RequestNamespace>& in_requestNamespaces) = 0;
  virtual ::ndk::ScopedAStatus setVerificationToken(const ::aidl::android::hardware::keymaster::VerificationToken& in_verificationToken) = 0;
  virtual ::ndk::ScopedAStatus deleteCredentialWithChallenge(const std::vector<uint8_t>& in_challenge, std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus proveOwnership(const std::vector<uint8_t>& in_challenge, std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus updateCredential(std::shared_ptr<::aidl::android::hardware::identity::IWritableIdentityCredential>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IIdentityCredential> default_impl;
};
class IIdentityCredentialDefault : public IIdentityCredential {
public:
  ::ndk::ScopedAStatus deleteCredential(std::vector<uint8_t>* _aidl_return) override __attribute__((deprecated("use deleteCredentalWithChallenge() instead.")));
  ::ndk::ScopedAStatus createEphemeralKeyPair(std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus setReaderEphemeralPublicKey(const std::vector<uint8_t>& in_publicKey) override;
  ::ndk::ScopedAStatus createAuthChallenge(int64_t* _aidl_return) override;
  ::ndk::ScopedAStatus startRetrieval(const std::vector<::aidl::android::hardware::identity::SecureAccessControlProfile>& in_accessControlProfiles, const ::aidl::android::hardware::keymaster::HardwareAuthToken& in_authToken, const std::vector<uint8_t>& in_itemsRequest, const std::vector<uint8_t>& in_signingKeyBlob, const std::vector<uint8_t>& in_sessionTranscript, const std::vector<uint8_t>& in_readerSignature, const std::vector<int32_t>& in_requestCounts) override;
  ::ndk::ScopedAStatus startRetrieveEntryValue(const std::string& in_nameSpace, const std::string& in_name, int32_t in_entrySize, const std::vector<int32_t>& in_accessControlProfileIds) override;
  ::ndk::ScopedAStatus retrieveEntryValue(const std::vector<uint8_t>& in_encryptedContent, std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus finishRetrieval(std::vector<uint8_t>* out_mac, std::vector<uint8_t>* out_deviceNameSpaces) override;
  ::ndk::ScopedAStatus generateSigningKeyPair(std::vector<uint8_t>* out_signingKeyBlob, ::aidl::android::hardware::identity::Certificate* _aidl_return) override;
  ::ndk::ScopedAStatus setRequestedNamespaces(const std::vector<::aidl::android::hardware::identity::RequestNamespace>& in_requestNamespaces) override;
  ::ndk::ScopedAStatus setVerificationToken(const ::aidl::android::hardware::keymaster::VerificationToken& in_verificationToken) override;
  ::ndk::ScopedAStatus deleteCredentialWithChallenge(const std::vector<uint8_t>& in_challenge, std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus proveOwnership(const std::vector<uint8_t>& in_challenge, std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus updateCredential(std::shared_ptr<::aidl::android::hardware::identity::IWritableIdentityCredential>* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace identity
}  // namespace hardware
}  // namespace android
}  // namespace aidl
