#ifndef CPP_ONEPLUSONEANDROIDSDK_PRINTER_LABELPRINTER
#define CPP_ONEPLUSONEANDROIDSDK_PRINTER_LABELPRINTER

#include <memory>
#include "OnePlusOneAndroidSDK\u_s_b_interface.hpp"
#include "android\content\context.hpp"
#include "android\graphics\bitmap.hpp"
#include "gni/common/interface_proxy.h"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace OnePlusOneAndroidSDK {
namespace Printer {

class LabelPrinter : public ::OnePlusOneAndroidSDK::USBInterface
{
public:
    class OnStatusChangedListener;

    static jclass GetClass();
    static void destroy(const LabelPrinter* object);
    explicit LabelPrinter(jobject object) : ::gni::Object(object), ::OnePlusOneAndroidSDK::USBInterface(object) {}
    ~LabelPrinter() override = default;
    static ::OnePlusOneAndroidSDK::Printer::LabelPrinter& getInstance(const ::android::content::Context& arg1);
    virtual bool isUsbPrinter() const;
    virtual bool Open() const;
    virtual void Close() const;
    virtual bool WriteData(int8_t arg1, int32_t arg2) const;
    virtual int8_t ReadData(int32_t arg1) const;
    virtual int32_t GetStatus() const;
    virtual bool PrintLabelBitmap(const ::android::graphics::Bitmap& arg1) const;

    class OnStatusChangedListener : virtual public ::gni::Object
    {
    public:
        using onStatusChangedCallback = void (*)(int32_t);

        static jclass GetClass();
        static void destroy(const OnStatusChangedListener* object);
        static OnStatusChangedListener* ImplementInterface(onStatusChangedCallback on_status_changed_callback);
        explicit OnStatusChangedListener(jobject object) : ::gni::Object(object) {}
        ~OnStatusChangedListener() override = default;
        virtual void onStatusChanged(int32_t arg1) const;
        onStatusChangedCallback on_status_changed_callback_ = nullptr;
    };
};

}  // namespace Printer
}  // namespace OnePlusOneAndroidSDK

#endif  // CPP_ONEPLUSONEANDROIDSDK_PRINTER_LABELPRINTER

