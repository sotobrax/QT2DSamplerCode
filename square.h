#pragma once

#include <QKeyEvent>
#include <QGraphicsRectItem>
class Square : public QGraphicsRectItem
{
public:
    Square();
    void keyPressEvent(QKeyEvent *event);
};

