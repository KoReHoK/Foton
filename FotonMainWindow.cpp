#include "stdafx.h"
#include "FotonMainWindow.h"

struct myToolButton {
	QIcon icon;
	QString toolTip;
	QMenu *menu;
};

FotonMainWindow::FotonMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupCentralWidget();
	setupStatusBar();
	setupToolBar();

	loadSettings();
}

FotonMainWindow::~FotonMainWindow()
{
	saveSettings();
}

void FotonMainWindow::setupCentralWidget()
{
	centralWidget = new QTabWidget(this);
	setCentralWidget(centralWidget);

	settings = new QSettings("config.ini", QSettings::Format::IniFormat, this);

	tab1 = new Tab1(centralWidget);
	tab2 = new Tab2(centralWidget);
	tab3 = new Tab3(centralWidget);

	centralWidget->addTab(tab1, "Осмотр");
	centralWidget->addTab(tab2, "Карта");
	centralWidget->addTab(tab3, "Настройки");
}

void FotonMainWindow::setupStatusBar()
{
	statusBar = new QStatusBar(this);
	statusBar->addWidget(new QLabel("StatusBar"));
	setStatusBar(statusBar);
}

void FotonMainWindow::setupToolBar()
{
	toolBar = new QToolBar(this);
	toolBar->setMovable(false);
	
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
	tButton.push_back({ QIcon(":/icons/Resources/icons/saveImage.png"), "Сохранить изображение", nullptr });
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
		tmp->setEnabled(false);
		tmp->installEventFilter(this);
		myToolBar.push_back(tmp);
		toolBar->addWidget(tmp);
		//delete *i;
	}

	myToolBar.at(0)->setEnabled(true);	// new analyses
	addToolBar(toolBar);
}

void FotonMainWindow::saveSettings()
{
	settings->setValue("geometry", geometry());
}

void FotonMainWindow::loadSettings()
{
	setGeometry(settings->value("geometry", QRect(200, 200, 600, 600)).toRect());
}

bool FotonMainWindow::eventFilter(QObject *watched, QEvent *event) {
	QToolButton *tmp;
	if ( (tmp = dynamic_cast<QToolButton*>(watched)) && tmp->isEnabled() && (event->type() == QEvent::MouseButtonPress) ) {	// successful
		
		if (tmp->toolTip() == "Новый анализ") {
			analysDialog = new NewAnalysDialog(this);
			if (analysDialog->exec() == QDialog::Accepted) {
				if (analysDialog->getMode()) {
					// Однокристальный режим
					QMessageBox::information(this,
						"infa100%",
						"Вы выбрали однокристальный режим");
					centralWidget->setCurrentIndex(0);	// вкладка осмотр
				}
				else {
					// Многокристальный режим
					QMessageBox::information(this,
						"infa100%",
						"Вы выбрали многокристальный режим");
					centralWidget->setCurrentIndex(1);	// вкладка карта
				}

				myToolBar.at(6)->setEnabled(true);	// мастер привязки
			}
			delete analysDialog;
		}
		else {
			tab1->dialog(&tmp->toolTip());
		}
	}

	return QMainWindow::eventFilter(watched, event);
}