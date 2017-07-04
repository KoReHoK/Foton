#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QGridLayout>
#include "ButtonsPult.h"
#include "HotButtons.h"
#include "ElseSettings.h"
#include "CameraSettings.h"

QT_BEGIN_NAMESPACE

class Ui_Tab3
{
protected:
	CameraSettings	*visibleCamera;
	CameraSettings		*ikCamera;
	ButtonsPult		*buttonsPult;
	HotButtons		*hotButtons;
	ElseSettings	*settings;
	QToolBox		*toolBox;
	QWidget			*cameraWidget;
	QWidget			*gistWidget;
	//QImage			*etiketka;
	QGridLayout		*gLayout;
public:

	void setupUi(QWidget *Form)
	{
		if (Form->objectName().isEmpty())
			Form->setObjectName(QStringLiteral("Form"));
		Form->resize(400, 300);

		visibleCamera = new CameraSettings();
		visibleCamera->addSetings("Экспозиция");
		visibleCamera->addSetings("Яркость");
		visibleCamera->addSetings("Усиление (цифр.)");
		visibleCamera->addSetings("Усиление (аналог.)");
		visibleCamera->addSetings("FPS");
		visibleCamera->addSetings("Гамма");
		visibleCamera->addSetings("Насыщенность");
		visibleCamera->addSetings("Красный");
		visibleCamera->addSetings("Синий");
		visibleCamera->addSetings("Зеленый");

		ikCamera = new CameraSettings();
		ikCamera->addSetings("Экспозиция");
		ikCamera->addSetings("Яркость");
		ikCamera->addSetings("Усиление (цифр.)");
		ikCamera->addSetings("Усиление (аналог.)");
		ikCamera->addSetings("FPS");

		buttonsPult = new ButtonsPult();
		hotButtons = new HotButtons();
		settings = new ElseSettings();
		toolBox = new QToolBox();
		toolBox->addItem(visibleCamera, "Камера видимого спектра");
		toolBox->addItem(ikCamera, "ИК камера");
		toolBox->addItem(buttonsPult, "Кнопки пульта");
		toolBox->addItem(hotButtons, "Горячие клавиши");
		toolBox->addItem(settings, "Прочие настройки");

		cameraWidget = new QWidget();
		gistWidget = new QWidget();

		gLayout = new QGridLayout(Form);
		gLayout->addWidget(toolBox, 0, 0, 2, 1, Qt::AlignLeft);
		gLayout->addWidget(cameraWidget, 0, 1, 1, 2, Qt::AlignRight);
		gLayout->addWidget(gistWidget, 1, 1, 1, 1, Qt::AlignCenter);
		//gLayout->addWidget(etiketka, 1, 2, 1, 1, Qt::AlignCenter);

		QMetaObject::connectSlotsByName(Form);
	} // setupUi

};

namespace Ui {
	class Tab3 : public Ui_Tab3 {};
} // namespace Ui

QT_END_NAMESPACE