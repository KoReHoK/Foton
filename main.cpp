#include "FotonMainWindow.h"
#include <QtWidgets/QApplication>
//#include "LoadDll.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication a(argc, argv);
	a.setApplicationName("Foton");
	a.setOrganizationName("Optoelectronic systems");
	//CLoadDll myDll("BaslerAce");
	FotonMainWindow w;
	w.show();

	return a.exec();
}
