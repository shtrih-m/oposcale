#include "OnePlusOneAndroidSDK\o_p_o_util.hpp"
#include <memory>
#include "android\content\context.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {

namespace {

jobject CreateJavaOPOUtilObject() {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(OPOUtil::GetClass(), "<init>", "()V");
  return env->NewObject(OPOUtil::GetClass(), method_id);
}

}  // namespace

jclass OPOUtil::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/OPOUtil");
  return cached_class;
}

void OPOUtil::destroy(const OPOUtil* object)
{
  delete object;
}

OPOUtil::OPOUtil() : OPOUtil(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaOPOUtilObject()).Get()) {}

bool OPOUtil::isAPPBackground(const ::android::content::Context& arg1)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "isAPPBackground", "(Landroid/content/Context;)Z");
  bool ret = env->CallStaticBooleanMethod(GetClass(), method_id, arg1.GetImpl());
  return ret;
}

void OPOUtil::WriteLog(const ::java::lang::String& arg1)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "WriteLog", "(Ljava/lang/String;)V");
  env->CallStaticVoidMethod(GetClass(), method_id, arg1.GetImpl());
}

void OPOUtil::SetLogPath(const ::java::lang::String& arg1)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "SetLogPath", "(Ljava/lang/String;)V");
  env->CallStaticVoidMethod(GetClass(), method_id, arg1.GetImpl());
}

}  // namespace OnePlusOneAndroidSDK

