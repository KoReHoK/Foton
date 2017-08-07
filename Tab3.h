#pragma once

#include "TableSettings.h"
#include "ElseSettings.h"
#include "CameraSettings.h"

class Tab3 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab3(QWidget *parent = Q_NULLPTR);

protected:
	CameraSettings	*visibleCamera;
	CameraSettings	*ikCamera;
	TableSettings	*buttonsPult;
	TableSettings	*hotButtons;
	ElseSettings	*settings;
	QToolBox		*toolBox;
	QWidget			*cameraWidget;
	QWidget			*gistWidget;
	//QImage			*etiketka;
	QGridLayout		*gLayout;
};