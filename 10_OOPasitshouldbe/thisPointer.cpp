#include <iostream>


class clsEmployee
{
    public:
        int ID;
        std::string Name;
        float Salary;

        clsEmployee(int ID, std::string Name, float Salary)
        {
            this->ID = ID;
            this->Name = Name;
            this->Salary = Salary;
        }
        static void Fun1(clsEmployee Employee)
        {
            Employee.Print();
        }
        void Fun2()
        {
            Fun1(*this);
        }
        void Print()
        {
            std::cout << ID << " " << Name << " " << Salary << std::endl;
        }
};

int main()
{
    clsEmployee Employee1(49, "kim", 4999);

    clsEmployee::Fun1(Employee1);
    Employee1.Fun2();

    return 0;
}