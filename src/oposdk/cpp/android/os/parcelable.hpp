#ifndef CPP_ANDROID_OS_PARCELABLE
#define CPP_ANDROID_OS_PARCELABLE

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace os {

class Parcelable : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Parcelable* object);
    explicit Parcelable(jobject object) : ::gni::Object(object) {}
    ~Parcelable() override = default;
};

}  // namespace os
}  // namespace android

#endif  // CPP_ANDROID_OS_PARCELABLE

