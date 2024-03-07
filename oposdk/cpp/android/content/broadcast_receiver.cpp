#include "android\content\broadcast_receiver.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace content {

jclass BroadcastReceiver::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/content/BroadcastReceiver");
  return cached_class;
}

void BroadcastReceiver::destroy(const BroadcastReceiver* object)
{
  delete object;
}

}  // namespace content
}  // namespace android

