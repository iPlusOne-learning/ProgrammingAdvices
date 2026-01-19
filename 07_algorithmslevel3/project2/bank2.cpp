#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <iostream>

std::string ClientsFileName = "file.txt";


struct sClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string ClientName;
    std::string PhoneNumber;
    double AccountBalance;
    bool MarkedToBeDeleted = false;
};

void TransactionsMenuScreen(std::vector <sClient> &vClients);
bool ShowMainMenu(std::vector<sClient> &vClients);

bool isClientAlreadyExist(std::string AccountNumber, std::vector<sClient> &vClients)
{
    for (sClient &C : vClients)
    {

        if (AccountNumber == C.AccountNumber)
        {
            return true;
        }
    }
    return false;
}

sClient ReadNewClientData(std::vector<sClient> &vClients)
{

    sClient NewClient;

    std::cout << "\nEnter account number: ";
    std::getline(std::cin >> std::ws, NewClient.AccountNumber);
    while (isClientAlreadyExist(NewClient.AccountNumber, vClients) == true)
    {
        std::cout << "Client with [" << NewClient.AccountNumber << "] already exits, Enter another Account Number: ";
        std::getline(std::cin, NewClient.AccountNumber);
    }

    std::cout << "\nEnter pin code: ";
    std::getline(std::cin >> std::ws, NewClient.PinCode);
    std::cout << "\nEnter client name: ";
    std::getline(std::cin, NewClient.ClientName);
    std::cout << "\nEnter phone number ";
    std::getline(std::cin, NewClient.PhoneNumber);
    std::cout << "\nEnter account balance: ";
    std::cin >> NewClient.AccountBalance;

    return NewClient;
}

std::vector<std::string> SplitString(std::string Line, std::string Separator = "#//#")
{
    std::string sWord = "";
    int pos = 0;
    std::vector<std::string> NewWord;

    while ((pos = Line.find(Separator)) != std::string::npos)
    {
        sWord = Line.substr(0, pos);
        if (sWord != "")
        {
            NewWord.push_back(sWord);
        }
        Line.erase(0, pos + Separator.length());
    }
    if (Line != "")
    {
        NewWord.push_back(Line);
    }
    return NewWord;
}

sClient ConvertLineToRecord(std::string Line)
{
    sClient Client;
    std::vector<std::string> ClientLine = SplitString(Line);

    Client.AccountNumber = ClientLine[0];
    Client.PinCode = ClientLine[1];
    Client.ClientName = ClientLine[2];
    Client.PhoneNumber = ClientLine[3];
    Client.AccountBalance = stod(ClientLine[4]);
    return Client;
}
std::string ConvertRecordToLine(sClient Client, std::string Separator = "#//#")
{

    std::string NewLine = "";

    NewLine += Client.AccountNumber + Separator;
    NewLine += Client.PinCode + Separator;
    NewLine += Client.ClientName + Separator;
    NewLine += Client.PhoneNumber + Separator;
    NewLine += std::to_string(Client.AccountBalance);

    return NewLine;
}

void WriteClientsDataToFile(std::vector<sClient> &vClients)
{

    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::out);

    if (MyFile.is_open())
    {
        std::string Line = "";
        for (sClient &C : vClients)
        {
            if (C.MarkedToBeDeleted == false)
            {
                Line = ConvertRecordToLine(C);
                MyFile << Line << std::endl;
            }
        }
        MyFile.close();
    }
}

void LoadClientsDataInVector(std::vector<sClient> &vClients)
{

    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::in);

    if (MyFile.is_open())
    {
        std::string Line = "";
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
    }
}

void PrintClientsCard(std::vector<sClient> vClients)
{
    bool IsAlreadyPrinted = false;

    system("clear");
    if (IsAlreadyPrinted == false)
    {
        std::cout << "\t\t\t\t Client List (" << vClients.size() << ") Client(s)" << std::endl;
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        std::cout << "| " << std::setw(14) << std::left << "Account Number";
        std::cout << "| " << std::setw(14) << std::left << "Pin Code";
        std::cout << "| " << std::setw(20) << std::left << "Client Name";
        std::cout << "| " << std::setw(16) << std::left << "Phone Number";
        std::cout << "| " << std::setw(14) << std::left << "Account Balance";
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        IsAlreadyPrinted = true;
    }

    for (sClient &C : vClients)
    {
        std::cout << "\n| " << std::setw(14) << std::left << C.AccountNumber;
        std::cout << "| " << std::setw(14) << std::left << C.PinCode;
        std::cout << "| " << std::setw(20) << std::left << C.ClientName;
        std::cout << "| " << std::setw(16) << std::left << C.PhoneNumber;
        std::cout << "| " << std::setw(14) << std::left << C.AccountBalance;
    }
    std::cout << "\n";
}

void AddNewClient(std::vector<sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\t\tAdd New Clients Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    char AddMore;
    std::cout << "\n Adding New Clients: ";
    do
    {
        sClient NewClient = ReadNewClientData(vClients);
        vClients.push_back(NewClient);
        std::cout << "\nClient Added successfully, do you want to add more clients? Y/N: ";
        std::cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void PrintOneClientData(std::string AccountNumber, std::vector<sClient> &vClients)
{
    std::cout << "\nThe following are the client details: ";
    std::cout << "\n---------------------------------------------------------------------\n";
    for (sClient &C : vClients)
    {
        if (AccountNumber == C.AccountNumber)
        {
            std::cout << "Account Number: " << C.AccountNumber;
            std::cout << "\nPin Code: " << C.PinCode;
            std::cout << "\nClient Name: " << C.ClientName;
            std::cout << "\nPhone Number: " << C.PhoneNumber;
            std::cout << "\nAccount Balance: " << C.AccountBalance;
        }
    }
    std::cout << "\n---------------------------------------------------------------------\n";
}

void DeleteClientInFile(std::vector<sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\t\tDelete Client Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    std::string AccountNumberToBeDeleted;
    char ToBeDeleted;
    std::cout << "Please enter account number: ";
    std::getline(std::cin >> std::ws, AccountNumberToBeDeleted);
    if (isClientAlreadyExist(AccountNumberToBeDeleted, vClients) == false)
    {
        std::cout << "Client with account number (" << AccountNumberToBeDeleted << ") is NOT FOUND!\n";
    }
    else
    {
        PrintOneClientData(AccountNumberToBeDeleted, vClients);
        std::cout << "Are you sure you want to delete this client? y/n: ";
        std::cin >> ToBeDeleted;
        if (toupper(ToBeDeleted) == 'Y')
        {
            for (sClient &C : vClients)
            {
                if (AccountNumberToBeDeleted == C.AccountNumber)
                {
                    C.MarkedToBeDeleted = true;
                }
            }
            WriteClientsDataToFile(vClients);
            std::cout << "/Client deleted successfully.\n";
        }
    }
}

void UpdateClientInfo(std::vector<sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\tUpdate Client Info Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    std::string AccountNumberToBeUpdated;
    char ToBeUpdated;
    std::cout << "Please enter account number: ";
    std::getline(std::cin >> std::ws, AccountNumberToBeUpdated);
    if (isClientAlreadyExist(AccountNumberToBeUpdated, vClients) == false)
    {
        std::cout << "Client with account number (" << AccountNumberToBeUpdated << ") is NOT FOUND!\n";
    }
    else
    {
        PrintOneClientData(AccountNumberToBeUpdated, vClients);
        std::cout << "Are you sure you want to update this client? y/n: ";
        std::cin >> ToBeUpdated;
        if (toupper(ToBeUpdated) == 'Y')
        {
            sClient AddNewClient;
            for (sClient &C : vClients)
            {
                if (AccountNumberToBeUpdated == C.AccountNumber)
                {
                    std::cout << "\nEnter pin code: ";
                    std::getline(std::cin >> std::ws, AddNewClient.PinCode);
                    C.PinCode = AddNewClient.PinCode;

                    std::cout << "\nEnter client name: ";
                    std::getline(std::cin, AddNewClient.ClientName);
                    C.ClientName = AddNewClient.ClientName;

                    std::cout << "\nEnter phone number ";
                    std::getline(std::cin, AddNewClient.PhoneNumber);
                    C.PhoneNumber = AddNewClient.PhoneNumber;

                    std::cout << "\nEnter account balance: ";
                    std::cin >> AddNewClient.AccountBalance;
                    C.AccountBalance = AddNewClient.AccountBalance;
                }
            }
            WriteClientsDataToFile(vClients);
            std::cout << "\nClient Updated successfully.\n";
        }
    }
}

void    FindClientInFile(std::vector <sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\tFind Client Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    std::string AccountNumberToSearch;
    char ToBeUpdated;
    std::cout << "Please enter account number: ";
    std::cin >> AccountNumberToSearch;
    if (isClientAlreadyExist(AccountNumberToSearch, vClients) == false)
    {
        std::cout << "Client with account number (" << AccountNumberToSearch << ") is NOT FOUND!\n";
    }
    else
    {
        PrintOneClientData(AccountNumberToSearch,vClients);
    }
}

void EndProgram()
{
    std::cout << "\n========================================================================\n";
    std::cout << "\n\t\t\t Program Ends :-) \n";
    std::cout << "\n========================================================================\n";
}

enum enTransactions{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eMainMenu = 4
};

double SumTotalBalances(std::vector <sClient> &vClients)
{
    double TotalBalances = 0;
    for (sClient &C : vClients)
    {
        TotalBalances+= C.AccountBalance;
    }
    return TotalBalances;
}

void BalancesList(std::vector <sClient> &vClients)
{
        bool IsAlreadyPrinted = false;

    system("clear");
    if (IsAlreadyPrinted == false)
    {
        std::cout << "\t\t\t Balances List (" << vClients.size() << ") Client(s)" << std::endl;
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        std::cout << "| " << std::setw(20) << std::left << "Account Number";
        std::cout << "| " << std::setw(30) << std::left << "Client Name";
        std::cout << "| " << std::setw(14) << std::left << "Account Balance";
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        IsAlreadyPrinted = true;
    }

    for (sClient &C : vClients)
    {
        std::cout << "\n| " << std::setw(20) << std::left << C.AccountNumber;
        std::cout << "| " << std::setw(30) << std::left << C.ClientName;
        std::cout << "| " << std::setw(14) << std::left << C.AccountBalance;
    }
    std::cout << "\n----------------------------------------------------------------------------------------\n";
    std::cout << "\t\t\t\t\tTotal Balances = " << SumTotalBalances(vClients) << std::endl;

}

void WithdrawMoney(std::string AccountNumber, std::vector <sClient> &vClients)
{
    double AmountToWithdraw;
    char Answer;

    std::cout << "Please enter amount to withdraw: ";
    std::cin >> AmountToWithdraw;
    std::cout << "\n Are you sure you want to perform this transaction? Y/N: ";
    std::cin >> Answer;
    if (toupper(Answer) == 'Y')
    {
        for (sClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                if (C.AccountBalance < AmountToWithdraw)
                {
                    std::cout << "\nAmount exceeds the balance. you can withdraw up to: " << C.AccountBalance << std::endl;
                    do {
                        std::cout << "\nPlease enter another amount: ";
                        std::cin >> AmountToWithdraw;
                        
                    } while (C.AccountBalance < AmountToWithdraw);
                
                    C.AccountBalance -= AmountToWithdraw;
                    std::cout << "\nThe amount of [" << AmountToWithdraw << "] has been withdrawn successfully.\n";
                    WriteClientsDataToFile(vClients);
                    return ;
                }
                else
                {
                    C.AccountBalance -= AmountToWithdraw;
                    std::cout << "\nThe amount of [" << AmountToWithdraw << "] has been withdrawn successfully.\n";
                    WriteClientsDataToFile(vClients);
                    return ;

                }
            }
        }
    }
    else
    {
        return ;
    }
}

void WithdrawOnClientAccountNumber(std::vector <sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\tWithdraw Screen";
    std::cout << "\n---------------------------------------------------------------------\n";
    
    std::string AccountNumber;
    bool DoesExist = true;
    do
    {
        std::cout << "Pleaser enter your account number: ";
        std::cin >> AccountNumber;
        if (isClientAlreadyExist(AccountNumber, vClients) == false)
        {
            std::cout << "Client with account number [" << AccountNumber << "] does NOT EXIST!\n";
            DoesExist = false;
            continue;
        }
    } while (DoesExist == false);

    PrintOneClientData(AccountNumber, vClients);
    WithdrawMoney(AccountNumber, vClients);
}

void DepositMoney(std::string AccountNumber, std::vector <sClient> &vClients)
{
    double AmountToDeposit;
    char Answer;

    std::cout << "Please enter the deposit amount: ";
    std::cin >> AmountToDeposit;
    std::cout << "\n Are you sure you want to perform this transaction? Y/N: ";
    std::cin >> Answer;
    if (toupper(Answer) == 'Y')
    {
        for (sClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += AmountToDeposit;
                std::cout << "\nThe amount of [" << AmountToDeposit << "] has been added successfully.\n";
                WriteClientsDataToFile(vClients);
                return ;
            }
        }
    }
    else
    {
        return ;
    }
}

void DepositOnClientAccountNumber(std::vector <sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\tDeposit Screen";
    std::cout << "\n---------------------------------------------------------------------\n";
    
    std::string AccountNumber;
    bool DoesExist = true;
    do
    {
        std::cout << "Pleaser enter your account number: ";
        std::cin >> AccountNumber;
        if (isClientAlreadyExist(AccountNumber, vClients) == false)
        {
            std::cout << "Client with account number [" << AccountNumber << "] does NOT EXIST!\n";
            DoesExist = false;
            continue;
        }
    } while (DoesExist == false);

    PrintOneClientData(AccountNumber, vClients);
    DepositMoney(AccountNumber, vClients);
}

void PerformTransactionMenuOperations(std::vector <sClient> &vClients)
{
    short Choice;
    std::cin >> Choice;

    switch (Choice)
    {
        case enTransactions::eDeposit:
        {
            system("clear");
            DepositOnClientAccountNumber(vClients);
            TransactionsMenuScreen(vClients);
            break;
        }
        case enTransactions::eWithdraw:
        {
            system("clear");
            WithdrawOnClientAccountNumber(vClients);
            TransactionsMenuScreen(vClients);
            break;
        }
        case enTransactions::eTotalBalance:
        {
            system("clear");
            BalancesList(vClients);
            break;
        }
        case enTransactions::eMainMenu:
        {
            system("clear");
            ShowMainMenu(vClients);
            break;
        }
    }

}

void TransactionsMenuScreen(std::vector <sClient> &vClients)
{
    std::cout << "\n========================================================================\n";
    std::cout << "\n\t\t\t Transactions Menu Screen\n";
    std::cout << "\n========================================================================\n";

    std::cout << "\t[1] Deposit." << std::endl;
    std::cout << "\t[2] Withdraw." << std::endl;
    std::cout << "\t[3] Total Balances." << std::endl;
    std::cout << "\t[4] Main Menu." << std::endl;

    std::cout << "========================================================================\n";

    std::cout << "Choose what you want to do from [1 to 4]: \n";

    PerformTransactionMenuOperations(vClients);
    
}


bool ShowMainMenu(std::vector<sClient> &vClients)
{
    std::cout << "\n========================================================================\n";
    std::cout << "\n\t\t\t Main Menu Screen\n";
    std::cout << "\n========================================================================\n";

    std::cout << "\t[1] Show Client List." << std::endl;
    std::cout << "\t[2] Add New Client." << std::endl;
    std::cout << "\t[3] Delete Client." << std::endl;
    std::cout << "\t[4] Update Client Info." << std::endl;
    std::cout << "\t[5] Find Client." << std::endl;
    std::cout << "\t[6] Transactions." << std::endl;
    std::cout << "\t[7] Exit." << std::endl;

    std::cout << "========================================================================\n";

    short Choice;
    std::cout << "Choose what you want to do from [1 to 7]: \n";
    std::cin >> Choice;
    if (Choice == 1)
    {
        system("clear");
        PrintClientsCard(vClients);
    }
    else if (Choice == 2)
    {
        system("clear");
        AddNewClient(vClients);
        WriteClientsDataToFile(vClients);
    }
    else if (Choice == 3)
    {
        system("clear");
        DeleteClientInFile(vClients);
    }
    else if (Choice == 4)
    {
        system("clear");
        UpdateClientInfo(vClients);
    }
    else if (Choice == 5)
    {
        system("clear");
        FindClientInFile(vClients);
    }
    else if (Choice == 6)
    {
        system("clear");
        TransactionsMenuScreen(vClients);
    }
    else if (Choice == 7)
    {
        system("clear");
        EndProgram();
        return false;
    }
    return true;
}

int main()
{
    std::vector<sClient> vClients;

    LoadClientsDataInVector(vClients);
    char BackToMainMenu;

    bool KeepRunning = true;
    while (KeepRunning)
    {
       KeepRunning = ShowMainMenu(vClients);
       if (KeepRunning)
       {
           std::cout << "\nPress any key to return to main men....";
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           std::cin.get();
       }
    }

    return 0;
}