#ifndef ANDROID_OS_PARCEL_H_
#define ANDROID_OS_PARCEL_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Parcel_ Parcel;

/// Wraps a JNI reference with Parcel object.
/// @param jobj A JNI reference to be wrapped with Parcel object.
/// @see Parcel_destroy
Parcel* Parcel_wrapJniReference(jobject jobj);

jobject Parcel_getJniReference(const Parcel* parcel);

/// Destroys parcel and all internal resources related to it. This function should be
/// called when parcel is no longer needed.
/// @param parcel An object to be destroyed.
void Parcel_destroy(const Parcel* parcel);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_OS_PARCEL_H_
