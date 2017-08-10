#pragma once
#include "NewAnalysDialog.h"
#include "Wizard.h"

class ToolBar : public QToolBar
{
	Q_OBJECT
public:
	explicit ToolBar(QWidget *parent = Q_NULLPTR);

private:
	QVector<QToolButton*> myToolBar;
	NewAnalysDialog *newAnalys;
	Wizard			*wizard = nullptr;

public:
	bool eventFilter(QObject *watched, QEvent *event) override;

signals:
	void showPanorama();
	void showCamera();
};