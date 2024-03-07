#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
#include "weightdata.h"
#include "OnePlusOneAndroidSDK\ScalesOS\weight_info.hpp"
#include "OnePlusOneAndroidSDK\ScalesOS\scales_s_d_k.hpp"

using OnePlusOneAndroidSDK::ScalesOS::WeightInfo;
using OnePlusOneAndroidSDK::ScalesOS::ScalesSDK;

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

void weightChanged2(const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo* weightInfo){

}


void MainDialog::on_btnOpen_clicked()
{
    ui->edtResult->clear();
    QString deviceName = ui->edtDeviceName->text();
    if (sdk.Open(deviceName))
    {
        /*
        ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener* listener;
        listener = ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener::ImplementInterface(&weightChanged2);
        ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener& listener2 = listener;
        sdk.setWeightChangedListener(listener2);
        */

        qDebug() << "File open succeeded";
        ui->edtResult->setText("OK");
    } else{
        qDebug() << "File open failed";
        ui->edtResult->setText("Failed");
    }
    sdk.setScaleAlwaysRead();
}

void MainDialog::weightChanged(const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo* weightInfo){

}

void MainDialog::on_btnClose_clicked()
{
    ui->edtResult->clear();
    int rc = sdk.Close();
    ui->edtResult->setText(sdk.getErrorMessage(rc));
}


void MainDialog::on_btnReadWeight_clicked()
{
    ui->edtResult->clear();
    QString rc = sdk.GetResult();
    ui->edtResult->setText(rc);
    WeightData weight = sdk.getWeight();
    ui->lblNetWeight->setText("Net weight: " + weight.getNetWeight());
    ui->lblTareWeight->setText("Tare weight: " + weight.getTareWeight());
    ui->lblGrossWeight->setText("Gross weight: " + weight.getGrossWeight());
}


void MainDialog::on_btnZero_clicked()
{
    ui->edtResult->clear();
    int rc = sdk.Zero();
    ui->edtResult->setText(sdk.getErrorMessage(rc));
}


void MainDialog::on_btnTare_clicked()
{
    ui->edtResult->clear();
    int rc = sdk.Tare();
    ui->edtResult->setText(sdk.getErrorMessage(rc));
}


void MainDialog::on_btnOpen_pressed()
{
}


void MainDialog::on_btnPreTare_clicked()
{
    ui->edtResult->clear();
    int rc = sdk.PreTare(0);
    ui->edtResult->setText(sdk.getErrorMessage(rc));
}


void MainDialog::on_btnExitTare_clicked()
{
    ui->edtResult->clear();
    int rc = sdk.ExitTare();
    ui->edtResult->setText(sdk.getErrorMessage(rc));
}
