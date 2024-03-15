#ifndef JAVA_LANG_STRING_H_
#define JAVA_LANG_STRING_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct String_ String;

String* String_fromCString(const char* c_string);
const char* String_toCString(String* string);
void String_destroyCString(const char* c_string);

/// Wraps a JNI reference with String object.
/// @param jobj A JNI reference to be wrapped with String object.
/// @see String_destroy
String* String_wrapJniReference(jobject jobj);

jobject String_getJniReference(const String* string);

/// Destroys string and all internal resources related to it. This function should be
/// called when string is no longer needed.
/// @param string An object to be destroyed.
void String_destroy(const String* string);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // JAVA_LANG_STRING_H_
