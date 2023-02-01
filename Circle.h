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
	Circle();
	void setColor(QColor col);
	void setRadius(int radius);
	void setPoints(int points);
	void setOrigin(QPoint xy);
	void eraseCircle();
protected:
	void paintEvent(QPaintEvent* paintEvent);
private:
	double rads;
	double point;
	double angleRadians;
	QPainter *painter = new QPainter();
	QPoint origin;
	QPoint result;
	QColor color;
	QPen pen;
	std::vector<QPoint> pointList;
	void findPoints();
	bool pointListCheck(QPoint r);


};

