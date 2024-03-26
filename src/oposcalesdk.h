#ifndef OPOSCALESDK_H
#define OPOSCALESDK_H

#include <QObject>
#include <QJniObject>
#include "OnePlusOneAndroidSDK\ScalesOS\scales_s_d_k.hpp"
#include "weightdata.h"

const int ENoError              = 0;
const int EClassNotFound        = -1;
const int EMethodNotFound       = -2;
const int EMethodCallFailed     = -3;
const int EContextIsNull        = -4;
const int ESDKInstanceIsNull    = -5;
const int EOpenFailed           = -6;
// Device errors
const int EIllegalCommandData   = 32768; // 0x8000
const int EUnstableWeight       = 33024; // 0x8100
const int EADOverflow           = 33280; // 0x8200
const int ETareMode             = 33536; // 0x8300
const int ENoPowerOnZero        = 33792; // 0x8400
const int EPresetTareMode       = 34048; // 0x8500
const int EAntiCheatOff         = 34304; // 0x8600
const int EInvalidCommand       = 65024; // 0xFE00


class OpoScaleSDK : public QObject
{
    Q_OBJECT
private:
    WeightData weight;
    QJniEnvironment env;
    jobject gcontext = nullptr;
    OnePlusOneAndroidSDK::ScalesOS::WeightInfo* weightInfo;
    OnePlusOneAndroidSDK::ScalesOS::ScalesSDK* sdk = nullptr;
public:
    explicit OpoScaleSDK(QObject *parent = nullptr);

    jobject getGlobalContext();
    jobject getFile(QString deviceName);
    OnePlusOneAndroidSDK::ScalesOS::ScalesSDK* getsdk();

    WeightData getWeight();

    bool isFailed(int rc);
    bool isSucceeded(int rc);
    QString getErrorMessage(int rc);
    void setWeightChangedListener(const ::OnePlusOneAndroidSDK::ScalesOS::ScalesSDK::WeightChangedListener& arg1);
    void setScaleAlwaysRead();
    bool Open(QString deviceName);
    ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo* getWeihtInfo();
    void ReadThread(bool arg1);
    QString OPOModuleSend(int32_t arg1, int32_t arg2, int8_t arg3, int32_t arg4);
    int32_t Close();
    QString GetResult();
    int32_t Zero();
    int32_t Tare();
    int32_t PreTare(int32_t arg1);
    int32_t ExitTare();
signals:
};

#endif // OPOSCALESDK_H
