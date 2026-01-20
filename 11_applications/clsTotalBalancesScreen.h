#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(20) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(30) << left << Client.FullName();
        cout << "| " << setw(14) << left << Client.GetAccountBalance();
    }

public:

    static void ShowTotalBalances()
    {

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t\t  Balances List Screen";
        string SubTitle = "\t\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        std::cout << "\n----------------------------------------------------------------------------------------\n";     

        cout << setw(20) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(14) << "Balance";
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        cout << left << "" << "\t\t\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
        cout << left << "" << "\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }
};