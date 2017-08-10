#include "stdafx.h"
#include "ToolBar.h"

struct myToolButton {
	QIcon icon;
	QString toolTip;
	QMenu *menu;
};

ToolBar::ToolBar(QWidget *parent) 
	: QToolBar(parent)
{
	setMovable(false);

	QList<QAction*> listObjectives;
	listObjectives << new QAction("X5");
	listObjectives << new QAction("X10");
	listObjectives << new QAction("X20");
	listObjectives << new QAction("IX5");
	listObjectives << new QAction("IX10");
	listObjectives << new QAction("IX20");

	QMenu *tmpObjectives;
	tmpObjectives = new QMenu();
	tmpObjectives->addActions(listObjectives);

	QList<QAction*> listJoystick;
	listJoystick << new QAction("Медленно");
	listJoystick << new QAction("Нормально");
	listJoystick << new QAction("Быстро");
	listJoystick << new QAction("Рывки");
	listJoystick << new QAction("В зоне");

	QMenu *tmpJoystik;
	tmpJoystik = new QMenu();
	tmpJoystik->addActions(listJoystick);

	QVector<myToolButton> tButton;
	tButton.push_back({ QIcon(":/icons/Resources/icons/analyse.png"), "Новый анализ", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/toFirst.png"), "Первый кристал", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/next.png"), "Следующий кристал", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/prev.png"), "Предыдущий кристал", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/liftUp.png"), "Поднять зонды", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/liftDown.png"), "Опустить зонды", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/wizard.png"), "Мастер привязки", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/lightning.png"), "Подать напряжение", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/endControl.png"), "Завершнение контроля", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/genReport.png"), "Генерация отчета", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/saveImage.png"), "Камера", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/inversion.png"), "Инверсия цвета", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/layer.png"), "Слои", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/panorama.png"), "Панорама кристалла", nullptr });
	tButton.push_back({ QIcon(":/icons/Resources/icons/objective.png"), "Объектив", tmpObjectives });
	tButton.push_back({ QIcon(":/icons/Resources/icons/joystick.png"), "Режим джойстика", tmpJoystik });

	QVector<myToolButton>::iterator i = tButton.begin();
	for (; i != tButton.end(); ++i) {
		QToolButton *tmp;
		tmp = new QToolButton();
		tmp->setIcon((*i).icon);
		tmp->setToolTip((*i).toolTip);
		if ((*i).menu) {
			tmp->setMenu((*i).menu);
			tmp->setPopupMode(QToolButton::ToolButtonPopupMode::MenuButtonPopup);
		}
		tmp->setEnabled(true);
		tmp->installEventFilter(this);
		myToolBar.push_back(tmp);
		addWidget(tmp);
	}

	myToolBar.at(0)->setEnabled(true);	// new analyses
}

bool ToolBar::eventFilter(QObject *watched, QEvent *event) {
	QToolButton *tmp;
	if ((tmp = dynamic_cast<QToolButton*>(watched)) && tmp->isEnabled() && (event->type() == QEvent::MouseButtonPress)) {	// successful

		if (tmp->toolTip() == "Новый анализ") {
			newAnalys = new NewAnalysDialog(this);
			if (newAnalys->exec() == QDialog::Accepted) {
				if (newAnalys->getMode()) {
					// Однокристальный режим
					QMessageBox::information(this,
						"infa100%",
						"Вы выбрали однокристальный режим");
					//centralWidget->setCurrentIndex(0);	// вкладка осмотр
				}
				else {
					// Многокристальный режим
					QMessageBox::information(this,
						"infa100%",
						"Вы выбрали многокристальный режим");
					//centralWidget->setCurrentIndex(1);	// вкладка карта
				}

				myToolBar.at(6)->setEnabled(true);	// мастер привязки
			}
			delete newAnalys;
		};

		if ((tmp->toolTip() == "Мастер привязки") && !wizard) {

			QMessageBox::information(this,
				"infa100%",
				"Вы выбрали мастер привязки");

			wizard = new Wizard();

			wizard->setFixedSize(200, 200);
			wizard->move(width() - 200, 0);
			wizard->show();
			wizard->setAutoFillBackground(true);
		};

		if (tmp->toolTip() == "Панорама кристалла") {

			emit showPanorama();

			QMessageBox::information(this,
				"infa100%",
				"Вы выбрали режим панорамы");
		}

		if (tmp->toolTip() == "Камера") {

			emit showCamera();

			QMessageBox::information(this,
				"infa100%",
				"Вы выбрали режим камеры");
		}
	}

	return QToolBar::eventFilter(watched, event);
}