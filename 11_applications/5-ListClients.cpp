#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsBankClient.h"

using namespace std;

void PrintClientRecordLine(clsBankClient Client)
{
        std::cout << "\n| " << setw(15) << left << Client.GetAccountNumber();
        std::cout << "| " << setw(20) << left << Client.FullName();
        std::cout << "| " << setw(12) << left << Client.GetPhone();
        std::cout << "| " << setw(20) << left << Client.GetEmail();
        std::cout << "| " << setw(10) << left << Client.GetPinCode();
        std::cout << "| " << setw(12) << left << Client.GetAccountBalance();
}

void ShowClientList()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    // system("clear");

    std::cout << "\t\t\t\t Client List (" << vClients.size() << ") Client(s)" << std::endl;
    std::cout << "\n-----------------------------------------------------------------------------------------------------------\n";
    std::cout << "| " << std::setw(15) << std::left << "Account Number";
    std::cout << "| " << std::setw(20) << std::left << "Client Name";
    std::cout << "| " << std::setw(12) << std::left << "Phone Number";
    std::cout << "| " << std::setw(20) << std::left << "Email";
    std::cout << "| " << std::setw(10) << std::left << "Pin Code";
    std::cout << "| " << std::setw(12) << std::left << "Account Balance";
    std::cout << "\n-----------------------------------------------------------------------------------------------------------\n";

    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients available in the system: ";
    }
    else
    {
        for (clsBankClient &Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }
}

int main()
{
    ShowClientList();

    return 0;
}