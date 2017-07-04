#pragma once

#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1
{
public:

	void setupUi(QWidget *Form)
	{
		if (Form->objectName().isEmpty())
			Form->setObjectName(QStringLiteral("Form"));
		Form->resize(400, 300);

		QMetaObject::connectSlotsByName(Form);
	} // setupUi

};

namespace Ui {
	class Tab1 : public Ui_Tab1 {};
} // namespace Ui

QT_END_NAMESPACE