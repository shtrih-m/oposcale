#include "OnePlusOneAndroidSDK\ScalesOS\scales_s_d_k.hpp"
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

namespace {

jobject ScalesSDKWeightChangedListenerProxyCallback(void* object_pointer, const char* method_name, jobject* arguments, uint32_t arguments_count)
{
  if (strcmp(method_name, "onWeightChanged") == 0)
  {
    reinterpret_cast<ScalesSDK::WeightChangedListener*>(object_pointer)->on_weight_changed_callback_(new ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo(arguments[0]));
  }

  return nullptr;
}

}  // namespace

jclass ScalesSDK::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/ScalesOS/ScalesSDK");
  return cached_class;
}

void ScalesSDK::destroy(const ScalesSDK* object)
{
  delete object;
}

void ScalesSDK::setWeightChangedListener(const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener& arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setWeightChangedListener", "(LOnePlusOneAndroidSDK/ScalesOS/ScalesSDK$WeightChangedListener;)V");
  env->CallVoidMethod(GetImpl(), method_id, arg1.GetImpl());
}

void ScalesSDK::setScaleAlwaysRead() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setScaleAlwaysRead", "()V");
  env->CallVoidMethod(GetImpl(), method_id);
}

::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK& ScalesSDK::getInstance(const ::android::content::Context& arg1)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "getInstance", "(Landroid/content/Context;)LOnePlusOneAndroidSDK/ScalesOS/ScalesSDK;");
  ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK* ret = new ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK(gni::common::ScopedLocalRef<jobject>(env, env->CallStaticObjectMethod(GetClass(), method_id, arg1.GetImpl())).Get());
  return *ret;
}

::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK& ScalesSDK::getInstance(const ::android::content::Context& arg1, const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener& arg2)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "getInstance", "(Landroid/content/Context;LOnePlusOneAndroidSDK/ScalesOS/ScalesSDK$WeightChangedListener;)LOnePlusOneAndroidSDK/ScalesOS/ScalesSDK;");
  ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK* ret = new ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK(gni::common::ScopedLocalRef<jobject>(env, env->CallStaticObjectMethod(GetClass(), method_id, arg1.GetImpl(), arg2.GetImpl())).Get());
  return *ret;
}

bool ScalesSDK::Open(const ::java::io::File& arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Open", "(Ljava/io/File;)Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id, arg1.GetImpl());
  return ret;
}

::OnePlusOneAndroidSDK::ScalesOS::WeightInfo& ScalesSDK::getWeihtInfo() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getWeihtInfo", "()LOnePlusOneAndroidSDK/ScalesOS/WeightInfo;");
  ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo* ret = new ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

void ScalesSDK::ReadThread(bool arg1)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "ReadThread", "(Z)V");
  env->CallStaticVoidMethod(GetClass(), method_id, arg1);
}

::java::lang::String& ScalesSDK::OPOModuleSend(int32_t arg1, int32_t arg2, int8_t arg3, int32_t arg4) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "OPOModuleSend", "(IIBI)Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id, arg1, arg2, arg3, arg4)).Get());
  return *ret;
}

int32_t ScalesSDK::Close() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Close", "()I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id);
  return ret;
}

::java::lang::String& ScalesSDK::GetResult() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "GetResult", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

int32_t ScalesSDK::Zero() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Zero", "()I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id);
  return ret;
}

int32_t ScalesSDK::Tare() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "Tare", "()I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id);
  return ret;
}

int32_t ScalesSDK::PreTare(int32_t arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "PreTare", "(I)I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id, arg1);
  return ret;
}

int32_t ScalesSDK::ExitTare() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "ExitTare", "()I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id);
  return ret;
}

ScalesSDK::WeightChangedListener* ScalesSDK::WeightChangedListener::ImplementInterface(onWeightChangedCallback on_weight_changed_callback)
{
  ScalesSDK::WeightChangedListener* instance = new ScalesSDK::WeightChangedListener(nullptr);
  instance->SetImpl(gni::GniCore::GetInstance()->GetJniEnv()->NewGlobalRef(gni::common::interface_proxy::RegisterCallback("OnePlusOneAndroidSDK/ScalesOS/ScalesSDK$WeightChangedListener", instance, ScalesSDKWeightChangedListenerProxyCallback)));
  instance->on_weight_changed_callback_ = on_weight_changed_callback;
  return instance;
}

jclass ScalesSDK::WeightChangedListener::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/ScalesOS/ScalesSDK$WeightChangedListener");
  return cached_class;
}

void ScalesSDK::WeightChangedListener::destroy(const ScalesSDK::WeightChangedListener* object)
{
  delete object;
}

void ScalesSDK::WeightChangedListener::onWeightChanged(const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo& arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "onWeightChanged", "(LOnePlusOneAndroidSDK/ScalesOS/WeightInfo;)V");
  env->CallVoidMethod(GetImpl(), method_id, arg1.GetImpl());
}

}  // namespace ScalesOS
}  // namespace OnePlusOneAndroidSDK

