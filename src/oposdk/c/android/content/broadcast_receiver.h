#ifndef ANDROID_CONTENT_BROADCASTRECEIVER_H_
#define ANDROID_CONTENT_BROADCASTRECEIVER_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BroadcastReceiver_ BroadcastReceiver;

/// Wraps a JNI reference with BroadcastReceiver object.
/// @param jobj A JNI reference to be wrapped with BroadcastReceiver object.
/// @see BroadcastReceiver_destroy
BroadcastReceiver* BroadcastReceiver_wrapJniReference(jobject jobj);

jobject BroadcastReceiver_getJniReference(const BroadcastReceiver* broadcast_receiver);

/// Destroys broadcast_receiver and all internal resources related to it. This function should be
/// called when broadcast_receiver is no longer needed.
/// @param broadcast_receiver An object to be destroyed.
void BroadcastReceiver_destroy(const BroadcastReceiver* broadcast_receiver);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_CONTENT_BROADCASTRECEIVER_H_
