#pragma once

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Rectangle : public QGraphicsRectItem
{
public:
    Rectangle();
    void keyPressEvent(QKeyEvent* event);
};


