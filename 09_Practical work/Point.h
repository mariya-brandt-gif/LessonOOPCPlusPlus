#pragma once
class Point
{
private:
    int x;
    int y;

public:
    Point();
    Point(int x, int y);

    Point(const Point& other);

    void Print() const;

    Point& operator++();

    Point& operator--();


    bool operator>(const Point& other) const;
    bool operator<(const Point& other) const;


    Point operator!() const;
};

class point
{
};
