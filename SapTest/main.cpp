#include "cameradisp.h"
#include <Qtwidgets/QApplication>
#include "readQss.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	readQss::setStyle("./Resources/AMOLED.qss");

	CameraDisp w;
	w.setWindowFlags(w.windowFlags()&~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);
	w.show();
	return a.exec();
}
