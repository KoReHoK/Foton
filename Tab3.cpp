#include "stdafx.h"
#include "Tab3.h"

Tab3::Tab3(QWidget *parent)
	: QWidget(parent)
{
	CameraSettings *visibleCamera = new CameraSettings(new QString("visibleCamera"), this);
	visibleCamera->addSettings("Экспозиция");
	visibleCamera->addSettings("Яркость");
	visibleCamera->addSettings("Усиление (цифр.)");
	visibleCamera->addSettings("Усиление (аналог.)");
	visibleCamera->addSettings("FPS");
	visibleCamera->addSettings("Гамма");
	visibleCamera->addSettings("Насыщенность");
	visibleCamera->addSettings("Красный");
	visibleCamera->addSettings("Синий");
	visibleCamera->addSettings("Зеленый");
	visibleCamera->addFieldSettings("X5");
	visibleCamera->addFieldSettings("X10");
	visibleCamera->addFieldSettings("X20");
	visibleCamera->loadSettings();

	CameraSettings *ikCamera = new CameraSettings(new QString("ikCamera"), this);
	ikCamera->addSettings("Экспозиция");
	ikCamera->addSettings("Яркость");
	ikCamera->addSettings("Усиление (цифр.)");
	ikCamera->addSettings("Усиление (аналог.)");
	ikCamera->addSettings("FPS");
	ikCamera->addFieldSettings("IX5");
	ikCamera->addFieldSettings("IX10");
	ikCamera->addFieldSettings("IX20");
	ikCamera->loadSettings();

	TableSettings *buttonsPult = new TableSettings(this);
	TableSettings *hotButtons = new TableSettings(this);
	ElseSettings *settings = new ElseSettings(this);
	QToolBox *toolBox = new QToolBox(this);
	toolBox->addItem(visibleCamera, "Камера видимого спектра");
	toolBox->addItem(ikCamera, "ИК камера");
	toolBox->addItem(buttonsPult, "Кнопки пульта");
	toolBox->addItem(hotButtons, "Горячие клавиши");
	toolBox->addItem(settings, "Прочие настройки");
	toolBox->setFixedWidth(300);

	/*Redaktor *redaktor = new Redaktor(this);
	connect(this, &Tab3::addDef, redaktor, &Redaktor::addDef);*/

	ModelViewDemoWidget *demoWidget = new ModelViewDemoWidget(this);
	connect(this, &Tab3::addDef, demoWidget, &ModelViewDemoWidget::onAppend);

	QGridLayout *gLayout = new QGridLayout(this);
	gLayout->addWidget(toolBox, 0, 0, 1, 1, Qt::AlignLeft);
	gLayout->addWidget(demoWidget, 0, 1, 1, 1);
}