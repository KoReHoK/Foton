#pragma once

#include <utility>
#include <vector>
#include <string>
#include "MenuWidget.h"

class NavigationBar : public QWidget
{
	Q_OBJECT
public:
	explicit NavigationBar(bool isRightExpand = true, QWidget *parent = 0);
	void ExpandPressed();
	void addElement(QIcon icon, QString caption, MenuWidget* menu = nullptr);
protected:
	QVBoxLayout *vLayout;
	std::vector<std::pair<QToolButton*, MenuWidget*>> m_buttons;
	QToolButton* m_expandButton;
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
};