#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
#include <QJniObject>
#include <QBitmap>
#include <QJniEnvironment>

#include "weightdata.h"
#include "OnePlusOneAndroidSDK\ScalesOS\weight_info.hpp"
#include "OnePlusOneAndroidSDK\ScalesOS\scales_s_d_k.hpp"
#include "OnePlusOneAndroidSDK\Printer\label_printer.hpp"

using OnePlusOneAndroidSDK::ScalesOS::WeightInfo;
using OnePlusOneAndroidSDK::ScalesOS::ScalesSDK;
using OnePlusOneAndroidSDK::Printer::LabelPrinter;

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}


void MainDialog::on_btnOpen_clicked()
{
    ui->edtResult->clear();
    QString deviceName = ui->edtDeviceName->text();
    if (scale.Open(deviceName))
    {
        qDebug() << "File open succeeded";
        ui->edtResult->setText("OK");
        //scale.SetAutoMode();
    } else{
        qDebug() << "File open failed";
        ui->edtResult->setText("Failed");
    }
}

void MainDialog::on_btnClose_clicked()
{
    ui->edtResult->clear();
    int rc = scale.Close();
    ui->edtResult->setText(scale.getErrorMessage(rc));
}


void MainDialog::on_btnReadWeight_clicked()
{
    ui->edtResult->clear();
    QString result = scale.GetResult();
    ui->edtResult->setText(result);

    WeightData weight = scale.getWeight();
    ui->lblNetWeight->setText("Net weight: " + weight.getNetWeight());
    ui->lblTareWeight->setText("Tare weight: " + weight.getTareWeight());
    ui->lblGrossWeight->setText("Gross weight: " + weight.getGrossWeight());
}


void MainDialog::on_btnZero_clicked()
{
    ui->edtResult->clear();
    int rc = scale.Zero();
    ui->edtResult->setText(scale.getErrorMessage(rc));
}


void MainDialog::on_btnTare_clicked()
{
    ui->edtResult->clear();
    int rc = scale.Tare();
    ui->edtResult->setText(scale.getErrorMessage(rc));
}


void MainDialog::on_btnOpen_pressed()
{
}


void MainDialog::on_btnPreTare_clicked()
{
    ui->edtResult->clear();
    int32_t tare = ui->edtTare->text().toInt();
    int rc = scale.PreTare(tare);
    ui->edtResult->setText(scale.getErrorMessage(rc));
}

void MainDialog::on_btnExitTare_clicked()
{
    ui->edtResult->clear();
    int rc = scale.ExitTare();
    ui->edtResult->setText(scale.getErrorMessage(rc));
}

void MainDialog::on_btnPrinterOpen_clicked()
{
    ui->edtPrinterResult->clear();
    if (printer.Open()){
        qDebug() << "Printer open succeeded";
        ui->edtPrinterResult->setText("OK");
    } else{
        qDebug() << "Printer open failed";
        ui->edtPrinterResult->setText("Failed");
    }
}


void MainDialog::on_btnPrinterClose_clicked()
{
    ui->edtPrinterResult->clear();
    printer.Close();
}

void MainDialog::on_btnPrinterPrintLabel_clicked()
{
    ui->edtPrinterResult->clear();
    QBitmap bitmap;
    printer.PrintLabelBitmap(bitmap);
}

void MainDialog::on_btnPrinterGetStatus_clicked()
{
    ui->edtPrinterResult->clear();
    int32_t status = printer.GetStatus();
    QString text = printer.getStatusText(status);
    ui->edtPrinterResult->setText(text);
}


void MainDialog::on_lblResult_3_linkActivated(const QString &link)
{

}

