#include "stdafx.h"
#include "Tab2.h"

Tab2::Tab2(QWidget *parent)
	: QWidget(parent)
{
	settings = new SettingsWidget();
	legend = new LegendWidget();
	toolBox = new QToolBox(this);
	toolBox->addItem(settings, "Настройка карты пластины");
	toolBox->addItem(legend, "Легенда");
	toolBox->setFixedWidth(300);
	navBar = new NavigationBar(true, this);
	navBar->addElement(QIcon(":/icons/Resources/icons/createFile.png"), "Создать");
	navBar->addElement(QIcon(":/icons/Resources/icons/openFile.png"), "Открыть");
	navBar->addElement(QIcon(":/icons/Resources/icons/saveFile.png"), "Сохранить");
	navBar->addElement(QIcon(":/icons/Resources/icons/handLayer.png"), "Выделить");
	connect(navBar, &NavigationBar::showDialog, this, &Tab2::dialog);
	navBar->setGeometry(0, 9, 38, 170);
	widget = new QWidget();
	hLayout = new QHBoxLayout(this);
	hLayout->addWidget(widget, 0, Qt::AlignLeft);
	hLayout->addWidget(toolBox, 0, Qt::AlignRight);

	cameraFrame = new QCameraFrame();
	cameraFrame->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
	cameraFrame->setParent(this);
	cameraFrame->setGeometry(0, height() - 195, 255, 195);	// 13:17 соотношение сторон
}

void Tab2::dialog(QString *tmp) {
	if(*tmp == "Открыть")
		QString str = QFileDialog::getOpenFileName(0, "Открыть файл", "*.cpp *.h");
	if (*tmp == "Сохранить")
		QString str = QFileDialog::getSaveFileName(0, "Сохранить файл", "*.cpp *.h");
}

void Tab2::resizeEvent(QResizeEvent *event) {
	if (cameraFrame)
		cameraFrame->move(0, height() - cameraFrame->height());
}