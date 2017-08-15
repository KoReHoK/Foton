#pragma once
#include "QCameraFrame.h"
#include "navigationbar.h"
#include "Wizard.h"

class Tab1 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab1(QWidget *parent = Q_NULLPTR);

private:
	QStackedWidget *mainWidget;
	Wizard		*wizard = nullptr;

public slots:
	void showCamera();
	void showPanorama();
	void showWizard();
	void deleteWizard();
	void updateFrame(uchar* newFrame, int w, int h, int bits);

protected:
	void resizeEvent(QResizeEvent *event) override;
};
