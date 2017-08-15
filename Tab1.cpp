#include "stdafx.h"
#include "Tab1.h"

Tab1::Tab1(QWidget *parent)
	: QWidget(parent)
{
	QCameraFrame *cameraFrame = new QCameraFrame(true);
	cameraFrame->setParent(this);
	cameraFrame->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

	QGraphicsScene *scene = new QGraphicsScene(this);
	QGraphicsItem *item1 = new  QGraphicsPixmapItem(QPixmap(":/icons/Resources/icons/endControl.png"));
	item1->setPos(0, 0);
	QGraphicsItem *item2 = new  QGraphicsPixmapItem(QPixmap(":/icons/Resources/icons/toFirst.png"));
	item1->setPos(300, 0);
	scene->addItem(item1);
	scene->addItem(item2);

	QGraphicsView *panoramaView = new QGraphicsView(this);
	panoramaView->setScene(scene);

	mainWidget = new QStackedWidget(this);
	mainWidget->addWidget(cameraFrame);
	mainWidget->addWidget(panoramaView);

	QHBoxLayout *hLayout = new QHBoxLayout(this);
	hLayout->addWidget(mainWidget, Qt::AlignLeft);

	NavigationBar *defBar = new NavigationBar(true, this);
	defBar->addElement(QIcon(":/icons/Resources/icons/toFirst.png"), "Первый кристал");
	defBar->addElement(QIcon(":/icons/Resources/icons/next.png"), "Следующий кристал");
	defBar->addElement(QIcon(":/icons/Resources/icons/prev.png"), "Предыдущий кристал");
	defBar->setGeometry(0, 9, 38, 170);
}

void Tab1::showCamera() {
	mainWidget->setCurrentIndex(0);
}

void Tab1::showPanorama()
{
	mainWidget->setCurrentIndex(1);
}

void Tab1::showWizard() {
	if (!wizard) {
		wizard = new Wizard(this);
		connect(wizard, &Wizard::closeWizard, this, &Tab1::deleteWizard);

		wizard->setFixedSize(200, 200);
		wizard->move(width() - 200, 0);
		wizard->show();
		wizard->setAutoFillBackground(true);
	}
}

void Tab1::deleteWizard() {
	if (wizard) {
		delete wizard;
		wizard = nullptr;
	}
}

void Tab1::updateFrame(uchar * newFrame, int w, int h, int bits)
{
	if(QCameraFrame *tmp = dynamic_cast<QCameraFrame*>(mainWidget->currentWidget()))
		tmp->updateFrame(newFrame, w, h, bits);
}

void Tab1::resizeEvent(QResizeEvent *event) {
	if(wizard)
		wizard->move(width() - 200, 0);
}