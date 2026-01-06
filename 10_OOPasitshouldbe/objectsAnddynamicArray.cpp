#include <iostream>

using namespace std;

class clsA
{
    public:
        int x;
        clsA() {}
        clsA(int Value)
        {
            x = Value;
        }
        void Print()
        {
            cout << "The value of x= " << x << endl;
        }
};
int main()
{
    short NumberOfObjects = 5;
    clsA *arrA = new clsA[NumberOfObjects];

    for (short i = 0; i < NumberOfObjects; i++)
    {
        arrA[i] = clsA(i);
    }

    for (short i = 0; i < NumberOfObjects; i++)
    {
        arrA[i].Print();
    }
        return 0;
}