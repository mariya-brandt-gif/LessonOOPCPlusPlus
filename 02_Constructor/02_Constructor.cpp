// 01_IntroToOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Windows.h>
using namespace std;

/*
struct Player
{
    string name;
    int age;
    int games;
    int goals;
};

void PrintPlayer(Player &pl)
{
    cout << "Name : " << pl.name << endl;
    cout << "Age : " << pl.age << endl;
    cout << "Games : " << pl.games << endl;
    cout << "Goals : " << pl.goals << endl;
}
void InitPlayer(Player& pl)
{
    cout << "Enter name : "; cin >> pl.name;
    cout << "Enter age : "; cin >> pl.age;
    pl.games = 0;
    pl.goals = 0;
}
void AddGameToPlayer(Player &pl, int goals = 0)
{
    pl.games++;
    pl.goals += goals;
}

struct Player // public
{
    string name;
    int age;
    int games;
    int goals;
};
*/
class Player  //private
{
private:
    string name;
    int age;
    int games;
    int goals;
public:
    void PrintPlayer()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void InitPlayer()
    {
        cout << "Enter name : "; cin >> name;
        cout << "Enter age : "; cin >> age;
        games = 0;
        goals = 0;
    }
    void AddGameToPlayer(int goals = 0)
    {
        games++;
        // (*this).goals += goals;
        this->goals += goals;
    }
};

class Student
{
private:
    string name;//data members. змінні-члени класу
    int marks[3];
public:
    //setter
    void setName(string name)
    {
        this->name = name;
    }
    void setMark(int index, int mark)
    {
        if (mark >= 1 and mark <= 12)
        {
            marks[index] = mark;
        }
        else
        {
            marks[index] = 0;
        }
    }

    //getter
    string getName()
    {
        return name;
    }
    int getMark(int index)
    {
        return marks[index];
    }


    double getAverageMark()// member function. функції-члени класу,методи
    {
        double summa = 0;
        for (int i = 0; i < 3; i++)
        {
            summa += marks[i];
        }
        return (double)summa / 3;
    }
};

//Exercice 1

struct Coord
{
    int x;
    int y;
};
class MyRectagle
{
private:
    int width;
    int height;
    char symbol;
    Coord position;
public:
    MyRectagle()
    {
        width = 5;
        height = 3;
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    MyRectagle(int size)
    {
        if (size > 0)
        {
            width = size;
            height = size;
        }
        else
        {
            width = 5;
            height = 3;
        }
        symbol = '*';
        position.x = 0;
        position.y = 0;

    }
    MyRectagle(int w, int h)
    {
        if (w > 0)
        {
            width = w;
        }
        else
        {
            width = 5;
        }
        if (h > 0)
        {
            height = h;
        }
        else
        {
            height = 3;
        }
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    void SetSymbol(char s) 
    {
        symbol = s;
    }
    void ChangeSize(int deltaHeight, int deltaWidth)
    {
        if (height + deltaHeight > 0 && width + deltaWidth > 0)
        {
            height += deltaHeight;
            width += deltaWidth;
        }
        else
        {
            cout << "Incorrect size!" << endl;
        }
    }
    void Move(int deltaX, int deltaY)
    {
        if (position.x + deltaX >= 0 && position.y + deltaY >= 0)
        {
            position.x += deltaX;
            position.y += deltaY;            
        }
        else
        {
            cout << "Incorrect coordinates!" << endl;
        }
    }
    void Print() 
    {
        // позиція вниз
        for (int i = 0; i < position.y; i++)
        {
            cout << endl;
        }
        // малює чотирикутник
        for (int i = 0; i < height; i++)
        {
            // позиція вправо
            for (int j = 0; j < position.x; j++)
            {
                cout << ' ';
            }
            // малює одну частинку чотирикутника 
            for (int j = 0; j< width; j++)
            {
                cout << symbol;
            }
            cout << endl;
        }
    }
    
};


int main()
{
    //Student st;
    /* st.Init();
     st.Print();

     st.setX(100);
     st.setX(100);
     st.setX(100);

     cout<< st.getX()<< st.getY()*/

   /* st.setName("Ivan");
    st.setMark(0, 10);
    st.setMark(1, 7);
    st.setMark(2, 8);

    cout << "Name : " << st.getName() << " Marks : " << st.getMark(0) << endl;

    cout << "Average mark : " << st.getAverageMark() << endl;*/


    /*   Player player;
       player.InitPlayer();
       player.PrintPlayer();

       player.AddGameToPlayer(1);
       player.AddGameToPlayer(2);
       player.AddGameToPlayer(3);
       player.PrintPlayer();*/


       /*InitPlayer(player);
       PrintPlayer(player);

       AddGameToPlayer(player);
       AddGameToPlayer(player,1);
       AddGameToPlayer(player,2);
       PrintPlayer(player);*/

       //Exercice 1
    {
        MyRectagle rect(6, 4);
        cout << "Original rectangle: " << endl;
        rect.Print();

        //змінити знак
        rect.SetSymbol('%');

        // висоту збільшити на 2 а ширину на 3
        rect.ChangeSize(2, 3);

        cout << endl << "After changing size: " << endl;
        rect.Print();

        //здвинути на 10 вправо і на 5 вниз
        rect.Move(10, 5);

        cout << endl << "After moving: " << endl;
        rect.Print();

        //шукає помилку
        rect.ChangeSize(-1, 0);
        rect.Move(-1, 0);

    }


}