#pragma once
#include <iostream>
using namespace std;

enum Genre {Nomne, Fantasy, Comedy, Novel, SciFi, Education, Roman, Political};

class Book
{
	// variable
	//inline methods
	//prototype function

private:
	string title;
	int year;
	string author;
	int page;
	Genre genre; //

public:
	Book();
	Book(string t, int y, string a, int p, Genre g):title(t), year(y), author(a),page(p), genre(g){}
	void ShowInfo()const;
	{
		cout << "Title: " << title << endl;
		cout << "Year: " << year << endl;
		cout << "Author: " << author << endl;
		cout << "Page: " << page << endl;
		cout << "Genre: ;
			switch(genre)

		{
			case None:
		}
	}



};