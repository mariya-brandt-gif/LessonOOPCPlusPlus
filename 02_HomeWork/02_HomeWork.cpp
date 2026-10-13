
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int age;
    int* marks;
    int markCount;
    double averageMark;

    void SetAverageMark()
    {
        if (markCount == 0)
        {
            averageMark = 0.0;
            return;
        }

        int sum = 0;

        for (int i = 0; i < markCount; i++)
        {
            sum += marks[i];
        }

        averageMark = (double)sum / markCount;
    }

public:

    Student() : Student("Unknown", 0)
    {
    }

    Student(const char* name, int age)
    {
        this->name = name;
        this->age = age;

        marks = nullptr;
        markCount = 0;
        averageMark = 0.0;
    }

    ~Student()
    {
        delete[] marks;
    }

  
    void Print()
    {
        cout << "\n----- Student info -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Number of marks: " << markCount << endl;

        cout << "Marks: ";

        if (markCount == 0)
        {
            cout << "No marks";
        }
        else
        {
            for (int i = 0; i < markCount; i++)
            {
                cout << marks[i] << " ";
            }
        }

        cout << endl;
        cout << "Average mark: " << averageMark << endl;
    }

   
    void AddMark(int mark)
    {
        if (mark < 1 || mark > 12)
        {
            cout << "Invalid mark!" << endl;
            return;
        }

  
        int* newMarks = new int[markCount + 1];

      
        for (int i = 0; i < markCount; i++)
        {
            newMarks[i] = marks[i];
        }

        newMarks[markCount] = mark;

        delete[] marks;

        marks = newMarks;

        markCount++;

        SetAverageMark();
    }


    void Save()
    {
        ofstream file("student.txt");

        if (file.is_open())
        {
            file << name << endl;
            file << age << endl;
            file << markCount << endl;

            for (int i = 0; i < markCount; i++)
            {
                file << marks[i] << endl;
            }

            file << averageMark << endl;

            file.close();

            cout << "Data saved to file!" << endl;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }

    void Load()
    {
        ifstream file("student.txt");

        if (!file.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string loadedName;
        int loadedAge;
        int loadedCount;

        if (!getline(file, loadedName) ||
            !(file >> loadedAge >> loadedCount) ||
            loadedCount < 0)
        {
            cout << "Error reading data!" << endl;
            return;
        }


        int* loadedMarks = nullptr;

        if (loadedCount > 0)
        {
            loadedMarks = new int[loadedCount];
        }

        for (int i = 0; i < loadedCount; i++)
        {
            if (!(file >> loadedMarks[i]) ||
                loadedMarks[i] < 1 ||
                loadedMarks[i] > 12)
            {
                delete[] loadedMarks;
                cout << "Invalid mark data!" << endl;
                return;
            }
        }

        name = loadedName;
        age = loadedAge;

        delete[] marks;

        marks = loadedMarks;
        markCount = loadedCount;

        SetAverageMark();

        file.close();

        cout << "Data loaded from file!" << endl;
    }

     void SetName(string name)
    {
        this->name = name;
    }

    void SetAge(int age)
    {
        if (age >= 0)
        {
            this->age = age;
        }
    }

    string GetName()
    {
        return name;
    }

    int GetAge()
    {
        return age;
    }

    int GetMarkCount()
    {
        return markCount;
    }

    double GetAverageMark()
    {
        return averageMark;
    }

    int GetMark(int index)
    {
        if (index >= 0 && index < markCount)
        {
            return marks[index];
        }

        return -1;
    }
};

int main()
{
    Student st("Mariya Brandt", 20);

    st.AddMark(5);
    st.AddMark(4);
    st.AddMark(6);
    st.AddMark(3);

    st.Print();

    st.Save();

    st.SetName("Test Name");
    st.AddMark(2);

    cout << "\n----- Changed data -----" << endl;
    st.Print();

    st.Load();

    cout << "\n----- Loaded data -----" << endl;
    st.Print();

    cout << "\n----- Getters example -----" << endl;
    cout << "Name: " << st.GetName() << endl;
    cout << "Age: " << st.GetAge() << endl;
    cout << "Number of marks: " << st.GetMarkCount() << endl;
    cout << "Average mark: " << st.GetAverageMark() << endl;

 
}