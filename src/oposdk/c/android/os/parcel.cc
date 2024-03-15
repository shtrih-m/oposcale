#include "android\os\parcel.h"

#include "android\os\parcel.hpp"

Parcel* Parcel_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Parcel*>(new ::android::os::Parcel(jobj));
}

jobject Parcel_getJniReference(const Parcel* parcel) {
  return reinterpret_cast<const ::android::os::Parcel*>(parcel)->GetImpl();
}

void Parcel_destroy(const Parcel* parcel) {
  ::android::os::Parcel::destroy(reinterpret_cast<const ::android::os::Parcel*>(parcel));
}
