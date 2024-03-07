#include "OnePlusOneAndroidSDK\Printer\pos_printer.h"

#include "OnePlusOneAndroidSDK\Printer\pos_printer.hpp"

PosPrinter* PosPrinter_wrapJniReference(jobject jobj) {
  return reinterpret_cast<PosPrinter*>(new ::OnePlusOneAndroidSDK::Printer::PosPrinter(jobj));
}

jobject PosPrinter_getJniReference(const PosPrinter* pos_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->GetImpl();
}

void PosPrinter_destroy(const PosPrinter* pos_printer) {
  ::OnePlusOneAndroidSDK::Printer::PosPrinter::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer));
}

PosPrinter* PosPrinter_getInstance(Context* arg1) {
  return reinterpret_cast<PosPrinter*>(&::OnePlusOneAndroidSDK::Printer::PosPrinter::getInstance(*reinterpret_cast<const ::android::content::Context*>(arg1)));
}

bool PosPrinter_RollPaperStatus(const PosPrinter* pos_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->RollPaperStatus();
}

bool PosPrinter_PrintLabelBitmap(const PosPrinter* pos_printer, Bitmap* arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->PrintLabelBitmap(*reinterpret_cast<const ::android::graphics::Bitmap*>(arg1));
}

void PosPrinter_setsDevice(const PosPrinter* pos_printer, String* arg1) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->setsDevice(*reinterpret_cast<const ::java::lang::String*>(arg1));
}

void PosPrinter_onReceive(const PosPrinter* pos_printer, Context* arg1, Intent* arg2) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->onReceive(*reinterpret_cast<const ::android::content::Context*>(arg1), *reinterpret_cast<const ::android::content::Intent*>(arg2));
}

String* PosPrinter_getPrinterList(const PosPrinter* pos_printer) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->getPrinterList());
}

bool PosPrinter_Open(const PosPrinter* pos_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->Open();
}

void PosPrinter_Close(const PosPrinter* pos_printer) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->Close();
}

bool PosPrinter_WriteData(const PosPrinter* pos_printer, int8_t arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->WriteData(arg1);
}

int8_t PosPrinter_ReadData(const PosPrinter* pos_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::PosPrinter*>(pos_printer)->ReadData();
}
