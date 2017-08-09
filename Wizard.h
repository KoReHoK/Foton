#pragma once
#include <deque>

class Wizard : public QWidget
{
	Q_OBJECT
private:

	QStackedWidget *mainWidget;
	QGridLayout		*gLayout;
	unsigned int thisPage;
	QToolButton *pNextButton;
	QToolButton	*pPrevButton;
	QToolButton	*pBeginButton;

private slots:
	void showNextPage();
	void showPrevPage();
	void showFirstPage();

public:
	Wizard(QWidget *parent = 0);
};

class IntroPage : public QWizardPage
{
private:
	QLabel *label;

public:
	IntroPage(QWidget *parent = 0) {
		//setTitle("Вас приветствует мастер привязки...");

		label = new QLabel(tr("Этот мастер поможет Вам привязать карту пластины с Вашим изображением."));
		label->setWordWrap(true);

		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(label);
		setLayout(layout);
	};
};

class FirstPage : public QWizardPage
{
private:
	QLabel *label;

public:
	FirstPage(QWidget *parent = 0) {
		//setTitle("Вас приветствует мастер привязки...");

		label = new QLabel(tr("First page"));
		label->setWordWrap(true);

		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(label);
		setLayout(layout);
	};
};

class SecondPage : public QWizardPage
{
private:
	QLabel *label;

public:
	SecondPage(QWidget *parent = 0) {
		//setTitle("Вас приветствует мастер привязки...");

		label = new QLabel(tr("Second page"));
		label->setWordWrap(true);

		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(label);
		setLayout(layout);
	};
};