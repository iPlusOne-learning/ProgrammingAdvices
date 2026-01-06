#include <iostream>

class clsPerson
{
    class clsAddress
    {
        public:
        std::string AddressLine1;
        std::string AddressLine2;
        std::string City;
        std::string Country;

        void Print()
        {
            std::cout << AddressLine1 << std::endl;
            std::cout << AddressLine2 << std::endl;
            std::cout << City << std::endl;
            std::cout << Country << std::endl;
        }
    };

    public:
        std::string FullName;
        clsAddress Address;
        clsPerson()
        {
            FullName = "iplusone";
            Address.AddressLine1 = "Bourla";
            Address.AddressLine2 = "Anvers";
            Address.City = "Anvers";
            Address.Country = "NL";
        }
};

int main()
{
    clsPerson Person1;
    Person1.Address.Print();
    return 0;
}