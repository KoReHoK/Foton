#pragma once

class MenuWidget : public QWidget
{
	Q_OBJECT
private:
	bool state;
	QVBoxLayout *vLayout;
public:
	explicit MenuWidget(QList<QPushButton*> *list, QWidget *parent = 0);
};