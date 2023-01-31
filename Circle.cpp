#include "Circle.h"
#include "qmath.h"
using namespace std;

Circle::Circle(QColor col, int radius, int points, QPoint xy)
{
	color = col;
	rads = radius;
	point = points;
    origin.setX(xy.x());
    origin.setY(xy.y());
    pen.setColor(col);
    angleRadians = (M_PI * 2) / points;
    
    //createLines();
    //drawLines();

}

/*void Circle::position(int radius) {
    origin.setX()
}*/
void Circle::findPoints()
{
    cout << "Finding points";
    pointList.clear();
    for (int i = 1; i <= point; i++) {
        cout << printf("Finding Points: ", i);
        result.setX(origin.x() + (rads * sin(angleRadians * i)));
        result.setY(origin.y() + (rads * cos(angleRadians * i)));
        if (pointListCheck(result) == false) {
            pointList.push_back(result);
        }
    }
    
}
bool Circle::pointListCheck(QPoint r) {
    for (int i = 0; i < pointList.size(); i++) {
        cout << printf("Checking points: ", i);
        if (pointList[i] == r) {
            return true;
        }
    }
    return false;
}
void Circle::paintEvent(QPaintEvent * paintEvent) {
    cout << "painting lines of circles";
    findPoints();
    QPainter painter(this);
    painter.setPen(pen);
    
    cout << pointList.size();
    for (int i = 0; i < point; i++) {
        for (int j = i; j < point; j++) {
            qDebug() << printf("Drawing points:", i);

            painter.drawLine(pointList[i].x(), pointList[i].y(), pointList[j].x(), pointList[j].y());
        }
    }
}
void Circle::drawLines() {
    for (int i = 0; i < lines.size(); i++) {
        lines[i].setPen(pen);
        lines[i].show();

    }
}