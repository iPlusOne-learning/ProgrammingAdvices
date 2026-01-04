#include <iostream>


class clsA
{
    private:
    int _Var1;

    protected:
    int _Var3;

    public:
        int Var2;

    friend class clsB;
};

class clsB : public clsA
{
    public: 
    void Function1(clsA A2)
    {
        std::cout << A2.Var2 << std::endl;
    }
};
int main()
{
    clsA A1;
    clsB B1;

    return 0;
}