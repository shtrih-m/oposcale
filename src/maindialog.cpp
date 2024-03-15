#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
#include <QJniObject>
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

jobject getGlobalContext()
{
    QJniEnvironment env;
    jclass activityThread = env.jniEnv()->FindClass("android/app/ActivityThread");
    jmethodID currentActivityThread = env.jniEnv()->GetStaticMethodID(activityThread, "currentActivityThread", "()Landroid/app/ActivityThread;");
    jobject activityThreadObj = env.jniEnv()->CallStaticObjectMethod(activityThread, currentActivityThread);
    jmethodID getApplication = env.jniEnv()->GetMethodID(activityThread, "getApplication", "()Landroid/app/Application;");
    jobject context = env.jniEnv()->CallObjectMethod(activityThreadObj, getApplication);
    return context;
}

::OnePlusOneAndroidSDK::Printer::LabelPrinter* MainDialog::getPrinter(){
    if (printer == nullptr)
    {
        const android::content::Context context(getGlobalContext());
        printer = &::OnePlusOneAndroidSDK::Printer::LabelPrinter::getInstance(context);
    }
    return printer;
}


void MainDialog::on_btnOpen_clicked()
{
    ui->edtResult->clear();
    QString deviceName = ui->edtDeviceName->text();
    if (sdk.Open(deviceName))
    {
        qDebug() << "File open succeeded";
        ui->edtResult->setText("OK");
        //sdk.SetAutoMode();
    } else{
        qDebug() << "File open failed";
        ui->edtResult->setText("Failed");
    }
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
    QString result= "";
    int rc = sdk.ReadResultCache(result);
    rc = sdk.GetResult(result);
    ui->edtResult->setText(sdk.getErrorMessage(rc));

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
    int32_t tare = ui->edtTare->text().toInt();
    int rc = sdk.PreTare(tare);
    ui->edtResult->setText(sdk.getErrorMessage(rc));
}

void MainDialog::on_btnExitTare_clicked()
{
    ui->edtResult->clear();
    int rc = sdk.ExitTare();
    ui->edtResult->setText(sdk.getErrorMessage(rc));
}

void MainDialog::on_btnPrinterOpen_clicked()
{
    ui->edtPrinterResult->clear();
    if (getPrinter()->Open()){
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
    getPrinter()->Close();
}

jobject getBitmap(QString fileName)
{
    qDebug() << "getBitmap";
    QJniEnvironment env;
    jclass BitmapFactoryClass = env.jniEnv()->FindClass("android/graphics/BitmapFactory");
    if (BitmapFactoryClass == nullptr){
        qDebug() << "BitmapFactory class not found";
        return nullptr;
    }
    jmethodID methodID = env.jniEnv()->GetStaticMethodID(BitmapFactoryClass, "decodeFile", "(Ljava/lang/String;)Landroid/graphics/Bitmap;");
    if (methodID == nullptr){
        qDebug() << "BitmapFactory method decodeFile not found";
        return nullptr;
    }
    jobject bitmap = env.jniEnv()->CallStaticObjectMethod(BitmapFactoryClass, methodID,
        QJniObject::fromString(fileName).object<jstring>());
    return bitmap;
}

void MainDialog::on_btnPrinterPrintLabel_clicked()
{
    ui->edtPrinterResult->clear();
    QString fileName = "";
    jobject jbitmap = getBitmap(fileName);
    ::android::graphics::Bitmap bitmap(jbitmap);
    getPrinter()->PrintLabelBitmap(bitmap);
}

QString getStatusText(int status)
{
    QString result = "Unknown status";
    switch (status) {
        case 0:
            result = "Printer OK";
            break;

        case 1:
            result = "Printer is out of paper";
            break;

        case 2:
            result = "Printer did not pick up paper";
            break;

        case 3:
            result = "Printer open";
            break;

        case 4:
            result = "Printer high temperature";
            break;

        case 5:
            result = "Printer positioning exception";
            break;

        case 6:
            result = "Printer busy";
            break;

        case 7:
            result = "Printer unknown exception";
            break;

        case 8:
            result = "Writing error, abnormal cover opening";
            break;
        }
    return QString("%1, %2").arg(QString::number(status), result);
}

void MainDialog::on_btnPrinterGetStatus_clicked()
{
    ui->edtPrinterResult->clear();
    int32_t status = getPrinter()->GetStatus();
    QString text = getStatusText(status);
    ui->edtPrinterResult->setText(text);
}

