#pragma once

#include "TableSettings.h"
#include "ElseSettings.h"
#include "CameraSettings.h"

QT_BEGIN_NAMESPACE

class Ui_Tab3
{
protected:
	CameraSettings	*visibleCamera;
	CameraSettings	*ikCamera;
	TableSettings	*buttonsPult;
	TableSettings	*hotButtons;
	ElseSettings	*settings;
	QToolBox		*toolBox;
	QWidget			*cameraWidget;
	QWidget			*gistWidget;
	//QImage			*etiketka;
	QGridLayout		*gLayout;
public:

	void setupUi(QWidget *Form)
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

		gLayout = new QGridLayout(Form);
		gLayout->addWidget(toolBox, 0, 0, 2, 1, Qt::AlignLeft);
		//gLayout->addWidget(cameraWidget, 0, 1, 1, 2, Qt::AlignRight);
		//gLayout->addWidget(gistWidget, 1, 1, 1, 1, Qt::AlignCenter);
		//gLayout->addWidget(etiketka, 1, 2, 1, 1, Qt::AlignCenter);
	} // setupUi

};

namespace Ui {
	class Tab3 : public Ui_Tab3 {};
} // namespace Ui

QT_END_NAMESPACE