#include "stdafx.h"
#include "Tab1.h"

Tab1::Tab1(QWidget *parent)
	: QWidget(parent)
{
	scene = nullptr;

	cameraFrame = new QCameraFrame();
	cameraFrame->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

	hLayout = new QHBoxLayout(this);
	hLayout->addWidget(cameraFrame, Qt::AlignLeft);

	QList<QPushButton*> listObjectives;
	listObjectives << new QPushButton("X5")
		<< new QPushButton("X10")
		<< new QPushButton("X20")
		<< new QPushButton("IX5")
		<< new QPushButton("IX10")
		<< new QPushButton("IX20");
	objectivesMenu = new MenuWidget(&listObjectives, this);

	QList<QPushButton*> listJoystik;
	listJoystik << new QPushButton("Медленно")
		<< new QPushButton("Нормально")
		<< new QPushButton("Быстро")
		<< new QPushButton("Рывки")
		<< new QPushButton("В зоне");
	joystickMenu = new MenuWidget(&listJoystik, this);

	navBar = new NavigationBar(true, this);
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
	navBar->addElement(QIcon(":/icons/Resources/icons/objective.png"), "Объектив", objectivesMenu);
	navBar->addElement(QIcon(":/icons/Resources/icons/joystick.png"), "Режим джойстика", joystickMenu);

	defBar = new NavigationBar(false, this);
	defBar->addElement(QIcon(":/icons/Resources/icons/toFirst.png"), "Первый кристал");
	defBar->addElement(QIcon(":/icons/Resources/icons/next.png"), "Следующий кристал");
	defBar->addElement(QIcon(":/icons/Resources/icons/prev.png"), "Предыдущий кристал");

	connect(navBar, &NavigationBar::showDialog, this, &Tab1::dialog);
}

void Tab1::dialog(QString *tmp) {
	if ((*tmp == "Панорама кристалла") && !scene) {

		scene = new QGraphicsScene();
		QGraphicsItem *item1 = new  QGraphicsPixmapItem(QPixmap(":/icons/Resources/icons/endControl.png"));
		item1->setPos(0, 0);
		QGraphicsItem *item2 = new  QGraphicsPixmapItem(QPixmap(":/icons/Resources/icons/toFirst.png"));
		item1->setPos(300, 0);
		scene->addItem(item1);
		scene->addItem(item2);

		view = new QGraphicsView(scene);
		view->show();
	}
}

void Tab1::resizeEvent(QResizeEvent * event)
{
	navBar->move(0, 9);
	defBar->move(width() - 36, 9);
}