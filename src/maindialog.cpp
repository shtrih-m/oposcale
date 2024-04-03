#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
#include <QJniObject>
#include <QBitmap>
#include <QJniEnvironment>
#include <QFileDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QDir>
#include <QStringList>
#include <QByteArrayList>
#include <QByteArray>
#include <QStandardPaths>


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
    QImage image(":images/res/Label.jpg");
    QBitmap bitmap = QBitmap::fromImage(image);
    ui->lblImage->setPixmap(bitmap);
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
    QImage image(":images/res/Label.jpg");
    QBitmap bitmap = QBitmap::fromImage(image);
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

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
                                                  ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    //dialog.selectMimeTypeFilter("image/jpeg"); !!!
    dialog.setAcceptMode(acceptMode);
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void MainDialog::on_btnOpenImage_clicked()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
    if (dialog.exec() == QDialog::Accepted){
        QString fileName = dialog.selectedFiles().constFirst();
        QPicture picture;
        if (picture.load(fileName)){
            ui->lblImage->setPicture(picture);
        } else{
            QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                tr("Cannot load picture %1").arg(QDir::toNativeSeparators(fileName)));
        }
    }
}

