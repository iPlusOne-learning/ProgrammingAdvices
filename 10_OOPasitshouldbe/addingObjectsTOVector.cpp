#include <iostream>

using namespace std;

class clsA
{
    public:
        int x;
        clsA(int value)
        {
            x = value;
        }
        void Print()
        {
            cout << "The value of x= " << x << endl;
        }
};
int main()
{
    vector <clsA> v1;
    short NumberOfObjects = 5;
    for (short i = 0; i < NumberOfObjects; i++)
    {
        v1.push_back(clsA(i));
    }
    for (short i = 0; i < NumberOfObjects; i++)
    {
        v1[i].Print();
    }
        return 0;
}