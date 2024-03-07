#include "android\content\context.h"

#include "android\content\context.hpp"

Context* Context_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Context*>(new ::android::content::Context(jobj));
}

jobject Context_getJniReference(const Context* context) {
  return reinterpret_cast<const ::android::content::Context*>(context)->GetImpl();
}

void Context_destroy(const Context* context) {
  ::android::content::Context::destroy(reinterpret_cast<const ::android::content::Context*>(context));
}
