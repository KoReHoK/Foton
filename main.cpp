#include "FotonMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FotonMainWindow w;
	w.show();
	return a.exec();
}
