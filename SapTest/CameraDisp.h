#ifndef CAMERADISP_H
#define CAMERADISP_H

#include <QtWidgets/QMainWindow>
#include "ui_cameradisp.h"
#include <QAtomicInt>
#include <QFile>
#include "SapClassBasic.h"
#include <QUdpSocket>
#include <QPainter>
#include <string>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QBasicTimer>
#include <QTimer>
#include <QHostInfo>
#include "dmirror.h"
#include  "centercal.h"
using namespace std;

int const PIXEL_MAX_VAL = 16383; /* 2^14 */
int const PIXEL_MIN_VAL = -16384; /* - 2^14 */
int const CIRCULAR_BUFFER = 6000;
int const IMAGE_WIDTH_NORMAL  = 240;      /* 16bit witdth*/
int const IMAGE_HEIGHT_NORMAL = 240;      /* 16bit witdth*/

int const BOUND_WIDTH_NORMAL = 900;
int const BOUND_HEIGHT_NORMAL = 900;

int const PIXELS_IMAGE_NORMAL = IMAGE_WIDTH_NORMAL*IMAGE_HEIGHT_NORMAL; //57600 pixels(16bit witdth) per image area (240x240)

#define IMAGE_WIDTH         IMAGE_WIDTH_NORMAL
#define IMAGE_HEIGHT        IMAGE_HEIGHT_NORMAL

#define BOUND_WIDTH			BOUND_WIDTH_NORMAL
#define BOUND_HEIGHT		BOUND_HEIGHT_NORMAL

#define PIXELS_IMAGE        PIXELS_IMAGE_NORMAL
#define IMAGE_WIDTH_RAW     IMAGE_WIDTH_RAW_NORMAL
#define IMAGE_HEIGHT_RAW    IMAGE_HEIGHT_RAW_NORMAL
#define PIXELS_RAW          PIXELS_RAW_NORMAL

#define SUB_PIXELS 10
#define NUMTOTAL_SUB 576

#ifndef IMAGE_NB_OFFSET
#define IMAGE_NB_OFFSET 8 /* Offset of image number in raw image (bytes)*/
#endif
#define IMAGE_NB_SZ 4
class CameraDisp : public QMainWindow
{
	Q_OBJECT                                              

public:
	CameraDisp(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~CameraDisp();
	bool needSend;
	void sendData();
	void extractTemp(char* str, string* Temp);
	string Temp[10];

signals:
    void fireUpdateScreen();
private slots:
	void on_btnStartAndStop_clicked();
	

	void updateScreen();
	void on_startStandard_clicked();

	void on_resetBack_clicked();
	
	void on_btnStartCalibarate_clicked();
	void on_btnStopCalibarate_clicked();

	
	void on_slider_valueChanged(int value);

	void on_radioButton_20_toggled(bool tog);
	void on_radioButton_m30_toggled(bool tog);
	void on_radioButton_m45_toggled(bool tog);// cooling set

	void on_frameSetButton_clicked();
	void on_frameButton_300_toggled(bool tog);
	void on_frameButton_500_toggled(bool tog);
	void on_frameButton_800_toggled(bool tog);
	void on_frameButton_1000_toggled(bool tog);
	void on_frameButton_2000_toggled(bool tog);
	void on_frameButton_1500_toggled(bool tog);// frame setting

	void on_gainResetButton_clicked();         // gain setting

	void on_bias_toggled(bool tog);//bias setting

	

	void on_saveRawButton_clicked();//save raw unprocessed image
	void on_saveProcessButton_clicked();//save processed image
	void on_saveBackButton_clicked();//save Background image
	void showData();

	void on_btnSetGain_clicked(); //设置增益
	void on_checkUpdateTemp_toggled(bool tog); //设置温度自动更新


	void on_btnStartVol_clicked();
	void on_spinChannelNum_valueChanged(int channel);
	void on_spinSingleVol_valueChanged(double vol);


	void on_spinAllVol_valueChanged(double vol);
	void on_btnSetAll_clicked();

	void on_btnDMtest_clicked();
	void on_btnInitDM_clicked();
	void on_btnShutDM_clicked();
	void on_btnResetDM_clicked();
	void on_btnKeepIntensity_clicked();
	void tempFrameEnable(bool state);
	void on_gainSlider_valueChanged(int gainSlider);
	void on_spinBox_2_valueChanged(int gainSpinTrue);

	void on_sliderDmIntPara_valueChanged(int DmIntPara);
	void on_sliderFsmIntPara_valueChanged(int FsmIntPara);
	void on_btnDmIntPara_clicked();
	void on_btnFsmIntPara_clicked();

	void on_btnStartStandard_clicked();
	void on_btnStopStandard_clicked();

private:
	Ui::CameraDispClass ui;
	//QImage frame;
	QImage frame_minusBack;
	QImage bound;
    std::vector<int> dsbIdx;
    void initDescrambling();
    void descramble(short *image,short *imageRaw);
    SapAcquisition* SapAcq;
    SapBuffer*   SapBuffs;
    SapTransfer* SapTfer;
    inline static void  SapXferCb(SapXferCallbackInfo *);
    void initSap();
    void exitSap();
    void updateVideo();
    void initImgBigBuffer();
    void clearImgBigBuffer();
    short **BigImgBuffer;
    unsigned int *BigImgNum;
    QAtomicInt guiProtect;
    void emitFireUpDateScreen();
    
	bool initSerialPort();

	void minusBackGround(short *image,short *imageMinusBack);
	float backGround[240][240];

	bool ndToDisplay;
	bool ndToStandard;
	void resetBackGround();
	void standard(short *image);
	short standardImage[PIXELS_IMAGE];
	int maxValue;
	float threshold;
	QUdpSocket *udpSocket;
	QPainter painter;
	QVector<QRect> refRects;
	void initRefRect();
	void drawRef();

	int standardTimes;
	void resetBackGroundZero();
	void avgBackGround();

	short calStandardAvg(short *image,int i ,int j);
	short calStandardMedian(short *image,int i,int j);
	short calStandardSecond(short *image,int i,int j);

	QString getFileName();


    char da_data[480*6];
	char da_data1[480*6];

	QSerialPort m_serial;
	QString m_callbackToShow;
	QBasicTimer timerTemp;
	QTimer timerFlagProcessCommand;
	QUdpSocket* m_udpSocket;
	void timerEvent(QTimerEvent* event);


	DMirror aMirror;
	int singleChannel=1;
	float singleVoltage=-1;
	float allVoltage=-1;

	void updateZernike();
	centercal aCal;
	float *datacenter;
	float xCenterMean;
	float yCenterMean;
	void calCenterMean();

	bool flagSpin;
	bool flagSlider;
	int gainSliderArray[1000];
	int gainSpinArray[999];
};

#endif // CAMERADISP_H
