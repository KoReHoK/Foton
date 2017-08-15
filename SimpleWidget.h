#pragma once

class SimpleWidget : public QWidget
{
	Q_OBJECT

private:
	QColor	color;
	uint	id;

protected:
	void paintEvent(QPaintEvent *event) override;

public slots:
	void delWidget();
	void colorChanged(const QColor &color);

signals:
	void deleteWidget(uint);

public:
	explicit SimpleWidget(QColor, QWidget *parent = Q_NULLPTR);

	void setID(uint);
};