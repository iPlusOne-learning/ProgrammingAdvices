#include <iostream>

class clsPerson
{
    struct stAddress
    {
        std::string AddressLine1;
        std::string AddressLine2;
        std::string City;
        std::string Country;
    };
    public:
        std::string FullName;
        stAddress Address;
    clsPerson(){
        FullName = "iPlus One";
        Address.AddressLine1 = "bourlastraat 44";
        Address.AddressLine2 = "rue de rien";
        Address.City = "Paris";
        Address.Country = "Japan";
    }
    void Print()
    {
        std::cout << FullName << std::endl;
        std::cout << Address.AddressLine1 << std::endl;
        std::cout << Address.AddressLine2 << std::endl;
        std::cout << Address.City << std::endl;
        std::cout << Address.Country << std::endl;
    }
};

int main()
{
    clsPerson Person1;

    Person1.Print();
    return 0;
}