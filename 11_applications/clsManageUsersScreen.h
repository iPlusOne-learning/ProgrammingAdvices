#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include <iomanip>

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:
    enum enManageUsersMenuOptions
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6
    };

    static short _ReadManageUsersMenuOption()
    {
        cout << setw(20) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Manage Users Menu...";
        cin.ignore();
        cin.get();
        ShowManageUsersMenu();
    }

    static void _ShowListUsersScreen()
    {
        // cout << "\nList Users Screen Will Be Here.\n";
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        cout << "\nAdd New User Screen Will Be Here.\n";
    }

    static void _ShowDeleteUserScreen()
    {
        cout << "\nDelete User Screen Will Be Here.\n";
    }

    static void _ShowUpdateUserScreen()
    {
        cout << "\nUpdate User Screen Will Be Here.\n";
    }

    static void _ShowFindUserScreen()
    {
        cout << "\nFind User Screen Will Be Here.\n";
    }

    static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOption)
    {

        switch (ManageUsersMenuOption)
        {
        case enManageUsersMenuOptions::eListUsers:
        {
            system("clear");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eAddNewUser:
        {
            system("clear");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eDeleteUser:
        {
            system("clear");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eUpdateUser:
        {
            system("clear");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eFindUser:
        {
            system("clear");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eMainMenu:
        {
            // do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:
    static void ShowManageUsersMenu()
    {

        system("clear");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(20) << left << "" << "===========================================\n";
        cout << setw(20) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(20) << left << "" << "===========================================\n";
        cout << setw(20) << left << "" << "\t[1] List Users.\n";
        cout << setw(20) << left << "" << "\t[2] Add New User.\n";
        cout << setw(20) << left << "" << "\t[3] Delete User.\n";
        cout << setw(20) << left << "" << "\t[4] Update User.\n";
        cout << setw(20) << left << "" << "\t[5] Find User.\n";
        cout << setw(20) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(20) << left << "" << "===========================================\n";

        _PerformManageUsersMenuOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
    }
};