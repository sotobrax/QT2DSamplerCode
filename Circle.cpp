#include "Circle.h"
#include "qmath.h"
using namespace std;

Circle::Circle()
{

}

void Circle::setColor(QColor col)
{
    pen.setColor(col);
}

void Circle::setRadius(int radius)
{
    rads = radius;
}

void Circle::setPoints(int points)
{
    point = points;
}

void Circle::setOrigin(QPoint xy)
{
    origin.setX(xy.x());
    origin.setY(xy.y());
}


// Function to find points and add them to pointList vector
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
//Checks to make sure points are not already in the pointlist
bool Circle::pointListCheck(QPoint r) {
    for (int i = 0; i < pointList.size(); i++) {
        if (pointList[i] == r) {
            return true;
        }
    }
    return false;
}
// Draws the lines 
void Circle::paintEvent(QPaintEvent * paintEvent) {
    cout << "painting lines of circles";
    angleRadians = (M_PI * 2) / point;
    findPoints();
    QPainter painter(this);
    painter.setPen(pen);
    qDebug() << pointList.size();
    cout << pointList.size();
    for (int i = 0; i < point; i++) {
        for (int j = i; j < point; j++) {


            painter.drawLine(pointList[i].x(), pointList[i].y(), pointList[j].x(), pointList[j].y());
        }
    }
}
