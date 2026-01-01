#include <iostream>

class clsAddress
{
    private:
    std::string _AddressLine1;
    std::string _AddressLine2;
    std::string _POBox;
    std::string _ZipCode;

    public:

    clsAddress(std::string Add1, std::string Add2, std::string POBOX, std::string ZipCode)
    {
        _AddressLine1 = Add1;
        _AddressLine2 = Add2;
        _POBox = POBOX;
        _ZipCode = ZipCode;
    }
    // clsAddress()
    // {
    //     _AddressLine1 = "IplusOne street";
    //     _AddressLine2 = "Second chapter";
    //     _POBox = "14/2";
    //     _ZipCode = "20000";
    // }
    void Print()
    {
        std::cout << "\nAddress details: \n";
        std::cout << "---------------------------\n";
        std::cout << "\nAddressLine1 : " << _AddressLine1 << std::endl;
        std::cout << "\nAddressline2 : " << _AddressLine2 << std::endl;
        std::cout << "\nPOBOX        : " << _POBox << std::endl;
        std::cout << "\nZipCode      : " << _ZipCode << std::endl;
    }
};

int main()
{

    clsAddress Address1("iplus one street", "second chapter", "12/4", "20000");
    Address1.Print();

    return 0;
}