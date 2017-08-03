#include "stdafx.h"
#include "navigationbar.h"

NavigationBar::NavigationBar(bool isRightExpand, QWidget *parent) : QWidget(parent)
{
	myCursor = new QCursor(Qt::PointingHandCursor);
	m_isRightExpand = isRightExpand;
	vLayout = new QVBoxLayout();
	vLayout->setMargin(0);
	setLayout(vLayout);
	m_expandButton = new QToolButton();
	m_expandButton->setIcon(QIcon(":/icons/Resources/icons/expand.png"));
	m_expandButton->setIconSize(QSize(ICON_W, ICON_W));
	m_expandButton->setCursor(*myCursor);
	m_expandButton->setAttribute(Qt::WA_Hover);	// необходимо для обработки событий QEvent::HoverEnter и QEvent::HoverLeave
	m_expandButton->installEventFilter(this);
	vLayout->addWidget(m_expandButton);

	if (m_isRightExpand) {
		m_expandButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
		vLayout->setAlignment(Qt::AlignmentFlag::AlignLeft);
	}
		
	else {
		m_expandButton->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
		vLayout->setAlignment(Qt::AlignmentFlag::AlignRight);
	}
		
	connect(m_expandButton, &QPushButton::clicked, this, &NavigationBar::ExpandPressed);
	QPalette Pal(palette());
	// устанавливаем цвет фона 
	Pal.setColor(QPalette::Background, QColor(200, 200, 200));
	setAutoFillBackground(true);
	setPalette(Pal);
	show();

	setStyleSheet("QPushButton{"
		"border: 0px solid black;"
		"background: rgb(200,200,200);}"
		"QToolButton{"
		"border: 0px solid black;"
		"background: rgb(200,200,200);}"
		"QToolButton::menu-indicator{"
		"subcontrol-position: right center;}"
		"QMenu{"
		"background: rgb(200,200,200);"
		//"margin: 10px;"
		"padding: 0px;}"
		);
	isExpand = false;
	maxTextWidth = 0;
}

void NavigationBar::ExpandPressed()
{
	isExpand = !isExpand;
//	m_expandButton->setChecked(isExpand);
	
 	QRect geom = geometry();
	if (isExpand) {
		for (const auto &b : m_buttons)
			b.first->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
	}
	else {
		for (const auto &b : m_buttons)
			b.first->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	}

	animation = new QPropertyAnimation(this, "geometry");
	animation->setDuration(300);
	animation->setStartValue(geom);

	if(m_isRightExpand && isExpand)
		animation->setEndValue(QRect(geom.x(), geom.y(), ICON_W + 4 + maxTextWidth, geom.height()));
	
	if(m_isRightExpand && !isExpand)
		animation->setEndValue(QRect(geom.x(), geom.y(), ICON_W + 4, geom.height()));

	if(!m_isRightExpand && isExpand)
		animation->setEndValue(QRect(geom.x() - maxTextWidth, geom.y(), ICON_W + 4 + maxTextWidth, geom.height()));

	if(!m_isRightExpand && !isExpand)
		animation->setEndValue(QRect(geom.x() + geom.width() - (ICON_W + 4), geom.y(), ICON_W + 4, geom.height()));

	animation->start();
}

bool NavigationBar::eventFilter(QObject * watched, QEvent * event)
{
	QToolButton *tmp = dynamic_cast<QToolButton*>(watched);

	if (event->type() == QEvent::MouseButtonRelease) 
		emit showDialog(&tmp->text());

	if (event->type() == QEvent::HoverEnter) {
		tmp->setStyleSheet("background: rgb(100,100,100)");
		for (const auto vec : m_buttons) {
			if (vec.first == tmp && vec.second) {
				vec.second->setGeometry(tmp->x() + tmp->width() - 9, tmp->y(), vec.second->width(), vec.second->height());
				vec.second->show();
				return true;
			}	
		}
	}

	if (event->type() == QEvent::HoverLeave) {
		tmp->setStyleSheet("background: rgb(200,200,200)");
		for (const auto vec : m_buttons) {
			if (vec.first == tmp && vec.second) {
				//if (vec.second->getState()) {
					vec.second->hide();
					return true;
				//}	
			}
		}
		return true;
	}
	return false;
}

void NavigationBar::addElement(QIcon icon, QString caption, MenuWidget* menu)
{
	m_buttons.push_back(std::make_pair(new QToolButton(), menu));
	m_buttons.back().first->setIcon(icon);
	m_buttons.back().first->setText(caption);
	m_buttons.back().first->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	m_buttons.back().first->setIconSize(QSize(ICON_W, ICON_W));
	m_buttons.back().first->setCursor(*myCursor);
	if(menu) m_buttons.back().second->setCursor(*myCursor);
	m_buttons.back().first->installEventFilter(this);
//	Определяем самую длинную строчку, чтобы знать насколько экспандить меню
	QFont font = m_buttons.back().first->font();
	QFontMetrics fm(font);
	if (fm.width(caption) > maxTextWidth)
		maxTextWidth = fm.width(caption) + 10;

	if (m_isRightExpand)
	{
		m_buttons.back().first->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
		vLayout->addWidget(m_buttons.back().first);
	}
	else
	{
		m_buttons.back().first->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
		vLayout->addWidget(m_buttons.back().first);
	}
		
	vLayout->addWidget(m_buttons.back().first);

	QRect pos = geometry();
	pos.setWidth(ICON_W + 4);
	pos.setHeight(height() + ICON_W);
	setGeometry(pos);
}
