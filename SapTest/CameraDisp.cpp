#include "cameradisp.h"
#include <stdio.h>
#include <math.h>
//#include "PCOMM.H"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#define SPORT 8
int flag = 0;
using namespace std;

CameraDisp::CameraDisp(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags), frame_minusBack(IMAGE_WIDTH, IMAGE_HEIGHT, QImage::Format_RGB888),bound(BOUND_WIDTH, BOUND_HEIGHT, QImage::Format_ARGB32)
{
	ui.setupUi(this);
	initSap();
	if(!initSerialPort())
	{
		int a = 1;
		//exit(0);
	}
	threshold = 0.02;
	
	QObject::connect(this, SIGNAL(fireUpdateScreen()), this, SLOT(updateScreen()), Qt::QueuedConnection);
	//读取串口回来的消息
	QObject::connect(&this->m_serial, SIGNAL(readyRead()), this, SLOT(showData()));


	//frame.fill(Qt::black);
	frame_minusBack.fill(Qt::black);
	QPainter painter;
	//painter.begin(&frame);
	initRefRect();
	drawRef();

	needSend = false;

    //ui.video->setPixmap(QPixmap::fromImage(frame.scaled(ui.video->size().width(),ui.video->size().height(),Qt::IgnoreAspectRatio, Qt::FastTransformation)));
	ui.videoBack->setPixmap(QPixmap::fromImage(frame_minusBack.scaled(ui.videoBack->size().width(),ui.videoBack->size().height(),Qt::IgnoreAspectRatio, Qt::FastTransformation)));
	initDescrambling();
	initImgBigBuffer();
	ndToDisplay = true;
	ndToStandard = false;
	guiProtect.fetchAndStoreOrdered(0);
	for(int i = 0 ;i < 240 ; i++)
		for(int j = 0 ; j < 240 ; j++)
			backGround[i][j] = 1;
	udpSocket = new QUdpSocket(this);
	standardTimes = 0;
	    for (int i = 0 ; i < 480*3 ; i++)
	{
		da_data[2*i] = 0x20;
		da_data[2*i+1] = 0x67;
	}
	memset(da_data1,0x0,480*6*sizeof(unsigned char));

	//设置timerFlagProcessCommand 一次触发 50ms时间间隔
	//目的：不与更新温度的串口通信冲突
	timerFlagProcessCommand.setSingleShot(true);
	timerFlagProcessCommand.setInterval(100);
	ui.radioButton_m45->setChecked(true);

	m_udpSocket = new QUdpSocket(this);
	m_udpSocket->bind(95);
	//QString localIP = getlocalIP();
	//this->setWindowTitle(this->windowTitle() + "--IP" + localIP);

	//读取UDP回来的消息
	connect(m_udpSocket, SIGNAL(readyRead()),this, SLOT(onSocketReadyRead()));

	bound.fill(Qt::transparent);
	painter.begin(&bound);
	//painter.setBrush(QBrush(QColor(0xFF, 0xFF, 0xFF)));
	QColor orange(0xE6, 0x7E, 0x22);
	painter.setPen(QPen(orange, 2));
	painter.drawEllipse(QPoint(469, 469), 394, 394);
	painter.end();
	//ui.videoBack->setPixmap(QPixmap::fromImage(bound.scaled(ui.labBorder->size().width(), ui.labBorder->size().height()/*, Qt::IgnoreAspectRatio, Qt::FastTransformation*/), Qt::NoFormatConversion));
	ui.labBorder->setPixmap(QPixmap::fromImage(bound));
	ui.labBorder->repaint();

	flagSlider = false;
	flagSpin = false;
	for (int i = 0; i < 999; i++)
	{
		gainSpinArray[i] = i + 1;
		gainSliderArray[i] = int(sqrt(double(gainSpinArray[i]) / 1000) * 2000);
	}
	gainSliderArray[999] = 2000;


}

CameraDisp::~CameraDisp()
{
	exitSap();

}

//是否自动更新温度
void CameraDisp::on_checkUpdateTemp_toggled(bool tog)
{
	if (tog == true && m_serial.isOpen())
	{
		timerTemp.start(1000, this);
	}
	else
	{
		timerTemp.stop();
	}
}

//处理timer事件 更新温度信息
void CameraDisp::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timerTemp.timerId())
	{
		if (timerFlagProcessCommand.isActive() == false) //使温度更新的串口通信不与命令的串口通信冲突
		{
			QObject::disconnect(&this->m_serial, SIGNAL(readyRead()), this, SLOT(showData()));

			m_serial.write("temp\r");
			while (m_serial.waitForReadyRead(20));
			QByteArray data = m_serial.readAll();
			char* buffer = data.data();

			if (data.endsWith("Ok :") && buffer[0] == 'T')
			{
				extractTemp(buffer, Temp);
				ui.CCDTempValue->setText((QString::fromStdString(Temp[0])));
				ui.WaterTempValue->setText(QString::fromStdString(Temp[4]));

				memset(Temp, 0x00, 10 * sizeof(string));
			}
			else
			{
				while (m_serial.waitForReadyRead(10));
				QByteArray trash = m_serial.readAll();
			}

			QObject::connect(&this->m_serial, SIGNAL(readyRead()), this, SLOT(showData()));
		}
		
		//再次触发定时器 存疑：为啥需要触发两次
		timerTemp.start(1000, this);
	}
}

//从串口传回的字符串提取温度
void CameraDisp::extractTemp(char* str, string* Temp)
{
	int j = 0;
	int len = strlen(str);
	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] == '[')
		{
			for (i = i + 1; str[i] != ']'; i++)
			{
				Temp[j] += str[i];
			}
			j++;
		}
	}

}

void CameraDisp::initSap()
{
    SapLocation loc(1,0);
    try
    {
        SapAcq = new SapAcquisition(loc,"ocam2_sap.ccf");
        //SapBuffs = new SapBuffer(10,240,240,SapFormatMono8);
		SapBuffs = new SapBuffer(1,SapAcq);
        SapTfer= new SapAcqToBuf(SapAcq, SapBuffs, SapXferCb, this);
    }
    catch (std::exception& e)
    {
      exit (EXIT_FAILURE);
    }
    /* Trully initialize objects */
    bool success = SapAcq->Create();
    success = SapBuffs->Create();
    success = SapTfer->Create();
}

void CameraDisp::exitSap()
{
    if (SapTfer)
        SapTfer->Destroy();
    if (SapBuffs)
        SapBuffs->Destroy();
    if (SapAcq)
        SapAcq->Destroy();

    if (SapTfer)
    {
        delete SapTfer;
        SapTfer = NULL;
    }
    if (SapBuffs)
    {
        delete SapBuffs;
        SapBuffs = NULL;
    }
    if (SapAcq)
    {
        delete SapAcq;
        SapAcq = NULL;
    }

}

//遍历串口，寻找能够通信的串口
bool CameraDisp::initSerialPort()
{
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		m_serial.setPort(info);
		if (m_serial.open(QIODevice::ReadWrite))
		{
			m_serial.setBaudRate(QSerialPort::Baud115200);
			m_serial.setDataBits(QSerialPort::Data8);
			m_serial.setParity(QSerialPort::NoParity);
			m_serial.setStopBits(QSerialPort::OneStop);
			m_serial.write("\r");
			while (m_serial.waitForReadyRead(20));
			QByteArray buffer = m_serial.readAll();
			if (!buffer.isNull())
				return 1;
			else
				m_serial.close();
		}
	}
	return 0;

}

void CameraDisp::initDescrambling()
{
    QFile file;
    file.setFileName("ocam2_descrambling.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray fileContent = file.readAll();
    QList<QByteArray> vals = fileContent.split(',');
    foreach (QByteArray val , vals)
        dsbIdx.push_back(val.toInt());
    file.close();

}

void CameraDisp::descramble(short *image, short *imageRaw)
{
	int i = 0;
    for (i=0; i< 57600; i++)
    {
         image[i] = imageRaw[dsbIdx[i]];
    }
	printf("%d\n",i);

	printf("%d\n",dsbIdx[i]);
}

void CameraDisp::initImgBigBuffer()
{
    try
    {
        // memory allocated for elements of rows.
        BigImgBuffer = new short *[10];
        BigImgNum = new unsigned int [10];

        // memory allocated for  elements of each column.
        for( short i = 0 ; i < 10 ; i++ )
        {
            BigImgBuffer[i] = new short[PIXELS_IMAGE];
            memset(BigImgBuffer[i],0x0,PIXELS_IMAGE*sizeof(short));
        }
    }
    catch (std::exception& e)
    {
      exit (EXIT_FAILURE);
    }
}

void CameraDisp::clearImgBigBuffer()
{


    // free the allocated memory
    for( short i = 0 ; i < 10 ; i++ )
    {
        delete [] BigImgBuffer[i];
    }
    delete [] BigImgBuffer;
    delete [] BigImgNum;

    BigImgBuffer=NULL;
}

short CameraDisp::calStandardAvg(short *image,int i,int j)
{
	int sum = image[(10*i+2) * 240 + (10*j + 2)] + image[(10*i+2) * 240 + (10*j + 7)]+image[(10*i+7) * 240 + (10*j + 2)]+image[(10*i+7) * 240 + (10*j + 7)];
	return (short)(sum/4);
	
	
}
short CameraDisp::calStandardMedian(short *image,int i,int j)
{
	short data[4];
	data[0] = image[(10*i+2) * 240 + (10*j + 2)];
	data[1] = image[(10*i+2) * 240 + (10*j + 7)];
	data[2] = image[(10*i+7) * 240 + (10*j + 2)];
	data[3] = image[(10*i+7) * 240 + (10*j + 7)];
	int sum = 0, maxdata = 0;
	short mindata = 16384;

	for(int i = 0;i < 4; i++)
	{
		sum = sum + data[i];
		if(data[i] > maxdata)
			maxdata = data[i];
		if(data[i] < mindata)
			mindata = data[i];
	}

	return ((sum - mindata - maxdata)/2);
	//return maxdata;

}

short CameraDisp::calStandardSecond(short *image,int i,int j)
{
	QVector<short> data;
	data.push_back(image[(10*i+1) * 240 + (10*j + 4)]);
	data.push_back(image[(10*i+4) * 240 + (10*j + 1)]);
	data.push_back(image[(10*i+4) * 240 + (10*j + 9)]);
	data.push_back(image[(10*i+9) * 240 + (10*j + 4)]);
	qSort(data.begin(),data.end());
	return data[2];
	
}
void CameraDisp::minusBackGround(short *image,short *imageMinusBack)
{
	for(int i = 0 ; i < 24 ; i++)
		for(int j = 0 ; j < 24 ;j++)
		{
			//short standard = image[(10*i+2) * 240 + (10*j + 2)];
			short standardValue = calStandardMedian(image,i,j);
			for(int m = 10 * i; m < 10 * i +SUB_PIXELS ; m++)
				for(int n = 10 * j ; n < 10 * j + SUB_PIXELS ; n++)
				{
					imageMinusBack[m*240 + n] = image[m*240 + n] -  standardValue * backGround[m][n];
					if(imageMinusBack[m*240 + n] < threshold*16384)
						imageMinusBack[m*240 + n] = 0;
					if ((pow((float)(m - 125),2) + pow((float)(n - 125),2)) > 105*105)
						imageMinusBack[m*240 + n] = 0;
				}
		}
}
inline void CameraDisp::updateVideo()
{

    short *frm = BigImgBuffer[0];

	short *frm_back = BigImgBuffer[1];

	DWORD a = GetTickCount();
	

	for(int i = 0 ; i < PIXELS_IMAGE;i++)
	{
		if(frm[i] < (short)(0))
			frm[i] = (short)(0);
 	}
	minusBackGround(frm,frm_back);
	short maxImage = 0, maxBackground = 0;
	short minImage =16384,minBackground = 16384;
	for (int i = 0; i< PIXELS_IMAGE; i++)
	{
		if(frm[i] > maxImage)
			maxImage = frm[i];
		if(frm[i] < minImage)
			minImage = frm[i];
		if(frm_back[i] > maxBackground)
			maxBackground = frm_back[i];
		if(frm_back[i] < minBackground)
			minBackground = frm_back[i];
		maxValue = maxBackground;
		
		
	}
	short maxImage1 = 0, maxBackground1 = 0;
	short minImage1 =16384,minBackground1 = 16384;
	short subImage[10][10];
	for (int i = 80; i < 90; i++)
		for( int j = 130; j< 140; j++)
		{
			if(frm[i*240+j] > maxImage1)
				maxImage1 = frm[i*240+j];
			if(frm[i*240+j] < minImage1)
				minImage1 = frm[i*240+j];
			if(frm_back[i*240+j] > maxBackground1)
				maxBackground1 = frm_back[i*240+j];
			if(frm_back[i*240+j] < minBackground1)
				minBackground1 = frm_back[i*240+j];

			subImage[i-80][j-130] = frm_back[i*240+j];
		}

	
	QString str = QString::number(maxBackground);
	QString str_image = QString::number(maxImage);
    for (int pos = 0,i=0; i < PIXELS_IMAGE ;pos+=3,i++)
    {
        unsigned char PixRed = 0,PixGreen = 0,PixBlue = 0;
		unsigned char BPixRed = 0,BPixGreen = 0,BPixBlue = 0;
        short RawPixel = frm[i];
		short RawBackGroundPixel = frm_back[i];
		if(RawPixel < 0)
			RawPixel = 0;
		BPixRed = BPixGreen = BPixBlue = (unsigned char) (( (float)(RawBackGroundPixel-minBackground) /(maxBackground - minBackground) * 255));
		PixRed = PixGreen = PixBlue = (unsigned char) (( (float)(RawPixel - minImage) / (maxImage - minImage) * 255));
        //frame.bits()[pos]   = PixRed;
        //frame.bits()[pos+1] = PixGreen;
        //frame.bits()[pos+2] = PixBlue;

		frame_minusBack.bits()[pos]   = BPixRed;
		frame_minusBack.bits()[pos+1] = BPixGreen;
		frame_minusBack.bits()[pos+2] = BPixBlue;

    }
	drawRef();
	//ui.video->setPixmap(QPixmap::fromImage(frame.scaled(ui.video->size().width(),ui.video->size().height(),Qt::IgnoreAspectRatio, Qt::FastTransformation)));
	ui.videoBack->setPixmap(QPixmap::fromImage(frame_minusBack.scaled(ui.videoBack->size().width(),ui.videoBack->size().height(),Qt::IgnoreAspectRatio, Qt::FastTransformation)));
    //ui.video->repaint();
	ui.videoBack->repaint();
	ui.label->setText(str);
	ui.image->setText(str_image);
}

void CameraDisp::SapXferCb(SapXferCallbackInfo *pInfo)
{
		 CameraDisp *main = (CameraDisp *) pInfo->GetContext();
		 main->needSend = true;
		 short *pSapBuff;
		 main->SapBuffs->GetAddress((void**)&pSapBuff);

		 if(main->ndToStandard)
		 {
			 main->ndToStandard = false;
			 if(main->standardTimes == 0)
			 {
				 main->resetBackGroundZero();
			 }
			//main->descramble(main->BigImgBuffer[0],pSapBuff);
			//main->standard(main->BigImgBuffer[0]);
			main->descramble(main->standardImage,pSapBuff);
			main->standard(main->standardImage);
			main->SapBuffs->ReleaseAddress(pSapBuff);
			if (main->standardTimes < 10)
			{
				main->ndToStandard = true;
				main->standardTimes++;
			}
			else
			{
				main->avgBackGround();
				main->ndToStandard = false;
				main->standardTimes = 0;
			}			
		 }
		 else{
		 if(main->ndToDisplay == true)
		 {
			 main->descramble(main->BigImgBuffer[0],pSapBuff);
			 main->descramble(main->standardImage,pSapBuff);
			 main->ndToDisplay = false;
			 main->SapBuffs->ReleaseAddress(pSapBuff);
			 main->emitFireUpDateScreen();
		 }
		 }
}

void CameraDisp::on_btnStartAndStop_clicked()
{
	if (ui.btnStartAndStop->text() == QStringLiteral("启动"))
	{
		ui.btnStartAndStop->setText(QStringLiteral("停止"));
		
		
		ui.saveRawButton->setEnabled(false);
		ui.saveProcessButton->setEnabled(false);
		SapTfer->Grab();
	}
	else
	{
		ui.btnStartAndStop->setText(QStringLiteral("启动"));
		
		ui.saveRawButton->setEnabled(true);
		ui.saveProcessButton->setEnabled(true);
		SapTfer->Freeze();
	}
}

void CameraDisp::updateScreen()
{
	updateVideo();
	ndToDisplay = true;
    guiProtect.fetchAndStoreOrdered(0);
}
void CameraDisp::emitFireUpDateScreen()
{
    if (guiProtect.testAndSetOrdered(0,1))
        emit fireUpdateScreen();
}

void CameraDisp::on_startStandard_clicked()
{
	ndToStandard = true;
}

void CameraDisp::standard(short *image)
{
	ndToStandard = false;
	bool belowZero = false;
	for (int i = 0 ; i < PIXELS_IMAGE ; i++)
	{
		if(image[i] <= 0)
		{
			image[i] = 1;
			belowZero = true;
		}
	}
	if(belowZero)
	{
	    //QMessageBox::warning(this, "Error","below zero PIXEL! ");
		//ndToStandard = true;
	}
	//else
	{
		for(int i = 0 ; i < 24 ; i++)
		for(int j = 0 ; j < 24 ;j++)
		{
			//short standardData = image[(10*i+2) * 240 + (10*j + 2)];
			short standardData = calStandardMedian(image,i,j);
			for(int m = 10 * i; m < 10 * i +SUB_PIXELS ; m++)
				for(int n = 10 * j ; n < 10 * j + SUB_PIXELS ; n++)
				{
					backGround[m][n] += image[m*240 + n] / (standardData + 0.0000000001);
				}
		}
	}
}

void CameraDisp::resetBackGround()
{
		for(int i = 0 ;i < 240 ; i++)
		for(int j = 0 ; j < 240 ; j++)
			backGround[i][j] = 1;
}

void CameraDisp::resetBackGroundZero()
{
	for(int i = 0 ;i < 240 ; i++)
		for(int j = 0 ; j < 240 ; j++)
			backGround[i][j] = 0;
}

void CameraDisp::avgBackGround()
{
	for(int i = 0 ;i < 240 ; i++)
		for(int j = 0 ; j < 240 ; j++)
		{
			backGround[i][j] = backGround[i][j] / 10;
			if(backGround[i][j] < 1)
			{
				backGround[i][j] = 1;
			}
			if(backGround[i][j] > 3.5)
			{
				backGround[i][j] = 3.5;
			}
		}
	/*for(int i = 0 ; i < 240 ; i++)
		for(int j = 0 ; j < 240 ;j++)
		{
			backGround[i][j] = backGround[110+i%10][90+j%10];
		}*/
}
void CameraDisp::on_resetBack_clicked()
{
	resetBackGround();
}

void CameraDisp::on_slider_valueChanged(int value)
{
	if(value > 0 && value < 5000)
	{
		threshold = (float)(value / 16384.0);
	}
}

void CameraDisp::on_btnStartCalibarate_clicked()
{
	ui.btnStartCalibarate->setEnabled(false);
	ui.btnStopCalibarate->setEnabled(true);

	char command[3];
	command[0] = 's';
	command[1] = (unsigned char)((int)(threshold * 16384) / 256);
	command[2] = (unsigned char)((int)(threshold * 16384) % 256);

	QByteArray msg = QByteArray(command);
	m_udpSocket->writeDatagram(msg, QHostAddress("102.85.68.34"), 57346);

	/*
	char command[3];
	command[0] = 's';
	command[1] = (unsigned char)((int)(threshold * 16384) / 256);
	command[2] = (unsigned char)((int)(threshold * 16384) % 256);
	udpSocket->writeDatagram(command,3,QHostAddress("102.85.68.101"),57346);

	char bg_data[480];

	for(int i = 0 ; i < 240 ;i++)
	{
		for(int j = 0 ; j < 240 ; j++)
		{
			bg_data[2*j] = (unsigned char)((int)(backGround[i][j] * 16384) / 256);
			bg_data[2*j+1] = (unsigned char)((int)(backGround[i][j] * 16384) % 256);
		}
		udpSocket->writeDatagram(bg_data,480,QHostAddress("102.85.68.101"),57346);
	}
	*/
}


void CameraDisp::on_btnStopCalibarate_clicked()
{
	ui.btnStopCalibarate->setEnabled(false);
	ui.btnStartCalibarate->setEnabled(true);
	
	if (ui.checkIfHold->isChecked())
	{
		char command[3];
		command[0] = 'q';
		command[1] = 'h';
		command[2] = 0;


		QByteArray msg = QByteArray(command);
		m_udpSocket->writeDatagram(msg, QHostAddress("102.85.68.34"), 57346);
	}
	else
	{
		char command[3];
		command[0] = 'q';
		command[1] = 'a';
		command[2] = 0;

		QByteArray msg = QByteArray(command);
		m_udpSocket->writeDatagram(msg, QHostAddress("102.85.68.34"), 57346);
	}


	/*
	char command[3];
	command[0] = 'q';
	command[1] = (unsigned char)(((threshold * 16384) / 256));
	command[2] = (unsigned char)((int)(threshold * 16384) % 256);
	udpSocket->writeDatagram(command,3,QHostAddress("102.85.68.101"),57346);
	*/
}

void CameraDisp::drawRef()
{
	/*
	painter.begin(&frame);
	QPen pen(Qt::green,0.1);
	painter.setPen(pen);
	painter.drawRects(refRects);

	painter.setPen(QPen(Qt::red,0.1));
	painter.drawEllipse(QPoint(123,123),108,108);
	//painter.drawEllipse(QPoint(125,125),25,25);
	painter.end();
	*/
	
	painter.begin(&frame_minusBack);
	painter.setPen(QPen(Qt::yellow,0.1));
	painter.drawRects(refRects);

	//painter.setPen(QPen(Qt::red,0.1));
	//painter.drawEllipse(QPoint(125,125),105,105);
	//painter.drawEllipse(QPoint(125,125),25,25);

	painter.end();
	

}


void CameraDisp::initRefRect()
{
	/*
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 40; j++)
		{
			int distance = pow((float)(6 * i + 3 - 123), 2) + pow((float)(6 * j + 3 - 123), 2);
			if (distance < 108 * 108 )
			{
				QRect rect(6 * i, 6 * j, 6, 6);
				refRects.push_back(rect);
			}
		}
	*/
	
	for(int i = 0; i < 24; i++)
		for(int j = 0; j < 24 ; j++)
		{
			int distance = pow((float)(10*i+5 - 125),2) + pow((float)(10*j+5 - 125),2);
			if(distance < 105*105 /*&& distance > 25*25*/)
			{
				QRect rect(10*i,10*j,10,10);
				refRects.push_back(rect);
			}
		}
	
}

//设置帧率
void CameraDisp::on_frameSetButton_clicked()
{

	QString strFrame = ui.frameSpinBox->text();
	QString command = "fps " + strFrame + "\r";
	m_serial.write(command.toLatin1());

}

void CameraDisp::on_frameButton_1000_toggled(bool tog)
{

	if(tog == true)
	{
		m_serial.write("fps 1000\r");
		timerFlagProcessCommand.start();
	}

}

void CameraDisp::on_frameButton_2000_toggled(bool tog)
{

	if(tog == true)
	{
		m_serial.write("fps 2000\r");
		timerFlagProcessCommand.start();
	}

}

void CameraDisp::on_frameButton_1500_toggled(bool tog)
{

	if(tog == true)
	{
		m_serial.write("fps 1500\r");
		timerFlagProcessCommand.start();
	}

}

void CameraDisp::on_frameButton_300_toggled(bool tog)
{

	if(tog == true)
	{
		m_serial.write("fps 300\r");
		timerFlagProcessCommand.start();
	}

}

void CameraDisp::on_frameButton_500_toggled(bool tog)
{

	if(tog == true)
	{
		m_serial.write("fps 500\r");
		timerFlagProcessCommand.start();
	}

}

void CameraDisp::on_frameButton_800_toggled(bool tog)
{

	if(tog == true)
	{
		m_serial.write("fps 800\r");
		timerFlagProcessCommand.start();
	}

}

//设置增益
void  CameraDisp::on_btnSetGain_clicked()
{
	//int gain = ui.gainSlider->value();

	int gain = ui.spinBox_2->value();
	if (gain > 0 && gain < 999)
	{
		QString strGain, command;
		strGain = strGain.setNum(gain);
		command = "gain " + strGain + "\r";

		m_serial.write(command.toLatin1());
		timerFlagProcessCommand.start();

	}

}

void CameraDisp::on_gainSlider_valueChanged(int gainSlider)
{
	if (gainSlider < gainSliderArray[0])
		ui.spinBox_2->setValue(1);
	for (int i = 0; i < 999; i++)
	{
		if ((gainSlider >= gainSliderArray[i]) && (gainSlider < gainSliderArray[i + 1]))
		{
			ui.spinBox_2->setValue(gainSpinArray[i]);
			break;
		}
	}

	//ui.spinBox_2->setValue(gainSpinTrue);


}

void CameraDisp::on_spinBox_2_valueChanged(int gainSpin)
{

	ui.gainSlider->setValue(gainSliderArray[gainSpin - 1]);

}


//设置增益复位
void CameraDisp::on_gainResetButton_clicked()
{
	m_serial.write("protection reset\r");
	timerFlagProcessCommand.start();

}

//设置制冷温度
void CameraDisp::on_radioButton_20_toggled(bool tog)
{
	if(tog == true)
	{
		m_serial.write("cooling 20\r");
		timerFlagProcessCommand.start();
	}
}

void CameraDisp::on_radioButton_m30_toggled(bool tog)
{
	if(tog == true)
	{
		m_serial.write("cooling -30\r");
		timerFlagProcessCommand.start();
	}
}

void CameraDisp::on_radioButton_m45_toggled(bool tog)
{
	if(tog == true)
	{

		m_serial.write("cooling -45\r");
		timerFlagProcessCommand.start();
		flag = 1;
	}
}

//设置bias
void CameraDisp::on_bias_toggled(bool tog)
{
	char trash[500];

	if(tog == true)
	{
		m_serial.write("bias on\r");
		timerFlagProcessCommand.start();
	}
	else
	{
		m_serial.write("bias off\r");
		timerFlagProcessCommand.start();
	}
}


void CameraDisp::on_saveBackButton_clicked()
{
	QFile file(getFileName());
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream out(&file);
		//out.setByteOrder(QDataStream::LittleEndian);
		for(int i = 0 ; i < 240 ; i++)
		{
			for(int j = 0 ; j < 240 ; j++)
			{
				out << backGround[i][j] <<" ";
			}
			out << "\n";
		}
		file.close();
	}
	else
	{
		QMessageBox::warning(this,"Error","Cannot Open file");
	}
}

void CameraDisp::on_saveProcessButton_clicked()
{
	QFile file(getFileName());
	if(file.open(QIODevice::WriteOnly))
	{
		QDataStream out(&file);
		out.setByteOrder(QDataStream::LittleEndian);
		for(int i = 0 ; i < PIXELS_IMAGE ; i++)
		{
			out<<BigImgBuffer[1][i];
		}
		file.close();
	}
	else
	{
		QMessageBox::warning(this,"Error","Cannot Open file");
	}

}

void CameraDisp::on_saveRawButton_clicked()
{
	QFile file(getFileName());
	if(file.open(QIODevice::WriteOnly))
	{
		QDataStream out(&file);
		out.setByteOrder(QDataStream::LittleEndian);
		for(int i = 0 ; i < PIXELS_IMAGE ; i++)
		{
			out<<BigImgBuffer[0][i];
		}
		file.close();
	}
	else
	{
		QMessageBox::warning(this,"Error","Cannot Open file");
	}
}

QString CameraDisp::getFileName()
{
	QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),tr("D:\data"),tr("Raw files (*.raw);;All files (*)"));

	if(!fileName.isEmpty())
	{
		if(QFileInfo(fileName).suffix().isEmpty())
			fileName.append(".raw");
	}
	return fileName;
}


//通过串口向相机发送命令后 会有消息返回 显示返回的消息的槽函数
void CameraDisp::showData()
{
	QByteArray data = m_serial.readAll();
	m_callbackToShow += data;

	if (data.endsWith("Ok :")) //存在消息不完整的情况，可能连续调用该槽函数
	{

		m_callbackToShow = m_callbackToShow.section('\n', 0, 0);
		if (data.startsWith("Cooling"))
		{
			m_callbackToShow = m_callbackToShow.left(m_callbackToShow.length() - 3);
		}
		ui.stateShow->appendPlainText(m_callbackToShow);
		m_callbackToShow.clear();
	}
	else
	{
		timerFlagProcessCommand.start();
	}
}

void CameraDisp::on_btnKeepIntensity_clicked()
{
	QString str = ui.btnKeepIntensity->text();
	if (ui.btnKeepIntensity->text() == QStringLiteral("自动增益"))
	{
		ui.btnKeepIntensity->setText(QStringLiteral("取消"));
		tempFrameEnable(false);
		QObject::disconnect(&this->m_serial, SIGNAL(readyRead()), this, SLOT(showData()));
		timerTemp.stop();
		timerFlagProcessCommand.stop();

		short idealIntensity = 4915;



	}
	else
	{
		ui.btnKeepIntensity->setText(QStringLiteral("自动增益"));
		tempFrameEnable(true);
	}



}

void CameraDisp::tempFrameEnable(bool state)
{
	ui.radioButton_20->setEnabled(state);
	ui.radioButton_m30->setEnabled(state);
	ui.radioButton_m45->setEnabled(state);

	ui.frameButton_300->setEnabled(state);
	ui.frameButton_500->setEnabled(state);
	ui.frameButton_800->setEnabled(state);
	ui.frameButton_1000->setEnabled(state);
	ui.frameButton_1500->setEnabled(state);
	ui.frameButton_2000->setEnabled(state);
	ui.frameSpinBox->setEnabled(state);
	ui.frameSetButton->setEnabled(state);

	ui.gainSlider->setEnabled(state);
	ui.btnSetGain->setEnabled(state);
	ui.spinBox_2->setEnabled(state);
	ui.gainResetButton->setEnabled(state);
}


void CameraDisp::on_btnStartVol_clicked()
{
	aMirror.setChanelVoltage(singleChannel, singleVoltage);
}
void CameraDisp::on_spinChannelNum_valueChanged(int channel)
{
	singleChannel = channel;
}
void CameraDisp::on_spinSingleVol_valueChanged(double vol)
{
	singleVoltage = float(vol);
}


void CameraDisp::on_spinAllVol_valueChanged(double vol)
{
	allVoltage = float(vol);
}
void CameraDisp::on_btnSetAll_clicked()
{
	aMirror.setAllVoltage(allVoltage);
}

void CameraDisp::on_btnDMtest_clicked()
{
	aMirror.resetDMWork();
}
void CameraDisp::on_btnInitDM_clicked()
{
	aMirror.initDM();
}
void CameraDisp::on_btnShutDM_clicked()
{
	aMirror.shutDownDM();
}
void CameraDisp::on_btnResetDM_clicked()
{
	aMirror.resetDMWork();
}

void CameraDisp::updateZernike()
{
	if (datacenter == NULL)
		datacenter = new float[2 * NUMTOTAL_SUB];
	aCal.calCenter(BigImgBuffer[0], datacenter,aCal.defaultMask);
	calCenterMean();
 }

void CameraDisp::calCenterMean()
{
	int dataLength = aCal.validSubNum;
	xCenterMean = 0;
	yCenterMean = 0;
	for (int i = 0; i < dataLength; i++)
	{
		xCenterMean += datacenter[i];
		yCenterMean += datacenter[i + dataLength];
	}
	xCenterMean = xCenterMean / dataLength;
	yCenterMean = yCenterMean / dataLength;
}

void CameraDisp::on_sliderDmIntPara_valueChanged(int DmIntPara)
{
	ui.dspinDmIntPara->setValue(double(DmIntPara) / 100);
}

void CameraDisp::on_sliderFsmIntPara_valueChanged(int FsmIntPara)
{
	ui.dspinFsmIntPara->setValue(double(FsmIntPara) / 100);
}

void CameraDisp::on_btnDmIntPara_clicked()
{

}

void CameraDisp::on_btnFsmIntPara_clicked()
{

}

void CameraDisp::on_btnStartStandard_clicked()
{

}

void CameraDisp::on_btnStopStandard_clicked()
{

}