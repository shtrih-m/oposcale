#ifndef ANDROID_OS_PARCELABLE_H_
#define ANDROID_OS_PARCELABLE_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Parcelable_ Parcelable;

/// Wraps a JNI reference with Parcelable object.
/// @param jobj A JNI reference to be wrapped with Parcelable object.
/// @see Parcelable_destroy
Parcelable* Parcelable_wrapJniReference(jobject jobj);

jobject Parcelable_getJniReference(const Parcelable* parcelable);

/// Destroys parcelable and all internal resources related to it. This function should be
/// called when parcelable is no longer needed.
/// @param parcelable An object to be destroyed.
void Parcelable_destroy(const Parcelable* parcelable);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_OS_PARCELABLE_H_
