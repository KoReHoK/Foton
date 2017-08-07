#include "stdafx.h"
#include "NewAnalysDialog.h"

NewAnalysDialog::NewAnalysDialog(QWidget * parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
	hboxLayout = new QHBoxLayout(this);
	hboxLayout->setSpacing(6);
	hboxLayout->setContentsMargins(0, 0, 0, 0);

	spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);
	hboxLayout->addItem(spacerItem);

	okButton = new QPushButton(this);
	cancelButton = new QPushButton(this);

	connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
	connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

	hboxLayout->addWidget(okButton);
	hboxLayout->addWidget(cancelButton);

	oneCrystalMode = new QRadioButton("One crystal mode", this);
	multiCrystalMode = new QRadioButton("Multi crystal mode", this);
	oneCrystalMode->setChecked(true);
	multiCrystalMode->move(0, 15);

	connect(oneCrystalMode, &QRadioButton::clicked, this, &NewAnalysDialog::modeChanged);
	connect(multiCrystalMode, &QRadioButton::clicked, this, &NewAnalysDialog::modeChanged);

	setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
	okButton->setText(QApplication::translate("Dialog", "OK", Q_NULLPTR));
	cancelButton->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));

	mode = true;
	setModal(true);
	setFixedSize(400, 300);
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
