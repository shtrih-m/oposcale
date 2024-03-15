#ifndef CPP_ONEPLUSONEANDROIDSDK_PRINTER_POSPRINTER
#define CPP_ONEPLUSONEANDROIDSDK_PRINTER_POSPRINTER

#include <memory>
#include "OnePlusOneAndroidSDK\u_s_b_interface.hpp"
#include "android\content\context.hpp"
#include "android\graphics\bitmap.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace OnePlusOneAndroidSDK {
namespace Printer {

class PosPrinter : public ::OnePlusOneAndroidSDK::USBInterface
{
public:
    static jclass GetClass();
    static void destroy(const PosPrinter* object);
    explicit PosPrinter(jobject object) : ::gni::Object(object), ::OnePlusOneAndroidSDK::USBInterface(object) {}
    ~PosPrinter() override = default;
    static ::OnePlusOneAndroidSDK::Printer::PosPrinter& getInstance(const ::android::content::Context& arg1);
    virtual bool RollPaperStatus() const;
    virtual bool PrintLabelBitmap(const ::android::graphics::Bitmap& arg1) const;
};

}  // namespace Printer
}  // namespace OnePlusOneAndroidSDK

#endif  // CPP_ONEPLUSONEANDROIDSDK_PRINTER_POSPRINTER

