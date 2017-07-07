#include "navigationbar.h"

NavigationBar::NavigationBar(bool isRightExpand, QWidget *parent) : QWidget(parent)
{
	m_isRightExpand = isRightExpand;
	//mainLayout = new QVBoxLayout;
	formLayout = new QFormLayout;
	formLayout->setVerticalSpacing(2);
	formLayout->setHorizontalSpacing(0);
	formLayout->setMargin(0);
	setLayout(formLayout);
	m_expandButton = std::make_pair(new QPushButton(QIcon(":/icons/Resources/icons/expand.png"), ""), new QLabel(""));
	m_expandButton.first->setIconSize(QSize(ICON_W, ICON_W));
	//m_expandButton.first->setMaximumWidth(ICON_W + 4);
	m_expandButton.second->setVisible(0);
	m_expandButton.second->setMinimumWidth(0);
	if (m_isRightExpand)
		formLayout->addRow(m_expandButton.first, m_expandButton.second);
	else
		formLayout->addRow(m_expandButton.second, m_expandButton.first);
	connect(m_expandButton.first, &QPushButton::clicked, this, &NavigationBar::ExpandPressed);
	QPalette Pal(palette());
	// устанавливаем цвет фона 
	Pal.setColor(QPalette::Background, QColor(200, 200, 200));
	setAutoFillBackground(true);
	setPalette(Pal);
	show();
	setStyleSheet("QPushButton{"
		"border: 0px solid black;"
		"background: rgb(200,200,200);}"
		"QPushButton::menu-indicator{"
		"subcontrol-position: bottom center;}"
		"QMenu{"
		"background: rgb(200,200,200);"
		//"margin: 10px;"
		"padding: 0px;}"
		"QMenu::item::selected{"
		"background: rgb(200,200,200);"
		"border: 1px solid black;"
		"padding: 0px;}"
		);
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

	animation = new QPropertyAnimation(this, "geometry");
	animation->setDuration(300);
 	QRect geom = geometry();
	if (isExpand)
		geom.setWidth(ICON_W + 4);
	animation->setStartValue(geom);
	if (m_isRightExpand)
	{
		if (isExpand)
			animation->setEndValue(QRect(geom.x(), geom.y(), ICON_W + 4 + maxTextWidth, geom.height()));
		else
			animation->setEndValue(QRect(geom.x(), geom.y(), ICON_W + 4, geom.height()));
	}
	else
	{
		if (isExpand)
			animation->setEndValue(QRect(geom.x() - maxTextWidth, geom.y(), ICON_W + 4 + maxTextWidth, geom.height()));
		else
			animation->setEndValue(QRect(geom.x() + geom.width() - (ICON_W + 4), geom.y(), ICON_W + 4, geom.height()));
	}
	animation->start();
	//update();

}

void NavigationBar::resizeEvent(QResizeEvent *event)
{
	if (animation && animation->state() == QAbstractAnimation::Running)
		return;
	QRect pos = geometry();

	if (isExpand)
		setGeometry(pos.x(), pos.y(), ICON_W + 4 + maxTextWidth, pos.height());
	else
		setGeometry(pos.x(), pos.y(), ICON_W + 4, pos.height());
}

void NavigationBar::addElement(QIcon icon, QString caption, QMenu* menu)
{
	m_buttons.push_back(std::make_pair(new QPushButton(icon, ""), new QLabel(caption)));
	m_buttons.back().first->setIconSize(QSize(ICON_W, ICON_W));
	m_buttons.back().first->setMenu(menu);
	//ќпредел¤ем самую длинную строчку, чтобы знать насколько экспандить меню
	QFont font = m_buttons.back().second->font();
	QFontMetrics fm(font);
	if (fm.width(caption) > maxTextWidth)
		maxTextWidth = fm.width(caption) + 10;
//	formLayout->setFormAlignment(Qt::AlignRight);
//	formLayout->setLabelAlignment(Qt::AlignRight);
	if (m_isRightExpand)
		formLayout->addRow(m_buttons.back().first, m_buttons.back().second);
	else
		formLayout->addRow(m_buttons.back().second, m_buttons.back().first);
	setMaximumWidth(ICON_W + 4 + maxTextWidth);
	update();
}
