#include <iostream>
#include <string>

class clsPerson
{

    public:
    std::string FirstName;
    std::string LastName;

    std::string FullName()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{

    clsPerson Person1;

    Person1.FirstName = "Adam";
    Person1.LastName = "iPlusOne";

    std::cout << Person1.FullName() << std::endl;

    return 0;
}