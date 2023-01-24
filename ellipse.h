#pragma once
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Ellipse : public QGraphicsEllipseItem
{
public:
    Ellipse();
    void keyPressEvent(QKeyEvent* event);
};


