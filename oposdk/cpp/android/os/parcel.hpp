#ifndef CPP_ANDROID_OS_PARCEL
#define CPP_ANDROID_OS_PARCEL

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace os {

class Parcel : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Parcel* object);
    explicit Parcel(jobject object) : ::gni::Object(object) {}
    ~Parcel() override = default;
};

}  // namespace os
}  // namespace android

#endif  // CPP_ANDROID_OS_PARCEL

