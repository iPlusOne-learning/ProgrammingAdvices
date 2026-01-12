#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    bool _MarkedForDelete = false;
    float _AccountBalance;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }
    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.GetAccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += to_string(Client.GetAccountBalance());
    
        return stClientRecord;
    }
    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite
        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.GetMarkedForDeleted() == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }
    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }
    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.GetAccountNumber() == GetAccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
    }
    void _AddNew()
    {
        // This is my version and his version is much cleaner
        // vector <clsBankClient> _vClients;
        // _vClients = _LoadClientsDataFromFile();
        // _vClients.push_back(*this);
        // _SaveCleintsDataToFile(_vClients);
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string GetAccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = GetAccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string GetAccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }
    bool GetMarkedForDeleted()
    {
        return _MarkedForDelete;
    }
    static clsBankClient Find(string GetAccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.GetAccountNumber() == GetAccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string GetAccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.GetAccountNumber() == GetAccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }
            else
            {
                _AddNew();
                return enSaveResults::svSucceeded;
            }
            break;
        }
        }
    }

    static bool IsClientExist(string GetAccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(GetAccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "","","","",AccountNumber,"", 0);
    }
    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;
    }
    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }
    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;
        for (clsBankClient Client : vClients)
        {
            TotalBalances+= Client.GetAccountBalance();
        }
        return TotalBalances;
    }
};