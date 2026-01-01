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
    //copy constructor
    clsAddress(clsAddress &old_obj)
    {
        _AddressLine1 = old_obj.AddressLine1();
        _AddressLine2 = old_obj.AddressLine2();
        _POBox = old_obj.POBox();
        _ZipCode = old_obj.ZipCode();
    }
    // clsAddress()
    // {
    //     _AddressLine1 = "IplusOne street";
    //     _AddressLine2 = "Second chapter";
    //     _POBox = "14/2";
    //     _ZipCode = "20000";
    // }

    void SetAddressLine1(std::string AddressLine1)
    {
        _AddressLine1 = AddressLine1;
    }

    std::string AddressLine1()
    {
        return _AddressLine1;
    }

    void SetAddressLine2(std::string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }

    std::string AddressLine2()
    {
        return _AddressLine2;
    }

    void SetPOBox(std::string POBox)
    {
        _POBox = POBox;
    }

    std::string POBox()
    {
        return _POBox;
    }

    void _SetZipCode(std::string ZipCode)
    {
        _ZipCode = ZipCode;
    }

    std::string ZipCode()
    {
        return _ZipCode;
    }

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

    clsAddress Address2 = Address1;
    Address2.Print();

    return 0;
}