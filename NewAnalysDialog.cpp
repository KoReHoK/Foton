#include "stdafx.h"
#include "NewAnalysDialog.h"

NewAnalysDialog::NewAnalysDialog(QWidget * parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
	gLayout = new QGridLayout(this);
	myCursor = new QCursor(Qt::PointingHandCursor);

	oneCrystalMode = new QToolButton();
	oneCrystalMode->setText("Однокристальный режим");
	oneCrystalMode->setIcon(QIcon(":/icons/Resources/icons/oneCrystalMode.png"));
	oneCrystalMode->setIconSize(QSize(182, 137));
	oneCrystalMode->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
	oneCrystalMode->setCheckable(true);
	oneCrystalMode->setChecked(true);
	oneCrystalMode->setAutoExclusive(true);
	oneCrystalMode->setCursor(*myCursor);
	multiCrystalMode = new QToolButton();
	multiCrystalMode->setText("Многокристальный режим");
	multiCrystalMode->setIcon(QIcon(":/icons/Resources/icons/multiCrystalMode.png"));
	multiCrystalMode->setIconSize(QSize(182, 137));
	multiCrystalMode->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
	multiCrystalMode->setCheckable(true);
	multiCrystalMode->setAutoExclusive(true);
	multiCrystalMode->setCursor(*myCursor);
	vSpacerItem = new QSpacerItem(30, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

	hboxLayout = new QHBoxLayout();
	hboxLayout->setSpacing(6);
	hboxLayout->setContentsMargins(0, 0, 0, 0);

	okButton = new QPushButton("OK");
	cancelButton = new QPushButton("Cancel");

	hboxLayout->addWidget(okButton);
	hboxLayout->addWidget(cancelButton);

	gLayout->addWidget(oneCrystalMode, 0, 0, Qt::AlignHCenter);
	gLayout->addWidget(multiCrystalMode, 0, 1, Qt::AlignHCenter);
	gLayout->addItem(vSpacerItem, 1, 0, 1, 2, Qt::AlignHCenter);
	gLayout->addLayout(hboxLayout, 2, 1, Qt::AlignHCenter);
	
	connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
	connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

	connect(oneCrystalMode, &QToolButton::clicked, this, &NewAnalysDialog::modeChanged);
	connect(multiCrystalMode, &QToolButton::clicked, this, &NewAnalysDialog::modeChanged);

	mode = true;
	setModal(true);
	setFixedSize(400, 250);
	setWindowTitle("Выберите режим работы:");
}

bool NewAnalysDialog::getMode()
{
	return mode;
}

void NewAnalysDialog::modeChanged() {
	if (oneCrystalMode->isChecked())
		mode = true;
	else
		mode = false;
}
