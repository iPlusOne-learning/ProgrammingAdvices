#include <iostream>

class clsPerson
{
    private:
    int _ID;
    std::string _FirstName;
    std::string _LastName;
    std::string _Email;
    std::string _Phone;

    public:
    clsPerson(int ID, std::string FirstName, std::string LastName, std::string Email, std::string PhoneNumber )
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = PhoneNumber;
    }
    
    int ID()
    {
        return _ID;
    }

    void SetFirstName(std::string FirstName)
    {
        _FirstName = FirstName;
    }

    std::string GetFirstName()
    {
        return _FirstName;
    }

    void SetLastName(std::string LastName)
    {
         _LastName = LastName;
    }

    std::string GetLastName()
    {
        return _LastName;
    }

    void SetEmail(std::string Email)
    {
        _Email = Email;
    }

    std::string GetEmail()
    {
        return _Email;
    }

    void SetPhoneNumber(std::string PhoneNumber)
    {
        _Phone = PhoneNumber;
    }

    std::string GetPhoneNumber()
    {
        return _Phone;
    }

    std::string SetFullName()
    {
        return  _LastName + " " + _FirstName; 
    }

    void SendEmail(std::string Subject, std::string Body)
    {
        std::cout << "\nThe following email was sent successfully to email: " << _Email;
        std::cout << "\nSubject: " << Subject << std::endl;
        std::cout << "Body: " << Body << std::endl;
    }

    void SendSms(std::string TextMessage)
    {
        std::cout << "\nThe following smg was sent successfully to phone: " << _Phone << std::endl;
        std::cout << TextMessage << std::endl;
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
        std::cout << "Phone          : " << _Phone << std::endl; 
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
