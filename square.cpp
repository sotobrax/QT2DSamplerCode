#include "square.h"

Square::Square()
{

}

void Square::keyPressEvent(QKeyEvent *event)
{
    {
            if (event->key() == Qt::Key_A){
                setPos(x()-10, y());
            }
            else if (event->key() == Qt::Key_D){
                setPos(x()+10, y());
            }
            else if (event->key() == Qt::Key_S){
                setPos(x(), y()+10);
            }
            else if (event->key() == Qt::Key_W){
                setPos(x(), y()-10);
            }
        }
}
