#pragma once

class NewAnalysDialog : public QDialog 
{
	Q_OBJECT
public:
	explicit NewAnalysDialog(QWidget *parent = Q_NULLPTR);

private:
	QGridLayout	*gLayout;
	QHBoxLayout *hboxLayout;
	QSpacerItem *vSpacerItem;
	QPushButton *okButton;
	QPushButton *cancelButton;
	QToolButton *oneCrystalMode;
	QToolButton *multiCrystalMode;
	QCursor	*myCursor;

	bool mode;	// true is oneCrystalMode

public:
	bool getMode();

private slots:
	void modeChanged();
};