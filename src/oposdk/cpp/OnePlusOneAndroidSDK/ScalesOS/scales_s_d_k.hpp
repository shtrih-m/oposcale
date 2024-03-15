#ifndef CPP_ONEPLUSONEANDROIDSDK_SCALESOS_SCALESSDK
#define CPP_ONEPLUSONEANDROIDSDK_SCALESOS_SCALESSDK

#include <memory>
#include "OnePlusOneAndroidSDK\ScalesOS\weight_info.hpp"
#include "android\content\context.hpp"
#include "gni/common/interface_proxy.h"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\io\file.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {
namespace ScalesOS {

class ScalesSDK : virtual public ::gni::Object
{
public:
    class WeightChangedListener;

    static jclass GetClass();
    static void destroy(const ScalesSDK* object);
    explicit ScalesSDK(jobject object) : ::gni::Object(object) {}
    ~ScalesSDK() override = default;
    virtual void setWeightChangedListener(const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener& arg1) const;
    virtual void setScaleAlwaysRead() const;
    static ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK& getInstance(const ::android::content::Context& arg1);
    static ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK& getInstance(const ::android::content::Context& arg1, const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener& arg2);
    virtual bool Open(const ::java::io::File& arg1) const;
    virtual ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo& getWeihtInfo() const;
    static void ReadThread(bool arg1);
    virtual ::java::lang::String& OPOModuleSend(int32_t arg1, int32_t arg2, int8_t arg3, int32_t arg4) const;
    virtual int32_t Close() const;
    virtual ::java::lang::String& GetResult() const;
    virtual int32_t Zero() const;
    virtual int32_t Tare() const;
    virtual int32_t PreTare(int32_t arg1) const;
    virtual int32_t ExitTare() const;

    class WeightChangedListener : virtual public ::gni::Object
    {
    public:
        using onWeightChangedCallback = void (*)(const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*);

        static jclass GetClass();
        static void destroy(const WeightChangedListener* object);
        static WeightChangedListener* ImplementInterface(onWeightChangedCallback on_weight_changed_callback);
        explicit WeightChangedListener(jobject object) : ::gni::Object(object) {}
        ~WeightChangedListener() override = default;
        virtual void onWeightChanged(const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo& arg1) const;
        onWeightChangedCallback on_weight_changed_callback_ = nullptr;
    };
};

}  // namespace ScalesOS
}  // namespace OnePlusOneAndroidSDK

#endif  // CPP_ONEPLUSONEANDROIDSDK_SCALESOS_SCALESSDK

