#include <QDebug>
#include <QBitmap>
#include <QJniObject>

#include <QJniObject>

#include "opolabelprinter.h"
#include "OnePlusOneAndroidSDK\Printer\label_printer.hpp"
using OnePlusOneAndroidSDK::Printer::LabelPrinter;

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

OpoLabelPrinter::OpoLabelPrinter(QObject *parent)
    : QObject{parent}
{}

::OnePlusOneAndroidSDK::Printer::LabelPrinter* OpoLabelPrinter::getPrinter(){
    if (printer == nullptr)
    {
        const android::content::Context context(getGlobalContext());
        printer = &::OnePlusOneAndroidSDK::Printer::LabelPrinter::getInstance(context);
    }
    return printer;
}

QString OpoLabelPrinter::getStatusText(int status)
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

bool OpoLabelPrinter::isUsbPrinter()
{
    qDebug() << "OpoLabelPrinter::isUsbPrinter()";
    bool rc = getPrinter()->isUsbPrinter();
    qDebug() << "OpoLabelPrinter::isUsbPrinter()=" << rc;
    return rc;
}

bool OpoLabelPrinter::Open()
{
    qDebug() << "OpoLabelPrinter::Open()";
    bool rc = getPrinter()->Open();
    qDebug() << "OpoLabelPrinter::Open()=" << rc;
    return rc;
}

void OpoLabelPrinter::Close()
{
    qDebug() << "OpoLabelPrinter::Close()";
    getPrinter()->Close();
    qDebug() << "OpoLabelPrinter::Close(): OK";
}

bool OpoLabelPrinter::WriteData(int8_t arg1, int32_t arg2)
{
    qDebug() << "OpoLabelPrinter::WriteData(" << arg1 << ", " << arg2 << ")";
    bool rc = getPrinter()->WriteData(arg1, arg2);
    qDebug() << "OpoLabelPrinter::WriteData()=" << rc;
    return rc;
}

int8_t OpoLabelPrinter::ReadData(int32_t arg1)
{
    qDebug() << "OpoLabelPrinter::ReadData()";
    int8_t rc = getPrinter()->ReadData(arg1);
    qDebug() << "OpoLabelPrinter::ReadData()=" << rc;
    return rc;
}

int32_t OpoLabelPrinter::GetStatus()
{
    qDebug() << "OpoLabelPrinter::GetStatus()";
    int32_t rc = getPrinter()->GetStatus();
    qDebug() << "OpoLabelPrinter::GetStatus()=" << rc;
    return rc;
}

bool OpoLabelPrinter::PrintLabelBitmap(QBitmap bitmap)
{
    qDebug() << "OpoLabelPrinter::PrintLabelBitmap()";
    //jobject jbitmap = getBitmap(fileName);
    jobject jbitmap;
    ::android::graphics::Bitmap abitmap(jbitmap);
    bool rc = getPrinter()->PrintLabelBitmap(abitmap);
    qDebug() << "OpoLabelPrinter::PrintLabelBitmap()=" << rc;
    return rc;
}
