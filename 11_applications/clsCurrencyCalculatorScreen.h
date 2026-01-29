#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindClientScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iostream>
#include <iomanip>

class clsCurrencyCalculatorScreen : clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nConvert From :";
        cout << "\n___________________";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate(1$)  : " << Currency.Rate();
        cout << "\n___________________\n";
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        string CurrencyCode1, CurrencyCode2;
        float Amount;
        char Answer = 'n';

        _DrawScreenHeader("\nCurrency Calculator Screen");
        do
        {
            cout << "\nPlease enter currency1 code: \n";
            CurrencyCode1 = clsInputValidate::ReadString();
            clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode1);
            if (!clsCurrency::IsCurrencyExist(CurrencyCode1))
            {
                cout << "\nCurrent is not found: ";
                Currency1 = clsCurrency::FindByCode(CurrencyCode1);
            }
    
            cout << "\nPlease enter currency2 code: \n";
            CurrencyCode2 = clsInputValidate::ReadString();
            clsCurrency Currency2 = clsCurrency::FindByCode(CurrencyCode2);
            if (!clsCurrency::IsCurrencyExist(CurrencyCode2))
            {
                cout << "\nCurrent is not found: ";
                Currency1 = clsCurrency::FindByCode(CurrencyCode2);
            }
    
            cout << "\nEnter Amount to Exchange: ";
            Amount = clsInputValidate::ReadFloatNumber();
    
            _PrintCurrency(Currency1);
            
            float Result =  Amount / Currency1.Rate();
            cout << "\n" << Amount << " " << clsString::UpperAllString(CurrencyCode1) << " = " << Result << " " << clsString::UpperAllString(CurrencyCode2) << endl;
            cout << "\nDo you want to perform another calculation? y/n: ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
                system("clear");

        } while (Answer != 'n' && Answer != 'N');
    }
};