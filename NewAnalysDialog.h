#pragma once

class NewAnalysDialog : public QDialog 
{
	Q_OBJECT
public:
	explicit NewAnalysDialog(QWidget *parent = Q_NULLPTR);

private:
	QHBoxLayout *hboxLayout;
	QSpacerItem *spacerItem;
	QPushButton *okButton;
	QPushButton *cancelButton;
	QRadioButton *oneCrystalMode;
	QRadioButton *multiCrystalMode;

	bool mode;	// true is oneCrystalMode

public:
	bool getMode();

private slots:
	void modeChanged();
};