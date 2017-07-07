#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QWidget>
#include <QIcon>
#include <utility>
#include <vector>
#include <string>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QMenu>

#include <QToolBar>
class NavigationBar : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationBar(bool isRightExpand=true, QWidget *parent = 0);
	void ExpandPressed();
	void addElement(QIcon icon, QString caption, QMenu* menu = nullptr);
protected:
    QHBoxLayout *mainLayout;
    QFormLayout *formLayout;
    std::vector<std::pair<QPushButton*,QLabel*>> m_buttons;
	std::pair<QPushButton*, QLabel*> m_expandButton;
	bool isExpand;
	int maxTextWidth;
	QPropertyAnimation *animation = nullptr;
    void resizeEvent(QResizeEvent * event);
	const int ICON_W = 32;
	bool m_isRightExpand;
signals:

public slots:
};

#endif // NAVIGATIONBAR_H
