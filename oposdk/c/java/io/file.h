#ifndef JAVA_IO_FILE_H_
#define JAVA_IO_FILE_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct File_ File;

/// Wraps a JNI reference with File object.
/// @param jobj A JNI reference to be wrapped with File object.
/// @see File_destroy
File* File_wrapJniReference(jobject jobj);

jobject File_getJniReference(const File* file);

/// Destroys file and all internal resources related to it. This function should be
/// called when file is no longer needed.
/// @param file An object to be destroyed.
void File_destroy(const File* file);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // JAVA_IO_FILE_H_
