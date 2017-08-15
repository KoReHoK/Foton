#pragma once

#include "TableSettings.h"
#include "ElseSettings.h"
#include "CameraSettings.h"
#include "modelviewdemowidget.h"

class Tab3 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab3(QWidget *parent = Q_NULLPTR);

signals:
	void addDef(QString desc, int hotKey, byte keypad, int code, bool good, bool butt, bool foto);
};