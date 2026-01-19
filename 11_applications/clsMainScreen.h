#pragma once

#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include <thread>
#include <chrono>

class clsMainScreen : protected clsScreen
{
    private:
    
    enum enMainMenuOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
            eManageUsers = 7, eExit = 8
    };
    static short _ReadMainMenuOption()
    {
        cout << setw(20) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1,8);
        return Choice;
    }
    static void _GoBackToMainMenu()
    {
        cout << setw(20) << left << "" << "\n\tPress any key to go back to main menu...\n";
        cin.ignore(); // clear buffer, this is shorter one rather than one below
        //  cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cin.get();
        ShowMainMenu();
    }
    static void _ShowAllClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }
    static void _ShowUpdateClientScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }
    static void _ShowDeleteClientScreen()
    {
        // cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }
    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }
    static void _ShowTransactionsMenu()
    {
        cout << "\nTransactions Menu Will be here...\n";
    }
    static void _ShowManageUsersMenu()
    {
        cout << "\nUsers Menu Will be here...\n";
    }
    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";
    }
    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClients:
        {
            system("clear");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
            system("clear");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            system("clear");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eUpdateClient:
            system("clear");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eFindClient:
            system("clear");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eShowTransactionsMenu:
            system("clear");
            _ShowTransactionsMenu();
            break;

        case enMainMenuOptions::eManageUsers:
            system("clear");
            _ShowManageUsersMenu();
            break;

        case enMainMenuOptions::eExit:
            system("clear");
            _ShowEndScreen();
            //Login();

            break;
        }
    }

    public:
    
    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(20) << left <<""<< "===========================================\n";
        cout << setw(20) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(20) << left << "" << "===========================================\n";
        cout << setw(20) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(20) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(20) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(20) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(20) << left << "" << "\t[5] Find Client.\n";
        cout << setw(20) << left << "" << "\t[6] Transactions.\n";
        cout << setw(20) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(20) << left << "" << "\t[8] Logout.\n";
        cout << setw(20) << left << "" << "===========================================\n";
        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }

};