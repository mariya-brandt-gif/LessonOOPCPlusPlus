#include <iostream>
#include <string>
using namespace std;

class Airplane
{
private:
	string model;
	string typ;
	int currentNumOfPas;
	int maxNumOfPas;

public:
    Airplane(string model, string typ, int currentNumOfPas, int maxNumOfPas)
    {
        this->model = model;
        this->typ = typ;

        if (maxNumOfPas < 0)
            this->maxNumOfPas = 0;
        else
            this->maxNumOfPas = maxNumOfPas;

        if (currentNumOfPas < 0)
            this->currentNumOfPas = 0;
        else if (currentNumOfPas > this->maxNumOfPas)
            this->currentNumOfPas = this->maxNumOfPas;
        else
            this->currentNumOfPas = currentNumOfPas;

    }

    friend bool operator == (const Airplane& a, const Airplane& b)
    {
        return a.typ == b.typ;
    }

    Airplane& operator++()
    {
        if (currentNumOfPas < maxNumOfPas)
            currentNumOfPas++;
        else
            cout << "Maximum passenger capacity reached!" << endl;

        return *this;
    }

    Airplane& operator--()
    {
        if (currentNumOfPas > 0)
                currentNumOfPas--;
        else
            cout << "No passengers left on board!" << endl;
        return *this;
    }

    friend bool operator>(const Airplane& a, const Airplane& b)
    {
        return a.maxNumOfPas > b.maxNumOfPas;
    }

    void operator()(int value)
    {
        if (value < 0)
        {
            cout << "The value must not be negative!" << endl;
            return;
        }
        if (currentNumOfPas + value <= maxNumOfPas)
            currentNumOfPas += value;
        else
        {
            cout << "Too many passengers! The maximum number is " << maxNumOfPas << "." << endl;
        }
    }
    void PrintAirplane() const
    {
        cout << "Model: " << model << endl;
        cout << "Type: " << typ << endl;
        cout << "Current passengers: " << currentNumOfPas << endl;
        cout << "Maximum passengers: " << maxNumOfPas << endl;
    }
};

int main()
{
    Airplane a1("Boeing 737", "Passagierflugzeug", 100, 180);
    Airplane a2("Airbus A320", "Passagierflugzeug", 150, 200);
    Airplane a3("Airbus A32", "Passagierflugzeug", 50, 160);
    Airplane a4("F-16", "Kampfflugzeug", 1, 1);

    cout << " --- " << endl;
    a1.PrintAirplane();

    if (a1 == a2)
        cout << "a1 and a2 have the same type. " << endl;
    else
        cout << "a1 and a2 have different types." << endl;

    cout << endl;

    ++a1;
    cout << "After ++a1" << endl;
    a1.PrintAirplane();

    --a1;
    cout << "After --a1" << endl;
    a1.PrintAirplane();

    if (a2 > a1)
        cout << "a2 has a higher maximum passenger capacity." << endl;
    else
        cout << "a1 has an equal or higher maximum passenger capacity."<< endl;
    cout << endl;

    a1(15);
    cout << "After a1(15)" << endl;
    a1.PrintAirplane();
    cout << endl;

    a1(12);
    a1.PrintAirplane();


}

