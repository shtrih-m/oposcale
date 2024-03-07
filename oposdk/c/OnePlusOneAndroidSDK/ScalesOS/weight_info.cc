#include "OnePlusOneAndroidSDK\ScalesOS\weight_info.h"

#include "OnePlusOneAndroidSDK\ScalesOS\weight_info.hpp"

WeightInfo* WeightInfo_wrapJniReference(jobject jobj) {
  return reinterpret_cast<WeightInfo*>(new ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo(jobj));
}

jobject WeightInfo_getJniReference(const WeightInfo* weight_info) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->GetImpl();
}

WeightInfo* WeightInfo_construct() {
  return reinterpret_cast<WeightInfo*>(new ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo());
}

void WeightInfo_destroy(const WeightInfo* weight_info) {
  ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info));
}

bool WeightInfo_updata(const WeightInfo* weight_info, String* arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->updata(*reinterpret_cast<const ::java::lang::String*>(arg1));
}

String* WeightInfo_getMode(const WeightInfo* weight_info) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->getMode());
}

String* WeightInfo_getStatus(const WeightInfo* weight_info) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->getStatus());
}

bool WeightInfo_getZero(const WeightInfo* weight_info) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->getZero();
}

String* WeightInfo_getUnit(const WeightInfo* weight_info) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->getUnit());
}

String* WeightInfo_getNetWeight(const WeightInfo* weight_info) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->getNetWeight());
}

String* WeightInfo_getTareWeight(const WeightInfo* weight_info) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->getTareWeight());
}

String* WeightInfo_getGrossWeight(const WeightInfo* weight_info) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->getGrossWeight());
}

String* WeightInfo_toString(const WeightInfo* weight_info) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->toString());
}

int32_t WeightInfo_describeContents(const WeightInfo* weight_info) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->describeContents();
}

void WeightInfo_writeToParcel(const WeightInfo* weight_info, Parcel* arg1, int32_t arg2) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo*>(weight_info)->writeToParcel(*reinterpret_cast<const ::android::os::Parcel*>(arg1), arg2);
}
