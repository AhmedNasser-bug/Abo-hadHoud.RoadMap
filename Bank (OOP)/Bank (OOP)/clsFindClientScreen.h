#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "MainScreen.h"
class clsFindClientScreen : protected clsScreen
{
private:

    static inline void _PrintClientCard(clsBankClient& Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName();
        cout << "\nLastName    : " << Client.LastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.Phone();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }

    static string _GetExistingAccountNumber() {
        cout << "Enter client Account Number: ";
        string AccNum = InputValidation::ReadString();
        while (!clsBankClient::IsClientExist(AccNum)) {
            cout << "Account Number Doesn't exist, choose another one: ";
            AccNum = InputValidation::ReadString();
        }
        return AccNum;
    }

    static string _GetNewAccountNumber() {
        cout << "Please enter Account Number: ";
        string AccountNumber = InputValidation::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Client ALREADY EXISTS , please enter another Account Number: ";
            AccountNumber = InputValidation::ReadString();
        }

        return AccountNumber;
    }

public:

     static inline void FindClientScreen() {

        PrintScreenTitle("Find Client Screen");

        cout << "Enter Account Number: ";

        string AccountNumber = _GetExistingAccountNumber();

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClientCard(Client);
    }
};

