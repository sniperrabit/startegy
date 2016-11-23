#include "Point.h"

Point::Point()
{	
}

Point::Point(float x, float y)
{
	this-> x = x;
	this->y= y;
}

void Point::isoTo2D(Point * pt) {
	pt->x = (2 * pt->y + pt->x) / 2;
	pt->y = (2 * pt->y - pt->x) / 2;
}

Point Point::twoDToIso(Point * pt) {
	Point tmp;
	float x = pt->x - pt->y;
	float y = (pt->x + pt->y) / 2;
	tmp.x = x;
	tmp.y = y;
	return tmp;
}


Point::~Point()
{
}



