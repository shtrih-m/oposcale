#ifndef ONEPLUSONEANDROIDSDK_PRINTER_POSPRINTER_H_
#define ONEPLUSONEANDROIDSDK_PRINTER_POSPRINTER_H_

#include <cstdint>
#include <jni.h>
#include "android\content\context.h"
#include "android\content\intent.h"
#include "android\graphics\bitmap.h"
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PosPrinter_ PosPrinter;

/// Wraps a JNI reference with PosPrinter object.
/// @param jobj A JNI reference to be wrapped with PosPrinter object.
/// @see PosPrinter_destroy
PosPrinter* PosPrinter_wrapJniReference(jobject jobj);

jobject PosPrinter_getJniReference(const PosPrinter* pos_printer);

/// Destroys pos_printer and all internal resources related to it. This function should be
/// called when pos_printer is no longer needed.
/// @param pos_printer An object to be destroyed.
void PosPrinter_destroy(const PosPrinter* pos_printer);

PosPrinter* PosPrinter_getInstance(Context* arg1);

bool PosPrinter_RollPaperStatus(const PosPrinter* pos_printer);

bool PosPrinter_PrintLabelBitmap(const PosPrinter* pos_printer, Bitmap* arg1);

void PosPrinter_setsDevice(const PosPrinter* pos_printer, String* arg1);

void PosPrinter_onReceive(const PosPrinter* pos_printer, Context* arg1, Intent* arg2);

String* PosPrinter_getPrinterList(const PosPrinter* pos_printer);

bool PosPrinter_Open(const PosPrinter* pos_printer);

void PosPrinter_Close(const PosPrinter* pos_printer);

bool PosPrinter_WriteData(const PosPrinter* pos_printer, int8_t arg1);

int8_t PosPrinter_ReadData(const PosPrinter* pos_printer);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ONEPLUSONEANDROIDSDK_PRINTER_POSPRINTER_H_
