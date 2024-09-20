#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsWithdrawScreen :
    public clsScreen
{
private:

    static string _GetExistingAccountNumber() {

        cout << "Enter client Account Number: ";

        string AccNum = InputValidation::ReadString();

        while (not clsBankClient::IsClientExist(AccNum)) {

            cout << "Account Number Doesn't exist, choose another one: ";

            AccNum = InputValidation::ReadString();

        }

        return AccNum;
    }

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
        cout << "\n___________________\n";

    }

public:

    // Withdraw money to the given client
    static void ShowWithdrawScreen() {

        PrintScreenTitle("Withdraw Screen");

        string AccountNumber = _GetExistingAccountNumber();

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClientCard(Client);

        cout << "Available Balance : " << Client.AccountBalance << "\n Enter Amount : ";

        size_t WithdrawAmount = InputValidation::ReadIntWithinRange(0, Client.AccountBalance, "INSUFFECIENT BALANCE!!!!/INCORRECT INPUT\nEnter again: ");

        Client.Withdraw(WithdrawAmount);

        cout << "Withdrawal done!!\nAvailable Balance: " << Client.AccountBalance << endl;

    }
};

