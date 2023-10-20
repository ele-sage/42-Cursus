#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"



class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &point);
    Point& operator=(const Point &point);
    ~Point();

    Fixed const getX(void) const;
    Fixed const getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
void displayPoint(Point const a, Point const b, Point const c, Point const point, int const width, int const height);

#endif