#include "stdafx.h"
#include "Tab1.h"

Tab1::Tab1(QWidget *parent)
	: QWidget(parent)
{
	cameraFrame = new QCameraFrame();
	cameraFrame->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

	hLayout = new QHBoxLayout(this);
	hLayout->addWidget(cameraFrame, Qt::AlignLeft);

	objectivesMenu = new QMenu(this);
	QList<QAction*> listMenu;
	listMenu << new QAction("X5")
		<< new QAction("X10")
		<< new QAction("X20")
		<< new QAction("IX5")
		<< new QAction("IX10")
		<< new QAction("IX20");
	objectivesMenu->addActions(listMenu);

	joystickMenu = new QMenu(this);
	QList<QAction*> listJoystik;
	listJoystik << new QAction("Медленно")
		<< new QAction("Нормально")
		<< new QAction("Быстро")
		<< new QAction("Рывки")
		<< new QAction("В зоне");
	joystickMenu->addActions(listJoystik);

	navBar = new NavigationBar(true, this);
	navBar->setGeometry(0, 9, 38, 476);
	navBar->addElement(QIcon(":/icons/Resources/icons/toFirst.png"), "Первый кристал");
	navBar->addElement(QIcon(":/icons/Resources/icons/next.png"), "Следующий кристал");
	navBar->addElement(QIcon(":/icons/Resources/icons/prev.png"), "Предыдущий кристал");
	navBar->addElement(QIcon(":/icons/Resources/icons/liftUp.png"), "Поднять зонды");
	navBar->addElement(QIcon(":/icons/Resources/icons/liftDown.png"), "Опустить зонды");
	navBar->addElement(QIcon(":/icons/Resources/icons/wizard.png"), "Мастер привязки");
	navBar->addElement(QIcon(":/icons/Resources/icons/lightning.png"), "Подать напряжение");
	navBar->addElement(QIcon(":/icons/Resources/icons/endControl.png"), "Завершнение контроля");
	navBar->addElement(QIcon(":/icons/Resources/icons/genReport.png"), "Генерация отчета");
	navBar->addElement(QIcon(":/icons/Resources/icons/saveImage.png"), "Сохранить изображение");
	navBar->addElement(QIcon(":/icons/Resources/icons/inversion.png"), "Инверсия цвета");
	navBar->addElement(QIcon(":/icons/Resources/icons/layer.png"), "Слои");
	navBar->addElement(QIcon(":/icons/Resources/icons/panorama.png"), "Панорама кристалла");
	navBar->addElement(QIcon(":/icons/Resources/icons/objective.png"), "Оъектив", objectivesMenu);
	navBar->addElement(QIcon(":/icons/Resources/icons/joystick.png"), "Режим джойстика", joystickMenu);

	connect(navBar, &NavigationBar::showDialog, this, &Tab1::dialog);
}

Tab1::~Tab1()
{
}

void Tab1::dialog(QString *tmp) {
	//if (*tmp == "Открыть")
	//	QString str = QFileDialog::getOpenFileName(0, "Открыть файл", "*.cpp *.h");
	//if (*tmp == "Сохранить")
	//	QString str = QFileDialog::getSaveFileName(0, "Сохранить файл", "*.cpp *.h");
}