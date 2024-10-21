#pragma once
#include "clsScreen.h"
class clsTransferScreen :
    public clsScreen
{
private:

    static string _GetExistingAccountNumber(string SenderAccNum = " ") {
        cout << "Enter client Account Number: ";
        string AccNum = InputValidation::ReadString();
        while (!clsBankClient::IsClientExist(AccNum) or AccNum == SenderAccNum) {
            cout << "Account Number Doesn't exist or you choose the Sender as the Reciever , choose another one: ";
            AccNum = InputValidation::ReadString();
        }
        return AccNum;
    }

    static inline void _PrintClientCard(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }
    
public:

    static void ShowTransferScreen() {

        PrintScreenTitle("Transfer Screen");

        // Getting the sender
        cout << "Enter the Acount Number to transfer from: " << endl;
        string AccountNumber = _GetExistingAccountNumber();
        clsBankClient Sender = clsBankClient::Find(AccountNumber);

        _PrintClientCard(Sender);

        // Getting the Reciever
        cout << "Enter the Acount Number to transfer to: " << endl;
        AccountNumber = _GetExistingAccountNumber(AccountNumber);
        clsBankClient Reciever = clsBankClient::Find(AccountNumber);

        _PrintClientCard(Reciever);

        cout << "Choose the Amount: ";
        size_t Amount = InputValidation::ReadIntWithinRange(0, Sender.AccountBalance, "Not enough balance!\nChoose Less than " + to_string(Sender.AccountBalance));

        
        // Transfer process
        Sender.Transfer(Amount, Reciever, CurrentUser.UserName());


        cout << "-------------------------------------TRANSFER DONE-------------------------------------" << endl;
        
        cout << "---Sender Card---" << endl;
        _PrintClientCard(Sender);

        cout << "---Reciever Card---" << endl;
        _PrintClientCard(Reciever);
    }
};

