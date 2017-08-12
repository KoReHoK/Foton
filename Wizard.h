#pragma once
#include <deque>

class IntroPage;
class FirstPage;
class FinishPage;

class Wizard : public QStackedWidget
{
	Q_OBJECT
private:

	IntroPage *introPage;
	FirstPage *firstPage;
	FinishPage *finishPage;

private slots:
	void showNextPage();
	void showPrevPage();
	void showIntroPage();

signals:
	void closeWizard();

public:
	Wizard(QWidget *parent = 0);
};

class IntroPage : public QWizardPage
{
	Q_OBJECT
private:
	QLabel *label;

	QToolButton *pNextButton;
	QToolButton	*pPrevButton;
	QToolButton	*pExitButton;

signals:
	void next();
	void exit();

public:
	IntroPage(QWidget *parent = 0) {

		label = new QLabel(tr("Этот мастер поможет Вам привязать карту пластины с Вашим изображением."));
		label->setWordWrap(true);

		pNextButton = new QToolButton();
		pNextButton->setText("Далее");
		pNextButton->setIcon(QIcon(":/icons/Resources/icons/nextStep.png"));
		pNextButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pNextButton->setFixedWidth(60);

		pPrevButton = new QToolButton();
		pPrevButton->setText("Назад");
		pPrevButton->setIcon(QIcon(":/icons/Resources/icons/prevStep.png"));
		pPrevButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pPrevButton->setFixedWidth(60);
		pPrevButton->setEnabled(false);

		pExitButton = new QToolButton();
		pExitButton->setText("Выход");
		pExitButton->setIcon(QIcon(":/icons/Resources/icons/goback.png"));
		pExitButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pExitButton->setFixedWidth(60);

		QGridLayout *glayout = new QGridLayout(this);
		glayout->addWidget(label, 0, 0, 1, 3, Qt::AlignCenter);
		glayout->addWidget(pPrevButton, 1, 0, 1, 1, Qt::AlignHCenter);
		glayout->addWidget(pNextButton, 1, 1, 1, 1, Qt::AlignHCenter);
		glayout->addWidget(pExitButton, 1, 2, 1, 1, Qt::AlignHCenter);

		connect(pNextButton, &QToolButton::clicked, this, &IntroPage::next);
		connect(pExitButton, &QToolButton::clicked, this, &IntroPage::exit);
	};
};

class FirstPage : public QWizardPage
{
	Q_OBJECT
private:
	QLabel *label;

	QToolButton *pNextButton;
	QToolButton	*pPrevButton;
	QToolButton	*pBeginButton;

signals:
	void next();
	void prev();
	void begin();

public:
	FirstPage(QWidget *parent = 0) {

		label = new QLabel(tr("First page"));
		label->setWordWrap(true);

		pNextButton = new QToolButton();
		pNextButton->setText("Далее");
		pNextButton->setIcon(QIcon(":/icons/Resources/icons/nextStep.png"));
		pNextButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pNextButton->setFixedWidth(60);

		pPrevButton = new QToolButton();
		pPrevButton->setText("Назад");
		pPrevButton->setIcon(QIcon(":/icons/Resources/icons/prevStep.png"));
		pPrevButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pPrevButton->setFixedWidth(60);

		pBeginButton = new QToolButton();
		pBeginButton->setText("Сначала");
		pBeginButton->setIcon(QIcon(":/icons/Resources/icons/goback.png"));
		pBeginButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pBeginButton->setFixedWidth(60);

		QGridLayout *glayout = new QGridLayout(this);
		glayout->addWidget(label, 0, 0, 1, 3, Qt::AlignCenter);
		glayout->addWidget(pPrevButton, 1, 0, 1, 1, Qt::AlignHCenter);
		glayout->addWidget(pNextButton, 1, 1, 1, 1, Qt::AlignHCenter);
		glayout->addWidget(pBeginButton, 1, 2, 1, 1, Qt::AlignHCenter);

		connect(pPrevButton, &QToolButton::clicked, this, &FirstPage::prev);
		connect(pNextButton, &QToolButton::clicked, this, &FirstPage::next);
		connect(pBeginButton, &QToolButton::clicked, this, &FirstPage::begin);
	};
};

class FinishPage : public QWizardPage
{
	Q_OBJECT
private:
	QLabel *label;

	QToolButton *pNextButton;
	QToolButton	*pPrevButton;
	QToolButton	*pExitButton;

signals:
	void prev();
	void exit();

public:
	FinishPage(QWidget *parent = 0) {

		label = new QLabel(tr("Финальная страница"));
		label->setWordWrap(true);

		pNextButton = new QToolButton();
		pNextButton->setText("Далее");
		pNextButton->setIcon(QIcon(":/icons/Resources/icons/nextStep.png"));
		pNextButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pNextButton->setFixedWidth(60);
		pNextButton->setEnabled(false);

		pPrevButton = new QToolButton();
		pPrevButton->setText("Назад");
		pPrevButton->setIcon(QIcon(":/icons/Resources/icons/prevStep.png"));
		pPrevButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pPrevButton->setFixedWidth(60);

		pExitButton = new QToolButton();
		pExitButton->setText("Выход");
		pExitButton->setIcon(QIcon(":/icons/Resources/icons/goback.png"));
		pExitButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
		pExitButton->setFixedWidth(60);

		QGridLayout *glayout = new QGridLayout(this);
		glayout->addWidget(label, 0, 0, 1, 3, Qt::AlignCenter);
		glayout->addWidget(pPrevButton, 1, 0, 1, 1, Qt::AlignHCenter);
		glayout->addWidget(pNextButton, 1, 1, 1, 1, Qt::AlignHCenter);
		glayout->addWidget(pExitButton, 1, 2, 1, 1, Qt::AlignHCenter);
		
		connect(pPrevButton, &QToolButton::clicked, this, &FinishPage::prev);
		connect(pExitButton, &QToolButton::clicked, this, &FinishPage::exit);
	};
};