#include "GroupSizeOfCrystal.h"

GroupSizeOfCrystal::GroupSizeOfCrystal(QWidget *parent)
	: QGroupBox(parent)
{
	//TODO: Подумать, где лучше хранить элементы
	lWidthCryst = new QLabel("Ширина кристалла");
	lHeightCryst = new QLabel("Высота кристалла");
	lWidthLine = new QLabel("Ширина разделительной дорожки");
	lHeightLine = new QLabel("Высота разделительной дорожки");
	editWidthCryst = new QLineEdit();
	editHeightCryst = new QLineEdit();
	editWidthLine = new QLineEdit();
	editHeightLine = new QLineEdit();
	pushMe = new QPushButton("Определить с помощью");
	gLayout = new QGridLayout(this);
	gLayout->addWidget(lWidthCryst, 0, 0);
	gLayout->addWidget(lHeightCryst, 1, 0);
	gLayout->addWidget(lWidthLine, 2, 0);
	gLayout->addWidget(lHeightLine, 3, 0);
	gLayout->addWidget(editWidthCryst, 0, 1);
	gLayout->addWidget(editHeightCryst, 1, 1);
	gLayout->addWidget(editWidthLine, 2, 1);
	gLayout->addWidget(editHeightLine, 3, 1);
	gLayout->addWidget(pushMe, 5, 0, 2, 2, Qt::AlignCenter);
}

GroupSizeOfCrystal::~GroupSizeOfCrystal()
{
}