#pragma once
#include <QGraphicsLineItem>
#include <iostream>

class Circle
{
	Circle(QColor col, int radius, int points, int x, int y);
	
private:
	int rads;
	int point;
	int xx;
	int yy;
	QColor color;
	std::vector<int> pointList;
	void position();
	void findPoints(int numPoints, int radius);
};

