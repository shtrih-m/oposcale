#ifndef CPP_ONEPLUSONEANDROIDSDK_BUILDCONFIG
#define CPP_ONEPLUSONEANDROIDSDK_BUILDCONFIG

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {

class BuildConfig : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const BuildConfig* object);
    explicit BuildConfig(jobject object) : ::gni::Object(object) {}
    ~BuildConfig() override = default;
    explicit BuildConfig();
    static constexpr bool DEBUG = 0;
    static constexpr const char* APPLICATION_ID = "OnePlusOneAndroidSDK";
    static constexpr const char* BUILD_TYPE = "release";
    static constexpr const char* FLAVOR = "";
    static constexpr int32_t VERSION_CODE = 16;
    static constexpr const char* VERSION_NAME = "v2.016_220715";
};

}  // namespace OnePlusOneAndroidSDK

#endif  // CPP_ONEPLUSONEANDROIDSDK_BUILDCONFIG

