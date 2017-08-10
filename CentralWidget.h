#pragma once
#include "Tab1.h"
#include "Tab2.h"
#include "Tab3.h"
#include "QJobMicro.h"

class Singleton
{
public:
	static 	QJobMicro& instance()
	{
		// согласно стандарту, этот код ленивый и потокобезопасный
		static Singleton s;
		return s.mJob;
	}

private:
	Singleton();   // конструктор недоступен
	~Singleton() {} // и деструктор

	Singleton(Singleton const&) = delete;
	Singleton& operator= (Singleton const&) = delete;

	QJobMicro	mJob;
};

class EmitSignal : public QObject
{
	Q_OBJECT

signals :
	void newFrame(uchar* newFrame, int w, int h, int bits);
};

class CentralWidget : public QTabWidget
{
	Q_OBJECT
public:
	explicit CentralWidget(QWidget *parent = Q_NULLPTR);

private:
	Tab1 *tab1;
	Tab2 *tab2;
	Tab3 *tab3;

signals:
	void showPanorama();
	void showCamera();

private slots:
	void tabChanged(int index);
};