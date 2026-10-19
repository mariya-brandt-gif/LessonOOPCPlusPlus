
#include <iostream>

class Array
{
    long* arr;
    int size;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    Array(int size)
    {
        if (size < 0)
        {
            size = 0;
        }
        this->size = size;

        if (size > 0)
        {
            arr = new long[size];

            for (int i = 0; i < size; i++)
            {
                arr[i] = 0;
            }
        }
        else
        {
            arr = nullptr;
        }
    }

    Array(const Array & other)
    {

    }
    


};

int main()
{
    std::cout << "Hello World!\n";
}
