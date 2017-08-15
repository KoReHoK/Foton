#include "stdafx.h"
#include "Tab2.h"

Tab2::Tab2(QWidget *parent)
	: QWidget(parent)
{
	SettingsWidget *settings = new SettingsWidget(this);
	LegendWidget *legend = new LegendWidget(this);
	QToolBox *toolBox = new QToolBox(this);
	toolBox->addItem(settings, "Настройка карты пластины");
	toolBox->addItem(legend, "Легенда");
	toolBox->setFixedWidth(300);

	NavigationBar *navBar = new NavigationBar(true, this);
	navBar->addElement(QIcon(":/icons/Resources/icons/createFile.png"), "Создать");
	navBar->addElement(QIcon(":/icons/Resources/icons/openFile.png"), "Открыть");
	navBar->addElement(QIcon(":/icons/Resources/icons/saveFile.png"), "Сохранить");
	navBar->addElement(QIcon(":/icons/Resources/icons/handLayer.png"), "Выделить");
	navBar->setGeometry(0, 9, 38, 170);
	connect(navBar, &NavigationBar::showDialog, this, &Tab2::dialog);
	
	QWidget *widget = new QWidget();
	QHBoxLayout *hLayout = new QHBoxLayout(this);
	hLayout->addWidget(widget, 0, Qt::AlignLeft);
	hLayout->addWidget(toolBox, 0, Qt::AlignRight);

	cameraFrame = new QCameraFrame(false);
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

void Tab2::updateFrame(uchar * newFrame, int w, int h, int bits)
{
	cameraFrame->updateFrame(newFrame, w, h, bits);
}