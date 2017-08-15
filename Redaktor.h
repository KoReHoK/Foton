#pragma once

struct defekt {
	int code;
	QString deskription;
	QColor	color;
	bool good;
	bool button;
	bool autoFoto;
};

class Redaktor : public QTableWidget
{
	Q_OBJECT

public:
	explicit Redaktor(QWidget *parent = Q_NULLPTR);

private:
	QVector<defekt> def;
	void showColorDialog(int row, int column);

public slots:
	void addDef(QString desc, int code, bool good, bool butt, bool foto);
};