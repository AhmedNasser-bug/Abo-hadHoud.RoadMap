#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsBalancesList :
    public clsScreen
{
private:

    static inline void _PrintBalanceRecordLine(clsBankClient& Client) {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(40) << Client.FullName();
        cout << "| " << left << setw(12) << Client.AccountBalance;
    }

public:

    // Displays a screen with all existing clients balances in the database
    static inline void ShowTotalBalances() {
        
        vector <clsBankClient> Clients = clsBankClient::GetClientList();

        cout << "\n\t\t\t\t\tBalances List (" << Clients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        int64_t TotalBalances = clsBankClient::GetTotalBalances();

        for (clsBankClient& Client : Clients) {
            _PrintBalanceRecordLine(Client);
            cout << endl;
        }

        int64_t TotalBalance = clsBankClient::GetTotalBalances();
        cout << "\nTotal Balances: " << TotalBalance << endl;
        Utils::numToText((lli)TotalBalance);

        
    }
};

