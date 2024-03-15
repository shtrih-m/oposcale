#ifndef ANDROID_GRAPHICS_BITMAP_H_
#define ANDROID_GRAPHICS_BITMAP_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Bitmap_ Bitmap;

/// Wraps a JNI reference with Bitmap object.
/// @param jobj A JNI reference to be wrapped with Bitmap object.
/// @see Bitmap_destroy
Bitmap* Bitmap_wrapJniReference(jobject jobj);

jobject Bitmap_getJniReference(const Bitmap* bitmap);

/// Destroys bitmap and all internal resources related to it. This function should be
/// called when bitmap is no longer needed.
/// @param bitmap An object to be destroyed.
void Bitmap_destroy(const Bitmap* bitmap);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_GRAPHICS_BITMAP_H_
