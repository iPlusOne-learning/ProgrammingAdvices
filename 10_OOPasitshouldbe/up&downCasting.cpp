#include <iostream>

class clsPerson
{
    public:
        std::string FullName = "I am Base Class\n";
};

class clsEmployee : public clsPerson
{
    public:
        std::string Employee = "I am derived class employee\n";
};

int main()
{
    clsEmployee Employee1;
    std::cout << Employee1.FullName << std::endl;

    //upcasting
    clsPerson *Person1 = &Employee1;
    std::cout << Person1->FullName << std::endl;

    clsPerson Person2;
    std::cout << Person2.FullName << std::endl;

    // downcasting
    // clsEmployee *Employee2 = &Person2;
    // std::cout <<Employee2->FullName << std::endl;

    return 0;
} 