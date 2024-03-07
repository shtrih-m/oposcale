#include "android\os\parcel.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace os {

jclass Parcel::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/os/Parcel");
  return cached_class;
}

void Parcel::destroy(const Parcel* object)
{
  delete object;
}

}  // namespace os
}  // namespace android

