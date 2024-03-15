#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "oposcalesdk.h"
#include "OnePlusOneAndroidSDK\Printer\label_printer.hpp"


namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

private slots:
    void on_btnOpen_clicked();

    void on_btnClose_clicked();

    void on_btnReadWeight_clicked();

    void on_btnZero_clicked();

    void on_btnTare_clicked();

    void on_btnOpen_pressed();

    void on_btnPreTare_clicked();

    void on_btnExitTare_clicked();

    void on_btnPrinterOpen_clicked();

    void on_btnPrinterClose_clicked();

    void on_btnPrinterPrintLabel_clicked();

    void on_btnPrinterGetStatus_clicked();

private:
    OpoScaleSDK sdk;
    ::OnePlusOneAndroidSDK::Printer::LabelPrinter* printer = nullptr;

    Ui::MainDialog *ui;
    ::OnePlusOneAndroidSDK::Printer::LabelPrinter* getPrinter();
};

#endif // MAINDIALOG_H
