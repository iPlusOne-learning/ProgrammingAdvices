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
        _FirstName = LastName;
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
    Person1.setFirstName("One");
    std::cout << "Full Name is: " <<  Person1.getFullName() << std::endl;


    return 0;
}