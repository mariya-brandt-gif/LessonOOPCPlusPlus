
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
	string author;
	string title;
	string publisher;
	int year;
	int quantity;
	int pages;

public:
	explicit Book(string author, string title, string publisher, int year, int quantity, int pages)
	{
		this->author = author;
		this->title = title;
		this->publisher = publisher;
		this->year = year;
		this->quantity = quantity;
		this->pages = pages;
	}

	string getAuthor() const
	{
		return author;
	}
	string getPublisher() const
	{
		return publisher;
	}
	int getYear()const
	{
		return year;
	}

	void display() const
	{
		cout << "Autor: " << author << endl;
		cout << "Title: " << title << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Year: " << year << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Pages: " << pages << endl;
	}
};




int main()
{

	Book books[3] = {
		Book("Autor 1", "Titel 1", "Verlag 1", 2020, 5, 300),
		Book("Lesja Ukrainka", "Lisova pisnja", "Dnipro", 2021, 4, 180),
		Book("Ivan Franko", "Zakhar Berkut", "Veselka", 2019, 6, 240)
	};

	int size = sizeof(books) / sizeof(books[0]);

	string searchAuthor;
	cout << "Enter the author: ";
	getline(cin, searchAuthor);

	bool foundAuthor = false;

	for (int i = 0; i < size; i++)
	{
		
		if (books[i].getAuthor() == searchAuthor)
		{
			foundAuthor = true;
			books[i].display();
			cout << " ----- " << endl;
		}
		
	}
	if (foundAuthor == false)
	{
		cout << "The book was not found!" << endl;
	}

	string searchPublisher;
	cout << "Enter the publisher: ";
	getline(cin, searchPublisher);

	bool foundPublisher = false;

	for (int i = 0; i < size; i++)
	{
		if (books[i].getPublisher() == searchPublisher)
		{
			foundPublisher = true;
			books[i].display();
			cout << " ----- " << endl;
		}
	}
	if (foundPublisher == false)
	{
		cout << "The book was not found!" << endl;
	}

	int searchYear;
	cout << "Enter the year: ";
	cin >> searchYear;

	bool foundYear = false;

	for (int i = 0; i < size; i++)
	{
		if (books[i].getYear() > searchYear)
		{
			foundYear = true;
			books[i].display();
			cout << " ----- " << endl;
		}
	}
	if (foundYear == false)
	{
		cout << "The book was not found!" << endl;
	}
	


}
