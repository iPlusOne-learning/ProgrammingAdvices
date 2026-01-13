#pragma once

#include <iostream>

using namespace std;

class clsScreen
{
   protected:
   
   static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << "\t\t      ______________________________________";
        cout << "\n\n\t\t"<< Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t  " << SubTitle;
        }
        cout << "\n\t\t      ______________________________________\n\n";
    }
};