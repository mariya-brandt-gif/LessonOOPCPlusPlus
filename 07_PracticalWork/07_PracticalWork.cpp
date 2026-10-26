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

	
int main()
{

	{
		Array<int> a1(5);
		a1.Print();

		Array<int> a2{ 4, 7, 8, 9, 6 };
		a2.Print();

		a2.Fill({ 3, 2, 1 });
		a2.Print();


		a2 = { 10, 20, 30, 40 };
		a2.Print();


		Array<double> a3{ 1.5, 2.7, 3.9 };
		a3.Print();


		Array<string> a4{ "red", "green", "blue" };
		a4.Print();

	}

}