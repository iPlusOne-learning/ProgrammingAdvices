#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <limits>

std::string ClientsFileName = "file.txt";
std::string UsersFileName = "users.txt";
struct stClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string ClientName;
    std::string PhoneNumber;
    double AccountBalance;
    bool MarkedToBeDeleted = false;
};
struct stUser
{
    std::string Username;
    std::string Password;
    int Permissions;
    bool MarkedToBeDeleted = false;
};

void TransactionsMenuScreen(std::vector <stClient> &vClients);
bool ShowMainMenu(std::vector<stClient> &vClients);
void Login(std::vector<stClient> &vClients);
void ManageUsersMenuScreen(std::vector<stClient> &vClients);


stUser ReadUserInfo()
{
    stUser User;
    std::cout << "Enter Username: ";
    std::getline(std::cin, User.Username);
    std::cout << "Enter password: ";
    std::getline(std::cin, User.Password);
    return User;
}

bool isClientAlreadyExist(std::string AccountNumber, std::vector<stClient> &vClients)
{
    for (stClient &C : vClients)
    {

        if (AccountNumber == C.AccountNumber)
        {
            return true;
        }
    }
    return false;
}

stClient ReadNewClientData(std::vector<stClient> &vClients)
{

    stClient NewClient;

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

stClient ConvertLineToRecord(std::string Line)
{
    stClient Client;
    std::vector<std::string> ClientLine = SplitString(Line);

    Client.AccountNumber = ClientLine[0];
    Client.PinCode = ClientLine[1];
    Client.ClientName = ClientLine[2];
    Client.PhoneNumber = ClientLine[3];
    Client.AccountBalance = stod(ClientLine[4]);
    return Client;
}
std::string ConvertRecordToLine(stClient Client, std::string Separator = "#//#")
{

    std::string NewLine = "";

    NewLine += Client.AccountNumber + Separator;
    NewLine += Client.PinCode + Separator;
    NewLine += Client.ClientName + Separator;
    NewLine += Client.PhoneNumber + Separator;
    NewLine += std::to_string(Client.AccountBalance);

    return NewLine;
}

void WriteClientsDataToFile(std::vector<stClient> &vClients)
{

    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::out);

    if (MyFile.is_open())
    {
        std::string Line = "";
        for (stClient &C : vClients)
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

void LoadClientsDataInVector(std::vector<stClient> &vClients)
{

    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::in);

    if (MyFile.is_open())
    {
        std::string Line = "";
        stClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
    }
}

void PrintClientsCard(std::vector<stClient> vClients)
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

    for (stClient &C : vClients)
    {
        std::cout << "\n| " << std::setw(14) << std::left << C.AccountNumber;
        std::cout << "| " << std::setw(14) << std::left << C.PinCode;
        std::cout << "| " << std::setw(20) << std::left << C.ClientName;
        std::cout << "| " << std::setw(16) << std::left << C.PhoneNumber;
        std::cout << "| " << std::setw(14) << std::left << C.AccountBalance;
    }
    std::cout << "\n";
}

void AddNewClient(std::vector<stClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\t\tAdd New Clients Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    char AddMore;
    std::cout << "\n Adding New Clients: ";
    do
    {
        stClient NewClient = ReadNewClientData(vClients);
        vClients.push_back(NewClient);
        std::cout << "\nClient Added successfully, do you want to add more clients? Y/N: ";
        std::cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void PrintOneClientData(std::string AccountNumber, std::vector<stClient> &vClients)
{
    std::cout << "\nThe following are the client details: ";
    std::cout << "\n---------------------------------------------------------------------\n";
    for (stClient &C : vClients)
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

void DeleteClientInFile(std::vector<stClient> &vClients)
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
            for (stClient &C : vClients)
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

void UpdateClientInfo(std::vector<stClient> &vClients)
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
            stClient AddNewClient;
            for (stClient &C : vClients)
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

void    FindClientInFile(std::vector <stClient> &vClients)
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

double SumTotalBalances(std::vector <stClient> &vClients)
{
    double TotalBalances = 0;
    for (stClient &C : vClients)
    {
        TotalBalances+= C.AccountBalance;
    }
    return TotalBalances;
}

void BalancesList(std::vector <stClient> &vClients)
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

    for (stClient &C : vClients)
    {
        std::cout << "\n| " << std::setw(20) << std::left << C.AccountNumber;
        std::cout << "| " << std::setw(30) << std::left << C.ClientName;
        std::cout << "| " << std::setw(14) << std::left << C.AccountBalance;
    }
    std::cout << "\n----------------------------------------------------------------------------------------\n";
    std::cout << "\t\t\t\t\tTotal Balances = " << SumTotalBalances(vClients) << std::endl;

}

void WithdrawMoney(std::string AccountNumber, std::vector <stClient> &vClients)
{
    double AmountToWithdraw;
    char Answer;

    std::cout << "Please enter amount to withdraw: ";
    std::cin >> AmountToWithdraw;
    std::cout << "\nAre you sure you want to perform this transaction? Y/N: ";
    std::cin >> Answer;
    if (toupper(Answer) == 'Y')
    {
        for (stClient &C : vClients)
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

void WithdrawOnClientAccountNumber(std::vector <stClient> &vClients)
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

void DepositMoney(std::string AccountNumber, std::vector <stClient> &vClients)
{
    double AmountToDeposit;
    char Answer;

    std::cout << "Please enter the deposit amount: ";
    std::cin >> AmountToDeposit;
    std::cout << "\n Are you sure you want to perform this transaction? Y/N: ";
    std::cin >> Answer;
    if (toupper(Answer) == 'Y')
    {
        for (stClient &C : vClients)
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

void DepositOnClientAccountNumber(std::vector <stClient> &vClients)
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

void PerformTransactionMenuOperations(std::vector <stClient> &vClients)
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

void TransactionsMenuScreen(std::vector <stClient> &vClients)
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

void ShowUsersList(std::vector <stUser> &vUsers)
{

    std::cout << "\t\t\t Users List (" << vUsers.size() << ") User(s)" << std::endl;
    std::cout << "\n----------------------------------------------------------------------------------------\n";
    std::cout << "| " << std::setw(20) << std::left << "User Name";
    std::cout << "| " << std::setw(30) << std::left << "Password";
    std::cout << "| " << std::setw(14) << std::left << "Permissions";
    std::cout << "\n----------------------------------------------------------------------------------------\n";

 
    for (stUser &U : vUsers)
    {
        std::cout << "\n| " << std::setw(20) << std::left << U.Username;
        std::cout << "| " << std::setw(30) << std::left << U.Password;
        std::cout << "| " << std::setw(14) << std::left << U.Permissions;
    }

    std::cout << "\n---------------------------------------------------------------------\n";
}

enum enManageUsers
{
    ListUsers = 1,
    AddNewUser = 2,
    DeleteUser = 3,
    UpdateUser = 4,
    FindUser = 5,
    MainMenu = 6
};

std::string ConvertUserRecordToLine(stUser User, std::string Separator = "#//#")
{
    std::string NewLine = "";
    
    NewLine += User.Username + Separator;
    NewLine += User.Password + Separator;
    NewLine += std::to_string(User.Permissions);
    return NewLine;
}

void WriteUsersDataToFile(stUser User)
{
    std::fstream MyFile;
    MyFile.open(UsersFileName, std::ios::app);

    if (MyFile.is_open())
    {
        std::string Line = "";
        Line = ConvertUserRecordToLine(User);
        MyFile << Line << std::endl;
    }
    MyFile.close();
}

bool IsUserExist(std::string Username, std::vector <stUser> &vUsers)
{
    for (stUser &U : vUsers)
    {
        if (Username == U.Username)
        {
            return true;
        }
    }
    return false;
}

enum enUserPermissions
{
    ClientList = 1 << 0,
    AddNewClient2 = 1 << 1,
    DeleteClient = 1 << 2,
    UpdateClient = 1 << 3,
    FindClient = 1 << 4,
    Transactions = 1 << 5,
    ManageUsers = 1 << 6
};

void SpecificUserPermissions(stUser &AddNewUser)
{
    char Permission;
    int TotalPermission = 0;
    std::cout << "\nDo you want to give access to: " << std::endl;
    
    std::cout << "\nShow Client List: y/n? ";
    std::cin >> Permission;
    if (toupper(Permission) == 'Y')
    {
        TotalPermission |= enUserPermissions::ClientList;
    }

    std::cout << "\nAdd New Client: y/n? ";
    std::cin >> Permission;
    if (toupper(Permission) == 'Y')
    {
       TotalPermission|= enUserPermissions::AddNewClient2;
    }

    std::cout << "\nDelete client: y/n? ";
    std::cin >> Permission;
    if (toupper(Permission) == 'Y')
    {
        TotalPermission |= enUserPermissions::DeleteClient;
    }

    std::cout << "\nUpdate client: y/n? ";
    std::cin >> Permission;
    if (toupper(Permission) == 'Y')
    {
        TotalPermission |= enUserPermissions::UpdateClient;
    }

    std::cout << "\nFind Client: y/n? ";
    std::cin >> Permission;
    if (toupper(Permission) == 'Y')
    {
        TotalPermission |= enUserPermissions::FindClient;
    }

    std::cout << "\nTransactions: y/n? ";
    std::cin >> Permission;
    if (toupper(Permission) == 'Y')
    {
        TotalPermission |= enUserPermissions::Transactions;
    }

    std::cout << "\nManager Users: y/n? ";
    std::cin >> Permission;
    if (toupper(Permission) == 'Y')
    {
        TotalPermission |= enUserPermissions::ManageUsers;
    }
    AddNewUser.Permissions = TotalPermission;
    std::cout << "Total permission: " << TotalPermission << std::endl;
}

void AddNewUserToRecord(std::vector<stUser> &vUsers)
{
    char AddMore;
    char GiveFullAccess;
    stUser AddNewUser;
    
    std::cout << "\nEnter username: ";
    std::getline(std::cin >> std::ws, AddNewUser.Username);
    if (IsUserExist(AddNewUser.Username, vUsers))
    {
        while (true) 
        {
            std::cout << "\nUser with [" << AddNewUser.Username << "] already exists, Enter another Username? ";
            std::getline(std::cin >> std::ws, AddNewUser.Username);
            if (!IsUserExist(AddNewUser.Username, vUsers))
            {
                break;
            }
        };
    }
    
    std::cout << "Enter password: ";
    std::getline(std::cin >> std::ws, AddNewUser.Password);
    std::cout << "\nDo you want to give full access? y/n? ";
    std::cin >> GiveFullAccess;
    if (toupper(GiveFullAccess) == 'Y')
    {
        AddNewUser.Permissions = -1;
        WriteUsersDataToFile(AddNewUser);
    }
    else
    {
        SpecificUserPermissions(AddNewUser);
        WriteUsersDataToFile(AddNewUser);
    }
}
void PrintUserInfo(std::string Username, std::vector<stUser> &vUsers)
{
    std::cout << "\nThe following are the user details: " << std::endl;
    std::cout << "\n---------------------------------------------------------------------\n";

    for (stUser &U : vUsers)
    {
        if (Username == U.Username)
        {
            std::cout << "Username" << std::setw(14) << ": " << U.Username << std::endl;
            std::cout << "Password" << std::setw(14) << ": " << U.Password << std::endl;
            std::cout << "Permission" << std::setw(14) << ": " << U.Permissions << std::endl;
        }
    }
}

bool IsUserExistByOnlyUsername(std::string Username, std::vector<stUser> &vUsers)
{
    for (stUser &U : vUsers)
    {
        if (Username == U.Username)
        {
            return true;
        }
    }
    return false;
}

void ConfirmDeleteUserFromRecord(std::string Username, std::vector<stUser> &vUsers)
{
    std::vector <stUser> vUsers2;

    for (stUser &U : vUsers)
    {
        if (Username == U.Username)
        {
            U.MarkedToBeDeleted = true;
        }
    }

    for (stUser &U : vUsers)
    {
        vUsers2.push_back(U);
    }
    std::fstream MyFile;
    MyFile.open(UsersFileName, std::ios::out);

    if (MyFile.is_open())
    {
        std::string Line = "";
        for (stUser &U2 : vUsers2)
        {
            if (U2.MarkedToBeDeleted == false)
            {
                Line = ConvertUserRecordToLine(U2);
                MyFile << Line << std::endl;
            }
        }
    }
    MyFile.close();
 
}

void DeleteUserFromRecord(std::vector<stUser> &vUsers)
{
    std::string UserNameToDelete = "";
    char Choice;

    PrintUserInfo(UserNameToDelete, vUsers);

    std::cout << "\nAre you sure you want to dele this user? y/n";
    std::cin >> Choice;
    if (toupper(Choice) == 'Y')
    {
        ConfirmDeleteUserFromRecord(UserNameToDelete, vUsers);
    }
}

void DeleteUserScreen(std::vector<stUser> &vUsers, std::vector <stClient> &vClients)
{
    bool IsItAlreadyDisplayed = false;
    if (IsItAlreadyDisplayed == false)
    {
        std::cout << "\n---------------------------------------------------------------------\n";
        std::cout << "\t\t\tDelete User Screen";
        std::cout << "\n---------------------------------------------------------------------\n";
        IsItAlreadyDisplayed = true;
    }
    std::string UserNameToDelete = "";
    std::cout << "\nPlease enter username: : ";
    std::getline(std::cin >> std::ws, UserNameToDelete);
    char Choice;
    if (!IsUserExistByOnlyUsername(UserNameToDelete, vUsers))
    {
        std::cout << "\nUser with Username (" << UserNameToDelete << ") is NOT FOUND!" << std::endl;
        return ;
    }
    char AddMore;
    do
    {
        DeleteUserFromRecord(vUsers);
        std::cout << "\nUser deleted successfully, do you want to delete more users? y/n? ";
        std::cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

    ManageUsersMenuScreen(vClients);
}

void AddNewUserScreen(std::vector<stUser> &vUsers, std::vector <stClient> &vClients )
{
    bool IsItAlreadyDisplayed = false;
    if (IsItAlreadyDisplayed == false)
    {
        std::cout << "\n---------------------------------------------------------------------\n";
        std::cout << "\t\t\tAdd New User Screen";
        std::cout << "\n---------------------------------------------------------------------\n";
        IsItAlreadyDisplayed = true;
    }
    char AddMore;
    do
    {
        std::cout << "\nAdding New User: " << std::endl;
        AddNewUserToRecord(vUsers);
        std::cout << "\nUser added successfully, do you want to add more users? y/n? ";
        std::cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

    ManageUsersMenuScreen(vClients);
}

void  PerformManageUsersMenuOperations(std::vector <stUser> &vUsers, std::vector<stClient> &vClients)
{
    short Choice;
    std::cin >> Choice;

    switch (Choice)
    {
        case enManageUsers::ListUsers:
        {
            system("clear");
            ShowUsersList(vUsers);
            ManageUsersMenuScreen(vClients);
            break;
        }
        case enManageUsers::AddNewUser:
        {
            system("clear");
            AddNewUserScreen(vUsers, vClients);
            break;
        }
        case enManageUsers::DeleteUser:
        {
            system("clear");
            DeleteUserScreen(vUsers, vClients);
             ManageUsersMenuScreen(vClients);

            break;
        }
        case enManageUsers::UpdateUser:
        {
            system("clear");
            break;
        }
        case enManageUsers::FindUser:
        {
            system("clear");
            break;
        }
        case enManageUsers::MainMenu:
        {
            system("clear");
            ShowMainMenu(vClients);
            break;
        }
    }
}

stUser ConvertUserLineToRecord(std::string UserLine)
{
    stUser User;
    std::vector<std::string> vUser = SplitString(UserLine);
    User.Username = vUser[0];
    User.Password = vUser[1];
    User.Permissions = std::stoi(vUser[2]);

    return User;
}

std::vector <stUser> LoadUsersDateInVector()
{
    std::fstream File;
    File.open(UsersFileName, std::ios::in);
    std::vector <stUser> vUsers;
    if (File.is_open())
    {
        std::string UserLine = "";
        stUser User;
        while (std::getline(File, UserLine))
        {
            User = ConvertUserLineToRecord(UserLine);
            vUsers.push_back(User);
        }
        File.close();
    }
    return vUsers;
}

void ManageUsersMenuScreen(std::vector<stClient> &vClients)
{
    std::cout << "\n========================================================================\n";
    std::cout << "\n\t\t\t Manage Users Menu Screen\n";
    std::cout << "\n========================================================================\n";

    std::cout << "\t[1] List Users." << std::endl;
    std::cout << "\t[2] Add New User." << std::endl;
    std::cout << "\t[3] Delete User." << std::endl;
    std::cout << "\t[4] Update User." << std::endl;
    std::cout << "\t[5] Find User." << std::endl;
    std::cout << "\t[6] Main Menu." << std::endl;


    std::cout << "========================================================================\n";

    std::cout << "Choose what you want to do from [1 to 6]: ";
    
    std::vector <stUser> vUsers = LoadUsersDateInVector();
    PerformManageUsersMenuOperations(vUsers, vClients); 
}

bool IsUserExist(stUser User)
{

    std::vector <stUser> vUsers = LoadUsersDateInVector();
    for (stUser &U : vUsers)
    {
        if (User.Username == U.Username)
        {
            if (User.Password == U.Password)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

void Login(std::vector<stClient> &vClients)
{
    std::cout << "\n---------------------------------------------------\n";
    std::cout << "\t\tLogin Screen";
    std::cout << "\n---------------------------------------------------\n";
    
    do {
        stUser User = ReadUserInfo();

        if (IsUserExist(User))
        {
            ShowMainMenu(vClients);
        }
        else
        {
            std::cout << "Invalid username/password!\n";
        }
    } while (true);
}

bool ShowMainMenu(std::vector<stClient> &vClients)
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
    std::cout << "\t[7] Manage Users." << std::endl;
    std::cout << "\t[8] Logout." << std::endl;

    std::cout << "========================================================================\n";

    short Choice;
    std::cout << "Choose what you want to do from [1 to 8]: ";
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
        ManageUsersMenuScreen(vClients);

    }
    else if (Choice == 8)
    {
        system("clear");
        Login(vClients);
        // EndProgram();
        return false;
    }
    return true;
}

int main()
{
        std::vector<stClient> vClients;

        LoadClientsDataInVector(vClients);

        Login(vClients);
        bool KeepRunning = true;
        while (KeepRunning)
        {
            KeepRunning = ShowMainMenu(vClients);
            if (KeepRunning)
            {
                std::cout << "\nPress any key to return to main menu....";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
            }
        }

    return 0;
}