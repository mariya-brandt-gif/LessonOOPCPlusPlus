
#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class Stack
{
    enum {EMPTY = -1};

    T* arr;
    int size;
    int topIndex;

public:
    
    Stack(int size) : size(size)
    {
        arr = new T[size]{};
        topIndex = EMPTY;
    }


    Stack(int size, initializer_list<T> values) : size(size)
    {
        if (size < values.size())
            this->size = values.size();

        arr = new T[this->size]{};
        topIndex = EMPTY;

        for (const T& elem : values)
        {
            Push(elem);
        }
    }

    Stack(const Stack& other) : size(other.size), topIndex(other.topIndex)
    {
        arr = new T[size];
        
        for (int i = 0; i <= topIndex; i++)
        {
            arr[i] = other.arr[i];
        }
    }


    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }

    bool IsFull()
    {
        return topIndex == size - 1;
    }

    bool Push(T elem)
    {
        if (IsFull())
        {
            int newSize = size * 2;
            T* temp = new T[newSize]{};
            for (int i = 0; i <= topIndex; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size = newSize;
        }
        arr[++topIndex] = elem;
        return true;
    }

    T Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
        return 0;
    }
    T Peek()
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
        return 0;
    }

    int GetCount()
    {
        return topIndex + 1;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    void Print()
    {
        cout << "Capacity: " << size << endl;
        cout << "Size: " << GetCount() << endl;

        for (int i = 0; i <=topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }


};


int main()
{
    cout << "----- Char stack ----- " << endl;

    Stack<char> st(5);

    st.Push('A');
    st.Push('B');
    st.Push('C');
    st.Push('D');
    st.Push('E');

    st.Push('F');
    st.Push('G');

    st.Print();

    cout << "Count: " << st.GetCount() << endl;
    cout << "Top element: " << st.Peek() << endl;
    cout << "Delete element: " << st.Pop() << endl;

    st.Print();

    cout << "Is Empty: " << st.IsEmpty() << endl;
    cout << "Is Full: " << st.IsFull() << endl;

    st.Clear();

    cout << "After Clear: " << st.GetCount() << endl;

   
    cout << endl << "----- Integer stack -----" << endl;

    Stack<int> st2(5, { 1,5,8,9,6,7,7,8 });

    st2.Print();
    st2.Push(100);
    st2.Print();

    cout << endl << "----- Double stack -----" << endl;
    Stack<double> st3(3, { 1.5, 2.5, 3.5 });

    st3.Print();

}
