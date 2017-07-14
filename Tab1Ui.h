#pragma once

#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QDockWidget>
#include "QCameraFrame.h"
#include "navigationbar.h"
#include <QMenu>

QT_BEGIN_NAMESPACE

class Ui_Tab1
{
protected:
	QCameraFrame *cameraFrame;
	//QCameraFrame *cameraFrame2;
	NavigationBar *navBar;
	QDockWidget	*mapWidget;

	QVBoxLayout *vLayout;
	QHBoxLayout *hLayout;
	QMenu *objectivesMenu;
	QMenu *joystickMenu;


public:

	void setupUi(QWidget *Form)
	{
		cameraFrame = new QCameraFrame();
		cameraFrame->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

// 		cameraFrame2 = new QCameraFrame();
// 		cameraFrame2->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
		//mapWidget = new QDockWidget("Камера", cameraFrame);
		//mapWidget->setWidget(new QFrame());
		//mapWidget->setGeometry(Form->width() - 150, Form->height() - 150, 150, 150);
		//mapWidget->showFullScreen();
		//cameraFrame->SetSecondOutWnd((HWND)mapWidget->winId());
		hLayout = new QHBoxLayout(Form);
		hLayout->addWidget(cameraFrame, Qt::AlignLeft);

		objectivesMenu = new QMenu();
		objectivesMenu->addAction("X5");
		objectivesMenu->addAction("X10");
		objectivesMenu->addAction("X20");
		objectivesMenu->addAction("IX5");
		objectivesMenu->addAction("IX10");
		objectivesMenu->addAction("IX20");

		joystickMenu = new QMenu();
		joystickMenu->addAction("Медленно");
		joystickMenu->addAction("Нормально");
		joystickMenu->addAction("Быстро");
		joystickMenu->addAction("Рывки");
		joystickMenu->addAction("В зоне");

		navBar = new NavigationBar(true, Form);
		navBar->setGeometry(0, 9, 38, 476);
		navBar->addElement(QIcon(":/icons/Resources/icons/toFirst.png"), "Первый кристал");
		navBar->addElement(QIcon(":/icons/Resources/icons/next.png"), "Следующий кристал");
		navBar->addElement(QIcon(":/icons/Resources/icons/prev.png"), "Предыдущий кристал");
		navBar->addElement(QIcon(":/icons/Resources/icons/liftUp.png"), "Поднять зонды");
		navBar->addElement(QIcon(":/icons/Resources/icons/liftDown.png"), "Опустить зонды");
		navBar->addElement(QIcon(":/icons/Resources/icons/wizard.png"), "Мастер привязки");
		navBar->addElement(QIcon(":/icons/Resources/icons/lightning.png"), "Поднять напряжение");
		navBar->addElement(QIcon(":/icons/Resources/icons/endControl.png"), "Завершение контроля");
		navBar->addElement(QIcon(":/icons/Resources/icons/genReport.png"), "Генерация отчета");
		navBar->addElement(QIcon(":/icons/Resources/icons/saveImage.png"), "Сохранить изображение");
		navBar->addElement(QIcon(":/icons/Resources/icons/inversion.png"), "Инверсия цвета");
		navBar->addElement(QIcon(":/icons/Resources/icons/layer.png"), "Слои");
		navBar->addElement(QIcon(":/icons/Resources/icons/panorama.png"), "Панорамма кристалла");
		navBar->addElement(QIcon(":/icons/Resources/icons/objective.png"), "Объективы", objectivesMenu);
		navBar->addElement(QIcon(":/icons/Resources/icons/joystick.png"), "Режимы джойстика", joystickMenu);
	} // setupUi

};

namespace Ui {
	class Tab1 : public Ui_Tab1 {};
} // namespace Ui

QT_END_NAMESPACE