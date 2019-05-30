#include "dmirror.h"

DMirror::DMirror() : m_DaPort(1200),m_MyPort(57346)
{
    memset(data,0x0,PACKAGELENGTH*PACKAGENUM*sizeof(unsigned char));
	for (int i = 0; i < ELEMENTNUM; i++)
	{
		daValue[i] = -1;
	}
    getChannelList();
    udpSocket = new QUdpSocket();
    da_address1 = QHostAddress("102.85.68.65");
    da_address2 = QHostAddress("102.85.68.66");
    //da_address3 = QHostAddress("102.85.68.64");
    //da_address4 = QHostAddress("102.85.68.63");
    //da_address5 = QHostAddress("102.85.68.66");
    //da_address6 = QHostAddress("102.85.68.65");
}

void DMirror::getChannelList()
{
    QFile file;
    file.setFileName("dm-config.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(NULL, "Channel List not exist", "Error");
        //exit(0);
    }
    else
    {
        QByteArray fileContent = file.readAll();
        QList<QByteArray> vals = fileContent.split('\n');
        foreach (QByteArray val, vals) {
            chanelList.push_back(val.toInt());
        }
    }
}

int DMirror::sendDA()
{
    for (int i = 0 ; i < ELEMENTNUM ; i++)
    {
        float daTemp = 0.5 * (1 + daValue[i]) * 16590;
        data[chanelList[i]*2-2] = (uchar)(daTemp / 256);
        data[chanelList[i]*2-1] = (uchar)(fmod(daTemp,256));
    }
    udpSocket->writeDatagram((char*)(data),480,da_address1,m_DaPort);
    udpSocket->writeDatagram((char*)(data+480),480,da_address2,m_DaPort);
    //udpSocket->writeDatagram((char*)(data+480*2),480,da_address3,m_DaPort);
    //udpSocket->writeDatagram((char*)(data+480*3),480,da_address4,m_DaPort);
    //udpSocket->writeDatagram((char*)(data+480*4),480,da_address5,m_DaPort);
    //udpSocket->writeDatagram((char*)(data+480*5),480,da_address6,m_DaPort);
	return 1;
}


bool DMirror::setChanelVoltage(int channel, float voltage)
{
    bool result = false;
    if(channel < 0 || channel > ELEMENTNUM)
        return result;
    if(voltage > 1 || voltage < -1)
        return result;
    daValue[channel-1] = voltage;
    sendDA();
    return true;
}

bool DMirror::setChannelVoltageSingle(int channel, float voltage)
{
	bool result = false;
	if (channel < 0 || channel > ELEMENTNUM)
		return result;
	if (voltage > 1 || voltage < -1)
		return result;
	for (int i = 0; i < ELEMENTNUM; i++)
	{
		daValue[i] = 0;
	}
	daValue[channel] = voltage;
	sendDA();
	return true;
}

bool DMirror::setAllVoltage(float voltage)
{
    if(voltage >= -1 && voltage <= 1)
    {
        for (int i = 0 ; i < ELEMENTNUM ; i++)
        {
            daValue[i] = voltage;
        }
        sendDA();
        return true;
    }
    else
        return false;
}

bool DMirror::resetDMWork()
{
    return(setAllVoltage(0));
}
bool DMirror::resetDMZero()
{
    return (setAllVoltage(-1));
}

bool DMirror::initDM()
{
//    int delayTime = 1000;
    for (int i = 10 ; i >= 0 ; i--)
    {
        float nowDAValue = -i / 10.0;
        setAllVoltage(nowDAValue);
        Sleep(1000);
//        QTime dieTime = QTime::currentTime().addMSecs(delayTime);
//        while( QTime::currentTime() < dieTime )
//          QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
	return true;
}

bool DMirror::shutDownDM()
{
//    int delayTime = 1000;
    for (int i = 0 ; i <= 10 ; i++)
    {
        float nowDAValue = -i / 10.0;
        setAllVoltage(nowDAValue);
        Sleep(1000);
//        QTime dieTime = QTime::currentTime().addMSecs(delayTime);
//        while( QTime::currentTime() < dieTime )
//          QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
	return true;
}
