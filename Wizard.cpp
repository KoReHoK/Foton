#include "stdafx.h"
#include "Wizard.h"

Wizard::Wizard(QWidget *parent)
	: QStackedWidget(parent)
{
	introPage = new IntroPage();
	connect(introPage, &IntroPage::next, this, &Wizard::showNextPage);
	connect(introPage, &IntroPage::exit, this, &Wizard::closeWizard);

	firstPage = new FirstPage();
	connect(firstPage, &FirstPage::prev, this, &Wizard::showPrevPage);
	connect(firstPage, &FirstPage::next, this, &Wizard::showNextPage);
	connect(firstPage, &FirstPage::begin, this, &Wizard::showIntroPage);

	finishPage = new FinishPage();
	connect(finishPage, &FinishPage::prev, this, &Wizard::showPrevPage);
	connect(finishPage, &FinishPage::exit, this, &Wizard::closeWizard);

	addWidget(introPage);
	addWidget(firstPage);
	addWidget(finishPage);

	//setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
	//setPixmap(QWizard::BackgroundPixmap, QPixmap(":/images/background.png"));

	//setWindowTitle(tr("Мастер привязки"));
}

void Wizard::showNextPage() {
	if (currentIndex() < (count() - 1)) 
		setCurrentIndex(currentIndex() + 1);
}

void Wizard::showPrevPage() {
	if ((count() > 0) && (currentIndex() > 0))
		setCurrentIndex(currentIndex() - 1);
}

void Wizard::showIntroPage() {
	setCurrentIndex(0);
}