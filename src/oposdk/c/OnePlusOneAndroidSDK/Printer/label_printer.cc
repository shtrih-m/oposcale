#include "OnePlusOneAndroidSDK\Printer\label_printer.h"

#include "OnePlusOneAndroidSDK\Printer\label_printer.hpp"

LabelPrinter* LabelPrinter_wrapJniReference(jobject jobj) {
  return reinterpret_cast<LabelPrinter*>(new ::OnePlusOneAndroidSDK::Printer::LabelPrinter(jobj));
}

jobject LabelPrinter_getJniReference(const LabelPrinter* label_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->GetImpl();
}

void LabelPrinter_destroy(const LabelPrinter* label_printer) {
  ::OnePlusOneAndroidSDK::Printer::LabelPrinter::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer));
}

LabelPrinter* LabelPrinter_getInstance(Context* arg1) {
  return reinterpret_cast<LabelPrinter*>(&::OnePlusOneAndroidSDK::Printer::LabelPrinter::getInstance(*reinterpret_cast<const ::android::content::Context*>(arg1)));
}

bool LabelPrinter_isUsbPrinter(const LabelPrinter* label_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->isUsbPrinter();
}

bool LabelPrinter_Open(const LabelPrinter* label_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->Open();
}

void LabelPrinter_Close(const LabelPrinter* label_printer) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->Close();
}

bool LabelPrinter_WriteData(const LabelPrinter* label_printer, int8_t arg1, int32_t arg2) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->WriteData(arg1, arg2);
}

int8_t LabelPrinter_ReadData(const LabelPrinter* label_printer, int32_t arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->ReadData(arg1);
}

int32_t LabelPrinter_GetStatus(const LabelPrinter* label_printer) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->GetStatus();
}

bool LabelPrinter_PrintLabelBitmap(const LabelPrinter* label_printer, Bitmap* arg1) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->PrintLabelBitmap(*reinterpret_cast<const ::android::graphics::Bitmap*>(arg1));
}

void LabelPrinter_setsDevice(const LabelPrinter* label_printer, String* arg1) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->setsDevice(*reinterpret_cast<const ::java::lang::String*>(arg1));
}

void LabelPrinter_onReceive(const LabelPrinter* label_printer, Context* arg1, Intent* arg2) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->onReceive(*reinterpret_cast<const ::android::content::Context*>(arg1), *reinterpret_cast<const ::android::content::Intent*>(arg2));
}

String* LabelPrinter_getPrinterList(const LabelPrinter* label_printer) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter*>(label_printer)->getPrinterList());
}

LabelPrinter_OnStatusChangedListener* LabelPrinter_OnStatusChangedListener_wrapJniReference(jobject jobj) {
  return reinterpret_cast<LabelPrinter_OnStatusChangedListener*>(new ::OnePlusOneAndroidSDK::Printer::LabelPrinter::OnStatusChangedListener(jobj));
}

jobject LabelPrinter_OnStatusChangedListener_getJniReference(const LabelPrinter_OnStatusChangedListener* label_printer_on_status_changed_listener) {
  return reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter::OnStatusChangedListener*>(label_printer_on_status_changed_listener)->GetImpl();
}

LabelPrinter_OnStatusChangedListener* LabelPrinter_OnStatusChangedListener_implementInterface(LabelPrinter_OnStatusChangedListener_onStatusChangedCallback label_printer_on_status_changed_listener_on_status_changed_callback) {
  return reinterpret_cast<LabelPrinter_OnStatusChangedListener*>(::OnePlusOneAndroidSDK::Printer::LabelPrinter::OnStatusChangedListener::ImplementInterface(reinterpret_cast<::OnePlusOneAndroidSDK::Printer::LabelPrinter::OnStatusChangedListener::onStatusChangedCallback>(label_printer_on_status_changed_listener_on_status_changed_callback)));
}

void LabelPrinter_OnStatusChangedListener_destroy(const LabelPrinter_OnStatusChangedListener* label_printer_on_status_changed_listener) {
  ::OnePlusOneAndroidSDK::Printer::LabelPrinter::OnStatusChangedListener::destroy(reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter::OnStatusChangedListener*>(label_printer_on_status_changed_listener));
}

void LabelPrinter_OnStatusChangedListener_onStatusChanged(const LabelPrinter_OnStatusChangedListener* label_printer_on_status_changed_listener, int32_t arg1) {
  reinterpret_cast<const ::OnePlusOneAndroidSDK::Printer::LabelPrinter::OnStatusChangedListener*>(label_printer_on_status_changed_listener)->onStatusChanged(arg1);
}
