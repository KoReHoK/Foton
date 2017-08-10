#pragma once
#include "QCameraFrame.h"
#include "navigationbar.h"

class Tab1 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab1(QWidget *parent = Q_NULLPTR);
	QCameraFrame *cameraFrame;

private:
	QGraphicsScene	*scene;
	QGraphicsView	*panoramaView;
	
	NavigationBar *defBar;
	QHBoxLayout *hLayout;
	QStackedWidget *mainWidget;

public slots:
	void showCamera();
	void showPanorama();
};
