#pragma once

class OffsetGroup : public QGroupBox
{
	Q_OBJECT

protected:
	QLabel *xLabel;
	QLineEdit *xLineEdit;
	QSlider *xSlider;
	QLabel *percentLabelX;
	QLabel *yLabel;
	QLineEdit *yLineEdit;
	QSlider *ySlider;
	QLabel *percentLabelY;

	QGridLayout *gLayout;
public:
	explicit OffsetGroup(QWidget *parent = Q_NULLPTR);
	~OffsetGroup();
};