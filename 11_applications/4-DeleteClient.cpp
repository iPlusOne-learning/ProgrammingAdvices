#include <iostream>
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsBankClient.h"

using namespace std;


void DeleteClient()
{
    string AccountNumber = "";

    cout << "Please Enter clinet account number: ";
    AccountNumber = clsInputValidate::ReadString();

    while(!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    char Answer = 'n';
    cout << "\nAre you sure you want to delete this client? y/n: ";
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y')
    {
        if (Client1.Delete())
        {
            cout << "\nClient Deleted successfully: \n";
            Client1.Print();
        }
    }
    else
    {
        cout << "\nError Client was not deleted\n";
    }

}

int main()
{
    DeleteClient();

    return 0;
}