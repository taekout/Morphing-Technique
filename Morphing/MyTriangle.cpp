#include "MyTriangle.h"


class Point{
public:
	float x;
	float y;

public:
	Point(){x = -1; y = -1;}
	Point(float x, float y)
	{
		this ->x = x; this ->y = y;
	}
	Point &operator =(const Point & src)
	{
		x = src.x;
		y = src.y;
		return *this;
	}
	Point &operator =(const CvPoint &src)
	{
		x = src.x;
		y = src.y;
		return *this;
	}
	// ADD * operator!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Point & operator *(float t)
	{
		Point *pt = new Point(this ->x, this ->y);
		pt ->x = pt ->x * t;
		pt ->y = pt ->y * t;
		return *pt;
	}
	Point & operator+=(const Point &src)
	{
		x = x + src.x;
		y = y + src.y;
		return (*this);
	}
	Point & operator-=(const Point &src)
	{
		x = x - src.x;
		y = y - src.y;
		return	(*this);
	}
	const Point &operator-(const Point &src) const
	{
		return Point(*this) -= src;
	}
	const Point &operator +(const Point &src) const
	{
		return Point(*this) += src;
	}
	bool operator==(const Point &other) const {
		// Compare the values, and return a bool result.
		return (other.x == this ->x) &&(other.y == this ->y);
	}
	bool operator!=(const Point &other) const {
		return !(*this == other);
	}
	bool operator==(const CvPoint &other) const {
		// Compare the values, and return a bool result.
		return (other.x == this ->x) &&(other.y == this ->y);
	}
	bool operator!=(const CvPoint &other) const {
		return !(*this == other);
	}

	Point GetPoint(void)
	{
		Point ret(x, y);
		return	ret;
	}
	void NormalizeVector();
	static float GetLengthVector(Point p);
	static void CrossProduct(const Point p1, const Point p2, Point &p3);
	static float DotProduct(const Point p1, const Point p2)
	{
		return	p1.x * p2.x + p1.y * p2.y;
	}
};


CMyTriangle::CMyTriangle(void)
{
}

CMyTriangle::~CMyTriangle(void)
{
}

float compCross(CvPoint a, CvPoint b, float cx, float cy)
{
	float px = a.x - b.x;
	float py = a.y - b.y;
	float qx = cx - b.x;
	float qy = cy - b.y;
	return px*qy - py*qx;
}

bool CMyTriangle::IsIn(float x, float y)
{
	if(compCross(m_pt[1], m_pt[0], x, y)>0  
		&& compCross(m_pt[2], m_pt[1], x, y)>0
		&& compCross(m_pt[0], m_pt[2], x, y)>0) 
		return true;

	return false;
}


float CMyTriangle::DotProduct(float a[3], float b[3])
{
	float result;
	result = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	return result;
}

void CMyTriangle::CrossProduct(Point M1, Point M2, float resultM[3])
{
	resultM[0] = 0.0f;
	resultM[1] = 0.0f;
	resultM[2] = M1.x * M2.y - M1.y * M2.x;
}
// Determination of a point in the triangle
bool CMyTriangle::SameSide(Point p1, Point p2, Point a, Point b)
{
	//Point cp1, cp2;
	float cp1[3], cp2[3];
	Point b_a = b - a;
	Point p1_a = p1 - a;
	Point p2_a = p2 - a;
	CrossProduct(b_a, p1_a, cp1);
	CrossProduct(b_a, p2_a, cp2);
	if (DotProduct(cp1, cp2) >= 0)
		return true;
	else
		return false;
}

bool CMyTriangle::PointInTriangle(Point p, Point a, Point b, Point c)
{
	if(SameSide(p, a, b, c) && SameSide(p, b, a, c) && SameSide(p, c, a, b))
		return true;
	else
		return false;
}