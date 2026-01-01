#include <iostream>

class clsEmployee
{
    private:
    int _ID;
    std::string _FirstName;
    std::string _LastName;
    std::string _Title;
    std::string _Email;
    std::string _Phone;
    double _Salary;
    std::string _Department;

    public:
    clsEmployee(int ID, std::string FirstName, std::string LastName,std::string Title, std::string Email, std::string Phone, double Salary, std::string Department)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title;
        _Email = Email;
        _Phone = Phone;
        _Salary = Salary;
        _Department = Department;
    }
    int GetID()
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

    void SetTitle(std::string Title)
    {
        _Title = Title;
    }
    std::string GetTitle()
    {
        return _Title;
    }

    void SetEmail(std::string Email)
    {
        _Email = Email;
    }
    std::string GetEmail()
    {
        return _Email;
    }

    void SetPhone(std::string Phone)
    {
        _Phone = Phone;
    }
    std::string GetPhone()
    {
        return _Phone;
    }

    void SetSalary(double Salary)
    {
        _Salary = Salary;
    }

    double GetSalary()
    {
        return _Salary;
    }

    void SetDepartment(std::string Department)
    {
        _Department = Department;
    }
    std::string GetDepartment()
    {
        return _Department;
    }

    void SendEmail(std::string Subject, std::string Body)
    {
        std::cout << "\nThe following email was sent successfully to email: " << _Email;
        std::cout << "\nSubject: " << Subject << std::endl;
        std::cout << "Body: " << Body << std::endl;
    }

    void SendSMS(std::string TextMessage)
    {
        std::cout << "\nThe following smg was sent successfully to phone: " << _Phone << std::endl;
        std::cout << TextMessage << std::endl;
    }

    std::string FullName()
    {
        return  _LastName + " " + _FirstName; 
    }

    void Print()
    {
        std::cout << "Info: \n";
        std::cout << "================================\n";
        std::cout << "ID             : " << _ID << std::endl;
        std::cout << "FirstName      : " << _FirstName << std::endl; 
        std::cout << "LastName       : " << _LastName << std::endl; 
        std::cout << "Full Name      : " << FullName() << std::endl; 
        std::cout << "Title          : " << _Title << std::endl; 
        std::cout << "Email          : " << _Email << std::endl; 
        std::cout << "Phone          : " << _Phone << std::endl; 
        std::cout << "Salary         : " << _Salary << std::endl; 
        std::cout << "Department     : " << _Department << std::endl; 

        std::cout << "\n================================\n";
    } 
};

int main()
{

    clsEmployee Employee1(30,"iPlus", "One", "Technicien", "iplusone@gmail.com", "0333333", 2500,"IT");

    Employee1.Print();
    Employee1.SendEmail("Hello,", "Meeting is at 5am");
    Employee1.SendSMS("You left your keys on table");

    return 0;
}