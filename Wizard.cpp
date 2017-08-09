#include "stdafx.h"
#include "Wizard.h"

Wizard::Wizard(QWidget *parent)
	: QWidget(parent)
{
	mainWidget = new QStackedWidget();
	mainWidget->addWidget(new IntroPage);
	mainWidget->addWidget(new FirstPage);
	mainWidget->addWidget(new SecondPage);
	gLayout = new QGridLayout(this);

	thisPage = 0;

	pNextButton = new QToolButton();
	pNextButton->setText("Далее");
	pNextButton->setIcon(QIcon(":/icons/Resources/icons/nextStep.png"));
	pNextButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
	pNextButton->setFixedWidth(60);
	connect(pNextButton, &QToolButton::clicked, this, &Wizard::showNextPage);

	pPrevButton = new QToolButton();
	pPrevButton->setText("Назад");
	pPrevButton->setIcon(QIcon(":/icons/Resources/icons/prevStep.png"));
	pPrevButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
	pPrevButton->setFixedWidth(60);
	connect(pPrevButton, &QToolButton::clicked, this, &Wizard::showPrevPage);

	pBeginButton = new QToolButton();
	pBeginButton->setText("Сначала");
	pBeginButton->setIcon(QIcon(":/icons/Resources/icons/goback.png"));
	pBeginButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
	pBeginButton->setFixedWidth(60);
	connect(pBeginButton, &QToolButton::clicked, this, &Wizard::showFirstPage);

	gLayout->addWidget(mainWidget,0, 0, 1, 3, Qt::AlignHCenter);
	gLayout->addWidget(pPrevButton, 1, 0, 1, 1, Qt::AlignHCenter);
	gLayout->addWidget(pNextButton, 1, 1, 1, 1, Qt::AlignHCenter);
	gLayout->addWidget(pBeginButton, 1, 2, 1, 1, Qt::AlignHCenter);

	//setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
	//setPixmap(QWizard::BackgroundPixmap, QPixmap(":/images/background.png"));

	//setWindowTitle(tr("Мастер привязки"));
}

void Wizard::showNextPage() {
	if (thisPage < (mainWidget->count() - 1)) 
		mainWidget->setCurrentIndex(++thisPage);
}

void Wizard::showPrevPage() {
	if ((mainWidget->count() > 0) && (thisPage > 0))
		mainWidget->setCurrentIndex(--thisPage);
}

void Wizard::showFirstPage() {
	thisPage = 0;
	mainWidget->setCurrentIndex(thisPage);
}