#pragma once
#include "QCameraFrame.h"
#include "navigationbar.h"
#include "Wizard.h"
#include "QJobMicro.h"
class Tab1 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab1(QWidget *parent = Q_NULLPTR);

protected:
	QGraphicsScene	*scene;
	QGraphicsView	*view;
	Wizard			*wizard;
	QCameraFrame *cameraFrame;
	NavigationBar *defBar;
	QHBoxLayout *hLayout;

protected:
	void resizeEvent(QResizeEvent *event) override;

public slots:
	void dialog(QString*);
};
