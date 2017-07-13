#pragma once
#include <QtWidgets/QFrame>
#include <QLabel>
#include <mutex>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QOpenGLWidget>
#include <QTime>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QEvent>

class QCameraFrame :
	public QOpenGLWidget
{
public:
	QCameraFrame();
	~QCameraFrame();
	double imageAspectRatio() const;
	void paintEvent(QPaintEvent *);

	void SetSecondOutWnd(HWND winId);
	QTime myTimer;
	HWND secondWnd = nullptr;
	void SetScale(float newScale, const QPoint& immobilePoint);
	void IncrementScale(const QPoint& immobilePoint);
	void DecrementScale(const QPoint& immobilePoint);
	void SetUseAutoScale(bool val) { isAutoScale = val; }

	void wheelEvent(QWheelEvent *event);
	void UpdateOffset(QPointF curPt);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	QRect centeredViewport(int width, int height) const;

private:
	bool isAutoScale;
	QPointF m_RightDownPos;
	QImage currentImage;
	uchar tmpBuf[3000 * 3000 * 3];
	mutable std::mutex frameMutex;//������������� ���������� ������ � ��������� ��������
	float m_scale;//������� ���������� �����������
	QPoint m_drawOffset;  //�������� �������� �� ������ ��������
	QPoint immutablePointWnd;
	QPoint immutablePointImg;
	//	QRect m_viewPort;
	// 	QGraphicsScene *scene;
	// 	QGraphicsPixmapItem* pixmap;
	// 	QPixmap pix;

	double imageAspectRatioUnsafe() const;
	std::pair<QRect, QRect> customScaleRectangles() const;

public slots:
	//�������� �� ������, ���������� CallBack-�� ��� ����� �����
	void updateFrame(uchar* newFrame, int w, int h, int bits);

};

