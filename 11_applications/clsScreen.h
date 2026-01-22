#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t      ______________________________________";
        cout << "\n\n\t\t" << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t  " << SubTitle;
        }
        cout << "\n\t\t      ______________________________________\n\n";
        cout << "\t\t\tUser:" << CurrentUser.GetUserName() << endl;
        cout << "\t\t\tDate:"<< clsDate::DateToString(clsDate()) << endl;


    }
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t______________________________________";
            cout << "\n\n\t\t\t Access Denied! Contact your Admin.";
            cout << "\n\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};