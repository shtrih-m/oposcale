#ifndef OPOLABELPRINTER_H
#define OPOLABELPRINTER_H

#include <QObject>
#include <QJniObject>
#include "OnePlusOneAndroidSDK\Printer\label_printer.hpp"
using OnePlusOneAndroidSDK::Printer::LabelPrinter;

/*////////////////////////////////////////////////////////////////////////////////////////*/
// Pirnter status

const int StatusOutOfPaper              = 1; // Printer is out of paper
const int StatusNoPaperPickUp           = 2; // Printer did not pick up paper
const int StatusPrinterOpen             = 3; // Printer open
const int StatusPrinterHighTemperature  = 4; // Printer high temperature
const int StatusPrinterPositioning      = 5; // Printer positioning exception
const int StatusPrinterBusy             = 6; // Printer busy
const int StatusUnknownException        = 7; // Printer unknown exception
const int StatusWriteError              = 8; // Writing error, abnormal cover opening


class OpoLabelPrinter : public QObject
{
    Q_OBJECT

    ::OnePlusOneAndroidSDK::Printer::LabelPrinter* getPrinter();
    ::OnePlusOneAndroidSDK::Printer::LabelPrinter* printer = nullptr;
public:
    explicit OpoLabelPrinter(QObject *parent = nullptr);
    QString getStatusText(int status);
    bool isUsbPrinter();
    bool Open();
    void Close();
    bool WriteData(int8_t arg1, int32_t arg2);
    int8_t ReadData(int32_t arg1);
    int32_t GetStatus();
    bool PrintLabelBitmap(QBitmap bitmap);

signals:
};

#endif // OPOLABELPRINTER_H
