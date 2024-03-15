#include "OnePlusOneAndroidSDK\Printer\label_printer.hpp"
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

namespace {

jobject LabelPrinterOnStatusChangedListenerProxyCallback(void* object_pointer, const char* method_name, jobject* arguments, uint32_t arguments_count)
{

  return nullptr;
}

}  // namespace

jclass LabelPrinter::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/Printer/LabelPrinter");
  return cached_class;
}

void LabelPrinter::destroy(const LabelPrinter* object)
{
  delete object;
}

::OnePlusOneAndroidSDK::Printer::LabelPrinter& LabelPrinter::getInstance(const ::android::content::Context& arg1)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "getInstance", "(Landroid/content/Context;)LOnePlusOneAndroidSDK/Printer/LabelPrinter;");
  ::OnePlusOneAndroidSDK::Printer::LabelPrinter* ret = new ::OnePlusOneAndroidSDK::Printer::LabelPrinter(gni::common::ScopedLocalRef<jobject>(env, env->CallStaticObjectMethod(GetClass(), method_id, arg1.GetImpl())).Get());
  return *ret;
}

bool LabelPrinter::isUsbPrinter() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "isUsbPrinter", "()Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id);
  return ret;
}

bool LabelPrinter::Open() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Open", "()Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id);
  return ret;
}

void LabelPrinter::Close() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Close", "()V");
  env->CallVoidMethod(GetImpl(), method_id);
}

bool LabelPrinter::WriteData(int8_t arg1, int32_t arg2) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "WriteData", "(BI)Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id, arg1, arg2);
  return ret;
}

int8_t LabelPrinter::ReadData(int32_t arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "ReadData", "(I)B");
  int8_t ret = env->CallByteMethod(GetImpl(), method_id, arg1);
  return ret;
}

int32_t LabelPrinter::GetStatus() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "GetStatus", "()I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id);
  return ret;
}

bool LabelPrinter::PrintLabelBitmap(const ::android::graphics::Bitmap& arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "PrintLabelBitmap", "(Landroid/graphics/Bitmap;)Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id, arg1.GetImpl());
  return ret;
}

LabelPrinter::OnStatusChangedListener* LabelPrinter::OnStatusChangedListener::ImplementInterface(onStatusChangedCallback on_status_changed_callback)
{
  LabelPrinter::OnStatusChangedListener* instance = new LabelPrinter::OnStatusChangedListener(nullptr);
  instance->SetImpl(gni::GniCore::GetInstance()->GetJniEnv()->NewGlobalRef(gni::common::interface_proxy::RegisterCallback("OnePlusOneAndroidSDK/Printer/LabelPrinter$OnStatusChangedListener", instance, LabelPrinterOnStatusChangedListenerProxyCallback)));
  instance->on_status_changed_callback_ = on_status_changed_callback;
  return instance;
}

jclass LabelPrinter::OnStatusChangedListener::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/Printer/LabelPrinter$OnStatusChangedListener");
  return cached_class;
}

void LabelPrinter::OnStatusChangedListener::destroy(const LabelPrinter::OnStatusChangedListener* object)
{
  delete object;
}

void LabelPrinter::OnStatusChangedListener::onStatusChanged(int32_t arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "onStatusChanged", "(I)V");
  env->CallVoidMethod(GetImpl(), method_id, arg1);
}

}  // namespace Printer
}  // namespace OnePlusOneAndroidSDK

