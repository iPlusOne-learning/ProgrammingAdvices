#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsInputValidate.h"


class clsLoginScreen : protected clsScreen
{

private:

    static bool _Login()
    {

        bool LoginFaild = false;
        short FailedLoginCount = 0;

        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                FailedLoginCount++;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << (3 - FailedLoginCount) << " Trials to login\n" << endl;
                if (FailedLoginCount == 3)
                {
                    cout << "\n\nYou are locked after 3 failed trials" << endl;
                    return false;
                }
            }
            
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;
            
            CurrentUser = clsUser::Find(Username,Password);
            
            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\t\tLogin Screen");
        return _Login();
    }
  
};