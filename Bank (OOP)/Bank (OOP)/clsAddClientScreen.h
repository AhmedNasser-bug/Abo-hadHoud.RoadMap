#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "MainScreen.h"
#include <iostream>
#define cls system("cls");


using namespace std;
class clsAddClientScreen : protected clsScreen

{
    static inline void _ReadClientInfo(clsBankClient& Client) {
        cout << "Enter First Name: ";

        string FirstName = InputValidation::ReadString();
        Client.SetFirstName(FirstName);

        cout << "Enter Last Name: ";

        string LastName = InputValidation::ReadString();
        Client.SetLastName(LastName);

        cout << "Enter Email: ";

        string Email = InputValidation::ReadString();
        Client.SetEmail(Email);

        cout << "Enter Phone: ";

        string Phone = InputValidation::ReadString();
        Client.SetPhone(Phone);

        cout << "Enter PinCode: ";

        string PinCode = InputValidation::ReadString();
        Client.SetPinCode(PinCode);

        cout << "Enter Account Balance: ";

        float AccountBalance = InputValidation::ReadDouble();
        Client.SetAccountBalance(AccountBalance);



    }

    static inline void _PrintClientCard(clsBankClient Client)
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
    // Display a screen for adding a new client to the database
    static void DisplayAddClientScreen() {

        PrintScreenTitle("Add Client Screen");

        string AccountNumber = _GetNewAccountNumber();

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults Save = NewClient.Save();

        switch (Save)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "Add Failed (Empty Object Returned)!";
            break;
        case clsBankClient::svSucceeded:
            cout << "Successfully Added a new Client!!";
            _PrintClientCard(NewClient);
            break;
        case clsBankClient::svFailedAlreadyExists:
            cout << "Adding Failed (Aleady Exists)";
            break;
        default:
            break;
        }
    }
};

