#include "OnePlusOneAndroidSDK\o_p_o_util.h"

#include "OnePlusOneAndroidSDK\o_p_o_util.hpp"

OPOUtil* OPOUtil_wrapJniReference(jobject jobj) {
  return reinterpret_cast<OPOUtil*>(new ::OnePlusOneAndroidSDK::OPOUtil(jobj));
}

jobject OPOUtil_getJniReference(const OPOUtil* o_p_o_util) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::OPOUtil*>(o_p_o_util)->GetImpl();
}

OPOUtil* OPOUtil_construct() {
  return reinterpret_cast<OPOUtil*>(new ::OnePlusOneAndroidSDK::OPOUtil());
}

void OPOUtil_destroy(const OPOUtil* o_p_o_util) {
  ::OnePlusOneAndroidSDK::OPOUtil::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::OPOUtil*>(o_p_o_util));
}

bool OPOUtil_isAPPBackground(Context* arg1) {
  return ::OnePlusOneAndroidSDK::OPOUtil::isAPPBackground(*reinterpret_cast<const ::android::content::Context*>(arg1));
}

void OPOUtil_WriteLog(String* arg1) {
  ::OnePlusOneAndroidSDK::OPOUtil::WriteLog(*reinterpret_cast<const ::java::lang::String*>(arg1));
}

void OPOUtil_SetLogPath(String* arg1) {
  ::OnePlusOneAndroidSDK::OPOUtil::SetLogPath(*reinterpret_cast<const ::java::lang::String*>(arg1));
}
