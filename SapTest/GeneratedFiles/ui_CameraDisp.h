/********************************************************************************
** Form generated from reading UI file 'CameraDisp.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERADISP_H
#define UI_CAMERADISP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraDispClass
{
public:
    QWidget *centralWidget;
    QLabel *videoBack;
    QTabWidget *tabWidget;
    QWidget *tabDmirror;
    QGroupBox *groupBox_9;
    QPushButton *btnSetAll;
    QLabel *label_11;
    QDoubleSpinBox *spinAllVol;
    QGroupBox *groupBox_10;
    QPushButton *btnDMtest;
    QPushButton *btnInitDM;
    QPushButton *btnShutDM;
    QPushButton *btnResetDM;
    QGroupBox *groupBox_5;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *spinChannelNum;
    QPushButton *btnStartVol;
    QDoubleSpinBox *spinSingleVol;
    QGroupBox *groupBox_11;
    QSlider *sliderDmIntPara;
    QDoubleSpinBox *dspinDmIntPara;
    QPushButton *btnDmIntPara;
    QGroupBox *groupBox_13;
    QSlider *sliderFsmIntPara;
    QDoubleSpinBox *dspinFsmIntPara;
    QPushButton *btnFsmIntPara;
    QWidget *tabOcanCtrl;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnStopCalibarate;
    QCheckBox *checkIfHold;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartCalibarate;
    QCheckBox *checkIfFsm;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *slider;
    QSpinBox *spinBox;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QSlider *gainSlider;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *gainResetButton;
    QPushButton *btnKeepIntensity;
    QPushButton *btnSetGain;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_20;
    QRadioButton *radioButton_m30;
    QRadioButton *radioButton_m45;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_18;
    QSpinBox *frameSpinBox;
    QPushButton *frameSetButton;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *frameButton_300;
    QRadioButton *frameButton_800;
    QRadioButton *frameButton_1500;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *frameButton_500;
    QRadioButton *frameButton_1000;
    QRadioButton *frameButton_2000;
    QGroupBox *groupBox_7;
    QPushButton *btnUpdateStandard;
    QPushButton *btnStopStandard;
    QPushButton *btnStartStandard;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *bias;
    QCheckBox *checkUpdateTemp;
    QPushButton *btnStartAndStop;
    QWidget *wavefrontInfo;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QPlainTextEdit *stateShow;
    QLabel *labBorder;
    QGroupBox *groupBox_12;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *image;
    QGroupBox *groupBox_6;
    QLabel *label_3;
    QLabel *CCDTempValue;
    QLabel *label_4;
    QLabel *WaterTempValue;
    QPushButton *resetBack;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *saveRawButton;
    QPushButton *saveProcessButton;
    QPushButton *saveBackButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CameraDispClass)
    {
        if (CameraDispClass->objectName().isEmpty())
            CameraDispClass->setObjectName(QStringLiteral("CameraDispClass"));
        CameraDispClass->resize(1595, 954);
        centralWidget = new QWidget(CameraDispClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        videoBack = new QLabel(centralWidget);
        videoBack->setObjectName(QStringLiteral("videoBack"));
        videoBack->setGeometry(QRect(10, 0, 900, 900));
        videoBack->setFrameShape(QFrame::Box);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(920, 0, 321, 911));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabDmirror = new QWidget();
        tabDmirror->setObjectName(QStringLiteral("tabDmirror"));
        groupBox_9 = new QGroupBox(tabDmirror);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(40, 210, 241, 141));
        groupBox_9->setFont(font);
        btnSetAll = new QPushButton(groupBox_9);
        btnSetAll->setObjectName(QStringLiteral("btnSetAll"));
        btnSetAll->setGeometry(QRect(80, 90, 75, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        btnSetAll->setFont(font1);
        label_11 = new QLabel(groupBox_9);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(61, 41, 62, 29));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setFont(font);
        spinAllVol = new QDoubleSpinBox(groupBox_9);
        spinAllVol->setObjectName(QStringLiteral("spinAllVol"));
        spinAllVol->setGeometry(QRect(129, 41, 61, 29));
        sizePolicy.setHeightForWidth(spinAllVol->sizePolicy().hasHeightForWidth());
        spinAllVol->setSizePolicy(sizePolicy);
        spinAllVol->setFont(font);
        spinAllVol->setMinimum(-1);
        spinAllVol->setMaximum(1);
        spinAllVol->setSingleStep(0.01);
        spinAllVol->setValue(-1);
        groupBox_10 = new QGroupBox(tabDmirror);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(40, 360, 241, 221));
        groupBox_10->setFont(font);
        btnDMtest = new QPushButton(groupBox_10);
        btnDMtest->setObjectName(QStringLiteral("btnDMtest"));
        btnDMtest->setGeometry(QRect(60, 40, 121, 31));
        btnDMtest->setFont(font);
        btnInitDM = new QPushButton(groupBox_10);
        btnInitDM->setObjectName(QStringLiteral("btnInitDM"));
        btnInitDM->setGeometry(QRect(60, 80, 121, 31));
        btnInitDM->setFont(font);
        btnShutDM = new QPushButton(groupBox_10);
        btnShutDM->setObjectName(QStringLiteral("btnShutDM"));
        btnShutDM->setGeometry(QRect(60, 120, 121, 31));
        btnShutDM->setFont(font1);
        btnResetDM = new QPushButton(groupBox_10);
        btnResetDM->setObjectName(QStringLiteral("btnResetDM"));
        btnResetDM->setGeometry(QRect(60, 160, 121, 31));
        btnResetDM->setFont(font1);
        groupBox_5 = new QGroupBox(tabDmirror);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(40, 30, 241, 171));
        groupBox_5->setFont(font);
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 40, 64, 19));
        label_9->setFont(font);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(51, 80, 64, 31));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font);
        spinChannelNum = new QSpinBox(groupBox_5);
        spinChannelNum->setObjectName(QStringLiteral("spinChannelNum"));
        spinChannelNum->setGeometry(QRect(130, 40, 61, 31));
        sizePolicy.setHeightForWidth(spinChannelNum->sizePolicy().hasHeightForWidth());
        spinChannelNum->setSizePolicy(sizePolicy);
        spinChannelNum->setFont(font);
        spinChannelNum->setMinimum(1);
        spinChannelNum->setMaximum(961);
        btnStartVol = new QPushButton(groupBox_5);
        btnStartVol->setObjectName(QStringLiteral("btnStartVol"));
        btnStartVol->setGeometry(QRect(80, 130, 75, 31));
        btnStartVol->setFont(font);
        spinSingleVol = new QDoubleSpinBox(groupBox_5);
        spinSingleVol->setObjectName(QStringLiteral("spinSingleVol"));
        spinSingleVol->setGeometry(QRect(130, 85, 61, 31));
        sizePolicy.setHeightForWidth(spinSingleVol->sizePolicy().hasHeightForWidth());
        spinSingleVol->setSizePolicy(sizePolicy);
        spinSingleVol->setFont(font1);
        spinSingleVol->setMinimum(-1);
        spinSingleVol->setMaximum(1);
        spinSingleVol->setSingleStep(0.01);
        spinSingleVol->setValue(-1);
        groupBox_11 = new QGroupBox(tabDmirror);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(40, 600, 241, 101));
        groupBox_11->setFont(font);
        sliderDmIntPara = new QSlider(groupBox_11);
        sliderDmIntPara->setObjectName(QStringLiteral("sliderDmIntPara"));
        sliderDmIntPara->setGeometry(QRect(40, 30, 160, 19));
        sliderDmIntPara->setMaximum(40);
        sliderDmIntPara->setOrientation(Qt::Horizontal);
        dspinDmIntPara = new QDoubleSpinBox(groupBox_11);
        dspinDmIntPara->setObjectName(QStringLiteral("dspinDmIntPara"));
        dspinDmIntPara->setGeometry(QRect(40, 60, 62, 31));
        dspinDmIntPara->setFont(font);
        dspinDmIntPara->setMaximum(0.4);
        btnDmIntPara = new QPushButton(groupBox_11);
        btnDmIntPara->setObjectName(QStringLiteral("btnDmIntPara"));
        btnDmIntPara->setGeometry(QRect(120, 60, 75, 31));
        btnDmIntPara->setFont(font);
        groupBox_13 = new QGroupBox(tabDmirror);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setGeometry(QRect(40, 720, 241, 101));
        groupBox_13->setFont(font);
        sliderFsmIntPara = new QSlider(groupBox_13);
        sliderFsmIntPara->setObjectName(QStringLiteral("sliderFsmIntPara"));
        sliderFsmIntPara->setGeometry(QRect(40, 30, 160, 19));
        sliderFsmIntPara->setMaximum(40);
        sliderFsmIntPara->setOrientation(Qt::Horizontal);
        dspinFsmIntPara = new QDoubleSpinBox(groupBox_13);
        dspinFsmIntPara->setObjectName(QStringLiteral("dspinFsmIntPara"));
        dspinFsmIntPara->setGeometry(QRect(40, 60, 62, 31));
        dspinFsmIntPara->setFont(font);
        dspinFsmIntPara->setMaximum(0.4);
        btnFsmIntPara = new QPushButton(groupBox_13);
        btnFsmIntPara->setObjectName(QStringLiteral("btnFsmIntPara"));
        btnFsmIntPara->setGeometry(QRect(120, 60, 75, 31));
        btnFsmIntPara->setFont(font);
        tabWidget->addTab(tabDmirror, QString());
        tabOcanCtrl = new QWidget();
        tabOcanCtrl->setObjectName(QStringLiteral("tabOcanCtrl"));
        groupBox = new QGroupBox(tabOcanCtrl);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 140, 281, 111));
        groupBox->setFont(font1);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 70, 170, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnStopCalibarate = new QPushButton(layoutWidget);
        btnStopCalibarate->setObjectName(QStringLiteral("btnStopCalibarate"));
        btnStopCalibarate->setEnabled(false);
        sizePolicy.setHeightForWidth(btnStopCalibarate->sizePolicy().hasHeightForWidth());
        btnStopCalibarate->setSizePolicy(sizePolicy);
        btnStopCalibarate->setFont(font);

        horizontalLayout_2->addWidget(btnStopCalibarate);

        checkIfHold = new QCheckBox(layoutWidget);
        checkIfHold->setObjectName(QStringLiteral("checkIfHold"));
        checkIfHold->setFont(font);

        horizontalLayout_2->addWidget(checkIfHold);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 30, 170, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnStartCalibarate = new QPushButton(layoutWidget1);
        btnStartCalibarate->setObjectName(QStringLiteral("btnStartCalibarate"));
        sizePolicy.setHeightForWidth(btnStartCalibarate->sizePolicy().hasHeightForWidth());
        btnStartCalibarate->setSizePolicy(sizePolicy);
        btnStartCalibarate->setFont(font);

        horizontalLayout->addWidget(btnStartCalibarate);

        checkIfFsm = new QCheckBox(layoutWidget1);
        checkIfFsm->setObjectName(QStringLiteral("checkIfFsm"));
        checkIfFsm->setFont(font);

        horizontalLayout->addWidget(checkIfFsm);

        groupBox_8 = new QGroupBox(tabOcanCtrl);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 340, 281, 81));
        groupBox_8->setFont(font1);
        layoutWidget2 = new QWidget(groupBox_8);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 241, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        slider = new QSlider(layoutWidget2);
        slider->setObjectName(QStringLiteral("slider"));
        sizePolicy.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
        slider->setSizePolicy(sizePolicy);
        slider->setMinimum(1);
        slider->setMaximum(5000);
        slider->setSingleStep(1);
        slider->setPageStep(50);
        slider->setValue(328);
        slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(slider);

        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setFont(font);
        spinBox->setMinimum(1);
        spinBox->setMaximum(5000);
        spinBox->setValue(328);

        horizontalLayout_4->addWidget(spinBox);

        groupBox_2 = new QGroupBox(tabOcanCtrl);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 510, 281, 121));
        groupBox_2->setFont(font);
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 32, 241, 71));
        verticalLayout_6 = new QVBoxLayout(layoutWidget3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        gainSlider = new QSlider(layoutWidget3);
        gainSlider->setObjectName(QStringLiteral("gainSlider"));
        sizePolicy.setHeightForWidth(gainSlider->sizePolicy().hasHeightForWidth());
        gainSlider->setSizePolicy(sizePolicy);
        gainSlider->setMinimum(1);
        gainSlider->setMaximum(1998);
        gainSlider->setSliderPosition(1);
        gainSlider->setOrientation(Qt::Horizontal);
        gainSlider->setInvertedAppearance(false);
        gainSlider->setInvertedControls(false);

        horizontalLayout_13->addWidget(gainSlider);

        spinBox_2 = new QSpinBox(layoutWidget3);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        sizePolicy1.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy1);
        spinBox_2->setFont(font);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(999);

        horizontalLayout_13->addWidget(spinBox_2);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        gainResetButton = new QPushButton(layoutWidget3);
        gainResetButton->setObjectName(QStringLiteral("gainResetButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gainResetButton->sizePolicy().hasHeightForWidth());
        gainResetButton->setSizePolicy(sizePolicy2);
        gainResetButton->setFont(font);

        horizontalLayout_16->addWidget(gainResetButton);

        btnKeepIntensity = new QPushButton(layoutWidget3);
        btnKeepIntensity->setObjectName(QStringLiteral("btnKeepIntensity"));
        sizePolicy2.setHeightForWidth(btnKeepIntensity->sizePolicy().hasHeightForWidth());
        btnKeepIntensity->setSizePolicy(sizePolicy2);
        btnKeepIntensity->setFont(font);

        horizontalLayout_16->addWidget(btnKeepIntensity);

        btnSetGain = new QPushButton(layoutWidget3);
        btnSetGain->setObjectName(QStringLiteral("btnSetGain"));
        sizePolicy2.setHeightForWidth(btnSetGain->sizePolicy().hasHeightForWidth());
        btnSetGain->setSizePolicy(sizePolicy2);
        btnSetGain->setFont(font);

        horizontalLayout_16->addWidget(btnSetGain);


        verticalLayout_6->addLayout(horizontalLayout_16);

        groupBox_3 = new QGroupBox(tabOcanCtrl);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 430, 281, 71));
        groupBox_3->setFont(font);
        layoutWidget4 = new QWidget(groupBox_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 30, 241, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButton_20 = new QRadioButton(layoutWidget4);
        radioButton_20->setObjectName(QStringLiteral("radioButton_20"));
        sizePolicy2.setHeightForWidth(radioButton_20->sizePolicy().hasHeightForWidth());
        radioButton_20->setSizePolicy(sizePolicy2);
        radioButton_20->setFont(font);

        horizontalLayout_5->addWidget(radioButton_20);

        radioButton_m30 = new QRadioButton(layoutWidget4);
        radioButton_m30->setObjectName(QStringLiteral("radioButton_m30"));
        sizePolicy2.setHeightForWidth(radioButton_m30->sizePolicy().hasHeightForWidth());
        radioButton_m30->setSizePolicy(sizePolicy2);
        radioButton_m30->setFont(font);

        horizontalLayout_5->addWidget(radioButton_m30);

        radioButton_m45 = new QRadioButton(layoutWidget4);
        radioButton_m45->setObjectName(QStringLiteral("radioButton_m45"));
        sizePolicy2.setHeightForWidth(radioButton_m45->sizePolicy().hasHeightForWidth());
        radioButton_m45->setSizePolicy(sizePolicy2);
        radioButton_m45->setFont(font);

        horizontalLayout_5->addWidget(radioButton_m45);

        groupBox_4 = new QGroupBox(tabOcanCtrl);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 640, 281, 141));
        groupBox_4->setFont(font);
        layoutWidget5 = new QWidget(groupBox_4);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(20, 100, 241, 31));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        frameSpinBox = new QSpinBox(layoutWidget5);
        frameSpinBox->setObjectName(QStringLiteral("frameSpinBox"));
        sizePolicy.setHeightForWidth(frameSpinBox->sizePolicy().hasHeightForWidth());
        frameSpinBox->setSizePolicy(sizePolicy);
        frameSpinBox->setFont(font);
        frameSpinBox->setMinimum(1);
        frameSpinBox->setMaximum(2000);

        horizontalLayout_18->addWidget(frameSpinBox);

        frameSetButton = new QPushButton(layoutWidget5);
        frameSetButton->setObjectName(QStringLiteral("frameSetButton"));
        sizePolicy.setHeightForWidth(frameSetButton->sizePolicy().hasHeightForWidth());
        frameSetButton->setSizePolicy(sizePolicy);
        frameSetButton->setFont(font);

        horizontalLayout_18->addWidget(frameSetButton);

        layoutWidget6 = new QWidget(groupBox_4);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 30, 238, 58));
        verticalLayout_3 = new QVBoxLayout(layoutWidget6);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        frameButton_300 = new QRadioButton(layoutWidget6);
        frameButton_300->setObjectName(QStringLiteral("frameButton_300"));
        sizePolicy.setHeightForWidth(frameButton_300->sizePolicy().hasHeightForWidth());
        frameButton_300->setSizePolicy(sizePolicy);
        frameButton_300->setFont(font);

        horizontalLayout_11->addWidget(frameButton_300);

        frameButton_800 = new QRadioButton(layoutWidget6);
        frameButton_800->setObjectName(QStringLiteral("frameButton_800"));
        sizePolicy.setHeightForWidth(frameButton_800->sizePolicy().hasHeightForWidth());
        frameButton_800->setSizePolicy(sizePolicy);
        frameButton_800->setFont(font);

        horizontalLayout_11->addWidget(frameButton_800);

        frameButton_1500 = new QRadioButton(layoutWidget6);
        frameButton_1500->setObjectName(QStringLiteral("frameButton_1500"));
        sizePolicy.setHeightForWidth(frameButton_1500->sizePolicy().hasHeightForWidth());
        frameButton_1500->setSizePolicy(sizePolicy);
        frameButton_1500->setFont(font);

        horizontalLayout_11->addWidget(frameButton_1500);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        frameButton_500 = new QRadioButton(layoutWidget6);
        frameButton_500->setObjectName(QStringLiteral("frameButton_500"));
        sizePolicy.setHeightForWidth(frameButton_500->sizePolicy().hasHeightForWidth());
        frameButton_500->setSizePolicy(sizePolicy);
        frameButton_500->setFont(font);

        horizontalLayout_12->addWidget(frameButton_500);

        frameButton_1000 = new QRadioButton(layoutWidget6);
        frameButton_1000->setObjectName(QStringLiteral("frameButton_1000"));
        sizePolicy.setHeightForWidth(frameButton_1000->sizePolicy().hasHeightForWidth());
        frameButton_1000->setSizePolicy(sizePolicy);
        frameButton_1000->setFont(font);

        horizontalLayout_12->addWidget(frameButton_1000);

        frameButton_2000 = new QRadioButton(layoutWidget6);
        frameButton_2000->setObjectName(QStringLiteral("frameButton_2000"));
        sizePolicy.setHeightForWidth(frameButton_2000->sizePolicy().hasHeightForWidth());
        frameButton_2000->setSizePolicy(sizePolicy);
        frameButton_2000->setFont(font);

        horizontalLayout_12->addWidget(frameButton_2000);


        verticalLayout_3->addLayout(horizontalLayout_12);

        groupBox_7 = new QGroupBox(tabOcanCtrl);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 260, 281, 71));
        groupBox_7->setFont(font1);
        btnUpdateStandard = new QPushButton(groupBox_7);
        btnUpdateStandard->setObjectName(QStringLiteral("btnUpdateStandard"));
        btnUpdateStandard->setGeometry(QRect(190, 30, 75, 27));
        sizePolicy.setHeightForWidth(btnUpdateStandard->sizePolicy().hasHeightForWidth());
        btnUpdateStandard->setSizePolicy(sizePolicy);
        btnUpdateStandard->setFont(font);
        btnStopStandard = new QPushButton(groupBox_7);
        btnStopStandard->setObjectName(QStringLiteral("btnStopStandard"));
        btnStopStandard->setGeometry(QRect(110, 30, 75, 27));
        sizePolicy.setHeightForWidth(btnStopStandard->sizePolicy().hasHeightForWidth());
        btnStopStandard->setSizePolicy(sizePolicy);
        btnStopStandard->setFont(font);
        btnStartStandard = new QPushButton(groupBox_7);
        btnStartStandard->setObjectName(QStringLiteral("btnStartStandard"));
        btnStartStandard->setGeometry(QRect(30, 30, 75, 27));
        sizePolicy.setHeightForWidth(btnStartStandard->sizePolicy().hasHeightForWidth());
        btnStartStandard->setSizePolicy(sizePolicy);
        btnStartStandard->setFont(font);
        layoutWidget7 = new QWidget(tabOcanCtrl);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(30, 800, 262, 31));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        bias = new QCheckBox(layoutWidget7);
        bias->setObjectName(QStringLiteral("bias"));
        bias->setFont(font);

        horizontalLayout_19->addWidget(bias);

        checkUpdateTemp = new QCheckBox(layoutWidget7);
        checkUpdateTemp->setObjectName(QStringLiteral("checkUpdateTemp"));
        checkUpdateTemp->setFont(font);

        horizontalLayout_19->addWidget(checkUpdateTemp);

        btnStartAndStop = new QPushButton(tabOcanCtrl);
        btnStartAndStop->setObjectName(QStringLiteral("btnStartAndStop"));
        btnStartAndStop->setGeometry(QRect(60, 60, 75, 27));
        sizePolicy.setHeightForWidth(btnStartAndStop->sizePolicy().hasHeightForWidth());
        btnStartAndStop->setSizePolicy(sizePolicy);
        btnStartAndStop->setFont(font);
        tabWidget->addTab(tabOcanCtrl, QString());
        wavefrontInfo = new QWidget();
        wavefrontInfo->setObjectName(QStringLiteral("wavefrontInfo"));
        tableWidget = new QTableWidget(wavefrontInfo);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 11)
            tableWidget->setRowCount(11);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem11);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(90, 80, 131, 351));
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(true);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget_2 = new QTableWidget(wavefrontInfo);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem16);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(50, 510, 221, 111));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(wavefrontInfo, QString());
        stateShow = new QPlainTextEdit(centralWidget);
        stateShow->setObjectName(QStringLiteral("stateShow"));
        stateShow->setGeometry(QRect(1260, 640, 311, 241));
        labBorder = new QLabel(centralWidget);
        labBorder->setObjectName(QStringLiteral("labBorder"));
        labBorder->setGeometry(QRect(10, 0, 900, 900));
        groupBox_12 = new QGroupBox(centralWidget);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setGeometry(QRect(1270, 560, 291, 61));
        groupBox_12->setFont(font);
        label_2 = new QLabel(groupBox_12);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(21, 31, 50, 19));
        label_2->setFont(font);
        label = new QLabel(groupBox_12);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(84, 31, 50, 20));
        label->setFrameShape(QFrame::Box);
        label_5 = new QLabel(groupBox_12);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(141, 31, 75, 19));
        label_5->setFont(font);
        image = new QLabel(groupBox_12);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(222, 31, 50, 20));
        image->setFont(font);
        image->setFrameShape(QFrame::Box);
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(1270, 490, 291, 61));
        groupBox_6->setFont(font);
        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(31, 31, 31, 19));
        label_3->setFont(font);
        CCDTempValue = new QLabel(groupBox_6);
        CCDTempValue->setObjectName(QStringLiteral("CCDTempValue"));
        CCDTempValue->setGeometry(QRect(84, 31, 50, 20));
        CCDTempValue->setFont(font);
        CCDTempValue->setFrameShape(QFrame::Box);
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(161, 31, 41, 19));
        label_4->setFont(font);
        WaterTempValue = new QLabel(groupBox_6);
        WaterTempValue->setObjectName(QStringLiteral("WaterTempValue"));
        WaterTempValue->setGeometry(QRect(222, 31, 50, 20));
        WaterTempValue->setFont(font);
        WaterTempValue->setFrameShape(QFrame::Box);
        resetBack = new QPushButton(centralWidget);
        resetBack->setObjectName(QStringLiteral("resetBack"));
        resetBack->setGeometry(QRect(1370, 230, 75, 27));
        sizePolicy.setHeightForWidth(resetBack->sizePolicy().hasHeightForWidth());
        resetBack->setSizePolicy(sizePolicy);
        resetBack->setFont(font);
        layoutWidget8 = new QWidget(centralWidget);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(1290, 100, 239, 31));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        saveRawButton = new QPushButton(layoutWidget8);
        saveRawButton->setObjectName(QStringLiteral("saveRawButton"));
        saveRawButton->setEnabled(false);
        sizePolicy.setHeightForWidth(saveRawButton->sizePolicy().hasHeightForWidth());
        saveRawButton->setSizePolicy(sizePolicy);
        saveRawButton->setFont(font);

        horizontalLayout_15->addWidget(saveRawButton);

        saveProcessButton = new QPushButton(layoutWidget8);
        saveProcessButton->setObjectName(QStringLiteral("saveProcessButton"));
        saveProcessButton->setEnabled(false);
        sizePolicy.setHeightForWidth(saveProcessButton->sizePolicy().hasHeightForWidth());
        saveProcessButton->setSizePolicy(sizePolicy);
        saveProcessButton->setFont(font);

        horizontalLayout_15->addWidget(saveProcessButton);

        saveBackButton = new QPushButton(layoutWidget8);
        saveBackButton->setObjectName(QStringLiteral("saveBackButton"));
        sizePolicy.setHeightForWidth(saveBackButton->sizePolicy().hasHeightForWidth());
        saveBackButton->setSizePolicy(sizePolicy);
        saveBackButton->setFont(font);

        horizontalLayout_15->addWidget(saveBackButton);

        CameraDispClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CameraDispClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1595, 21));
        CameraDispClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CameraDispClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CameraDispClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CameraDispClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CameraDispClass->setStatusBar(statusBar);

        retranslateUi(CameraDispClass);
        QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CameraDispClass);
    } // setupUi

    void retranslateUi(QMainWindow *CameraDispClass)
    {
        CameraDispClass->setWindowTitle(QApplication::translate("CameraDispClass", "CameraDisp", nullptr));
        videoBack->setText(QString());
        groupBox_9->setTitle(QApplication::translate("CameraDispClass", "\345\205\250\351\200\232\351\201\223\346\265\213\350\257\225", nullptr));
        btnSetAll->setText(QApplication::translate("CameraDispClass", "\345\205\250\351\203\250\344\270\212\347\224\265", nullptr));
        label_11->setText(QApplication::translate("CameraDispClass", "\350\276\223\345\205\245\347\224\265\345\216\213", nullptr));
        groupBox_10->setTitle(QApplication::translate("CameraDispClass", "\345\270\270\347\224\250\346\223\215\344\275\234", nullptr));
        btnDMtest->setText(QApplication::translate("CameraDispClass", "\345\217\230\345\275\242\351\225\234\344\270\212\347\224\265\346\265\213\350\257\225", nullptr));
        btnInitDM->setText(QApplication::translate("CameraDispClass", "\345\217\230\345\275\242\351\225\234\344\270\212\347\224\265", nullptr));
        btnShutDM->setText(QApplication::translate("CameraDispClass", "\345\217\230\345\275\242\351\225\234\344\270\213\347\224\265", nullptr));
        btnResetDM->setText(QApplication::translate("CameraDispClass", "\345\217\230\345\275\242\351\225\234\347\224\265\345\216\213\345\244\215\344\275\215", nullptr));
        groupBox_5->setTitle(QApplication::translate("CameraDispClass", "\345\215\225\351\200\232\351\201\223\346\265\213\350\257\225", nullptr));
        label_9->setText(QApplication::translate("CameraDispClass", "\351\200\232\351\201\223\347\274\226\345\217\267", nullptr));
        label_10->setText(QApplication::translate("CameraDispClass", "\350\276\223\345\205\245\347\224\265\345\216\213", nullptr));
        btnStartVol->setText(QApplication::translate("CameraDispClass", "\344\270\212\347\224\265", nullptr));
        groupBox_11->setTitle(QApplication::translate("CameraDispClass", "\345\217\230\345\275\242\351\225\234\347\247\257\345\210\206\345\217\202\346\225\260", nullptr));
        btnDmIntPara->setText(QApplication::translate("CameraDispClass", "\350\256\276\347\275\256", nullptr));
        groupBox_13->setTitle(QApplication::translate("CameraDispClass", "\344\272\214\347\272\247\345\277\253\345\217\215\347\247\257\345\210\206\345\217\202\346\225\260", nullptr));
        btnFsmIntPara->setText(QApplication::translate("CameraDispClass", "\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDmirror), QApplication::translate("CameraDispClass", "\345\217\230\345\275\242\351\225\234\346\216\247\345\210\266", nullptr));
        groupBox->setTitle(QApplication::translate("CameraDispClass", "\346\240\241\346\255\243", nullptr));
        btnStopCalibarate->setText(QApplication::translate("CameraDispClass", "\347\273\223\346\235\237\346\240\241\346\255\243", nullptr));
        checkIfHold->setText(QApplication::translate("CameraDispClass", "\347\273\223\346\235\237\344\277\235\346\214\201", nullptr));
        btnStartCalibarate->setText(QApplication::translate("CameraDispClass", "\345\274\200\345\247\213\346\240\241\346\255\243", nullptr));
        checkIfFsm->setText(QApplication::translate("CameraDispClass", "\344\272\214\347\272\247\346\240\241\346\255\243", nullptr));
        groupBox_8->setTitle(QApplication::translate("CameraDispClass", "\351\230\210\345\200\274", nullptr));
        groupBox_2->setTitle(QApplication::translate("CameraDispClass", "\345\242\236\347\233\212", nullptr));
        gainResetButton->setText(QApplication::translate("CameraDispClass", "\345\242\236\347\233\212\345\244\215\344\275\215", nullptr));
        btnKeepIntensity->setText(QApplication::translate("CameraDispClass", "\350\207\252\345\212\250\345\242\236\347\233\212", nullptr));
        btnSetGain->setText(QApplication::translate("CameraDispClass", "\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QApplication::translate("CameraDispClass", "\345\210\266\345\206\267", nullptr));
        radioButton_20->setText(QApplication::translate("CameraDispClass", "20\342\204\203", nullptr));
        radioButton_m30->setText(QApplication::translate("CameraDispClass", "-30\342\204\203", nullptr));
        radioButton_m45->setText(QApplication::translate("CameraDispClass", "-45\342\204\203", nullptr));
        groupBox_4->setTitle(QApplication::translate("CameraDispClass", "\345\270\247\351\242\221", nullptr));
        frameSetButton->setText(QApplication::translate("CameraDispClass", "\350\256\276\347\275\256", nullptr));
        frameButton_300->setText(QApplication::translate("CameraDispClass", "300Hz", nullptr));
        frameButton_800->setText(QApplication::translate("CameraDispClass", "800Hz", nullptr));
        frameButton_1500->setText(QApplication::translate("CameraDispClass", "1500Hz", nullptr));
        frameButton_500->setText(QApplication::translate("CameraDispClass", "500Hz", nullptr));
        frameButton_1000->setText(QApplication::translate("CameraDispClass", "1000Hz", nullptr));
        frameButton_2000->setText(QApplication::translate("CameraDispClass", "2000Hz", nullptr));
        groupBox_7->setTitle(QApplication::translate("CameraDispClass", "\346\240\207\345\256\232", nullptr));
        btnUpdateStandard->setText(QApplication::translate("CameraDispClass", "\346\233\264\346\226\260\346\240\207\345\256\232", nullptr));
        btnStopStandard->setText(QApplication::translate("CameraDispClass", "\347\273\223\346\235\237\346\240\207\345\256\232", nullptr));
        btnStartStandard->setText(QApplication::translate("CameraDispClass", "\345\274\200\345\247\213\346\240\207\345\256\232", nullptr));
        bias->setText(QApplication::translate("CameraDispClass", "Bias on", nullptr));
        checkUpdateTemp->setText(QApplication::translate("CameraDispClass", "\346\233\264\346\226\260\346\270\251\345\272\246", nullptr));
        btnStartAndStop->setText(QApplication::translate("CameraDispClass", "\345\220\257\345\212\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabOcanCtrl), QApplication::translate("CameraDispClass", "\347\233\270\346\234\272\346\216\247\345\210\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CameraDispClass", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("CameraDispClass", "Z1", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("CameraDispClass", "Z2", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("CameraDispClass", "Z3", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("CameraDispClass", "Z4", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("CameraDispClass", "Z5", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("CameraDispClass", "Z6", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("CameraDispClass", "Z7", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("CameraDispClass", "Z8", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("CameraDispClass", "Z9", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("CameraDispClass", "Z10", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("CameraDispClass", "Z11", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("CameraDispClass", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("CameraDispClass", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("CameraDispClass", "SX", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("CameraDispClass", "SY", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("CameraDispClass", "SZ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(wavefrontInfo), QApplication::translate("CameraDispClass", "\346\263\242\345\211\215\344\277\241\346\201\257", nullptr));
        labBorder->setText(QApplication::translate("CameraDispClass", "TextLabel", nullptr));
        groupBox_12->setTitle(QApplication::translate("CameraDispClass", "\345\203\217\347\264\240", nullptr));
        label_2->setText(QApplication::translate("CameraDispClass", "maxBG", nullptr));
        label->setText(QString());
        label_5->setText(QApplication::translate("CameraDispClass", "maxImage", nullptr));
        image->setText(QString());
        groupBox_6->setTitle(QApplication::translate("CameraDispClass", "\346\270\251\345\272\246", nullptr));
        label_3->setText(QApplication::translate("CameraDispClass", "CCD", nullptr));
        CCDTempValue->setText(QString());
        label_4->setText(QApplication::translate("CameraDispClass", "Water", nullptr));
        WaterTempValue->setText(QString());
        resetBack->setText(QApplication::translate("CameraDispClass", "\351\207\215\347\275\256", nullptr));
        saveRawButton->setText(QApplication::translate("CameraDispClass", "\345\216\237\345\233\276", nullptr));
        saveProcessButton->setText(QApplication::translate("CameraDispClass", "\345\244\204\347\220\206\345\233\276", nullptr));
        saveBackButton->setText(QApplication::translate("CameraDispClass", "\346\240\207\345\256\232\347\237\251\351\230\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraDispClass: public Ui_CameraDispClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADISP_H
