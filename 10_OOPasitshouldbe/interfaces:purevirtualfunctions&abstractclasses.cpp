#include <iostream>

class clsPhone
{
    virtual void Dial(std::string PhoneNumber) = 0;
    virtual void SendSMS(std::string) = 0;
    virtual void TakePicture() = 0;
};

class clsiPhone : public clsPhone
{
    public:
    void Dial(std::string PhoneNumber)
    {

    }
    void SendSMS(std::string)
    {

    }
    void TakePicture()
    {
        
    }
};

int main()
{
    clsiPhone Phone1;

    return 0;
}