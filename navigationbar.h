#pragma once

#include <utility>
#include <vector>
#include <string>

class NavigationBar : public QWidget
{
	Q_OBJECT
public:
	explicit NavigationBar(bool isRightExpand = true, QWidget *parent = 0);
	void ExpandPressed();
	void addElement(QIcon icon, QString caption);
protected:
	QVBoxLayout *vLayout;
	std::vector<QToolButton*> m_buttons;
	bool isExpand;
	int maxTextWidth;
	QPropertyAnimation *animation = nullptr;
	QCursor	*myCursor;
	const int ICON_W = 32;
	bool m_isRightExpand;
public:
	bool eventFilter(QObject *watched, QEvent *event) override;
signals:
	void showDialog(QString*);
protected slots:
	void finish();
};