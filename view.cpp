#include "view.h"

View::View()
{

}

void View::mouseMoveEvent(QMouseEvent* event)
{
	cursorPosx = event->pos().x();
	cursorPosy = event->pos().y();
}
