#include "android\os\parcelable.h"

#include "android\os\parcelable.hpp"

Parcelable* Parcelable_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Parcelable*>(new ::android::os::Parcelable(jobj));
}

jobject Parcelable_getJniReference(const Parcelable* parcelable) {
  return reinterpret_cast<const ::android::os::Parcelable*>(parcelable)->GetImpl();
}

void Parcelable_destroy(const Parcelable* parcelable) {
  ::android::os::Parcelable::destroy(reinterpret_cast<const ::android::os::Parcelable*>(parcelable));
}
