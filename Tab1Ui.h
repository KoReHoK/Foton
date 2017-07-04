#pragma once

#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include "ViewWidget.h"
#include "CircumWidget.h"
#include "QCameraFrame.h"
#include "navigationbar.h"

QT_BEGIN_NAMESPACE

class Ui_Tab1
{
protected:
	ViewWidget *viewWidget;
	CircumWidget *circumWidget;
	QCameraFrame *cameraFrame;
	QWidget *rightWidgets;
	NavigationBar *navBar;

	QVBoxLayout *vLayout;
	QHBoxLayout *hLayout;

public:

	void setupUi(QWidget *Form)
	{
		if (Form->objectName().isEmpty())
			Form->setObjectName(QStringLiteral("Form"));
		Form->resize(400, 300);

		viewWidget = new ViewWidget();
		circumWidget = new CircumWidget();
		cameraFrame = new QCameraFrame();
		cameraFrame->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
		rightWidgets = new QWidget();
		rightWidgets->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);

		vLayout = new QVBoxLayout(rightWidgets);
		vLayout->addWidget(viewWidget, Qt::AlignTop);
		vLayout->addWidget(circumWidget, Qt::AlignTop);
		vLayout->addStretch();

		hLayout = new QHBoxLayout(Form);
		hLayout->addWidget(cameraFrame, Qt::AlignLeft);
		hLayout->addWidget(rightWidgets, Qt::AlignRight);

		navBar = new NavigationBar(Form);
		navBar->setGeometry(0, 0, 38, 476);
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

		QMetaObject::connectSlotsByName(Form);
	} // setupUi

};

namespace Ui {
	class Tab1 : public Ui_Tab1 {};
} // namespace Ui

QT_END_NAMESPACE