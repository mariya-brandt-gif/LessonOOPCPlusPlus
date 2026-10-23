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
    Airplane(string model, string typ, int currentNumOfPas,
        int maxNumOfPas)
    {
        this->model = model;
        this->currentNumOfPas = currentNumOfPas;
        this->maxNumOfPas=maxNumOfPas
        
    }
        
    }

    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    ~Airplane()
    {
        delete[];
    }

};

