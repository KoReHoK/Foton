#include "stdafx.h"
#include "FotonMainWindow.h"

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(0);

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication a(argc, argv);
	a.setApplicationName("Foton");
	a.setOrganizationName("Optoelectronic systems");
	FotonMainWindow w;
	w.show();

	return a.exec();
}
