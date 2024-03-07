#include "OnePlusOneAndroidSDK\u_s_b_interface.h"

#include "OnePlusOneAndroidSDK\u_s_b_interface.hpp"

USBInterface* USBInterface_wrapJniReference(jobject jobj) {
  return reinterpret_cast<USBInterface*>(new ::OnePlusOneAndroidSDK::USBInterface(jobj));
}

jobject USBInterface_getJniReference(const USBInterface* u_s_b_interface) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->GetImpl();
}

USBInterface* USBInterface_construct(Context* arg1) {
  return reinterpret_cast<USBInterface*>(new ::OnePlusOneAndroidSDK::USBInterface(*reinterpret_cast<const ::android::content::Context*>(arg1)));
}

void USBInterface_destroy(const USBInterface* u_s_b_interface) {
  ::OnePlusOneAndroidSDK::USBInterface::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface));
}

void USBInterface_setsDevice(const USBInterface* u_s_b_interface, String* arg1) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->setsDevice(*reinterpret_cast<const ::java::lang::String*>(arg1));
}

void USBInterface_onReceive(const USBInterface* u_s_b_interface, Context* arg1, Intent* arg2) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->onReceive(*reinterpret_cast<const ::android::content::Context*>(arg1), *reinterpret_cast<const ::android::content::Intent*>(arg2));
}

String* USBInterface_getPrinterList(const USBInterface* u_s_b_interface) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->getPrinterList());
}

bool USBInterface_Open(const USBInterface* u_s_b_interface) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->Open();
}

void USBInterface_Close(const USBInterface* u_s_b_interface) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->Close();
}

bool USBInterface_WriteData(const USBInterface* u_s_b_interface, int8_t arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->WriteData(arg1);
}

int8_t USBInterface_ReadData(const USBInterface* u_s_b_interface) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface*>(u_s_b_interface)->ReadData();
}

USBInterface_OnUpLoadProcessListener* USBInterface_OnUpLoadProcessListener_wrapJniReference(jobject jobj) {
  return reinterpret_cast<USBInterface_OnUpLoadProcessListener*>(new ::OnePlusOneAndroidSDK::USBInterface::OnUpLoadProcessListener(jobj));
}

jobject USBInterface_OnUpLoadProcessListener_getJniReference(const USBInterface_OnUpLoadProcessListener* u_s_b_interface_on_up_load_process_listener) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface::OnUpLoadProcessListener*>(u_s_b_interface_on_up_load_process_listener)->GetImpl();
}

USBInterface_OnUpLoadProcessListener* USBInterface_OnUpLoadProcessListener_implementInterface(USBInterface_OnUpLoadProcessListener_onUpLoadProcessCallback u_s_b_interface_on_up_load_process_listener_on_up_load_process_callback) {
  return reinterpret_cast<USBInterface_OnUpLoadProcessListener*>(::OnePlusOneAndroidSDK::USBInterface::OnUpLoadProcessListener::ImplementInterface(reinterpret_cast<::OnePlusOneAndroidSDK::USBInterface::OnUpLoadProcessListener::onUpLoadProcessCallback>(u_s_b_interface_on_up_load_process_listener_on_up_load_process_callback)));
}

void USBInterface_OnUpLoadProcessListener_destroy(const USBInterface_OnUpLoadProcessListener* u_s_b_interface_on_up_load_process_listener) {
  ::OnePlusOneAndroidSDK::USBInterface::OnUpLoadProcessListener::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface::OnUpLoadProcessListener*>(u_s_b_interface_on_up_load_process_listener));
}

void USBInterface_OnUpLoadProcessListener_onUpLoadProcess(const USBInterface_OnUpLoadProcessListener* u_s_b_interface_on_up_load_process_listener, int32_t arg1, int32_t arg2) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::USBInterface::OnUpLoadProcessListener*>(u_s_b_interface_on_up_load_process_listener)->onUpLoadProcess(arg1, arg2);
}
