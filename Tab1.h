#pragma once
#include "QCameraFrame.h"
#include "navigationbar.h"
#include "Wizard.h"

class Tab1 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab1(QWidget *parent = Q_NULLPTR);
	QCameraFrame *cameraFrame;

private:
	QGraphicsScene	*scene = nullptr;
	QGraphicsView	*panoramaView;
	
	NavigationBar *defBar;
	QHBoxLayout *hLayout;
	QStackedWidget *mainWidget;

	Wizard		*wizard = nullptr;

public slots:
	void showCamera();
	void showPanorama();
	void showWizard();
	void deleteWizard();

protected:
	void resizeEvent(QResizeEvent *event) override;
};
