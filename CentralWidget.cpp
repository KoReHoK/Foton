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
	connect(this, &CentralWidget::showWizard, tab1, &Tab1::showWizard);
	connect(this, &CentralWidget::closeWizard, tab1, &Tab1::deleteWizard);
	connect(this, &QTabWidget::currentChanged, this, &CentralWidget::tabChanged);
	connect(&newSignalFrame, &EmitSignal::newFrame, tab1->cameraFrame, &QCameraFrame::updateFrame);
}

void CentralWidget::tabChanged(int index) {
	switch (currentIndex())
	{
		case 0: {
			connect(&newSignalFrame, &EmitSignal::newFrame, tab1->cameraFrame, &QCameraFrame::updateFrame);
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab2->cameraFrame, &QCameraFrame::updateFrame);
	} break;

		case 1: {
			connect(&newSignalFrame, &EmitSignal::newFrame, tab2->cameraFrame, &QCameraFrame::updateFrame);
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab1->cameraFrame, &QCameraFrame::updateFrame);
	} break;

		case 2: {
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab2->cameraFrame, &QCameraFrame::updateFrame);
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab1->cameraFrame, &QCameraFrame::updateFrame);
	} break;

	default: QMessageBox::information(this, "infa100%", "Ошибка. Данного таба не существует"); break;
	}
}

void CentralWidget::setCrystMode(int index) {
	switch (index) {

		case 0: {	// one crystal mode
			setCurrentIndex(index);
		}; break;

		case 1: {	// multi crystal mode
			setCurrentIndex(index);
		}; break;

		default: QMessageBox::information(this, "infa100%", "Ошибка. Данного режима не существует"); break;
	}
}