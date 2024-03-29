#include "pointline.h"
#include <QDebug>


PointLine::PointLine(QPoint startpos, int uwidth)
{
    startPos = startpos;
    setMouseTracking(true);
    width = uwidth;
}

PointLine::PointLine()
{
    setMouseTracking(true);
}

//Draws the line 
void PointLine::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPen pen = QPen(Qt::black, width, Qt::SolidLine, Qt::RoundCap);
    pen.setColor(col);
    painter.setPen(pen);
    painter.drawLine(startPos, m_cursorPos);
}

//Grabs the mouse position
void PointLine::mouseMoveEvent(QMouseEvent* event)
{
    m_cursorPos = event->pos();
    update();
}

void PointLine::setPos(QPoint pos)
{
    startPos = pos;
}

void PointLine::setWidth(int w)
{
    width = w;
}

void PointLine::setColor(QColor color)
{
    col = color;
}
