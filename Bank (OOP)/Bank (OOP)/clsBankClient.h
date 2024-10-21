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
public:
    struct stTransactionLog {
        string Date;
        string SenderAccNum;
        string RecieverAccNum;
        string Amount;
        string SenderBalance;
        string RecieverBalance;
        string CurrentUserName;
    };
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    bool _MarkedForDelete = false;
    int64_t _AccountBalance;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = String::WordsOf(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stoll(vClientData[6]));

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

        for (size_t ClientIndex = 0; ClientIndex < _vClients.size(); ClientIndex++)
        {
            
            if (_vClients[ClientIndex].AccountNumber() == AccountNumber())
            {
                _vClients[ClientIndex] = *this;

                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew() {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine, string FileDir = "Clients.txt")
    {
        fstream MyFile;
        MyFile.open(FileDir, ios::out | ios::app);

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

    static string _GetTransactionLog(clsBankClient Sender, clsBankClient Reciever, size_t Amount, string CurrentUserName, string Seperator = "#//#") {

        string TransferLogRecord = "";
        Date CurrentDate;
        TransferLogRecord += CurrentDate.GetStringDate("dd/mm/yyyy") + "-" + CurrentDate.GetStringTime("hh:mm:ss") + Seperator;
        TransferLogRecord += Sender.AccountNumber() + Seperator;
        TransferLogRecord += Reciever.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(Sender.AccountBalance) + Seperator;
        TransferLogRecord += to_string(Reciever.AccountBalance) + Seperator;
        TransferLogRecord += CurrentUserName;
        return TransferLogRecord;

    }

    static stTransactionLog _LineToTransactionLog(string Line) {
        vector<string> TransactionData = String::WordsOf(Line, "#//#");

        stTransactionLog TransactionLog;

        TransactionLog.Date = TransactionData[0];
        TransactionLog.SenderAccNum = TransactionData[1];
        TransactionLog.RecieverAccNum = TransactionData[2];
        TransactionLog.Amount = TransactionData[3];
        TransactionLog.SenderBalance = TransactionData[4];
        TransactionLog.RecieverBalance = TransactionData[5];
        TransactionLog.CurrentUserName = TransactionData[6];

        return TransactionLog;
    }

public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        int64_t AccountBalance) :
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


    void SetAccountBalance(size_t AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }


    inline void Deposit(int64_t Amount) {
        _AccountBalance += Amount;

         Save();

    }


    inline void Withdraw(int64_t Amount) {
        _AccountBalance -= Amount;

        Save();
    }


    inline void Transfer(size_t Amount, clsBankClient& TransferTo, string CurrentUserName) {
        Withdraw(Amount);

        TransferTo.Deposit(Amount);

        // Add transaction log to file
        _AddDataLineToFile(_GetTransactionLog(*this, TransferTo, Amount, CurrentUserName), "TransactionLogs.txt");
    }


    int64_t GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) int64_t AccountBalance;


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

                _SaveCleintsDataToFile(vClients);

                *this = _GetEmptyClientObject();

                return true;

            }
        }
        
        return false;
        
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

        return enSaveResults::svFaildEmptyObject;
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


    static int64_t GetTotalBalances() {
        int64_t Total = 0;
        vector <clsBankClient> Clients = GetClientList();
        for (clsBankClient& Client : Clients) {
            Total += Client.AccountBalance;
        }
        
        return Total;
    }


    static vector<stTransactionLog> LoadTransferLogsFromFile() {

        vector <stTransactionLog> vLogs;
        fstream MyFile;
        MyFile.open("TransactionLogs.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                vLogs.push_back(_LineToTransactionLog(Line));
            }
            MyFile.close();

        }

        return vLogs;
    }

};

