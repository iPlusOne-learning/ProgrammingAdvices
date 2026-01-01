#include <iostream>

class clsPerson
{
    private:
    int _ID; //read only property
    std::string _FirstName;
    std::string _LastName;
    std::string _FullName;
    std::string _Email;
    std::string _PhoneNumber;

    public:
    clsPerson(int ID, std::string FirstName, std::string LastName, std::string Email, std::string PhoneNumber )
    {
        _ID = ID;
        _FirstName = SetFirstName(FirstName);
        _LastName = SetLastName(LastName);
        _Email = SetEmail(Email);
        _PhoneNumber = SetPhoneNumber(PhoneNumber);
    }

    std::string SetFirstName(std::string FirstName)
    {
        return FirstName = FirstName;
    }
    std::string SetLastName(std::string LastName)
    {
        return _LastName = LastName;
    }
    std::string SetFullName()
    {
        return   _FullName = _LastName + " " + _FirstName; 

    }
    std::string SetEmail(std::string Email)
    {
        return  _Email = Email;
    }
    std::string SetPhoneNumber(std::string PhoneNumber)
    {
        return  _PhoneNumber = PhoneNumber;
    }
    void SendEmail(std::string Subject, std::string Body)
    {
        std::cout << "\nThe following email was sent successfully to email: " << _Email;
        std::cout << "\nSubject: ";
        std::cout << Subject << std::endl;
        std::cout << "Body: ";
        std::cout << Body << std::endl;
    }
    void SendSms(std::string Sms)
    {
        std::cout << "\nThe following smg was sent successfully to phone: " << _PhoneNumber << std::endl;
        std::cout << Sms << std::endl;
    }
    void GetId()
    {
        std::cout << _ID << std::endl;
    }
    void Print()
    {
        std::cout << "Info: \n";
        std::cout << "================================\n";
        std::cout << "ID             : " << _ID << std::endl;
        std::cout << "FirstName      : " << _FirstName << std::endl; 
        std::cout << "LastName       : " << _LastName << std::endl; 
        std::cout << "Full Name      : " << SetFullName() << std::endl; 
        std::cout << "Email          : " << _Email << std::endl; 
        std::cout << "Phone          : " << _PhoneNumber << std::endl; 
        std::cout << "\n================================\n";

    }   
};

int main()
{
    clsPerson Person1(10, "iPlus", "One","iplusone@gmail.com", "0477997711");

    Person1.Print();
    
    Person1.SendEmail("Hi", "How are you doing?");
    Person1.SendSms("What's up?");

    return 0;
}