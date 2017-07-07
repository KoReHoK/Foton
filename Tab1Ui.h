#pragma once

#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QDockWidget>
#include "ViewWidget.h"
#include "CircumWidget.h"
#include "QCameraFrame.h"
#include "navigationbar.h"
#include <QMenu>

QT_BEGIN_NAMESPACE

class Ui_Tab1
{
protected:
	QCameraFrame *cameraFrame;
	QCameraFrame *cameraFrame2;
	NavigationBar *navBar;
	QDockWidget	*mapWidget;

	QVBoxLayout *vLayout;
	QHBoxLayout *hLayout;
	QMenu* ObjectivesMenu = nullptr;

public:

	void setupUi(QWidget *Form)
	{
		if (Form->objectName().isEmpty())
			Form->setObjectName(QStringLiteral("Form"));
		Form->resize(400, 300);

		cameraFrame = new QCameraFrame();
		cameraFrame->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

		/*cameraFrame2 = new QCameraFrame();
		cameraFrame2->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
		mapWidget = new QDockWidget("Камера", cameraFrame);
		mapWidget->setWidget(cameraFrame2);
		mapWidget->setGeometry(Form->width() - 150, Form->height() - 150, 150, 150);
		mapWidget->showFullScreen();*/

		hLayout = new QHBoxLayout(Form);
		hLayout->addWidget(cameraFrame, Qt::AlignLeft);

		ObjectivesMenu = new QMenu();
		ObjectivesMenu->addAction("X5");
		ObjectivesMenu->addAction("X10");
		ObjectivesMenu->addAction("X20");
		ObjectivesMenu->addAction("IX5");
		ObjectivesMenu->addAction("IX10");
		ObjectivesMenu->addAction("IX20");

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
		navBar->addElement(QIcon(""), "Объективы", ObjectivesMenu);
		navBar->addElement(QIcon(""), "Режимы джойстика");

		//QMetaObject::connectSlotsByName(Form);
	} // setupUi

};

namespace Ui {
	class Tab1 : public Ui_Tab1 {};
} // namespace Ui

QT_END_NAMESPACE