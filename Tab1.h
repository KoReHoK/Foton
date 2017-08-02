#pragma once
#include "QCameraFrame.h"
#include "navigationbar.h"

class Tab1 : public QWidget
{
	Q_OBJECT

public:
	Tab1(QWidget *parent = Q_NULLPTR);

protected:
	QGraphicsScene	*scene;
	QGraphicsView	*view;
	QCameraFrame *cameraFrame;
	NavigationBar *navBar;
	NavigationBar *defBar;

	QHBoxLayout *hLayout;
	MenuWidget *objectivesMenu;
	MenuWidget *joystickMenu;

public slots:
	void dialog(QString*);
};
