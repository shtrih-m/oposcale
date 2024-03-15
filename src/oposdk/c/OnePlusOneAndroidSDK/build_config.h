#ifndef ONEPLUSONEANDROIDSDK_BUILDCONFIG_H_
#define ONEPLUSONEANDROIDSDK_BUILDCONFIG_H_

#include <cstdint>
#include <jni.h>
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BuildConfig_ BuildConfig;

/// Wraps a JNI reference with BuildConfig object.
/// @param jobj A JNI reference to be wrapped with BuildConfig object.
/// @see BuildConfig_destroy
BuildConfig* BuildConfig_wrapJniReference(jobject jobj);

jobject BuildConfig_getJniReference(const BuildConfig* build_config);

BuildConfig* BuildConfig_construct();

/// Destroys build_config and all internal resources related to it. This function should be
/// called when build_config is no longer needed.
/// @param build_config An object to be destroyed.
void BuildConfig_destroy(const BuildConfig* build_config);

bool BuildConfig_get_DEBUG();

const char* BuildConfig_get_APPLICATION_ID();

const char* BuildConfig_get_BUILD_TYPE();

const char* BuildConfig_get_FLAVOR();

int32_t BuildConfig_get_VERSION_CODE();

const char* BuildConfig_get_VERSION_NAME();

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ONEPLUSONEANDROIDSDK_BUILDCONFIG_H_
