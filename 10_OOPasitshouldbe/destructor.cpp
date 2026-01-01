#include <iostream>

class clsPerson
{
    public:
    std::string FullName;

    clsPerson()
    {
        FullName = "iPlus One";
        std::cout << "\nHi, I'm constructor.\n";
    }
    ~clsPerson()
    {
        std::cout << "\nHi, I am destructor\n";
    }
};

int main()
{
    clsPerson Person1;
    
    return 0;
}