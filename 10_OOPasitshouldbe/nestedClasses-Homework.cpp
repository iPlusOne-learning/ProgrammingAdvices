#include <iostream>

class clsPerson
{
    class clsAddress
    {
        private:
        std::string _AddressLine1;
        std::string _AddressLine2;
        std::string _City;
        std::string _Country;
        
        public:
        clsAddress(std::string AddressLine1, std::string AddressLine2, std::string City, std::string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country = Country;
        }
        void SetAddressLine1(std::string AddressLine1)
        {

        }
        std::string GetAddressLine1()
        {
            return _AddressLine1;
        }

        void SetAddressLine2(std::string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }
        std::string GetAddressLine2()
        {
            return _AddressLine2;
        }

        void SetCity(std::string City)
        {
            _City = City;
        }
        std::string GetCity()
        {
            return _City;
        }

        void SetCountry(std::string Country)
        {
            _Country = Country;
        }
        std::string GetCountry()
        {
            return _Country;
        }

        void Print()
        {
            std::cout << _AddressLine1 << std::endl;
            std::cout << _AddressLine2 << std::endl;
            std::cout << _City << std::endl;
            std::cout << _Country << std::endl;
        }
    };

    std::string _FullName;
    public:
    clsAddress Address = clsAddress("", "", "", "");
        clsPerson(std::string FullName, std::string AddressLine1, std::string AddressLine2, std::string City, std::string Country)
        {
            _FullName = FullName;
            Address = clsAddress(AddressLine1, AddressLine2, City, Country);
            // Address.SetAddressLine1(AddressLine1);
            // Address.SetAddressLine2(AddressLine2);
            // Address.SetCity(City);
            // Address.SetCountry(Country);
        }
        // void Print()
        // {
        //     std::cout << _FullName;
        //     std::cout << Address.GetAddressLine1() << std::endl;
        //     std::cout << Address.GetAddressLine2() << std::endl;
        //     std::cout << Address.GetCity() << std::endl;
        //     std::cout << Address.GetCountry() << std::endl;
        // }
};

int main()
{
    clsPerson Person1("kokito","bour", "bus", "anvers", "NL");

    Person1.Address.Print();

    return 0;
}