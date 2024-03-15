#ifndef ONEPLUSONEANDROIDSDK_SCALESOS_WEIGHTINFO_H_
#define ONEPLUSONEANDROIDSDK_SCALESOS_WEIGHTINFO_H_

#include <cstdint>
#include <jni.h>
#include "android\os\parcel.h"
#include "android\os\parcelable.h"
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WeightInfo_ WeightInfo;

/// Wraps a JNI reference with WeightInfo object.
/// @param jobj A JNI reference to be wrapped with WeightInfo object.
/// @see WeightInfo_destroy
WeightInfo* WeightInfo_wrapJniReference(jobject jobj);

jobject WeightInfo_getJniReference(const WeightInfo* weight_info);

WeightInfo* WeightInfo_construct();

/// Destroys weight_info and all internal resources related to it. This function should be
/// called when weight_info is no longer needed.
/// @param weight_info An object to be destroyed.
void WeightInfo_destroy(const WeightInfo* weight_info);

bool WeightInfo_updata(const WeightInfo* weight_info, String* arg1);

String* WeightInfo_getMode(const WeightInfo* weight_info);

String* WeightInfo_getStatus(const WeightInfo* weight_info);

bool WeightInfo_getZero(const WeightInfo* weight_info);

String* WeightInfo_getUnit(const WeightInfo* weight_info);

String* WeightInfo_getNetWeight(const WeightInfo* weight_info);

String* WeightInfo_getTareWeight(const WeightInfo* weight_info);

String* WeightInfo_getGrossWeight(const WeightInfo* weight_info);

String* WeightInfo_toString(const WeightInfo* weight_info);

int32_t WeightInfo_describeContents(const WeightInfo* weight_info);

void WeightInfo_writeToParcel(const WeightInfo* weight_info, Parcel* arg1, int32_t arg2);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ONEPLUSONEANDROIDSDK_SCALESOS_WEIGHTINFO_H_
