#include <iostream>
#include <string>

class clsPerson
{

    private:

    int _ID = 10;
    std::string _FirstName;
    std::string _LastName;

    public:

    void SetFirstName(std::string FirstName)
    {
        _FirstName = FirstName;
    }
    void SetLastName(std::string LastName)
    {
        _LastName = LastName;
    }

    std::string GetFirstName()
    {
        return _FirstName;
    }
    std::string GetLastName()
    {
        return _LastName;
    }
    std::string GetFullName()
    {
        return _FirstName + " " + _LastName;
    }
    // __declspec(property(get = GetFirstName, put = SetFirstName)) std::string FirstName;
};

int main()
{

    clsPerson Person1;

    Person1.SetFirstName("iPlus");
    std::cout <<  Person1.GetFirstName() << std::endl;

    // Person1.FirstName = "Adam";
    // std::cout << Person1.GetFirstName() << std::endl;



    return 0;
}