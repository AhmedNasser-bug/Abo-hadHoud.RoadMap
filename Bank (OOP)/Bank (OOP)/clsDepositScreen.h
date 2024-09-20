#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "MainScreen.h"
class clsDepositScreen :
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

    // Deposit money to the given client
    static void ShowDepositScreen() {

        PrintScreenTitle("Deposit Screen");

        string AccountNumber = _GetExistingAccountNumber();

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClientCard(Client);

        cout << "Available Balance : " << Client.AccountBalance << "\n Enter Amount : ";

        size_t DepositAmount = InputValidation::ReadPositiveInt();

        Client.Deposit(DepositAmount);

        cout << "Deposit done!!\nAvailable Balance: " << Client.AccountBalance << endl;

    }
    
};

