#include <iostream>
#include <string>
using namespace std;

class Abonent {
private:
    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

    static int count;

public:
    
    Abonent() : Abonent("Unknown") {
    }

    
    Abonent(string name) : Abonent(name, "Not specified") {
    }

    
    Abonent(string name, string home) : Abonent(name, home, "Not specified") {
    }

    
    Abonent(string name, string home, string work) : Abonent(name, home, work, "Not specified","Not specified") {
    }

   
    Abonent(string name, string home, string work,
        string mobile, string info) {
        fullName = name;
        homePhone = home;
        workPhone = work;
        mobilePhone = mobile;
        additionalInfo = info;
        count++;
    }

   
    ~Abonent() {
        count--;
    }

    
    void showInfo() const {
        cout << "\nFull name: " << fullName << endl;
        cout << "Home phone: " << homePhone << endl;
        cout << "Work phone: " << workPhone << endl;
        cout << "Mobile phone: " << mobilePhone << endl;
        cout << "Additional information: " << additionalInfo << endl;
    }

    
    void setMobilePhone(string phone) {
        mobilePhone = phone;
    }

   
    static int getCount() {
        return count;
    }
};


int Abonent::count = 0;

int main() {
    Abonent a1("Ivan Ivanenko",
        "044-123-45-67",
        "044-765-43-21",
        "+380501112233",
        "Colleague");

    Abonent a2("Olena Petrenko",
        "044-222-33-44",
        "Not specified",
        "+380671234567",
        "Friend");

    Abonent a3;

    cout << "PHONE BOOK\n";

    a1.showInfo();
    a2.showInfo();
    a3.showInfo();

    cout << "\nNumber of subscribers: "
        << Abonent::getCount() << endl;

  