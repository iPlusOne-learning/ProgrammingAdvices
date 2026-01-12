#include <iostream>
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsBankClient.h"

using namespace std;

void ReadClientInfo(clsBankClient &Client)
{
    cout << "\nEnter FirstName: ";
    Client.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter LastName: ";
    Client.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter email: ";
    Client.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter phone: ";
    Client.SetPhone(clsInputValidate::ReadString());

    cout << "\nEnter Pincode: ";
    Client.SetPinCode(clsInputValidate::ReadString());

    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());

}
void UpdateClient()
{
    string AccountNumber = "";

    cout << "Please Enter clinet account number: ";
    AccountNumber = clsInputValidate::ReadString();

    while(!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not foud, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info: ";
    cout << "\n_______________________\n";

    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client1.Save();
    switch (SaveResult)
    {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount updated successfully: ";
            Client1.Print();
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account  was not saved because it is emtpy";
            break;
        }
    }

}

int main()
{
    UpdateClient();
    
    return 0;
}