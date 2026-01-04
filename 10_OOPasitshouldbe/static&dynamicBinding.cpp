#include <iostream>

class clsPerson
{
    public:
    virtual void Print()
    {
        std::cout << "I am class Person\n";
    }
};

class clsEmployee : public clsPerson
{
    public:
    void Print()
    {
        std::cout << "I am employee class\n";
    }
};

class clsStudent : public clsPerson
{
    public:
    void Print()
    {
        std::cout << "I am student class\n";
    }
};
int main()
{
    clsEmployee Employee1;
    clsStudent Student1;
    //Early-Static binding
    Employee1.Print();
    Student1.Print();

    clsPerson *Person1 = &Employee1;
    clsPerson *Person2 = &Student1;

    //Late-Dynamic Binding
    Person1->Print();
    Person2->Print();
    return 0;
}