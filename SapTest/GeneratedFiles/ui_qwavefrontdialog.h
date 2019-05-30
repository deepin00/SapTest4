/********************************************************************************
** Form generated from reading UI file 'qwavefrontdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWAVEFRONTDIALOG_H
#define UI_QWAVEFRONTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_QWavefrontDialog
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QDialog *QWavefrontDialog)
    {
        if (QWavefrontDialog->objectName().isEmpty())
            QWavefrontDialog->setObjectName(QStringLiteral("QWavefrontDialog"));
        QWavefrontDialog->resize(480, 640);
        label = new QLabel(QWavefrontDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 480, 480));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(QWavefrontDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 510, 461, 121));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 30, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 30, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 60, 54, 12));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 60, 54, 12));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(200, 30, 54, 12));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 30, 54, 12));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 60, 54, 12));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 60, 54, 12));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(200, 90, 54, 12));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(260, 90, 54, 12));

        retranslateUi(QWavefrontDialog);

        QMetaObject::connectSlotsByName(QWavefrontDialog);
    } // setupUi

    void retranslateUi(QDialog *QWavefrontDialog)
    {
        QWavefrontDialog->setWindowTitle(QApplication::translate("QWavefrontDialog", "QWavefrontDialog", nullptr));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("QWavefrontDialog", "\346\263\242\345\211\215\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("QWavefrontDialog", "\346\263\242\345\211\215PV", nullptr));
        label_3->setText(QApplication::translate("QWavefrontDialog", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("QWavefrontDialog", "\346\263\242\345\211\215RMS", nullptr));
        label_5->setText(QApplication::translate("QWavefrontDialog", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("QWavefrontDialog", "sx", nullptr));
        label_7->setText(QApplication::translate("QWavefrontDialog", "TextLabel", nullptr));
        label_8->setText(QApplication::translate("QWavefrontDialog", "sy", nullptr));
        label_9->setText(QApplication::translate("QWavefrontDialog", "TextLabel", nullptr));
        label_10->setText(QApplication::translate("QWavefrontDialog", "sz", nullptr));
        label_11->setText(QApplication::translate("QWavefrontDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWavefrontDialog: public Ui_QWavefrontDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWAVEFRONTDIALOG_H
