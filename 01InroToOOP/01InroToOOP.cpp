
#include <iostream>
#include <fstream>
#include <string>

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
//class Player  //private
//{
//private:
//    string name;
//    int age;
//    int games;
//    int goals;
//public:
//    void PrintPlayer()
//    {
//        cout << "Name : " << name << endl;
//        cout << "Age : " << age << endl;
//        cout << "Games : " << games << endl;
//        cout << "Goals : " << goals << endl;
//    }
//    void InitPlayer()
//    {
//        cout << "Enter name : "; cin >> name;
//        cout << "Enter age : "; cin >> age;
//        games = 0;
//        goals = 0;
//    }
//    void AddGameToPlayer(int goals = 0)
//    {
//        games++;
//        // (*this).goals += goals;
//        this->goals += goals;
//    }
//};
//
//class Student
//{
//private:
//    string name;//data members. змінні-члени класу
//    int marks[3];
//public:
//    //setter
//    void setName(string name)
//    {
//        this->name = name;
//    }
//    void setMark(int index, int mark)
//    {
//        if (mark >= 1 and mark <= 12)
//        {
//            marks[index] = mark;
//        }
//        else
//        {
//            marks[index] = 0;
//        }
//    }
//
//    //getter
//    string getName()
//    {
//        return name;
//    }
//    int getMark(int index)
//    {
//        return marks[index];
//    }
//
//
//    double getAverageMark()// member function. функції-члени класу,методи
//    {
//        double summa = 0;
//        for (int i = 0; i < 3; i++)
//        {
//            summa += marks[i];
//        }
//        return (double)summa / 3;
//    }
//};
// Exercice 1

class Student
{
private:
    string name;
    string birthDate;
    string phone;
    string city;
    string country;
    string institution;
    string institutionCity;
    string institutionCountry;
    int groupNumber;
public:
    void Init()
    {
        cout << "Enter full name: ";
        getline(cin, name);

        cout << "Enter birth date: ";
        getline(cin, birthDate);

        cout << "Enter phone: ";
        getline(cin, phone);

        cout << "Enter city: ";
        getline(cin, city);

        cout << "Enter country: ";
        getline(cin, country);

        cout << "Enter educational institution: ";
        getline(cin, institution);

        cout << "Enter institution city: ";
        getline(cin, institutionCity);

        cout << "Enter institution country: ";
        getline(cin, institutionCountry);

        cout << "Enter group number: ";
        cin >> groupNumber;
    }
    void Print()
    {
        cout << endl << "------ Student information ----- " << endl;
        cout << "Full name: "<< name << endl;
        cout << "Birth date: "<< birthDate << endl;
        cout << "Phone: "<< phone << endl;
        cout << "City: "<< city << endl;
        cout << "Country: "<< country << endl;
        cout << "Institution: "<< institution << endl;
        cout << "Institution city: "<< institutionCity << endl;
        cout << "Institution coutry: "<< institutionCountry << endl;
        cout << "Group number:" << groupNumber<< endl;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setBirthDate(string birthDate)
    {
        this->birthDate = birthDate;
    }

    void setPhone(string phone)
    {
        this->phone = phone;
    }

    void setCity(string city)
    {
        this->city = city;
    }

    void setCountry(string country)
    {
        this->country = country;
    }

    void setInstitution(string institution)
    {
        this->institution = institution;
    }

    void setInstitutionCoutry(string institutionCountry)
    {
        this->institutionCountry = institutionCountry;
    }

    void setGroupNumber(int groupNumber)
    {
        this->groupNumber = groupNumber;
    }


    string getName()
    {
        return name;
    }

    string getBirthDate()
    {
        return birthDate;
    }

    string getPhone()
    {
        return phone;
    }

    string getCity()
    {
        return city;
    }

    string getCoutnry()
    {
        return country;
    }

    string getInstitution()
    {
        return institution;
    }

    string getInstitutionCity()
    {
        return institutionCity;
    }

    string getInstitutionCountry()
    {
        return institutionCountry;
    }

    int getGroupNumber()
    {
        return groupNumber;
    }
    void SaveToFile()
    {
        ofstream file("student.txt");
            if (file.is_open())
            {
                file << name << endl;
                file << birthDate << endl;
                file << phone << endl;
                file << city << endl;
                file << country << endl;
                file << institution << endl;
                file << institutionCity << endl;
                file << institutionCountry << endl;
                file << groupNumber << endl;

                file.close();
                cout << "Data saved to file! " << endl;
            }
            else
            {
                cout << "Error opening file!" << endl;
            }
    }

    void LoadFromFile()
    {
        ifstream file("student.txt");
        if (file.is_open())
        {
            getline(file, name);
            getline(file, birthDate);
            getline(file, phone);
            getline(file, city);
            getline(file, country);
            getline(file, institution);
            getline(file, institutionCity);
            getline(file, institutionCountry);

            file >> groupNumber;

            file.close();
            cout << "Data loaded from file!" << endl;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }
};


//Exercice 2

class Point
{
private:
    double x;
    double y;
    double z;
public:
    void Init()
    {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
        cout << "Enter z: ";
        cin >> z;
    }
    void Print()
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    }
    void setX(double x)
        {
            this->x = x;
        }
    void setY(double y)
        {
            this->y = y;
        }
    void setZ(double z)
        {
            this->z = z;
        }

    double getX()
        {
        return x;
        }

    double getY()
        {
        return y;
        }

    double getZ()
        {
        return z;
        }

    void SaveToFile()
    {
        ofstream file("point.txt");
        if (file.is_open())
        {
            file << x << endl;
            file << y << endl;
            file << z << endl;

            file.close();
            cout << "Data saved to file!" << endl;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }

    void LoadFromFile()
    {
        ifstream file("point.txt");

        if (file.is_open())
        {
            file >> x;
            file >> y;
            file >> z;

            file.close();
            cout << "Data loaded from file!" << endl;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }

};


int main()
{
    {
        /* Student st;
         st.Init();
         st.Print();

         st.setX(100);
         st.setX(100);
         st.setX(100);

         cout << st.getX() << st.getY()

             st.setName("Ivan");
         st.setMark(0, 10);
         st.setMark(1, 7);
         st.setMark(2, 8);

         cout << "Name : " << st.getName() << " Marks : " << st.getMark(0) << endl;

         cout << "Average mark : " << st.getAverageMark() << endl;


          Player player;
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
    }
    //Exercice 1

    {
        Student st;
        st.Init();
        st.Print();

        st.SaveToFile();
        st.setName("Test Name");
        
        cout << endl << "----- Changed data -----" << endl;
        st.Print();
        
        st.LoadFromFile();
        cout << endl << "---- Loaded data ----" << endl;
        st.Print(); 

        //cout << endl << "----- Getters example -----" << endl;
        //cout << "Name: " << st.getName() << endl;
        //cout << "Phone: " << st.getPhone() << endl;
        //cout << "Group: " << st.getGroupNumber() << endl;

        //st.setName("Mariya Brandt");
        //cout << endl << "Changed name: " << st.getName() << endl;

    }



    //Exercice 2
 /*   {
        Point p;

        p.Init();
        p.Print();

        cout << "X = " << p.getX() << endl;
        cout << "Y = " << p.getY() << endl;
        cout << "Z = " << p.getZ() << endl;

        p.SaveToFile();

        p.setX(100);
        p.setY(150);
        p.setZ(180);

        cout << endl << "Changed coordinates: " << endl;
        p.Print();

        p.LoadFromFile();
        cout << endl << "Loaded coordinates: " << endl;
        p.Print();

    }*/


    /*Завдання 2:

    Створити клас Student який буде містити характеристики : ім’я, вік, колекція оцінок, кількість оцінок та середню оцінку.

        В класі повинні буди реалізовані наступні конструктори :

    · Конструктор по замовчуванню() – встановлюватиме початкові дані

        · Параметризований конструктор(const char* name, int age) – ініціалізує клас значеннями з параметрів

        Також створити деструктор для звільнення ресурсів та наступні методи :

    1. Print() – виводить інформацію про студента на екран

        2. AddMark(int mark) – додає оцінку для студента

        3. SetAverageMark() – приватний метод для обрахунку та встановлення середньої оцінки студента(викликається всередині класа при додаванні оцінки)

        4. Save() – збереження студента в файл

        5. Load() – зчитування студента в файла

        Забезпечити клас необхідними методами для доступа до властивостей(getters, setters).По можливості застосувати делегування конструкторів
*/

}