#pragma once

#include "SettingsWidget.h"
#include "LegendWidget.h"
#include "navigationbar.h"

QT_BEGIN_NAMESPACE

class Ui_Tab2
{
protected:
	SettingsWidget *settings;
	LegendWidget	*legend;
	QWidget			*widget;
	QHBoxLayout		*hLayout;
	QToolBox		*toolBox;
	NavigationBar	*navBar;
public:

	void setupUi(QWidget *Form)
	{
		settings = new SettingsWidget();
		legend = new LegendWidget();
		toolBox = new QToolBox(Form);
		toolBox->addItem(settings, "Настройки карты пластины");
		toolBox->addItem(legend, "Легенда");
		toolBox->setFixedWidth(300);
		navBar = new NavigationBar(true, Form);
		navBar->addElement(QIcon(":/icons/Resources/icons/createFile.png"), "Создать");
		navBar->addElement(QIcon(":/icons/Resources/icons/openFile.png"), "Открыть");
		navBar->addElement(QIcon(":/icons/Resources/icons/saveFile.png"), "Сохранить");
		navBar->addElement(QIcon(":/icons/Resources/icons/handLayer.png"), "Выделить");
		navBar->setGeometry(0, 9, 38, 170);
		widget = new QWidget();
		hLayout = new QHBoxLayout(Form);
		hLayout->addWidget(widget, 0, Qt::AlignLeft);
		hLayout->addWidget(toolBox, 0, Qt::AlignRight);
	} // setupUi

};

namespace Ui {
	class Tab2 : public Ui_Tab2 {};
} // namespace Ui

QT_END_NAMESPACE