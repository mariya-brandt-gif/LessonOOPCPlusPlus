#include <iostream>
using namespace std;

class Array {
    int* arr;
    int size;

public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    ~Array()
    {
        delete[] arr;
    }

    int getSize() const
    {
        return size;
    }

    int getValue(int index) const
    {
        return arr[index];
    }

    void setValue(int num, int index)
    {
        arr[index] = num;
    }

    void display(int index) const
    {
        cout << arr[index] << " ";
    }


    int& operator[](int index)
    {
        return arr[index];
    }

    void operator()(int value)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] += value;
        }
    }
};

void PrintArray(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }
}

int main()
{
    int size = 5;
    Array arr(size);

    for (int i = 0; i < arr.getSize(); i++)
    {
        arr[i] = size - i;
    }

    cout << "Initial array: ";
    PrintArray(arr);


    arr[0] = 100;

    cout << endl << "After changing the first element: " ;
    PrintArray(arr);


    arr(10);

    cout <<endl << "After increasing by 10: "; 
    PrintArray(arr);
}
