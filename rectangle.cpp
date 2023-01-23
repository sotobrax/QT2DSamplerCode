#include "rectangle.h"
#include <QDebug>
Rectangle::Rectangle()
{

}

void Rectangle::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"key";
    if (event->key() == Qt::Key_A){
        if(pos().x() >= 0){
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_D){
        if(pos().x() <= 800){
            setPos(x()+10, y());
        }
    }
    else if (event->key() == Qt::Key_S){
        if(pos().y() <=600){
            setPos(x(), y()+10);
        }
    }
    else if (event->key() == Qt::Key_W){
        if(pos().y() >= 0){
            setPos(x(), y()-10);
        }
    }

}
