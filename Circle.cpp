#include "Circle.h"
using namespace std;

Circle::Circle(QColor col, int radius, int points, int x, int y)
{
	color = col;
	rads = radius;
	point = points;
	xx = x;
	yy = y;
}

void Circle::position() {

}
void Circle::findPoints(int numPoints, int radius)
{
    /*pointList.//.Clear(); //necessary, otherwise, the list won't start from scratch on the second try
    for (int i = 1; i <= numPoints; i++)
    {
        //the following lines I stole off the internet and slightly modified
        result.Y = origin.Y + (int)Math.Round(radius * Math.Sin(angleRadians * i));
        result.X = origin.X + (int)Math.Round(radius * Math.Cos(angleRadians * i));
        if (!pointList.Contains(result))
        {
            pointList.Add(result);
        }
    }*/
    pointList.clear();
    for (int i = 1; i <= numPoints; i++) {
        xx = xx + (int)Math::Round(radius * Math::Sin(angleRadians * i));
    }
    
}