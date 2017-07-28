#pragma once
#include "QCameraFrame.h"
#include "navigationbar.h"

class Tab1 : public QWidget
{
	Q_OBJECT

public:
	Tab1(QWidget *parent = Q_NULLPTR);
	~Tab1();

protected:
	QCameraFrame *cameraFrame;
	NavigationBar *navBar;
	QDockWidget	*mapWidget;

	QVBoxLayout *vLayout;
	QHBoxLayout *hLayout;
	QMenu *objectivesMenu;
	QMenu *joystickMenu;

public slots:
	void dialog(QString*);
};
