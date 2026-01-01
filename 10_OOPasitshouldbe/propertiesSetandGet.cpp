#include <iostream>
#include <string>

class clsPerson
{

    private:

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
    std::cout << "Full Name is: " <<  Person1.getFullName() << std::endl;


    return 0;
}