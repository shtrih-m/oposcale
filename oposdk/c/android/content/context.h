#ifndef ANDROID_CONTENT_CONTEXT_H_
#define ANDROID_CONTENT_CONTEXT_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Context_ Context;

/// Wraps a JNI reference with Context object.
/// @param jobj A JNI reference to be wrapped with Context object.
/// @see Context_destroy
Context* Context_wrapJniReference(jobject jobj);

jobject Context_getJniReference(const Context* context);

/// Destroys context and all internal resources related to it. This function should be
/// called when context is no longer needed.
/// @param context An object to be destroyed.
void Context_destroy(const Context* context);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_CONTENT_CONTEXT_H_
