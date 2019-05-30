#pragma once

#include <QDialog>
#include "ui_qwavefrontdialog.h"

class QWavefrontDialog : public QDialog
{
	Q_OBJECT

public:
	QWavefrontDialog(QWidget *parent = Q_NULLPTR);
	~QWavefrontDialog();

private:
	Ui::QWavefrontDialog ui;
};
