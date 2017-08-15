#pragma once

#include "QCameraFrame.h"
#include "SettingsWidget.h"
#include "LegendWidget.h"
#include "navigationbar.h"

class Tab2 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab2(QWidget *parent = Q_NULLPTR);

private:
	QCameraFrame *cameraFrame;

private slots:
	void dialog(QString*);

public slots:
	void updateFrame(uchar* newFrame, int w, int h, int bits);

protected:
	void resizeEvent(QResizeEvent *event) override;
};