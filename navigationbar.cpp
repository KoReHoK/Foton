#include "navigationbar.h"
#include <QPropertyAnimation>

NavigationBar::NavigationBar(QWidget *parent) : QWidget(parent)
{
    //mainLayout = new QVBoxLayout;
    formLayout = new QFormLayout;
	formLayout->setVerticalSpacing(2);
	formLayout->setMargin(0);
	setLayout(formLayout);
	m_expandButton = std::make_pair(new QPushButton(QIcon(":/icons/Resources/icons/expand.png"), ""), new QLabel(""));
	m_expandButton.first->setIconSize(QSize(32, 32));
	m_expandButton.second->setVisible(0);
	m_expandButton.second->setMinimumWidth(0);
	formLayout->addRow(m_expandButton.first, m_expandButton.second);
	connect(m_expandButton.first, &QPushButton::clicked, this, &NavigationBar::ExpandPressed);
	QPalette Pal(palette());
	// устанавливаем цвет фона 
	Pal.setColor(QPalette::Background, QColor(200,200,200)); 
	setAutoFillBackground(true); 
	setPalette(Pal); 
	show();
	setStyleSheet("QPushButton{"
								"border: 0px solid black;"
								"background: rgb(200,200,200);}");
	isExpand = false;
	maxTextWidth = 0;
}

void NavigationBar::ExpandPressed()
{
	isExpand = !isExpand;
	m_expandButton.first->setChecked(isExpand);
	for (const auto &b : m_buttons)
	{
		b.second->setVisible(isExpand);
	}
	QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
	animation->setDuration(150);
	QRect geom = geometry();
	if (isExpand)
		geom.setWidth(32 + 6);
	animation->setStartValue(geom);
	if (isExpand)
		animation->setEndValue(QRect(geom.x(), geom.y(), 32 + 6 + maxTextWidth, (m_buttons.size() + 1) * (32 + 2)));
	else
		animation->setEndValue(QRect(geom.x(), geom.y(), 32 + 6, (m_buttons.size() + 1) * (32 + 2)));
	//animation->setEndValue(QRect(200, 200, 100, 50));
	animation->start();
	//update();

}

void NavigationBar::resizeEvent(QResizeEvent *event)
{
	QRect pos = geometry();

// 	if(isExpand)
// 		setGeometry(pos.x(), pos.y(), 32+6+maxTextWidth , (m_buttons.size() + 1) * (32+2));
// 	else
// 		setGeometry(pos.x(), pos.y(), 32+6, (m_buttons.size() + 1) * (32 + 2));

}

void NavigationBar::addElement(QIcon icon, QString caption)
{
    m_buttons.push_back(std::make_pair(new QPushButton(icon,""),new QLabel(caption)));
	m_buttons.back().first->setIconSize(QSize(32, 32));
	//Определяем самую длинную строчку, чтобы знать насколько экспандить меню
	QFont font = m_buttons.back().second->font();
	QFontMetrics fm(font);
	if(fm.width(caption)>maxTextWidth)
		maxTextWidth = fm.width(caption);
    formLayout->addRow(m_buttons.back().first,m_buttons.back().second);
	setMaximumWidth(32 + 6 + maxTextWidth);
    update();
}
