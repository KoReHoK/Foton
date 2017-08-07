#include "stdafx.h"
#include "navigationbar.h"

NavigationBar::NavigationBar(bool isRightExpand, QWidget *parent) : QWidget(parent)
{
	animation = new QPropertyAnimation(this, "geometry");
	connect(animation, &QPropertyAnimation::finished, this, &NavigationBar::finish);

	myCursor = new QCursor(Qt::PointingHandCursor);
	
	vLayout = new QVBoxLayout();
	vLayout->setMargin(0);
	setLayout(vLayout);

	addElement(QIcon(":/icons/Resources/icons/expand.png"), "");

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
	m_isRightExpand = isRightExpand;
}

void NavigationBar::ExpandPressed()
{
	isExpand = !isExpand;

	if (isExpand) {
		for (const auto &b : m_buttons)
			b->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
	}

	QRect geom = geometry();
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

void NavigationBar::finish()	// для более красивой отрисовки
{
	if (!isExpand && (animation->state() == QAbstractAnimation::State::Stopped)) {
		for (const auto &b : m_buttons)
			b->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	}
}

bool NavigationBar::eventFilter(QObject * watched, QEvent * event)
{
	QToolButton *tmp;

	if (tmp = dynamic_cast<QToolButton*>(watched)) {

		if ((tmp == m_buttons.at(0)) && (event->type() == QEvent::MouseButtonRelease)) {
			ExpandPressed();
			return QWidget::eventFilter(watched, event);
		}
	
		switch (event->type())
		{
			case QEvent::MouseButtonRelease: emit showDialog(&tmp->text()); break;
			case QEvent::HoverEnter: tmp->setStyleSheet("background: rgb(100,100,100)"); break;
			case QEvent::HoverLeave: tmp->setStyleSheet("background: rgb(200,200,200)"); break;
		}
	}

	return QWidget::eventFilter(watched, event);
}

void NavigationBar::addElement(QIcon icon, QString caption)
{
	m_buttons.push_back(new QToolButton());
	m_buttons.back()->setIcon(icon);
	m_buttons.back()->setText(caption);
	m_buttons.back()->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
	m_buttons.back()->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	m_buttons.back()->setIconSize(QSize(ICON_W, ICON_W));
	m_buttons.back()->setAttribute(Qt::WA_Hover);	// необходимо для обработки событий QEvent::HoverEnter и QEvent::HoverLeave
	m_buttons.back()->setCursor(*myCursor);
	m_buttons.back()->installEventFilter(this);
//	Определяем самую длинную строчку, чтобы знать насколько экспандить меню
	QFont font = m_buttons.back()->font();
	QFontMetrics fm(font);
	if (fm.width(caption) > maxTextWidth)
		maxTextWidth = fm.width(caption) + 10;

	if (m_isRightExpand)
	{
		m_buttons.back()->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
		vLayout->addWidget(m_buttons.back());
	}
	else
	{
		m_buttons.back()->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
		vLayout->addWidget(m_buttons.back());
	}
		
	vLayout->addWidget(m_buttons.back());

	QRect pos = geometry();
	pos.setWidth(ICON_W + 4);
	pos.setHeight(height() + ICON_W);
	setGeometry(pos);
}
