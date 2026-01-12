#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsUtil.h"

using namespace std;

void PrintClientRecordBalanceLine(clsBankClient Client)
{
        std::cout << "\n| " << setw(15) << left << Client.GetAccountNumber();
        std::cout << "| " << setw(40) << left << Client.FullName();
        std::cout << "| " << setw(12) << left << Client.GetAccountBalance();
}

void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    // system("clear");

    std::cout << "\t\t\t\t Balances List (" << vClients.size() << ") Client(s)" << std::endl;
    std::cout << "\n---------------------------------------------------------------------------------\n";
    std::cout << "| " << std::setw(15) << std::left << "Account Number";
    std::cout << "| " << std::setw(40) << std::left << "Client Name";
    std::cout << "| " << std::setw(12) << std::left << "Account Balance";
    std::cout << "\n---------------------------------------------------------------------------------\n";

    double TotalBalances = clsBankClient::GetTotalBalances();
    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients available in the system: ";
    }
    else
    {
        for (clsBankClient &Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
        }
            
    }
    std::cout << "\n---------------------------------------------------------------------------------\n";

    cout << "\n\t\t\t\t\t    Total Balances = " << TotalBalances << endl;
    cout << "\n\t\t\t ( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;

}

int main()
{
    ShowTotalBalances();

    return 0;
}