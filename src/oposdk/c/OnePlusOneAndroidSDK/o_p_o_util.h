#ifndef ONEPLUSONEANDROIDSDK_OPOUTIL_H_
#define ONEPLUSONEANDROIDSDK_OPOUTIL_H_

#include <cstdint>
#include <jni.h>
#include "android\content\context.h"
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OPOUtil_ OPOUtil;

/// Wraps a JNI reference with OPOUtil object.
/// @param jobj A JNI reference to be wrapped with OPOUtil object.
/// @see OPOUtil_destroy
OPOUtil* OPOUtil_wrapJniReference(jobject jobj);

jobject OPOUtil_getJniReference(const OPOUtil* o_p_o_util);

OPOUtil* OPOUtil_construct();

/// Destroys o_p_o_util and all internal resources related to it. This function should be
/// called when o_p_o_util is no longer needed.
/// @param o_p_o_util An object to be destroyed.
void OPOUtil_destroy(const OPOUtil* o_p_o_util);

bool OPOUtil_isAPPBackground(Context* arg1);

void OPOUtil_WriteLog(String* arg1);

void OPOUtil_SetLogPath(String* arg1);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ONEPLUSONEANDROIDSDK_OPOUTIL_H_
