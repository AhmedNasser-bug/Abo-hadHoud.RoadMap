#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "MainScreen.h"
class clsDeleteClientScreen : protected clsScreen
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
    // Display a screen for deleting client from the database
    static inline void ShowDeleteClientScreen() {
        
        PrintScreenTitle("Delete Client Screen");

        string AccNum = _GetExistingAccountNumber();

        clsBankClient Client = clsBankClient::Find(AccNum);

        _PrintClientCard(Client);

        cout << "Do you Want to PERMENANTILY DELETE this Client?  (1/0)";

        bool DeleteConfirmed = InputValidation::ReadIntWithinRange(0, 1, "Invalid choice , insert '1' for confirming deletion '0' otherwise");

        if (DeleteConfirmed) {

            if (Client.Delete()) {

                cout << "Client Deleted Successfully !!!";
            }

            else {

                cout << "Error Deleting Client!";

            }

        }

    }
};

