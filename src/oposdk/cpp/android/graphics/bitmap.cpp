#include "android\graphics\bitmap.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace graphics {

jclass Bitmap::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/graphics/Bitmap");
  return cached_class;
}

void Bitmap::destroy(const Bitmap* object)
{
  delete object;
}

}  // namespace graphics
}  // namespace android

