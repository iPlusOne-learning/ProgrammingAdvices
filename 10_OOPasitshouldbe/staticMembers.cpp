#include <iostream>


class clsA
{
    public:
    int var;
    static int counter;

    clsA()
    {
        counter++;
    }
    
    void Print()
    {
        std::cout << "\nvar   = " << var << std::endl;
        std::cout << "counter = " << counter << std::endl;
    }
};

int clsA::counter = 0;

int main()
{
    clsA A1,A2,A3;
    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    
    A1.Print();
    A2.Print();
    A3.Print();

    return 0;
}