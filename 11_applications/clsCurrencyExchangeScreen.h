#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindClientScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iostream>
#include <iomanip>

class clsCurrencyExchangeScreen : clsScreen
{

private:
    enum enCurrencyExchangeMenuOptions
    {

        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateRate = 3,
        eCurrencyCalculator = 4,
        eShowMainMenu = 5
    };

    static short ReadTransactionsMenuOption()
    {
        cout << setw(20) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 5: ");
        return Choice;
    }
    static void _ShowListCurrenciesScreen()
    {
        clsListCurrenciesScreen::ShowListCurrencies();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowCurrencyCalculatorScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRate();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << setw(20) << left << "" << "\n\tPress any key to go back to transactions menu...\n";
        cin.ignore();
        std::cin.get();
        ShowCurrencyExchangeMenu();
    }

public:
    static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOption)
    {
        switch (CurrencyExchangeMenuOption)
        {
        case enCurrencyExchangeMenuOptions::eListCurrencies:
        {
            system("clear");
            _ShowListCurrenciesScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enCurrencyExchangeMenuOptions::eFindCurrency:
        {
            system("clear");
            _ShowFindCurrencyScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enCurrencyExchangeMenuOptions::eUpdateRate:
        {
            system("clear");
            _ShowUpdateRateScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enCurrencyExchangeMenuOptions::eCurrencyCalculator:
        {
            system("clear");
            _ShowCurrencyCalculatorScreen();
            _GoBackToTransactionsMenu();
        }
        case enCurrencyExchangeMenuOptions::eShowMainMenu:
        {
        }
        }
    }

    static void ShowCurrencyExchangeMenu()
    {
        system("clear");
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        _DrawScreenHeader("\t\tCurrency Exchange Menu Screen");

        cout << setw(20) << left << "" << "===========================================\n";
        cout << setw(20) << left << "" << "\t\t  Currency Exchange Menu\n";
        cout << setw(20) << left << "" << "===========================================\n";
        cout << setw(20) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(20) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(20) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(20) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(20) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(20) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenuOption((enCurrencyExchangeMenuOptions)ReadTransactionsMenuOption());
    }
};