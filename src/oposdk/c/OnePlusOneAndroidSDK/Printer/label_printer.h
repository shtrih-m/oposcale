#ifndef ONEPLUSONEANDROIDSDK_PRINTER_LABELPRINTER_H_
#define ONEPLUSONEANDROIDSDK_PRINTER_LABELPRINTER_H_

#include <cstdint>
#include <jni.h>
#include "android\content\context.h"
#include "android\content\intent.h"
#include "android\graphics\bitmap.h"
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LabelPrinter_ LabelPrinter;

typedef struct LabelPrinter_OnStatusChangedListener_ LabelPrinter_OnStatusChangedListener;

typedef void (*LabelPrinter_OnStatusChangedListener_onStatusChangedCallback)(int32_t arg1);

/// Wraps a JNI reference with LabelPrinter object.
/// @param jobj A JNI reference to be wrapped with LabelPrinter object.
/// @see LabelPrinter_destroy
LabelPrinter* LabelPrinter_wrapJniReference(jobject jobj);

jobject LabelPrinter_getJniReference(const LabelPrinter* label_printer);

/// Destroys label_printer and all internal resources related to it. This function should be
/// called when label_printer is no longer needed.
/// @param label_printer An object to be destroyed.
void LabelPrinter_destroy(const LabelPrinter* label_printer);

LabelPrinter* LabelPrinter_getInstance(Context* arg1);

bool LabelPrinter_isUsbPrinter(const LabelPrinter* label_printer);

bool LabelPrinter_Open(const LabelPrinter* label_printer);

void LabelPrinter_Close(const LabelPrinter* label_printer);

bool LabelPrinter_WriteData(const LabelPrinter* label_printer, int8_t arg1, int32_t arg2);

int8_t LabelPrinter_ReadData(const LabelPrinter* label_printer, int32_t arg1);

int32_t LabelPrinter_GetStatus(const LabelPrinter* label_printer);

bool LabelPrinter_PrintLabelBitmap(const LabelPrinter* label_printer, Bitmap* arg1);

void LabelPrinter_setsDevice(const LabelPrinter* label_printer, String* arg1);

void LabelPrinter_onReceive(const LabelPrinter* label_printer, Context* arg1, Intent* arg2);

String* LabelPrinter_getPrinterList(const LabelPrinter* label_printer);

/// Wraps a JNI reference with LabelPrinter_OnStatusChangedListener object.
/// @param jobj A JNI reference to be wrapped with LabelPrinter_OnStatusChangedListener object.
/// @see LabelPrinter_OnStatusChangedListener_destroy
LabelPrinter_OnStatusChangedListener* LabelPrinter_OnStatusChangedListener_wrapJniReference(jobject jobj);

jobject LabelPrinter_OnStatusChangedListener_getJniReference(const LabelPrinter_OnStatusChangedListener* label_printer_on_status_changed_listener);

LabelPrinter_OnStatusChangedListener* LabelPrinter_OnStatusChangedListener_implementInterface(LabelPrinter_OnStatusChangedListener_onStatusChangedCallback label_printer_on_status_changed_listener_on_status_changed_callback);

/// Destroys label_printer_on_status_changed_listener and all internal resources related to it. This function should be
/// called when label_printer_on_status_changed_listener is no longer needed.
/// @param label_printer_on_status_changed_listener An object to be destroyed.
void LabelPrinter_OnStatusChangedListener_destroy(const LabelPrinter_OnStatusChangedListener* label_printer_on_status_changed_listener);

void LabelPrinter_OnStatusChangedListener_onStatusChanged(const LabelPrinter_OnStatusChangedListener* label_printer_on_status_changed_listener, int32_t arg1);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ONEPLUSONEANDROIDSDK_PRINTER_LABELPRINTER_H_
