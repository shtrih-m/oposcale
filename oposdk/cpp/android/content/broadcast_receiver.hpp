#ifndef CPP_ANDROID_CONTENT_BROADCASTRECEIVER
#define CPP_ANDROID_CONTENT_BROADCASTRECEIVER

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace content {

class BroadcastReceiver : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const BroadcastReceiver* object);
    explicit BroadcastReceiver(jobject object) : ::gni::Object(object) {}
    ~BroadcastReceiver() override = default;
};

}  // namespace content
}  // namespace android

#endif  // CPP_ANDROID_CONTENT_BROADCASTRECEIVER

