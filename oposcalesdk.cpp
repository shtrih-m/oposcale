#include "OpoScaleSDK.h"

#include <QDebug>
#include <QJniObject>
#include "OnePlusOneAndroidSDK\ScalesOS\scales_s_d_k.hpp"
#include "weightdata.h"


OpoScaleSDK::OpoScaleSDK(QObject *parent)
    : QObject{parent}
{
    gcontext = getGlobalContext();
    gni::GniCore::Init(env.javaVM(), gcontext);
}

OnePlusOneAndroidSDK::ScalesOS::ScalesSDK* OpoScaleSDK::getsdk()
{
    if (sdk == nullptr)
    {
        qDebug() << "getsdk";
        const android::content::Context context(gcontext);
        sdk = &OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::getInstance(context);
        qDebug() << "getsdk: OK";
    }
    return sdk;
}

QString OpoScaleSDK::getErrorMessage(int rc)
{
    QString result = "Unknown error";
    switch(rc)
    {
        case 0:
            result = "No error";
            break;

        case 32768:
            result = "Command data not in legal range";
            break;

        case 33024:
            result = "Unstable weight";
            break;

        case 33280:
            result = "AD value overflow";
            break;

        case 33536:
            result = "Currently in tare mode";
            break;

        case 33792:
            result = "No power-on zero";
            break;

        case 34048:
            result = "Currently in preset tare mode";
            break;

        case 34304:
            result = "Anti-cheat is not turned on, cannot be set";
            break;

        case 65024:
            result = "Erroneous command";
            break;
    }
    return QString("%1, %2").arg(QString::number(rc), result);
}

bool OpoScaleSDK::isFailed(int rc){
    return rc != 0;
}

bool OpoScaleSDK::isSucceeded(int rc){
    return rc == 0;
}

jobject OpoScaleSDK::getGlobalContext()
{
    QJniEnvironment env;
    jclass activityThread = env.jniEnv()->FindClass("android/app/ActivityThread");
    jmethodID currentActivityThread = env.jniEnv()->GetStaticMethodID(activityThread, "currentActivityThread", "()Landroid/app/ActivityThread;");
    jobject activityThreadObj = env.jniEnv()->CallStaticObjectMethod(activityThread, currentActivityThread);
    jmethodID getApplication = env.jniEnv()->GetMethodID(activityThread, "getApplication", "()Landroid/app/Application;");
    jobject context = env.jniEnv()->CallObjectMethod(activityThreadObj, getApplication);
    return context;
}

void OpoScaleSDK::setWeightChangedListener(const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener& arg1)
{
    qDebug() << "setWeightChangedListener";
    getsdk()->setWeightChangedListener(arg1);
    qDebug() << "setWeightChangedListener: OK";
}

void OpoScaleSDK::setScaleAlwaysRead()
{
    qDebug() << "setScaleAlwaysRead";
    getsdk()->setScaleAlwaysRead();
    qDebug() << "setScaleAlwaysRead: OK";
}

jobject OpoScaleSDK::getFile(QString deviceName)
{
    qDebug() << "getFile";
    jclass fileclass = env.jniEnv()->FindClass("java/io/File");
    if (fileclass == nullptr){
        qDebug() << "File class not found";
        return nullptr;
    }
    jmethodID methodID = env.jniEnv()->GetMethodID(fileclass, "<init>", "(Ljava/lang/String;)V");
    if (methodID == nullptr){
        qDebug() << "File constructor not found";
        return nullptr;
    }

    jobject file = env.jniEnv()->NewObject(fileclass, methodID,
        QJniObject::fromString(deviceName).object<jstring>());
    if (file == nullptr){
        qDebug() << "File creation failed";
        return file;
    }
    return file;
}

bool OpoScaleSDK::Open(QString deviceName)
{
    qDebug() << "OpoScaleSDK::Open(" << deviceName << ")";
    java::io::File file(getFile(deviceName));
    bool rc = getsdk()->Open(file);
    qDebug() << "OpoScaleSDK::Open(" << deviceName << ")= " << rc;
    return rc;
}

::OnePlusOneAndroidSDK::ScalesOS::WeightInfo* OpoScaleSDK::getWeihtInfo()
{
    qDebug() << "OpoScaleSDK::getWeihtInfo";
    weightInfo = &getsdk()->getWeihtInfo();
    qDebug() << "OpoScaleSDK::getWeihtInfo: OK";
    return weightInfo;
}

void OpoScaleSDK::ReadThread(bool arg1)
{
    qDebug() << "OpoScaleSDK::ReadThread";
    getsdk()->ReadThread(arg1);
    qDebug() << "OpoScaleSDK::ReadThread: OK";
}

QString OpoScaleSDK::OPOModuleSend(int32_t arg1, int32_t arg2, int8_t arg3, int32_t arg4)
{
    qDebug() << "OpoScaleSDK::OPOModuleSend";
    QJniObject rc(getsdk()->OPOModuleSend(arg1, arg2, arg3, arg4).GetImpl());
    qDebug() << "OpoScaleSDK::OPOModuleSend=" << rc.toString();
    return rc.toString();
}

int32_t OpoScaleSDK::Close(){
    qDebug() << "OpoScaleSDK::Close";
    int32_t rc = getsdk()->Close();
    qDebug() << "OpoScaleSDK::Close: " << rc;
    return rc;
}

QString OpoScaleSDK::GetResult()
{
    qDebug() << "OpoScaleSDK::GetResult";
    QJniObject rc(getsdk()->GetResult().GetImpl());
    weight = WeightData::parse(rc.toString());
    qDebug() << "OpoScaleSDK::GetResult: " << rc.toString();
    return rc.toString();
}

WeightData OpoScaleSDK::getWeight(){
    return weight;
}

int32_t OpoScaleSDK::Zero()
{
    qDebug() << "OpoScaleSDK::Zero";
    int32_t rc = getsdk()->Zero();
    qDebug() << "OpoScaleSDK::Zero=" << rc;
    return rc;
}

int32_t OpoScaleSDK::Tare()
{
    qDebug() << "OpoScaleSDK::Tare";
    int32_t rc = getsdk()->Tare();
    qDebug() << "OpoScaleSDK::Tare=" << rc;
    return rc;
}

int32_t OpoScaleSDK::PreTare(int32_t arg1)
{
    qDebug() << "OpoScaleSDK::PreTare(" << arg1 << ")";
    int32_t rc = getsdk()->PreTare(arg1);
    qDebug() << "OpoScaleSDK::PreTare=" << rc;
    return rc;
}

int32_t OpoScaleSDK::ExitTare()
{
    qDebug() << "OpoScaleSDK::ExitTare";
    int32_t rc = getsdk()->ExitTare();
    qDebug() << "OpoScaleSDK::ExitTare=" << rc;
    return rc;
}

