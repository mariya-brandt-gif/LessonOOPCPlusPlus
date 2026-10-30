
#include "Vector.h"
#include <iostream>
using namespace std;


Vector::Vector()
{
    points = nullptr;
    countPoint = 0;
}

Vector::Vector(const Vector& other)
{
    countPoint = other.countPoint;

    if (countPoint > 0)
    {
        points = new Point[countPoint];

        for (int i = 0; i < countPoint; i++)
        {
            points[i] = other.points[i];
        }
    }
    else
    {
        points = nullptr;
    }
}

Vector::Vector(Vector&& other) noexcept
{
    points = other.points;
    countPoint = other.countPoint;

    other.points = nullptr;
    other.countPoint = 0;
}


Vector& Vector::operator=(const Vector& other)
{
   
    if (this == &other)
        return *this;

    
    Point* newPoints = nullptr;

    if (other.countPoint > 0)
    {
        newPoints = new Point[other.countPoint];

        for (int i = 0; i < other.countPoint; i++)
        {
            newPoints[i] = other.points[i];
        }
    }

  
    delete[] points;

    
    points = newPoints;
    countPoint = other.countPoint;

    return *this;
}


Vector& Vector::operator=(Vector&& other) noexcept
{
    if (this == &other)
        return *this;

    
    delete[] points;

 
    points = other.points;
    countPoint = other.countPoint;

   
    other.points = nullptr;
    other.countPoint = 0;

    return *this;
}


Vector::~Vector()
{
    delete[] points;
    points = nullptr;
    countPoint = 0;
}

void Vector::Add(const Point& point)
{

    Point* newPoints = new Point[countPoint + 1];

 
    for (int i = 0; i < countPoint; i++)
    {
        newPoints[i] = points[i];
    }

   
    newPoints[countPoint] = point;

  
    delete[] points;

   
    points = newPoints;
    countPoint++;
}


void Vector::Print() const
{
    cout << "Number of points: " << countPoint << endl;

    for (int i = 0; i < countPoint; i++)
    {
        cout << "Point " << i + 1 << ": ";
        points[i].Print();
    }
}