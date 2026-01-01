#include <iostream>


class clsA
{
    public:

    static int Function1()
    {
        return 10;
    }
    int Function2()
    {
        return 20;
    }
};


int main()
{
   std::cout << clsA::Function1() << std::endl;
    clsA A1;
    std::cout << A1.Function1() << std::endl;
    std::cout << A1.Function2() << std::endl;

    return 0;
}