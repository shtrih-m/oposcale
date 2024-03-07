#ifndef WEIGHTDATA_H
#define WEIGHTDATA_H

#include <QString>

class WeightData
{
private:
    QString sMode;
    QString sStatus;
    QString sZero;
    QString sUnit;
    QString sNetWeight;
    QString sTareWeight;
    QString sGrossWeight;
public:
    WeightData();
    static WeightData parse(QString data);

    QString getMode();
    QString getStatus();
    QString getZero();
    QString getUnit();
    QString getNetWeight();
    QString getTareWeight();
    QString getGrossWeight();
};

#endif // WEIGHTDATA_H
