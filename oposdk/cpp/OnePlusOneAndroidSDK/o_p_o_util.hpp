#ifndef CPP_ONEPLUSONEANDROIDSDK_OPOUTIL
#define CPP_ONEPLUSONEANDROIDSDK_OPOUTIL

#include <memory>
#include "android\content\context.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {

class OPOUtil : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const OPOUtil* object);
    explicit OPOUtil(jobject object) : ::gni::Object(object) {}
    ~OPOUtil() override = default;
    explicit OPOUtil();
    static bool isAPPBackground(const ::android::content::Context& arg1);
    static void WriteLog(const ::java::lang::String& arg1);
    static void SetLogPath(const ::java::lang::String& arg1);
};

}  // namespace OnePlusOneAndroidSDK

#endif  // CPP_ONEPLUSONEANDROIDSDK_OPOUTIL

