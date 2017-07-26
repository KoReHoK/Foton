#include "stdafx.h"
#include "QCameraFrame.h"
#include <qpainter.h>
#include <QDebug>

QCameraFrame::QCameraFrame() :
	m_scale(0.2),
	m_drawOffset(0, 0)
{
	isAutoScale = false;
	//setFrameStyle(QFrame::Panel);
// 	scene = new QGraphicsScene(this);
// 	setScene(scene);
	currentImage = QImage("D:\\03.jpg");

	// 	pix = QPixmap::fromImage(currentImage);
	// 	pixmap = scene->addPixmap(pix);
}


QCameraFrame::~QCameraFrame()
{
}

double QCameraFrame::imageAspectRatio() const {
	std::lock_guard<std::mutex> lock(frameMutex);
	return imageAspectRatioUnsafe();
}
double QCameraFrame::imageAspectRatioUnsafe() const {
	return ((double)currentImage.width()) / ((double)currentImage.height());
}

QRect QCameraFrame::centeredViewport(int width, int height) const {
	const double aspectRatio = imageAspectRatioUnsafe();
	const int heightFromWidth = (int)(width / aspectRatio);
	const int widthFromHeight = (int)(height*aspectRatio);

	if (heightFromWidth <= height) {
		return QRect(0, (height - heightFromWidth) / 2, width, heightFromWidth);
	}
	else {
		return QRect((width - widthFromHeight) / 2.0, 0, widthFromHeight, height);
	}
}
#include <QtWinExtras/qwinfunctions.h>
void QCameraFrame::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.fillRect(0, 0, width(), height(), Qt::BrushStyle::SolidPattern);

	painter.setRenderHint(QPainter::Antialiasing);
	{
		std::lock_guard<std::mutex> lock(frameMutex);
		if (isAutoScale) {
			painter.setViewport(centeredViewport(width(), height()));
			painter.drawImage(QRect(0, 0, width(), height()), currentImage);
		}
		else {
			auto& rects = customScaleRectangles();
			painter.drawImage(rects.first, currentImage, rects.second);
		}

		if (IsWindow(secondWnd))
		{
			HDC hdc = GetDC(secondWnd);
			QPixmap px = QPixmap::fromImage(currentImage);
			HBITMAP bitmap = QtWin::toHBITMAP(px);
			RECT secondWndRect;
			GetClientRect(secondWnd, &secondWndRect);
			HDC hMemDCOrig = CreateCompatibleDC(hdc);
			HGDIOBJ hOldBmOrig = SelectObject(hMemDCOrig, bitmap);

			StretchBlt(hdc, 0, 0, secondWndRect.right, secondWndRect.bottom, hMemDCOrig, 0, 0, currentImage.width(), currentImage.height(), SRCCOPY);
			DeleteDC(hMemDCOrig);
		}

	}
}

void QCameraFrame::SetSecondOutWnd(HWND winId)
{
	secondWnd = winId;
}

std::pair<QRect, QRect> QCameraFrame::customScaleRectangles() const {

	const auto imgWidth = currentImage.width();
	const auto imgHeight = currentImage.height();
	const auto wndWidth = width();
	const auto wndHeight = height();

	const auto subWidth = wndWidth / m_scale;
	const auto srcX = (imgWidth - subWidth) / 2 + m_drawOffset.x();

	const auto subHeight = wndHeight / m_scale;
	const auto srcY = ((imgHeight - subHeight) / 2 + m_drawOffset.y());

	QRect target(0,0,wndWidth,wndHeight);
	QRect source(srcX, srcY, subWidth, subHeight);

	return std::pair<QRect, QRect>(std::move(target), std::move(source));
}

void QCameraFrame::updateFrame(uchar* newFrame, int w, int h, int bits)
{
	if (!newFrame) return;
	{
		std::lock_guard<std::mutex> lock(frameMutex);

		memcpy(tmpBuf, newFrame, w*h*bits / 8);
		myTimer.start();
		if (bits == 24)
			currentImage = QImage(tmpBuf, w, h, QImage::Format_RGB888);
		else if (bits == 8)
			currentImage = QImage(tmpBuf, w, h, QImage::Format_Grayscale8);
		else return;

		update();
	}
}

void QCameraFrame::SetScale(float newScale, const QPoint& immobilePoint)
{
	//Ограничиваем минимум\максимум масштаба
	if (newScale > 2) newScale = 2;
	if (newScale < 0.1) newScale = 0.1;
	auto dx = (immobilePoint.x() - width() / 2) / m_scale;
	auto dy = (immobilePoint.y() - height() / 2) / m_scale;
	const auto relScale = newScale / m_scale;
	dx *= relScale;
	dy *= relScale;
	const auto originX = m_drawOffset.x() - (immobilePoint.x() - width() / 2) / m_scale + dx;
	const auto originY = m_drawOffset.y() - (immobilePoint.y() - height() / 2) / m_scale + dy;

	m_drawOffset.setX(originX);
	m_drawOffset.setY(originY);

	m_scale = newScale;
}

void QCameraFrame::IncrementScale(const QPoint& immobilePoint)
{
	SetScale(m_scale + 0.05, immobilePoint);
}

void QCameraFrame::DecrementScale(const QPoint& immobilePoint)
{
	SetScale(m_scale - 0.05, immobilePoint);
}

void QCameraFrame::wheelEvent(QWheelEvent *event)
{
	if (!isAutoScale) {
		QPoint point = event->pos();
		if (currentImage.width() * m_scale < width()) point.setX(width() / 2);
		if (currentImage.height() * m_scale < height()) point.setY(height() / 2);
		if (event->angleDelta().y() > 0)
			IncrementScale(point);
		else
			DecrementScale(point);

		repaint();
	}
}

void QCameraFrame::UpdateOffset(QPointF curPt)
{
	QRect rectWnd = this->geometry();

	int dx = m_RightDownPos.x() - curPt.x();
	m_drawOffset.setX(m_drawOffset.x() + dx / m_scale);
	m_RightDownPos.setX(curPt.x());

	int dy = m_RightDownPos.y() - curPt.y();
	m_drawOffset.setY(m_drawOffset.y() + dy / m_scale);
	m_RightDownPos.setY(curPt.y());
}


void QCameraFrame::mouseMoveEvent(QMouseEvent *event)
{
	if (!isAutoScale) {
		if (event->buttons() & Qt::RightButton)
		{
			UpdateOffset(event->localPos());
			update();
		}
	}
}

void QCameraFrame::mousePressEvent(QMouseEvent *event)
{
	if (!isAutoScale) {
		if (event->buttons() & Qt::RightButton)
		{
			m_RightDownPos = event->localPos();
		}
	}
}

void QCameraFrame::mouseReleaseEvent(QMouseEvent *event)
{

}

