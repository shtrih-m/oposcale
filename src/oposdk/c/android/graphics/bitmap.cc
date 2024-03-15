#include "android\graphics\bitmap.h"

#include "android\graphics\bitmap.hpp"

Bitmap* Bitmap_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Bitmap*>(new ::android::graphics::Bitmap(jobj));
}

jobject Bitmap_getJniReference(const Bitmap* bitmap) {
  return reinterpret_cast<const ::android::graphics::Bitmap*>(bitmap)->GetImpl();
}

void Bitmap_destroy(const Bitmap* bitmap) {
  ::android::graphics::Bitmap::destroy(reinterpret_cast<const ::android::graphics::Bitmap*>(bitmap));
}
