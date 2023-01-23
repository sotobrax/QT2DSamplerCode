#include "rectangle.h"
#include <QDebug>
Rectangle::Rectangle()
{

}

void Rectangle::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"key";
    if (event->key() == Qt::Key_A){
        if(pos().x() >= 10){
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_D){
        if(pos().x() <= 690){
            setPos(x()+10, y());
        }
    }
    else if (event->key() == Qt::Key_S){
        if(pos().y() <=490){
            setPos(x(), y()+10);
        }
    }
    else if (event->key() == Qt::Key_W){
        if(pos().y() >= 0){
            setPos(x(), y()-10);
        }
    }

}
