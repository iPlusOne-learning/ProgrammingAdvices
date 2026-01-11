#include "headerFiles/clsString.h"

int main()
{
    clsString String1;
    String1.SetValue("hello how are you doing?");

    vector <string> vStrings = String1.Split(" ");
    
    for (string &str : vStrings)
    {
        cout << str << endl;
    }
    return 0;
}