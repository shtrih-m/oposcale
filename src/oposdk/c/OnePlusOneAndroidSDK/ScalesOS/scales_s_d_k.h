#ifndef ONEPLUSONEANDROIDSDK_SCALESOS_SCALESSDK_H_
#define ONEPLUSONEANDROIDSDK_SCALESOS_SCALESSDK_H_

#include <cstdint>
#include <jni.h>
#include "android\content\context.h"
#include "java\io\file.h"
#include "java\lang\string.h"
#include "OnePlusOneAndroidSDK\ScalesOS\weight_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ScalesSDK_ ScalesSDK;

typedef struct ScalesSDK_WeightChangedListener_ ScalesSDK_WeightChangedListener;

typedef void (*ScalesSDK_WeightChangedListener_onWeightChangedCallback)(WeightInfo* arg1);

/// Wraps a JNI reference with ScalesSDK object.
/// @param jobj A JNI reference to be wrapped with ScalesSDK object.
/// @see ScalesSDK_destroy
ScalesSDK* ScalesSDK_wrapJniReference(jobject jobj);

jobject ScalesSDK_getJniReference(const ScalesSDK* scales_s_d_k);

/// Destroys scales_s_d_k and all internal resources related to it. This function should be
/// called when scales_s_d_k is no longer needed.
/// @param scales_s_d_k An object to be destroyed.
void ScalesSDK_destroy(const ScalesSDK* scales_s_d_k);

void ScalesSDK_setWeightChangedListener(const ScalesSDK* scales_s_d_k, ScalesSDK_WeightChangedListener* arg1);

void ScalesSDK_setScaleAlwaysRead(const ScalesSDK* scales_s_d_k);

ScalesSDK* ScalesSDK_getInstance(Context* arg1);

bool ScalesSDK_Open(const ScalesSDK* scales_s_d_k, File* arg1);

WeightInfo* ScalesSDK_getWeihtInfo(const ScalesSDK* scales_s_d_k);

void ScalesSDK_ReadThread(bool arg1);

String* ScalesSDK_OPOModuleSend(const ScalesSDK* scales_s_d_k, int32_t arg1, int32_t arg2, int8_t arg3, int32_t arg4);

int32_t ScalesSDK_Close(const ScalesSDK* scales_s_d_k);

String* ScalesSDK_GetResult(const ScalesSDK* scales_s_d_k);

int32_t ScalesSDK_Zero(const ScalesSDK* scales_s_d_k);

int32_t ScalesSDK_Tare(const ScalesSDK* scales_s_d_k);

int32_t ScalesSDK_PreTare(const ScalesSDK* scales_s_d_k, int32_t arg1);

int32_t ScalesSDK_ExitTare(const ScalesSDK* scales_s_d_k);

/// Wraps a JNI reference with ScalesSDK_WeightChangedListener object.
/// @param jobj A JNI reference to be wrapped with ScalesSDK_WeightChangedListener object.
/// @see ScalesSDK_WeightChangedListener_destroy
ScalesSDK_WeightChangedListener* ScalesSDK_WeightChangedListener_wrapJniReference(jobject jobj);

jobject ScalesSDK_WeightChangedListener_getJniReference(const ScalesSDK_WeightChangedListener* scales_s_d_k_weight_changed_listener);

ScalesSDK_WeightChangedListener* ScalesSDK_WeightChangedListener_implementInterface(ScalesSDK_WeightChangedListener_onWeightChangedCallback scales_s_d_k_weight_changed_listener_on_weight_changed_callback);

/// Destroys scales_s_d_k_weight_changed_listener and all internal resources related to it. This function should be
/// called when scales_s_d_k_weight_changed_listener is no longer needed.
/// @param scales_s_d_k_weight_changed_listener An object to be destroyed.
void ScalesSDK_WeightChangedListener_destroy(const ScalesSDK_WeightChangedListener* scales_s_d_k_weight_changed_listener);

void ScalesSDK_WeightChangedListener_onWeightChanged(const ScalesSDK_WeightChangedListener* scales_s_d_k_weight_changed_listener, WeightInfo* arg1);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ONEPLUSONEANDROIDSDK_SCALESOS_SCALESSDK_H_
