#ifndef OPOSCALESDK_H
#define OPOSCALESDK_H

#include <QObject>
#include <QLibrary>
#include "weightdata.h"


const int ENoError          = 0;
const int ENoError2          = 1;
const int ELibNotLoaded     = -1;

typedef void(__stdcall *OPO_SetModuleCallBack)(void *CallBack);
typedef int(__stdcall *OPO_Close)(void);
typedef int(__stdcall *OPO_SetAutoMode)(void);
typedef int(__stdcall *OPO_Open)(const char* Connect);
typedef int(__stdcall *OPO_GetResult)(char str[]);
typedef int(__stdcall *OPO_ReadResultCache)(char str[]);
typedef int(__stdcall *OPO_SendFre)(int Value);
typedef int(__stdcall *OPO_Zero)(void);
typedef int(__stdcall *OPO_Tare)(void);
typedef int(__stdcall *OPO_PreTare)(int Value);
typedef int(__stdcall *OPO_SetUnit)(int Value);
typedef int(__stdcall *OPO_PowOnZero)(void);
typedef int(__stdcall *OPO_ExitTare)(void);


class OpoScaleSDK : public QObject
{
    Q_OBJECT
private:
    QLibrary lib;
    WeightData weight;
    QString m_deviceName;

    OPO_Open opoOpen;
    OPO_Close opoClose;
    OPO_GetResult opoGetResult;
    OPO_PowOnZero opoPowOnZero;
    OPO_PreTare opoPreTare;
    OPO_ReadResultCache opoReadResultCache;
    OPO_SendFre opoSendFre;
    OPO_SetAutoMode opoSetAutoMode;
    OPO_SetModuleCallBack opoSetModuleCallBack;
    OPO_SetUnit opoSetUnit;
    OPO_Tare opoTare;
    OPO_Zero opoZero;
    OPO_ExitTare opoExitTare;

    int loadlib();
    QFunctionPointer resolve(const char *symbol);
public:
    explicit OpoScaleSDK(QObject *parent = nullptr);

    int Open(QString deviceName);
    int Close();
    int ReadResultCache(QString& result);
    int GetResult(QString& result);
    int Zero();
    int Tare();
    int PreTare(int value);
    int ExitTare();
    int SetAutoMode();
    int SendFre(int value);
    int SetUnit(int value);
    int PowOnZero();
    int SetModuleCallBack(void *CallBack);

    bool isFailed(int rc);
    bool isSucceeded(int rc);
    QString getErrorMessage(int rc);
    WeightData getWeight();

signals:
};

#endif // OPOSCALESDK_H
