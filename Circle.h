#pragma once
#include <QGraphicsLineItem>
#include <iostream>
#include <QPen>
#include <QGraphicsItemGroup>
#include <QWidget>
#include <QPainter>

 
class Circle : public QWidget
{
	Q_OBJECT
public:
	Circle(QColor col, int radius, int points, QPoint xy);
protected:
	void paintEvent(QPaintEvent* paintEvent);
private:
	double rads;
	double point;
	double angleRadians;
	QPoint origin;
	QPoint result;
	QColor color;
	QPen pen;
	std::vector<QPoint> pointList;

	void findPoints();
	bool pointListCheck(QPoint r);


};

