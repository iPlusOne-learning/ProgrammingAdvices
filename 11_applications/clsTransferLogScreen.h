#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <iostream>

class clsTransferLogScreen : clsScreen
{

private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.TransferAmount;
        cout << "| " << setw(10) << left << TransferLogRecord.strBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.UserName;
    }

public:
    static void ShowTransferLogScreen()
    {

        vector<clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\n\t\t\t\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acct";
        cout << "| " << left << setw(10) << "D.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Logs Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};