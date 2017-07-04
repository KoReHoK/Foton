#pragma once

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLayout>
#include "LensesGroup.h"
#include "CameraGroup.h"

class ViewWidget : public QGroupBox
{
	Q_OBJECT

public:
	ViewWidget(QWidget *parent = Q_NULLPTR);

private:
	QVBoxLayout *vertLayout;
	LensesGroup *lensGroup;
	CameraGroup *camGroup;
};
