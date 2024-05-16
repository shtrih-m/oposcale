#include <QThread>
#include <QDateTime>
#include "Slpa100uProtocol.h"
#include "IO\iocom.h"
#include "IO\iohttp.h"

QByteArray &operator<<(QByteArray &l, quint8 r) { l.append(r); return l; }
QByteArray &operator<<(QByteArray &l, quint16 r) { return l<<quint8(r)<<quint8(r>>8); }
QByteArray &operator<<(QByteArray &l, qint32 r) { return l<<quint16(r)<<quint16(r>>16); }

Slpa100uProtocol::Slpa100uProtocol(QObject *parent)
    : QObject{parent}
{
}

int Slpa100uProtocol::open(const QString &uri)
{
    close();
    if (IoCom::checkUri(uri)) io = new IoCom(this);
    else if (IoHttp::checkUri(uri)) io = new IoHttp(this);
    else return -11;
    if (!io->open(uri)) return io->error;
    return 0;
}

void Slpa100uProtocol::close()
{
    lastStatus = {0, 0, 0, 0, 0, 0, 0, 0};
    if (io != nullptr) delete io;
    io = nullptr;
}

int Slpa100uProtocol::cFeed(prnanswer *status)
{
    return command(cmFeed, status);
}

int Slpa100uProtocol::cBufferSize(const uint16_t value)
{
    QByteArray out;
    out << value;
    labelLength = value;
    return command(cmBufferSize, out);
}

int Slpa100uProtocol::cBufferData(const QByteArray &line)
{
    QByteArray out(line);
    int n = (getPrinterVersion() >= 0x0300) ? 56 : 54;
    if (out.size() < n) out += QByteArray(n-out.size(), 0x00);
    else if (out.size() > n) out.resize(n);
    return command(cmBufferData, out);
}

int Slpa100uProtocol::cClearBuffer()
{
    return command(cmClearBuffer);
}

int Slpa100uProtocol::cPrint(prnanswer *status)
{
    return command(cmPrint, status);
}

int Slpa100uProtocol::cGetStatus(prnanswer *status, const int isPE)
{
    emit showMessage(QString("cGetStatus"));
    QByteArray out;
    out << static_cast<uint8_t>(isPE);
    int res = command(cmGetStatus, out, status);
    if (res == 0) lastStatus = *status;
    return res;
}

int Slpa100uProtocol::cSetBrightness(const uint8_t value)
{
    QByteArray out;
    out << value;
    return command(cmSetBrightness, out);
}

int Slpa100uProtocol::cSetOffset(const uint8_t value)
{
    QByteArray out;
    out << value;
    return command(cmSetOffset, out);
}

int Slpa100uProtocol::cSetPaperType(const papertype value)
{
    QByteArray out;
    out << value;
    return command(cmSetPaperType, out);
}

int Slpa100uProtocol::cSensorControl(const bool value)
{
    QByteArray out;
    uint8_t c = (value)?1:0;
    out << c;
    return command(cmSensorControl, out);
}

int Slpa100uProtocol::cReset()
{
    return command(cmReset);
}

int Slpa100uProtocol::cSetOffset2(const uint8_t value)
{
    QByteArray out;
    out << value;
    return command(cmSetOffset2, out);
}

int Slpa100uProtocol::cGetOffset2(uint8_t *value)
{
    prnanswer status;
    int res = command(cmGetOffset2, &status);
    if (res == 0) *value = status.brightness;
    return res;
}

int Slpa100uProtocol::cGetVersion(uint8_t *versionH, uint8_t *versionL)
{
    if (!io) return -20;
    *versionH = lastStatus.versionH;
    *versionL = lastStatus.versionL;
    return 0;
}

int Slpa100uProtocol::cGetPE(uint8_t *value)
{
    prnanswer status;
    int res = command(cmGetPE, &status);
    if (res == 0) *value = status.PE;
    return res;
}

int Slpa100uProtocol::cGetLAB(uint8_t *value)
{
    prnanswer status;
    int res = command(cmGetLAB, &status);
    if (res == 0) *value = status.LAB;
    return res;
}

int Slpa100uProtocol::cMemoryTest(memorytest *test)
{
    return command(cmMemoryTest, test);
}

int Slpa100uProtocol::cPrintTest(const uint16_t lines, prnanswer *status)
{
    QByteArray out;
    out << lines;
    testLength = lines;
    return command(cmPrintTest, out, status);
}

int Slpa100uProtocol::cErrorCnt(counters *cnt)
{
    return command(cmErrorCnt, cnt);
}

int Slpa100uProtocol::cResetCnt(counters *cnt)
{
    return command(cmResetCnt, cnt);
}

int Slpa100uProtocol::cProtectionCnt(counters *cnt)
{
    return command(cmProtectionCnt, cnt);
}

int Slpa100uProtocol::cProtectionMode(const bool value)
{
    QByteArray out;
    uint8_t c = (value)?1:0;
    out << c;
    return command(cmProtectionMode, out);
}

int Slpa100uProtocol::getPrinterVersion()
{
    return lastStatus.versionH * 256 + lastStatus.versionL;
}

Slpa100uProtocol::deviceinterface Slpa100uProtocol::getInterface()
{
    return deviceInterface;
}

int Slpa100uProtocol::command(prncommand cmd, const QByteArray &out, QByteArray &in)
{
    int res = 0;
    //if (QDateTime::currentMSecsSinceEpoch() < delayTill) res = -17;
    if (!res) res = executeCommand(cmd, out, in);
    setDelay(cmd, res);
    QByteArray ba(9,0);
    QByteArrayView bav(ba);
    if (((res == -13 && in.contains(bav)) || res == -4) && QDateTime::currentMSecsSinceEpoch() < delayTill)
    {
        if (cmd == cmGetStatus)
        {
            in = statusToByteArray(lastStatus);
            res = 0;
        }
        else res = -17;
    }
    return res;
}

int Slpa100uProtocol::command(prncommand cmd, const QByteArray &out, prnanswer *ans)
{
    QByteArray in;
    int res = command(cmd, out, in);
    if (res >=0 && ans != nullptr) {
        QDataStream ds(in);
        ds.setByteOrder(QDataStream::LittleEndian);
        ds >> ans->printerStatus >> ans->versionH >> ans->versionL >> ans->PE >> ans->LAB >> ans->TM >> ans->RUL >> ans->brightness;
    }
    return res;
}

int Slpa100uProtocol::command(prncommand cmd, const QByteArray &out)
{
    QByteArray in;
    return command(cmd, out, in);
}

int Slpa100uProtocol::command(prncommand cmd, prnanswer *ans)
{
    QByteArray out, in;
    int res = command(cmd, out, in);
    if (res >= 0 && ans != nullptr) {
        QDataStream ds(in);
        ds.setByteOrder(QDataStream::LittleEndian);
        ds >> ans->printerStatus >> ans->versionH >> ans->versionL >> ans->PE >> ans->LAB >> ans->TM >> ans->RUL >> ans->brightness;
    }
    return res;
}

int Slpa100uProtocol::command(prncommand cmd, memorytest *ans)
{
    QByteArray out, in;
    int res = command(cmd, out, in);
    if (res >=0 ) {
        QDataStream ds(in);
        ds.setByteOrder(QDataStream::LittleEndian);
        ds >> ans->address >> ans->readByte >> ans->expectedByte >> ans->reserved1 >> ans->reserved2 >> ans->reserved3;
    }
    return res;
}

int Slpa100uProtocol::command(prncommand cmd, counters *ans)
{
    QByteArray out, in;
    int res = command(cmd, out, in);
    if (res >=0 ) {
        QDataStream ds(in);
        ds.setByteOrder(QDataStream::LittleEndian);
        ds >> ans->c1 >> ans->c2 >> ans->c3 >> ans->c4 >> ans->reserved1;
    }
    return res;
}

void Slpa100uProtocol::setDelay(prncommand cmd, const int res)
{
    if (res>=0 && (cmd == cmFeed || cmd == cmPrint || cmd == cmPrintTest)) delayTill = QDateTime::currentMSecsSinceEpoch() + 2000/*labelLength*12*/;
}

QByteArray Slpa100uProtocol::statusToByteArray(const prnanswer &st)
{
    QByteArray arr;
    arr << st.printerStatus << st.versionH << st.versionL << st.PE << st.LAB << st.TM << st.RUL << st.brightness;
    return arr;
}
