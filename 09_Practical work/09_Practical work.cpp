
#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point p1;
    Point p2(3, 5);

    cout << "Point 1: ";
    p1.Print();

    cout << "Point 2: ";
    p2.Print();

    Point p3(p2);
    p3.Print();



    cout << "Before ++: ";
    p2.Print();

    ++p2;

    cout << "After ++: ";
    p2.Print();



    cout << "Before --: ";
    p2.Print();

    --p2;

    cout << "After --: ";
    p2.Print();




    Point a(3, 4);
    Point b(1, 2);

    if (a > b)
        cout << "a is farther from origin\n";

    if (a < b)
        cout << "a is closer to origin\n";



    Point p(3, 4);

    cout << "Original: ";
    p.Print();

    Point opposite = !p;

    cout << "Opposite: ";
    opposite.Print();
}