#include "android\content\broadcast_receiver.h"

#include "android\content\broadcast_receiver.hpp"

BroadcastReceiver* BroadcastReceiver_wrapJniReference(jobject jobj) {
  return reinterpret_cast<BroadcastReceiver*>(new ::android::content::BroadcastReceiver(jobj));
}

jobject BroadcastReceiver_getJniReference(const BroadcastReceiver* broadcast_receiver) {
  return reinterpret_cast<const ::android::content::BroadcastReceiver*>(broadcast_receiver)->GetImpl();
}

void BroadcastReceiver_destroy(const BroadcastReceiver* broadcast_receiver) {
  ::android::content::BroadcastReceiver::destroy(reinterpret_cast<const ::android::content::BroadcastReceiver*>(broadcast_receiver));
}
