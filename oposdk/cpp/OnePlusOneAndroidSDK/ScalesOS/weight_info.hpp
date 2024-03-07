#ifndef CPP_ONEPLUSONEANDROIDSDK_SCALESOS_WEIGHTINFO
#define CPP_ONEPLUSONEANDROIDSDK_SCALESOS_WEIGHTINFO

#include <memory>
#include "android\os\parcel.hpp"
#include "android\os\parcelable.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {
namespace ScalesOS {

class WeightInfo : public ::android::os::Parcelable
{
public:
    static jclass GetClass();
    static void destroy(const WeightInfo* object);
    explicit WeightInfo(jobject object) : ::gni::Object(object), ::android::os::Parcelable(object) {}
    ~WeightInfo() override = default;
    explicit WeightInfo();
    explicit WeightInfo(const ::java::lang::String& arg1);
    virtual bool updata(const ::java::lang::String& arg1) const;
    virtual ::java::lang::String& getMode() const;
    virtual ::java::lang::String& getStatus() const;
    virtual bool getZero() const;
    virtual ::java::lang::String& getUnit() const;
    virtual ::java::lang::String& getNetWeight() const;
    virtual ::java::lang::String& getTareWeight() const;
    virtual ::java::lang::String& getGrossWeight() const;
    virtual ::java::lang::String& toString() const;
    virtual int32_t describeContents() const;
    virtual void writeToParcel(const ::android::os::Parcel& arg1, int32_t arg2) const;
};

}  // namespace ScalesOS
}  // namespace OnePlusOneAndroidSDK

#endif  // CPP_ONEPLUSONEANDROIDSDK_SCALESOS_WEIGHTINFO

