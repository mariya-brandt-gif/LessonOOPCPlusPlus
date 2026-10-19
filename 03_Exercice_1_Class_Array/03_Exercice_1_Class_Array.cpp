
#include <iostream>
#include <ctime>
using namespace std;

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
        if (size < 0) size = 0;
        
        this->size = size;

        if (this->size > 0)
        {
            arr = new long[this->size];
            for (int i = 0; i < this->size; i++)
            {
                arr[i] = 0;
            }
        }
        else
        {
            arr = nullptr;
        }
    }

    Array(const Array& other)
    {
        size = other.size;
        if (size > 0)
        {
            arr = new long[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        else
        {
            arr = nullptr;
        }
    }

    void RandomFill()
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }
    void Input()
    {
        int n;

        cout << "Enter array size: "; cin >> n;

        if (n < 0)
        {
            cout << "Invalid size!" << endl;
            return;
        }
        if (arr != nullptr)
            delete[]arr;
        size = n;

        if (size > 0)
        {
            arr = new long[size];
            for (int i = 0; i < size; i++)
            {
                cout << "arr[" << i << "] = "; cin >> arr[i];
            }
        }
        else
        {
            arr = nullptr;
        }

    }
    void Print()
    {
        if (size == 0)
        {
            cout << "Array is empty! " << endl;
            return;
        }
        cout << "Array: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Add(long value)
    {
        long* temp = new long[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = value;
        if (arr != nullptr)
            delete[]arr;

        arr = temp;
        size++;
    }

    void DeleteByIndex(int index)
    {
        if (size == 0)
        {
            cout << "Array is empty! " << endl; 
            return;
        }
        if (index < 0 || index >= size)
        {
            cout << "Invalid index!" << endl;
            return;
        }
        long* temp = nullptr;
        if (size > 1)
            temp = new long[size - 1];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (i != index)
            {
                temp[j] = arr[i];
                j++;
            }
        }
        delete[] arr;
        arr = temp;
        size--;
    }

    void DeleteByValue(long value)
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
            return;
        }
        int index = -1;

        for (int  i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Element not found!" << endl;
            return;
        }
        DeleteByIndex(index);
    }

    void SortAscending()
    {
        for (int i = 0; i < size-1; i++)
        {
            for (int j = 0;j < size - 1 - i;j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    
    void SortDescending()
    {
        for (int i = 0; i < size -1; i++)
        {
            for (int j = 0; j < size - 1-i; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }

        }
    }

    long Min()
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
            return 0;
        }

        long min = arr[0];

        for (int i = 1; i < size; i++)
        {
            if(arr[i] < min)
            min = arr[i];
        }
        return min;
    }

    long Max()
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
            return 0;
        }

        long max = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (arr[i] > max)
            max = arr[i];
        }
        return max;
    }

    double Average()
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
            return 0;
        }
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum / size;
    }
    ~Array()
    {
        if (arr != nullptr)
            delete[]arr;
    }
 
};


int main()
{
    srand(time(0));
    
    Array a;

    a.Input();

    cout << endl<< "Original array: " << endl;
    a.Print();

    a.Add(50);
    cout << endl << "After adding 50: "<< endl;
    a.Print();

    a.DeleteByIndex(0);
    cout << endl << "After deleting element at index 0: " << endl;
    a.Print();

    a.DeleteByValue(50);
    cout << endl << "After deleting value 50: " << endl;
    a.Print();

    a.SortAscending();
    cout << endl << "Ascending order: " << endl;
    a.Print();

    a.SortDescending();
    cout << endl << "Descending order: " << endl;
    a.Print();

    if (a.Average() || true)
    {
    }

    cout << endl << "Mimimum: " << a.Min() << endl;
    cout << endl << "Maximum: " << a.Max() << endl;
    cout << endl << "Average: " << a.Average() << endl;

    Array b(5);

    cout << endl << "Array b (initialized with zeros): " << endl;
    b.Print();

    b.RandomFill();
    cout << endl << "Array b (random values): " << endl;
    b.Print();

    Array c(b);
    cout << endl << "Copied array c: " << endl;
    c.Print();
}
