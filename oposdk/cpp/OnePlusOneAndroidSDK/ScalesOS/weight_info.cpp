#include "OnePlusOneAndroidSDK\ScalesOS\weight_info.hpp"
#include <memory>
#include "android\os\parcel.hpp"
#include "android\os\parcelable.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {
namespace ScalesOS {

namespace {

jobject CreateJavaWeightInfoObject() {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(WeightInfo::GetClass(), "<init>", "()V");
  return env->NewObject(WeightInfo::GetClass(), method_id);
}

jobject CreateJavaWeightInfoObject(const ::java::lang::String& arg1) {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(WeightInfo::GetClass(), "<init>", "(Ljava/lang/String;)V");
  return env->NewObject(WeightInfo::GetClass(), method_id, arg1.GetImpl());
}

}  // namespace

jclass WeightInfo::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/ScalesOS/WeightInfo");
  return cached_class;
}

void WeightInfo::destroy(const WeightInfo* object)
{
  delete object;
}

WeightInfo::WeightInfo() : WeightInfo(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaWeightInfoObject()).Get()) {}

WeightInfo::WeightInfo(const ::java::lang::String& arg1) : WeightInfo(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaWeightInfoObject(arg1)).Get()) {}

bool WeightInfo::updata(const ::java::lang::String& arg1) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "updata", "(Ljava/lang/String;)Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id, arg1.GetImpl());
  return ret;
}

::java::lang::String& WeightInfo::getMode() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getMode", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

::java::lang::String& WeightInfo::getStatus() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getStatus", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

bool WeightInfo::getZero() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getZero", "()Z");
  bool ret = env->CallBooleanMethod(GetImpl(), method_id);
  return ret;
}

::java::lang::String& WeightInfo::getUnit() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getUnit", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

::java::lang::String& WeightInfo::getNetWeight() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getNetWeight", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

::java::lang::String& WeightInfo::getTareWeight() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getTareWeight", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

::java::lang::String& WeightInfo::getGrossWeight() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getGrossWeight", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

::java::lang::String& WeightInfo::toString() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "toString", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

int32_t WeightInfo::describeContents() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "describeContents", "()I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id);
  return ret;
}

void WeightInfo::writeToParcel(const ::android::os::Parcel& arg1, int32_t arg2) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "writeToParcel", "(Landroid/os/Parcel;I)V");
  env->CallVoidMethod(GetImpl(), method_id, arg1.GetImpl(), arg2);
}

}  // namespace ScalesOS
}  // namespace OnePlusOneAndroidSDK

