#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "String.h"
#include "IputValidation.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    bool _MarkedForDelete = false;
    float _AccountBalance;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = String::WordsOf(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName() + Seperator;
        stClientRecord += Client.LastName() + Seperator;
        stClientRecord += Client.Email() + Seperator;
        stClientRecord += Client.Phone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

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

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                DataLine = _ConverClientObjectToLine(C);
                if (not C._MarkedForDelete) { MyFile << DataLine << endl; }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew() {
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
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
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
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string AccountNumber)
    {
       

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {

     

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    bool Delete() {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();
        for (size_t ClientIndex = 0; ClientIndex < vClients.size(); ClientIndex++) {
            if (vClients[ClientIndex].AccountNumber() ==  _AccountNumber) {
                vClients[ClientIndex]._MarkedForDelete = true;

            }
        }

        _SaveCleintsDataToFile(vClients);

        *this = _GetEmptyClientObject();
        
        return true;
    }
        

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedAlreadyExists };


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
                if(IsEmpty())
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {

            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case enMode::AddNew:

            if (IsClientExist(_AccountNumber)) {
                return enSaveResults::svFailedAlreadyExists;
            }
            else {
                _AddNew();
                return enSaveResults::svSucceeded;
            }
            break;
        }

    }


    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    
    static clsBankClient GetAddNewClientObject(string AccountNumber) {
        return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
    }


    static vector<clsBankClient> GetClientList() {
        return _LoadClientsDataFromFile();
    }

    static long double GetTotalBalances() {
        long double Total = 0;
        vector <clsBankClient> Clients = GetClientList();
        for (clsBankClient& Client : Clients) {
            Total += Client.AccountBalance;
        }
        
        return Total;
    }

};

