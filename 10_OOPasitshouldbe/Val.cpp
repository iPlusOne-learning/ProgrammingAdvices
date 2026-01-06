#include <iostream>

using namespace std;

class clsA
{
    public:
        int x;
        void Print()
        {
            cout << "The value of x = " << x << endl;
        }
};

void Func1(clsA A1)
{
    A1.x = 100;
}

void Func2(clsA &A1)
{
    A1.x = 200;
}

int main()
{
    clsA A1;
    A1.x = 50;
    cout << "\nbefore call func1: \n";
    A1.Print();

    Func1(A1);
    cout << "After calling function1\n";
    A1.Print();

    Func2(A1);
    cout << "After calling function2: \n";
    A1.Print();
}