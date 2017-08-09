#include "stdafx.h"
#include "Tab1.h"

Tab1::Tab1(QWidget *parent)
	: QWidget(parent)
{
	scene = nullptr;
	wizard = nullptr;

	cameraFrame = new QCameraFrame();
	cameraFrame->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

	hLayout = new QHBoxLayout(this);
	hLayout->addWidget(cameraFrame, Qt::AlignLeft);

	defBar = new NavigationBar(true, cameraFrame);
	defBar->addElement(QIcon(":/icons/Resources/icons/toFirst.png"), "Первый кристал");
	defBar->addElement(QIcon(":/icons/Resources/icons/next.png"), "Следующий кристал");
	defBar->addElement(QIcon(":/icons/Resources/icons/prev.png"), "Предыдущий кристал");
	//mJob = new QJobMicro("JobMicro.dll");
	//mJob->Init();
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
		hLayout->removeWidget(cameraFrame);
		hLayout->addWidget(view);
	}

	if ((*tmp == "Мастер привязки") && !wizard) {
		wizard = new Wizard(this);

		wizard->setFixedSize(200, 200);
		wizard->move(width() - 200, 0);
		wizard->show();
		wizard->setAutoFillBackground(true);
	}
}

void Tab1::resizeEvent(QResizeEvent * event)
{
	defBar->move(0, 0);
	if (wizard)
		wizard->move(width() - 200, 0);
}