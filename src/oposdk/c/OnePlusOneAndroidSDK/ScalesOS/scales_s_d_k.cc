#include "OnePlusOneAndroidSDK\ScalesOS\scales_s_d_k.h"

#include "OnePlusOneAndroidSDK\ScalesOS\scales_s_d_k.hpp"

ScalesSDK* ScalesSDK_wrapJniReference(jobject jobj) {
  return reinterpret_cast<ScalesSDK*>(new ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK(jobj));
}

jobject ScalesSDK_getJniReference(const ScalesSDK* scales_s_d_k) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->GetImpl();
}

void ScalesSDK_destroy(const ScalesSDK* scales_s_d_k) {
  ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k));
}

void ScalesSDK_setWeightChangedListener(const ScalesSDK* scales_s_d_k, ScalesSDK_WeightChangedListener* arg1) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->setWeightChangedListener(*reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener*>(arg1));
}

void ScalesSDK_setScaleAlwaysRead(const ScalesSDK* scales_s_d_k) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->setScaleAlwaysRead();
}

ScalesSDK* ScalesSDK_getInstance(Context* arg1) {
  return reinterpret_cast<ScalesSDK*>(&::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::getInstance(*reinterpret_cast<const ::android::content::Context*>(arg1)));
}

bool ScalesSDK_Open(const ScalesSDK* scales_s_d_k, File* arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->Open(*reinterpret_cast<const ::java::io::File*>(arg1));
}

WeightInfo* ScalesSDK_getWeihtInfo(const ScalesSDK* scales_s_d_k) {
  return reinterpret_cast<WeightInfo*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->getWeihtInfo());
}

void ScalesSDK_ReadThread(bool arg1) {
  ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::ReadThread(arg1);
}

String* ScalesSDK_OPOModuleSend(const ScalesSDK* scales_s_d_k, int32_t arg1, int32_t arg2, int8_t arg3, int32_t arg4) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->OPOModuleSend(arg1, arg2, arg3, arg4));
}

int32_t ScalesSDK_Close(const ScalesSDK* scales_s_d_k) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->Close();
}

String* ScalesSDK_GetResult(const ScalesSDK* scales_s_d_k) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->GetResult());
}

int32_t ScalesSDK_Zero(const ScalesSDK* scales_s_d_k) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->Zero();
}

int32_t ScalesSDK_Tare(const ScalesSDK* scales_s_d_k) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->Tare();
}

int32_t ScalesSDK_PreTare(const ScalesSDK* scales_s_d_k, int32_t arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->PreTare(arg1);
}

int32_t ScalesSDK_ExitTare(const ScalesSDK* scales_s_d_k) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK*>(scales_s_d_k)->ExitTare();
}

ScalesSDK_WeightChangedListener* ScalesSDK_WeightChangedListener_wrapJniReference(jobject jobj) {
  return reinterpret_cast<ScalesSDK_WeightChangedListener*>(new ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener(jobj));
}

jobject ScalesSDK_WeightChangedListener_getJniReference(const ScalesSDK_WeightChangedListener* scales_s_d_k_weight_changed_listener) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener*>(scales_s_d_k_weight_changed_listener)->GetImpl();
}

ScalesSDK_WeightChangedListener* ScalesSDK_WeightChangedListener_implementInterface(ScalesSDK_WeightChangedListener_onWeightChangedCallback scales_s_d_k_weight_changed_listener_on_weight_changed_callback) {
  return reinterpret_cast<ScalesSDK_WeightChangedListener*>(::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener::ImplementInterface(reinterpret_cast<::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener::onWeightChangedCallback>(scales_s_d_k_weight_changed_listener_on_weight_changed_callback)));
}

void ScalesSDK_WeightChangedListener_destroy(const ScalesSDK_WeightChangedListener* scales_s_d_k_weight_changed_listener) {
  ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener*>(scales_s_d_k_weight_changed_listener));
}

void ScalesSDK_WeightChangedListener_onWeightChanged(const ScalesSDK_WeightChangedListener* scales_s_d_k_weight_changed_listener, WeightInfo* arg1) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener*>(scales_s_d_k_weight_changed_listener)->onWeightChanged(*reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(arg1));
}
