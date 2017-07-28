#include "stdafx.h"
#include "Tab3.h"

Tab3::Tab3(QWidget *parent)
	: QWidget(parent)
{
	visibleCamera = new CameraSettings(new QString("visibleCamera"));
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

	ikCamera = new CameraSettings(new QString("ikCamera"));
	ikCamera->addSettings("Экспозиция");
	ikCamera->addSettings("Яркость");
	ikCamera->addSettings("Усиление (цифр.)");
	ikCamera->addSettings("Усиление (аналог.)");
	ikCamera->addSettings("FPS");
	ikCamera->addFieldSettings("IX5");
	ikCamera->addFieldSettings("IX10");
	ikCamera->addFieldSettings("IX20");
	ikCamera->loadSettings();

	buttonsPult = new TableSettings();
	hotButtons = new TableSettings();
	settings = new ElseSettings();
	toolBox = new QToolBox();
	toolBox->addItem(visibleCamera, "Камера видимого спектра");
	toolBox->addItem(ikCamera, "ИК камера");
	toolBox->addItem(buttonsPult, "Кнопки пульта");
	toolBox->addItem(hotButtons, "Горячие клавиши");
	toolBox->addItem(settings, "Прочие настройки");
	toolBox->setFixedWidth(300);

	//cameraWidget = new QWidget();
	//gistWidget = new QWidget();

	gLayout = new QGridLayout(this);
	gLayout->addWidget(toolBox, 0, 0, 2, 1, Qt::AlignLeft);
	//gLayout->addWidget(cameraWidget, 0, 1, 1, 2, Qt::AlignRight);
	//gLayout->addWidget(gistWidget, 1, 1, 1, 1, Qt::AlignCenter);
	//gLayout->addWidget(etiketka, 1, 2, 1, 1, Qt::AlignCenter);
}

Tab3::~Tab3()
{
}