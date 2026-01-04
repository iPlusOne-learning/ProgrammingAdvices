#include <iostream>

class clsA
{
    private:
        int _Var1;
    protected:
        int _Var3;
    public:
        int Var2;

    clsA (){
        _Var1 = 10;
        _Var3 = 30;
        Var2 = 40;
    }
    friend void SumNum(clsA A1);
};

void SumNum(clsA A1)
{
    std::cout << A1.Var2  + A1._Var1 + A1._Var3 << std::endl;
}

int main()
{
    clsA A1;
    SumNum(A1);
    return 0;
}