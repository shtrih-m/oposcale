#include "OnePlusOneAndroidSDK\build_config.h"

#include "OnePlusOneAndroidSDK\build_config.hpp"

BuildConfig* BuildConfig_wrapJniReference(jobject jobj) {
  return reinterpret_cast<BuildConfig*>(new ::OnePlusOneAndroidSDK::BuildConfig(jobj));
}

jobject BuildConfig_getJniReference(const BuildConfig* build_config) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::BuildConfig*>(build_config)->GetImpl();
}

BuildConfig* BuildConfig_construct() {
  return reinterpret_cast<BuildConfig*>(new ::OnePlusOneAndroidSDK::BuildConfig());
}

void BuildConfig_destroy(const BuildConfig* build_config) {
  ::OnePlusOneAndroidSDK::BuildConfig::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::BuildConfig*>(build_config));
}

bool BuildConfig_get_DEBUG() {
  return ::OnePlusOneAndroidSDK::BuildConfig::DEBUG;
}

const char* BuildConfig_get_APPLICATION_ID() {
  return ::OnePlusOneAndroidSDK::BuildConfig::APPLICATION_ID;
}

const char* BuildConfig_get_BUILD_TYPE() {
  return ::OnePlusOneAndroidSDK::BuildConfig::BUILD_TYPE;
}

const char* BuildConfig_get_FLAVOR() {
  return ::OnePlusOneAndroidSDK::BuildConfig::FLAVOR;
}

int32_t BuildConfig_get_VERSION_CODE() {
  return ::OnePlusOneAndroidSDK::BuildConfig::VERSION_CODE;
}

const char* BuildConfig_get_VERSION_NAME() {
  return ::OnePlusOneAndroidSDK::BuildConfig::VERSION_NAME;
}
