#include "android\content\intent.h"

#include "android\content\intent.hpp"

Intent* Intent_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Intent*>(new ::android::content::Intent(jobj));
}

jobject Intent_getJniReference(const Intent* intent) {
  return reinterpret_cast<const ::android::content::Intent*>(intent)->GetImpl();
}

void Intent_destroy(const Intent* intent) {
  ::android::content::Intent::destroy(reinterpret_cast<const ::android::content::Intent*>(intent));
}
