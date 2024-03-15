#include "android\content\intent.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace content {

jclass Intent::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/content/Intent");
  return cached_class;
}

void Intent::destroy(const Intent* object)
{
  delete object;
}

}  // namespace content
}  // namespace android

