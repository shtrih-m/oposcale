#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "oposcalesdk.h"


namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

private slots:
    void on_btnOpen_clicked();

    void on_btnClose_clicked();

    void on_btnReadWeight_clicked();

    void on_btnZero_clicked();

    void on_btnTare_clicked();

    void on_btnOpen_pressed();

    void on_btnPreTare_clicked();

    void on_btnExitTare_clicked();

    void weightChanged(const ::OnePlusOneAndroidSDK::ScalesOS::WeightInfo* weightInfo);

private:
    OpoScaleSDK sdk;
    Ui::MainDialog *ui;
};

#endif // MAINDIALOG_H
