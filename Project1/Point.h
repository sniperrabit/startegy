#pragma once
class Point
{
public:
	Point();
	Point(float x, float y);
	~Point();
	 Point twoDToIso(Point * pt);
	void isoTo2D(Point * pt);
	float x;
	float y;

};

