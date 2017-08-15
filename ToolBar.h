#pragma once
#include "NewAnalysDialog.h"

class ToolBar : public QToolBar
{
	Q_OBJECT
public:
	explicit ToolBar(QWidget *parent = Q_NULLPTR);

private:
	QVector<QToolButton*> myToolBar;

public:
	bool eventFilter(QObject *watched, QEvent *event) override;

signals:
	void showPanorama();
	void showCamera();
	void showWizard();
	void setCrystMode(int);
};