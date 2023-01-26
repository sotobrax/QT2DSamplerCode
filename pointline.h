#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QGraphicsLineItem>
#include <iostream>
#include <QGraphicsSceneMouseEvent>


class PointLine : public QWidget
{
    Q_OBJECT

public:
    PointLine(QPoint startpos, int width);
    PointLine();
    void setPos(QPoint point);
    void setWidth(int width);

protected:
    void paintEvent(QPaintEvent* event) override;
    
    void mouseMoveEvent(QMouseEvent* event) override;


private:
    QPoint m_cursorPos;
    QPoint startPos;
    int length;
    int width;
};