#pragma once
#include <QGraphicsLineItem>
#include <iostream>
#include <QPen>
#include <QGraphicsItemGroup>
#include <QWidget>
#include <QPainter>

 
class Circle : public QWidget
{
public:
	Circle(QColor col, int radius, int points, QPoint xy);
protected:
	void paintEvent(QPaintEvent* paintEvent);
private:
	int rads;
	int point;
	int xx;
	int yy;
	int angleRadians;
	QPoint origin;
	QPoint result;
	QColor color;
	QPen pen;
	std::vector<QGraphicsLineItem> lines;
	std::vector<QPoint> pointList;
	//void position();
	void findPoints();
	bool pointListCheck(QPoint r);
	void drawLines();
	//void createLines();

};

