

#include"readQss.h"

void readQss::setStyle(const QString &style)
{
	QFile qss(style);
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}

