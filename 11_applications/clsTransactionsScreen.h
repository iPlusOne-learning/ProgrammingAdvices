#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include <iostream>
#include <iomanip>

class clsTransactionsScreen : public clsScreen
{
private:
    enum enTransactionsMenuOptions
    {

        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eShowMainMenu = 4
    };
    static short ReadTransactionsMenuOption()
    {
        cout << setw(20) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4: ");
        return Choice;
    }
    static void _ShowDepositScreen()
    {
        // cout << "\n Depost screen will be here later....\n";
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen()
    {
        // cout << "\n withdaw screen will be here later....\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalancesScreen()
    {
        // cout << "\n total balances screen will be here later....\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _GoBackToTransactionsMenu()
    {
        cout << setw(20) << left << "" << "\n\tPress any key to go back to transactions menu...\n";
        cin.ignore();
        std::cin.get();
        ShowTransactionsMenu();
    }

public:
    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {
        switch (TransactionsMenuOption)
        {
        case enTransactionsMenuOptions::eDeposit:
        {
            system("clear");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eWithdraw:
        {
            system("clear");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eShowTotalBalance:
        {
            system("clear");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eShowMainMenu:
        {
            // do nothing here the main screen will handle it :-) ;
        }
        }
    }
    static void ShowTransactionsMenu()
    {
        system("clear");
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        _DrawScreenHeader("\t\tTransaction Menu Screen");

        cout << setw(20) << left << "" << "===========================================\n";
        cout << setw(20) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(20) << left << "" << "===========================================\n";
        cout << setw(20) << left << "" << "\t[1] Deposit.\n";
        cout << setw(20) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(20) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(20) << left << "" << "\t[4] Main Menu.\n";
        cout << setw(20) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
    };
};