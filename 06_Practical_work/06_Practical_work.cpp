#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

class Time
{
    int hours;
    int minutes;
    int seconds;

    int ToSeconds()const
    {
        return hours * 3600 + minutes * 60 + seconds;
    }

public:
    Time()
    {
        hours = minutes = seconds = 0;
    }
    Time(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    explicit Time(int seconds)
    {
        this->hours = seconds / 3600;
        this->minutes = seconds / 60 % 60;
        this->seconds = seconds % 60;
    }
    void Print()
  
    {
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << endl;
    }

    Time& operator++()
    {
        seconds++;

        if (seconds >= 60)
        {
            seconds = 0;
            minutes++;
        }
        if (minutes >= 60)
        {
            minutes = 0;
            hours++;
        }

        if (hours >= 24)
        {
            hours = 0;
        }

        return *this;
    }

    Time operator+(const Time& other) const
    {
        return Time(ToSeconds() + other.ToSeconds());
    }

    Time operator-(const Time& other) const
    {
        int total = ToSeconds() - other.ToSeconds();

        if (total < 0)
            total = 0;

        return Time(total);
    }

    Time operator*(const Time& other) const
    {
        return Time(ToSeconds() * other.ToSeconds());
    }

    Time operator/(const Time& other) const
    {
        if (other.ToSeconds() == 0)
        {
            cout << "Error: division by zero!" << endl;
            return Time();
        }

        return Time(ToSeconds() / other.ToSeconds());
    }


    bool operator>(const Time& other) const
    {
        return ToSeconds() > other.ToSeconds();
    }

    bool operator<(const Time& other) const
    {
        return ToSeconds() < other.ToSeconds();
    }


    bool operator>=(const Time& other) const
    {
        return ToSeconds() >= other.ToSeconds();
    }

    bool operator<=(const Time& other) const
    {
        return ToSeconds() <= other.ToSeconds();
    }

    bool operator==(const Time& other) const
    {
        return ToSeconds() == other.ToSeconds();
    }

    bool operator!=(const Time& other) const
    {
        return !(*this == other);
    }
};

int main()
{
    Time t1;
    Time t2(12, 45, 30);
    Time t3(5555);

    cout << "Default time: ";
    t1.Print();

    cout << "Three parameters: ";
    t2.Print();

    cout << "5555 seconds: ";
    t3.Print();

    cout << endl << "Increment: " << endl;
    Time t4(11, 59, 59);
    ++t4;
    t4.Print();

    cout << endl << "Addition: " << endl;
    Time a(1, 20, 30);
    Time b(2, 10, 40);
    Time result = a + b;
    result.Print();

    cout << endl << "Subtraction: "<< endl;
    result = a - b;
    result.Print();

    cout << endl << "Multiplication: " << endl;
    Time c(0, 0, 4);
    Time d(0, 0, 5);
    result = c * d;
    result.Print();

    cout << endl << "Division: " << endl;
    result = d / c;
    result.Print();

    cout << "Comparison: " << endl;

    if (a > b)
        cout << " a > b " << endl;
    else
        cout << " a < b " << endl;

    if (a == b)
        cout << " a == b " << endl;
    else 
        cout << " a != b " << endl;

    cout << "Press Enter to start the clock...";
    cin.get();

    Time t(11, 59, 55);

    while (true)
    {
        system("cls");
        t.Print();
        Sleep(1000);
        ++t;
    }
}


