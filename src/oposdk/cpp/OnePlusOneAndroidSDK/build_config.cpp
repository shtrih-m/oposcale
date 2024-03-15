#include "OnePlusOneAndroidSDK\build_config.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace OnePlusOneAndroidSDK {

namespace {

jobject CreateJavaBuildConfigObject() {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(BuildConfig::GetClass(), "<init>", "()V");
  return env->NewObject(BuildConfig::GetClass(), method_id);
}

}  // namespace

jclass BuildConfig::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("OnePlusOneAndroidSDK/BuildConfig");
  return cached_class;
}

void BuildConfig::destroy(const BuildConfig* object)
{
  delete object;
}

BuildConfig::BuildConfig() : BuildConfig(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaBuildConfigObject()).Get()) {}

}  // namespace OnePlusOneAndroidSDK

