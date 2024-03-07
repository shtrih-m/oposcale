#ifndef CPP_ANDROID_GRAPHICS_BITMAP
#define CPP_ANDROID_GRAPHICS_BITMAP

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace graphics {

class Bitmap : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Bitmap* object);
    explicit Bitmap(jobject object) : ::gni::Object(object) {}
    ~Bitmap() override = default;
};

}  // namespace graphics
}  // namespace android

#endif  // CPP_ANDROID_GRAPHICS_BITMAP

