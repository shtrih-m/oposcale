#include "oposcalesdk.h"

#include <QLibrary>
#include <QDebug>
#include <QMessageLogger>
#include "weightdata.h"

OpoScaleSDK::OpoScaleSDK(QObject *parent)
    : QObject{parent}
{}

WeightData OpoScaleSDK::getWeight(){
    return weight;
}

QString OpoScaleSDK::getErrorMessage(int rc)
{
    QString result = "Unknown error";
    switch(rc)
    {
    case ENoError:
    case ENoError2:
        result = "No error";
        break;

    case ELibNotLoaded:
        result = "Lib not found";
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
    return (!isSucceeded(rc));
}

bool OpoScaleSDK::isSucceeded(int rc){
    return (rc == ENoError)||(rc == ENoError2);
}

QFunctionPointer OpoScaleSDK::resolve(const char *symbol){
    QFunctionPointer rc = lib.resolve(symbol);
    if (rc) {
        qDebug() << "Resolve succeeded for "  << symbol;
    } else{
        qDebug() << "Resolve failed for " << symbol;
    }
    return rc;
}

int OpoScaleSDK::loadlib()
{
    if (!lib.isLoaded())
    {
        qDebug() << "loadlib()";
        lib.setFileName("liboposcalessdk.so");
        if (!lib.load()){
            qDebug() << "Library liboposcalessdk.so load failed";
            return ELibNotLoaded;
        }
        qDebug() << "Library liboposcalessdk.so load succeeded";

        opoClose = (OPO_Close)resolve("OPO_Close");
        opoOpen = (OPO_Open)resolve("OPO_Open");
        opoExitTare = (OPO_ExitTare)resolve("OPO_ExitTare");
        opoGetResult = (OPO_GetResult)resolve("OPO_GetResult");
        opoPreTare = (OPO_PreTare)resolve("OPO_PreTare");
        opoTare = (OPO_Tare)resolve("OPO_Tare");
        opoZero = (OPO_Zero) resolve("OPO_Zero");
        opoPowOnZero = (OPO_PowOnZero)resolve("OPO_PowOnZero");
        opoReadResultCache = (OPO_ReadResultCache) resolve("OPO_ReadResultCache");
        opoSendFre = (OPO_SendFre)resolve("OPO_SendFre");
        opoSetAutoMode = (OPO_SetAutoMode) resolve("OPO_SetAutoMode");
        opoSetModuleCallBack = (OPO_SetModuleCallBack)resolve("OPO_SetModuleCallBack");
        opoSetUnit = (OPO_SetUnit)resolve("OPO_SetUnit");

        qDebug() << "loadlib(): OK";
    }
    return ENoError;
}

int OpoScaleSDK::Open(QString deviceName)
{
    qDebug() << "Open(" + deviceName + ")";

    int rc = loadlib();
    if (isSucceeded(rc))
    {
        char* s = deviceName.toStdString().data();
        qDebug() << "Open(" << s << ")";
        rc = opoOpen(s);
    }
    qDebug() << "Open(" + deviceName + ")=" << rc;
    return rc;
}

int OpoScaleSDK::SetAutoMode()
{
    qDebug() << "SetAutoMode()";
    int rc = loadlib();
    if (isSucceeded(rc)) {
        rc = opoSetAutoMode();
    }
    qDebug() << "SetAutoMode()=" << rc;
    return rc;
}

int OpoScaleSDK::GetResult(QString& result)
{
    qDebug() << "GetResult()";
    int rc = loadlib();
    if (isSucceeded(rc))
    {
        char buffer[256];
        rc = opoGetResult(buffer);
        if (isSucceeded(rc))
        {
            //QByteArray array(buffer, 256);
            //qDebug() << "GetResult()=" << QString(array.toHex());
            result = QString(buffer);
            weight = WeightData::parse(result);
        }
    }
    qDebug() << "GetResult()=" << rc << ", " << result;
    return rc;
}

int OpoScaleSDK::ReadResultCache(QString& result)
{
    qDebug() << "ReadResultCache()";
    int rc = loadlib();
    if (isSucceeded(rc)){
        char buffer[256];
        rc = opoReadResultCache(buffer);
        if (isSucceeded(rc))
        {
            //QByteArray array(buffer, 256);
            //qDebug() << "ReadResultCache()=" << QString(array.toHex());
            result = QString(buffer);
        }
    }
    qDebug() << "ReadResultCache()=" << rc << ", " << result;
    return rc;
}

int OpoScaleSDK::Close()
{
    qDebug() << "Close()";
    int rc = loadlib();
    if (isSucceeded(rc))
    {
        rc = opoClose();
    }
    qDebug() << "Close()=" << rc;
    return rc;
}

int OpoScaleSDK::Zero(){
    qDebug() << "Zero()";
    int rc = loadlib();
    if (isSucceeded(rc)){
        rc = opoZero();
    }
    qDebug() << "Zero()=" << rc;
    return rc;
}

int OpoScaleSDK::Tare(){
    qDebug() << "Tare()";
    int rc = loadlib();
    if (isSucceeded(rc)){
        rc = opoTare();
    }
    qDebug() << "Tare()=" << rc;
    return rc;
}

int OpoScaleSDK::PreTare(int value)
{
    qDebug() << "PreTare(" << value << ")";
    int rc = loadlib();
    if (isSucceeded(rc)){
        rc = opoPreTare(value);
    }
    qDebug() << "PreTare(" << value << ")=" << rc;
    return rc;
}

int OpoScaleSDK::ExitTare()
{
    qDebug() << "ExitTare()";
    int rc = loadlib();
    if (isSucceeded(rc))
    {
        rc = opoExitTare();
    }
    qDebug() << "ExitTare()=" << rc;
    return rc;
}

int OpoScaleSDK::SendFre(int value){
    qDebug() << "SendFre(" << value << ")";
    int rc = loadlib();
    if (isSucceeded(rc))
    {
        rc = opoSendFre(value);
    }
    qDebug() << "SendFre(" << value << ")=" << rc;
    return rc;
}

int OpoScaleSDK::SetUnit(int value){
    qDebug() << "SetUnit(" << value << ")";
    int rc = loadlib();
    if (isSucceeded(rc))
    {
        rc = opoSetUnit(value);
    }
    qDebug() << "SetUnit(" << value << ")=" << rc;
    return rc;
}

int OpoScaleSDK::PowOnZero()
{
    qDebug() << "PowOnZero";
    int rc = loadlib();
    if (isSucceeded(rc))
    {
        rc = opoPowOnZero();
    }
    qDebug() << "PowOnZero()=" << rc;
    return rc;
}

int OpoScaleSDK::SetModuleCallBack(void *CallBack){
    qDebug() << "SetModuleCallBack";
    int rc = loadlib();
    if (isSucceeded(rc))
    {
        opoSetModuleCallBack(CallBack);
    }
    qDebug() << "SetModuleCallBack()=" << rc;
    return rc;
}

