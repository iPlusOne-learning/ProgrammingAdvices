
#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsCurrency.h"
#include <iomanip>
#include <iostream>

class clsListCurrenciesScreen : clsScreen
{

private:
    static void PrintListCurrenciesRecordLine(clsCurrency ListCurrenciesRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << ListCurrenciesRecord.Country();
        cout << "| " << setw(10) << left << ListCurrenciesRecord.CurrencyCode();
        cout << "| " << setw(30) << left << ListCurrenciesRecord.CurrencyName();
        cout << "| " << setw(10) << left << ListCurrenciesRecord.Rate();
    }

public:
    static void ShowListCurrencies()
    {

        vector<clsCurrency> vListCurrenciesRecord = clsCurrency::GetCurrenciesList();

        string Title = "\n\t\t\t\tCurrencies List Screen";
        string SubTitle = "\t\t(" + to_string(vListCurrenciesRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(18) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vListCurrenciesRecord.size() == 0)
            cout << "\t\t\t\tNo Curencies Available In the System!";
        else

            for (clsCurrency &Record : vListCurrenciesRecord)
            {

                PrintListCurrenciesRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};