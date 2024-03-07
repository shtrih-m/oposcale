#include "OnePlusOneAndroidSDK\Printer\pos_printer.hpp"
#include <memory>
#include "OnePlusOneAndroidSDK\u_s_b_interface.hpp"
#include "android\content\context.hpp"
#include "android\graphics\bitmap.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace OnePlusOneAndroidSDK {
namespace Printer {

jclass PosPrinter::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/Printer/PosPrinter");
  return cached_class;
}

void PosPrinter::destroy(const PosPrinter* object)
{
  delete object;
}

::OnePlusOneAndroidSDK::Printer::PosPrinter& PosPrinter::getInstance(const ::android::content::Context& arg1)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "getInstance", "(Landroid/content/Context;)LOnePlusOneAndroidSDK/Printer/PosPrinter;");
  ::OnePlusOneAndroidSDK::Printer::PosPrinter* ret = new ::OnePlusOneAndroidSDK::Printer::PosPrinter(gni::common::ScopedLocalRef<jobject>(env, env->CallStaticObjectMethod(GetClass(), method_id, arg1.GetImpl())).Get());
  return *ret;
}

bool PosPrinter::RollPaperStatus() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "RollPaperStatus", "()Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id);
  return ret;
}

bool PosPrinter::PrintLabelBitmap(const ::android::graphics::Bitmap& arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "PrintLabelBitmap", "(Landroid/graphics/Bitmap;)Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id, arg1.GetImpl());
  return ret;
}

}  // namespace Printer
}  // namespace OnePlusOneAndroidSDK

