#ifndef ANDROID_CONTENT_INTENT_H_
#define ANDROID_CONTENT_INTENT_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Intent_ Intent;

/// Wraps a JNI reference with Intent object.
/// @param jobj A JNI reference to be wrapped with Intent object.
/// @see Intent_destroy
Intent* Intent_wrapJniReference(jobject jobj);

jobject Intent_getJniReference(const Intent* intent);

/// Destroys intent and all internal resources related to it. This function should be
/// called when intent is no longer needed.
/// @param intent An object to be destroyed.
void Intent_destroy(const Intent* intent);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_CONTENT_INTENT_H_
