#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QGraphicsLineItem>


class PointLine : public QGraphicsItem
{
    Q_OBJECT

public:
    PointLine(QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private:
    QPoint m_cursorPos;
};