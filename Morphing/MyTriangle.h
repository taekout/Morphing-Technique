#pragma once
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

extern class Point;

class CMyTriangle
{
public:
	CMyTriangle(void);
public:
	~CMyTriangle(void);

	CvPoint m_pt[3];

	bool IsIn(float x, float y);
	float DotProduct(float a[3], float b[3]);
	void CrossProduct(Point M1, Point M2, float resultM[3]);
	// Determination of a point in the triangle
	bool SameSide(Point p1, Point p2, Point a, Point b);
	bool PointInTriangle(Point p, Point a, Point b, Point c);
};
