#ifndef ONEPLUSONEANDROIDSDK_USBINTERFACE_H_
#define ONEPLUSONEANDROIDSDK_USBINTERFACE_H_

#include <cstdint>
#include <jni.h>
#include "android\content\context.h"
#include "android\content\intent.h"
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct USBInterface_ USBInterface;

typedef struct USBInterface_OnUpLoadProcessListener_ USBInterface_OnUpLoadProcessListener;

typedef void (*USBInterface_OnUpLoadProcessListener_onUpLoadProcessCallback)(int32_t arg1, int32_t arg2);

/// Wraps a JNI reference with USBInterface object.
/// @param jobj A JNI reference to be wrapped with USBInterface object.
/// @see USBInterface_destroy
USBInterface* USBInterface_wrapJniReference(jobject jobj);

jobject USBInterface_getJniReference(const USBInterface* u_s_b_interface);

USBInterface* USBInterface_construct(Context* arg1);

/// Destroys u_s_b_interface and all internal resources related to it. This function should be
/// called when u_s_b_interface is no longer needed.
/// @param u_s_b_interface An object to be destroyed.
void USBInterface_destroy(const USBInterface* u_s_b_interface);

void USBInterface_setsDevice(const USBInterface* u_s_b_interface, String* arg1);

void USBInterface_onReceive(const USBInterface* u_s_b_interface, Context* arg1, Intent* arg2);

String* USBInterface_getPrinterList(const USBInterface* u_s_b_interface);

bool USBInterface_Open(const USBInterface* u_s_b_interface);

void USBInterface_Close(const USBInterface* u_s_b_interface);

bool USBInterface_WriteData(const USBInterface* u_s_b_interface, int8_t arg1);

int8_t USBInterface_ReadData(const USBInterface* u_s_b_interface);

/// Wraps a JNI reference with USBInterface_OnUpLoadProcessListener object.
/// @param jobj A JNI reference to be wrapped with USBInterface_OnUpLoadProcessListener object.
/// @see USBInterface_OnUpLoadProcessListener_destroy
USBInterface_OnUpLoadProcessListener* USBInterface_OnUpLoadProcessListener_wrapJniReference(jobject jobj);

jobject USBInterface_OnUpLoadProcessListener_getJniReference(const USBInterface_OnUpLoadProcessListener* u_s_b_interface_on_up_load_process_listener);

USBInterface_OnUpLoadProcessListener* USBInterface_OnUpLoadProcessListener_implementInterface(USBInterface_OnUpLoadProcessListener_onUpLoadProcessCallback u_s_b_interface_on_up_load_process_listener_on_up_load_process_callback);

/// Destroys u_s_b_interface_on_up_load_process_listener and all internal resources related to it. This function should be
/// called when u_s_b_interface_on_up_load_process_listener is no longer needed.
/// @param u_s_b_interface_on_up_load_process_listener An object to be destroyed.
void USBInterface_OnUpLoadProcessListener_destroy(const USBInterface_OnUpLoadProcessListener* u_s_b_interface_on_up_load_process_listener);

void USBInterface_OnUpLoadProcessListener_onUpLoadProcess(const USBInterface_OnUpLoadProcessListener* u_s_b_interface_on_up_load_process_listener, int32_t arg1, int32_t arg2);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ONEPLUSONEANDROIDSDK_USBINTERFACE_H_
