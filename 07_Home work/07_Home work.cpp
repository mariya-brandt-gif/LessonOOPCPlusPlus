#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;

template<typename T>
class Array
{
	T* arr;
	int size;
public:
	Array()
	{
		size = 0;
		arr = nullptr;
	}

	explicit Array(int size)
	{
		this->size = size;
		if (size > 0)
		{
			arr = new T[size]{};
		}
		else
		{
			arr = nullptr;
		}
	}

	Array(initializer_list<T> list)
	{
		size = static_cast<int>(list.size());
		if (size > 0)
		{
			arr = new T[size]{};
		}
		else
		{
			arr = nullptr;
		}

		int i = 0;
		for (const T& elem : list)
		{
			arr[i++] = elem;
		}
	}
	Array(const Array& other)
	{
		size = other.size;
		if (size > 0)
		{
			arr = new T[size]{};
		}
		else
		{
			arr = nullptr;
		}

		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}

	Array& operator=(const Array& other)
	{
		if (this == &other)
			return *this;

		T* newArr = nullptr;

		if (other.size > 0)
		{
			newArr = new T[other.size];

			for (int i = 0; i < other.size; i++)
				newArr[i] = other.arr[i];
		}

		delete[] arr;

		arr = newArr;
		size = other.size;

		return *this;
	}

	Array& operator=(initializer_list<T> list)
	{
		T* newArr = nullptr;
		if (list.size() > 0)
			newArr = new T[list.size()];

		int i = 0;
		for (const T& elem : list)
			newArr[i++] = elem;

		delete[] arr;

		arr = newArr;
		size = static_cast<int>(list.size());

		return *this;
	}
	void Fill(initializer_list<T> list)
	{
		*this = list;
	}

	void Print() const
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";

		cout << endl;
	}
	T* GetData()
	{
		return arr;
	}

	const T* GetData() const
	{
		return arr;
	}

	int GetSize() const
	{
		return size;
	}
	T& operator[](int index)
	{
		return arr[index];
	}

	const T& operator[](int index) const
	{
		return arr[index];
	}

	~Array()
	{
		delete[] arr;
	}
};

template<typename T>
T FindMax(const Array<T>& arr)
{
    if (arr.GetSize() == 0)
        return T{};

    T max = arr[0];

    for (int i = 1; i < arr.GetSize(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

template<typename T>
T FindMin(const Array<T>& arr)
{
    if (arr.GetSize() == 0)
        return T{};

    T min = arr[0];

    for (int i = 1; i < arr.GetSize(); i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

template<typename T>
void Sort(Array<T>& arr)
{
    int size = arr.GetSize();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
int BinarySearch(const Array<T>& arr, const T& value)
{
    int left = 0;
    int right = arr.GetSize() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value)
            return mid;

        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

template<typename T>
bool ReplaceElement(Array<T>& arr, int index, const T& value)
{
    if (index < 0 || index >= arr.GetSize())
        return false;

    arr[index] = value;
    return true;
}

int main()
{
	Array<int> a{ 8, 3, 7, 1, 9, 4 };

	cout << "Original array: ";
	a.Print();

	cout << "Maximum: " << FindMax(a) << endl;
	cout << "Minimum: " << FindMin(a) << endl;

	Sort(a);

	cout << "Sorted array: ";
	a.Print();

	int index = BinarySearch(a, 7);

	if (index != -1)
		cout << "Element 7 found at index: "
		<< index << endl;
	else
		cout << "Element not found!" << endl;

	if (ReplaceElement(a, 2, 100))
		cout << "Element replaced successfully." << endl;
	else
		cout << "Invalid index!" << endl;

	a.Print();

	
}

