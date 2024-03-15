#include "OnePlusOneAndroidSDK\u_s_b_interface.hpp"
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

namespace {

jobject CreateJavaUSBInterfaceObject(const ::android::content::Context& arg1) {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(USBInterface::GetClass(), "<init>", "(Landroid/content/Context;)V");
  return env->NewObject(USBInterface::GetClass(), method_id, arg1.GetImpl());
}

jobject USBInterfaceOnUpLoadProcessListenerProxyCallback(void* object_pointer, const char* method_name, jobject* arguments, uint32_t arguments_count)
{

  return nullptr;
}

}  // namespace

jclass USBInterface::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/USBInterface");
  return cached_class;
}

void USBInterface::destroy(const USBInterface* object)
{
  delete object;
}

USBInterface::USBInterface(const ::android::content::Context& arg1) : USBInterface(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaUSBInterfaceObject(arg1)).Get()) {}

void USBInterface::setsDevice(const ::java::lang::String& arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setsDevice", "(Ljava/lang/String;)V");
  env->CallVoidMethod(GetImpl(), method_id, arg1.GetImpl());
}

void USBInterface::onReceive(const ::android::content::Context& arg1, const ::android::content::Intent& arg2) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "onReceive", "(Landroid/content/Context;Landroid/content/Intent;)V");
  env->CallVoidMethod(GetImpl(), method_id, arg1.GetImpl(), arg2.GetImpl());
}

::java::lang::String& USBInterface::getPrinterList() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getPrinterList", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

bool USBInterface::Open() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Open", "()Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id);
  return ret;
}

void USBInterface::Close() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Close", "()V");
  env->CallVoidMethod(GetImpl(), method_id);
}

bool USBInterface::WriteData(int8_t arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "WriteData", "(B)Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id, arg1);
  return ret;
}

bool USBInterface::WriteData(int8_t arg1, int32_t arg2) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "WriteData", "(BI)Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id, arg1, arg2);
  return ret;
}

int8_t USBInterface::ReadData() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "ReadData", "()B");
  int8_t ret = env->CallByteMethod(GetImpl(), method_id);
  return ret;
}

int8_t USBInterface::ReadData(int32_t arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "ReadData", "(I)B");
  int8_t ret = env->CallByteMethod(GetImpl(), method_id, arg1);
  return ret;
}

USBInterface::OnUpLoadProcessListener* USBInterface::OnUpLoadProcessListener::ImplementInterface(onUpLoadProcessCallback on_up_load_process_callback)
{
  USBInterface::OnUpLoadProcessListener* instance = new USBInterface::OnUpLoadProcessListener(nullptr);
  instance->SetImpl(gni::GniCore::GetInstance()->GetJniEnv()->NewGlobalRef(gni::common::interface_proxy::RegisterCallback("OnePlusOneAndroidSDK/USBInterface$OnUpLoadProcessListener", instance, USBInterfaceOnUpLoadProcessListenerProxyCallback)));
  instance->on_up_load_process_callback_ = on_up_load_process_callback;
  return instance;
}

jclass USBInterface::OnUpLoadProcessListener::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/USBInterface$OnUpLoadProcessListener");
  return cached_class;
}

void USBInterface::OnUpLoadProcessListener::destroy(const USBInterface::OnUpLoadProcessListener* object)
{
  delete object;
}

void USBInterface::OnUpLoadProcessListener::onUpLoadProcess(int32_t arg1, int32_t arg2) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "onUpLoadProcess", "(II)V");
  env->CallVoidMethod(GetImpl(), method_id, arg1, arg2);
}

}  // namespace OnePlusOneAndroidSDK

