#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
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
        eTransfer = 4,
        eTransferLog = 5,
        eShowMainMenu = 6
    };
    static short ReadTransactionsMenuOption()
    {
        cout << setw(20) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6: ");
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
    static void _ShowTransferScreen()
    {
        // cout << "\n total balances screen will be here later....\n";
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen()
    {
        // cout << "\n total balances screen will be here later....\n";
        clsTransferLogScreen::ShowTransferLogScreen();
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
        case enTransactionsMenuOptions::eTransfer:
        {
            system("clear");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
        }
        case enTransactionsMenuOptions::eTransferLog:
        {
            system("clear");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
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
        cout << setw(20) << left << "" << "\t[4] Transfer.\n";
        cout << setw(20) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(20) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(20) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
    };
};