
#include "Point.h"
#include <iostream>
using namespace std;


Point::Point()
{
    x = 0;
    y = 0;
}


Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other)
{
    x = other.x;
    y = other.y;
}

void Point::Print() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}

Point& Point::operator++()
{
    ++x;
    ++y;

    return *this;
}

Point& Point::operator--()
{
    --x;
    --y;

    return *this;
}

bool Point::operator>(const Point& other) const
{
    return x * x + y * y >
        other.x * other.x + other.y * other.y;
}

bool Point::operator<(const Point& other) const
{
    return x * x + y * y <
        other.x * other.x + other.y * other.y;
}

Point Point::operator!() const
{
    return Point(-x, -y);
}