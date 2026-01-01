#include <iostream>
#include <string>

class clsPerson
{

    private:

    int _ID = 10;
    std::string _FirstName;
    std::string _LastName;

    public:

    void setFirstName(std::string FirstName)
    {
        _FirstName = FirstName;
    }
    void setLastName(std::string LastName)
    {
        _LastName = LastName;
    }

    int getID()
    {
        return _ID;
    }
    std::string getFirstName()
    {
        return _FirstName;
    }
    std::string getLastName()
    {
        return _LastName;
    }
    std::string getFullName()
    {
        return _FirstName + " " + _LastName;
    }

};

int main()
{

    clsPerson Person1;

    Person1.setFirstName("iPlus");
    Person1.setLastName("One");

    std::cout << "ID is: " <<  Person1.getID() << std::endl;
    std::cout << "Full Name is: " <<  Person1.getFullName() << std::endl;


    return 0;
}