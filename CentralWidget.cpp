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
	if (code == 11)
	{
		int count = Singleton::instance().pDefects()->GetCount();

		for (int i = 0; i < count; ++i) {
			std::string desc = Singleton::instance().pDefects()->GetAt(i)->description;
			QString qDesc = QString::fromLocal8Bit(desc.c_str());
			int hotKey = Singleton::instance().pDefects()->GetAt(i)->hotkey;
			byte keypad = Singleton::instance().pDefects()->GetAt(i)->keypad;
			int code = Singleton::instance().pDefects()->GetAt(i)->code;
			bool isGood = Singleton::instance().pDefects()->GetAt(i)->isGood;
			bool isButton = Singleton::instance().pDefects()->GetAt(i)->isButton;
			bool isAutoFoto = Singleton::instance().pDefects()->GetAt(i)->isAutoPhoto;

			emit newSignalFrame.addDef(qDesc, hotKey, keypad, code, isGood, isButton, isAutoFoto);
		}
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

	addTab(tab1, "Осмотр");
	addTab(tab2, "Карта");
	addTab(tab3, "Настройки");

	connect(this, &CentralWidget::showPanorama, tab1, &Tab1::showPanorama);
	connect(this, &CentralWidget::showCamera, tab1, &Tab1::showCamera);
	connect(this, &CentralWidget::showWizard, tab1, &Tab1::showWizard);
	connect(this, &QTabWidget::currentChanged, this, &CentralWidget::tabChanged);
	connect(&newSignalFrame, &EmitSignal::newFrame, tab1, &Tab1::updateFrame);
	connect(&newSignalFrame, &EmitSignal::addDef, tab3, &Tab3::addDef);
}

void CentralWidget::tabChanged(int index) {
	switch (currentIndex())
	{
		case 0: {
			connect(&newSignalFrame, &EmitSignal::newFrame, tab1, &Tab1::updateFrame);
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab2, &Tab2::updateFrame);
	} break;

		case 1: {
			connect(&newSignalFrame, &EmitSignal::newFrame, tab2, &Tab2::updateFrame);
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab1, &Tab1::updateFrame);
	} break;

		case 2: {
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab2, &Tab2::updateFrame);
			disconnect(&newSignalFrame, &EmitSignal::newFrame, tab1, &Tab1::updateFrame);
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