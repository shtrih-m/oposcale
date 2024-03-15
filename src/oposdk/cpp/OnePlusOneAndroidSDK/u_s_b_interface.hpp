#ifndef CPP_ONEPLUSONEANDROIDSDK_USBINTERFACE
#define CPP_ONEPLUSONEANDROIDSDK_USBINTERFACE

#include <memory>
#include "android\content\broadcast_receiver.hpp"
#include "android\content\context.hpp"
#include "android\content\intent.hpp"
#include "gni/common/interface_proxy.h"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {

class USBInterface : public ::android::content::BroadcastReceiver
{
public:
    class OnUpLoadProcessListener;

    static jclass GetClass();
    static void destroy(const USBInterface* object);
    explicit USBInterface(jobject object) : ::gni::Object(object), ::android::content::BroadcastReceiver(object) {}
    ~USBInterface() override = default;
    explicit USBInterface(const ::android::content::Context& arg1);
    virtual void setsDevice(const ::java::lang::String& arg1) const;
    virtual void onReceive(const ::android::content::Context& arg1, const ::android::content::Intent& arg2) const;
    virtual ::java::lang::String& getPrinterList() const;
    virtual bool Open() const;
    virtual void Close() const;
    virtual bool WriteData(int8_t arg1) const;
    virtual bool WriteData(int8_t arg1, int32_t arg2) const;
    virtual int8_t ReadData() const;
    virtual int8_t ReadData(int32_t arg1) const;

    class OnUpLoadProcessListener : virtual public ::gni::Object
    {
    public:
        using onUpLoadProcessCallback = void (*)(int32_t, int32_t);

        static jclass GetClass();
        static void destroy(const OnUpLoadProcessListener* object);
        static OnUpLoadProcessListener* ImplementInterface(onUpLoadProcessCallback on_up_load_process_callback);
        explicit OnUpLoadProcessListener(jobject object) : ::gni::Object(object) {}
        ~OnUpLoadProcessListener() override = default;
        virtual void onUpLoadProcess(int32_t arg1, int32_t arg2) const;
        onUpLoadProcessCallback on_up_load_process_callback_ = nullptr;
    };
};

}  // namespace OnePlusOneAndroidSDK

#endif  // CPP_ONEPLUSONEANDROIDSDK_USBINTERFACE

