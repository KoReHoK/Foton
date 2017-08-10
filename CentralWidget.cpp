#include "stdafx.h"
#include "CentralWidget.h"

#include "IplImage.h"

EmitSignal newSignalFrame;
void __stdcall OnCallBack(long code, long value)
{
	if (code == 15)
	{
		CIplImage* img = (CIplImage*)value;
		emit newSignalFrame.newFrame(img->pdata(), img->width(), img->height(), img->nChannels()*8);
	}
}

Singleton::Singleton() : mJob("JobMicro.dll")
{
	mJob.SetCallBack((CallBackFunc)OnCallBack);
}

CentralWidget::CentralWidget(QWidget *parent)
	: QTabWidget(parent)
{
	tab1 = new Tab1(this);
	tab2 = new Tab2(this);
	tab3 = new Tab3(this);

	Singleton::instance().Init();

	this->addTab(tab1, "Осмотр");
	this->addTab(tab2, "Карта");
	this->addTab(tab3, "Настройки");

	connect(this, &CentralWidget::showPanorama, tab1, &Tab1::showPanorama);
	connect(this, &CentralWidget::showCamera, tab1, &Tab1::showCamera);
	connect(this, &QTabWidget::currentChanged, this, &CentralWidget::tabChanged);
	connect(&newSignalFrame, &EmitSignal::newFrame, tab1->cameraFrame, &QCameraFrame::updateFrame);
}

void CentralWidget::tabChanged(int index) {
	switch (currentIndex())
	{
		case 0: {
		QMessageBox::information(this, "infa100%", "Вы выбрали Tab0");
		//TODO: организовать connect и disconnect при получении нового кадра
	} break;

		case 1: {
		QMessageBox::information(this, "infa100%", "Вы выбрали Tab1");
		//TODO: организовать connect и disconnect при получении нового кадра
	} break;

		case 2: {
		QMessageBox::information(this, "infa100%", "Вы выбрали Tab2");
		//TODO: организовать connect и disconnect при получении нового кадра
	} break;

	default: QMessageBox::information(this, "infa100%", "Ошибка"); break;
	}
}