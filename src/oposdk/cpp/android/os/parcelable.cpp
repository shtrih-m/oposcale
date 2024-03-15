#include "android\os\parcelable.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace os {

jclass Parcelable::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/os/Parcelable");
  return cached_class;
}

void Parcelable::destroy(const Parcelable* object)
{
  delete object;
}

}  // namespace os
}  // namespace android

