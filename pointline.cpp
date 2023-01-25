#include "pointline.h"
#include <QDebug>


PointLine::PointLine(QPoint startpos, int uwidth)// : QWidget(parent)
{
    startPos = startpos;
    setMouseTracking(true);
    width = uwidth;
}

void PointLine::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
//QPoint startPos(width() / 2, height() / 2);
    
    painter.drawLine(startPos, m_cursorPos);
    painter.setPen(QPen(Qt::black, width, Qt::SolidLine, Qt::RoundCap));
}


void PointLine::mouseMoveEvent(QMouseEvent* event)
{
    m_cursorPos = event->pos();
    update();
}