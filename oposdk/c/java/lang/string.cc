#include "java\lang\string.h"

#include "java\lang\string.hpp"

String* String_fromCString(const char* c_string) {
  return String_wrapJniReference(gni::GniCore::GetInstance()->ConvertString(c_string).GetImpl());
}

const char* String_toCString(String* string) {
  return gni::GniCore::GetInstance()->ConvertString(String_getJniReference(string));
}

void String_destroyCString(const char* c_string) {
  free(const_cast<char*>(c_string));
}

String* String_wrapJniReference(jobject jobj) {
  return reinterpret_cast<String*>(new ::java::lang::String(jobj));
}

jobject String_getJniReference(const String* string) {
  return reinterpret_cast<const ::java::lang::String*>(string)->GetImpl();
}

void String_destroy(const String* string) {
  ::java::lang::String::destroy(reinterpret_cast<const ::java::lang::String*>(string));
}
