#ifndef DMIRROR_H
#define DMIRROR_H
#define ELEMENTNUM 349
#define PACKAGENUM 2
#define PACKAGELENGTH 480
#include <QVector>
#include <QUdpSocket>
#include <QMessageBox>
#include <QFile>
#include <windows.h>
class DMirror
{
public:
    DMirror();
    bool setChanelVoltage(int channel,float voltage);
	bool setChannelVoltageSingle(int channel, float voltage);
    bool setAllVoltage(float voltage);
    bool resetDMWork();
    bool resetDMZero();
    bool initDM();
    bool shutDownDM();
private:
    QVector<int> chanelList;
    void getChannelList();
    unsigned char data[PACKAGELENGTH*PACKAGENUM];
    float daValue[ELEMENTNUM];
    float flatDaValue[ELEMENTNUM];
    QUdpSocket *udpSocket;
    int m_DaPort;
    int m_MyPort;

    int sendDA();
    QHostAddress da_address1;
    QHostAddress da_address2;
    //QHostAddress da_address3;
    //QHostAddress da_address4;
    //QHostAddress da_address5;
    //QHostAddress da_address6;

};

#endif // DMIRROR_H
