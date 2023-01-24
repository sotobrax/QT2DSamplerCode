#include "pointline.h"

PointLine::PointLine(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}

void PointLine::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPoint startPos(width() / 2, height() / 2);
    painter.drawLine(startPos, m_cursorPos);
}


void PointLine::mouseMoveEvent(QMouseEvent *event)
{
    m_cursorPos = event->pos();
    update();
}