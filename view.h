#pragma once
#include <QMouseEvent>
#include <QGraphicsView>

class View : public QGraphicsView
{
public:
    View();
    void mouseMoveEvent(QMouseEvent* event);
};


