#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
    private:

    string _Name;
    public:
    clsPerson(){ _Name = "baaaaa";}
    clsPerson (string Name)
    {
        _Name = Name;
    }
    void SetName(string Name)
    {
        _Name = Name;
    }
    void ChangeThis()
    {
        clsPerson NewName;
        NewName = *this;
    }
    void Print()
    {
        cout << _Name << endl;
    }
};

int main()
{
    clsPerson Person;
    Person.Print();
    Person.ChangeThis();
    Person.Print();


    return 0;
}