#pragma once
#include "QCameraFrame.h"
#include "navigationbar.h"

class Tab1 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab1(QWidget *parent = Q_NULLPTR);

protected:
	QGraphicsScene	*scene;
	QGraphicsView	*view;
	QCameraFrame *cameraFrame;
	NavigationBar *navBar;
	NavigationBar *defBar;

	QHBoxLayout *hLayout;

protected:
	void resizeEvent(QResizeEvent *event) override;

public slots:
	void dialog(QString*);
};
