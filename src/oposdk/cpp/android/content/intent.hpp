#ifndef CPP_ANDROID_CONTENT_INTENT
#define CPP_ANDROID_CONTENT_INTENT

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace content {

class Intent : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Intent* object);
    explicit Intent(jobject object) : ::gni::Object(object) {}
    ~Intent() override = default;
};

}  // namespace content
}  // namespace android

#endif  // CPP_ANDROID_CONTENT_INTENT

