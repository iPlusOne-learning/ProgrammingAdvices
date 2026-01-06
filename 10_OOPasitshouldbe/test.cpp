#include <iostream>
#include <clsString.h>

using namespace std;

void CheckNumber(int n)
{
    if (n > 100)
        throw "Too big";
    cout << "Number is: " << n << endl;
}

int main()
{
    try
    {
        CheckNumber(50);
        CheckNumber(150);
    }
    catch(const string msg)
    {
        cout << "Error caught: " << msg << endl;
    }
    return 0;
}