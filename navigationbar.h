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

#include <QToolBar>
class NavigationBar : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationBar(QWidget *parent = 0);
	void ExpandPressed();
	void addElement(QIcon icon, QString caption);
protected:
    QHBoxLayout *mainLayout;
    QFormLayout *formLayout;
    std::vector<std::pair<QPushButton*,QLabel*>> m_buttons;
	std::pair<QPushButton*, QLabel*> m_expandButton;
	bool isExpand;
	int maxTextWidth;
    void resizeEvent(QResizeEvent * event);
signals:

public slots:
};

#endif // NAVIGATIONBAR_H
