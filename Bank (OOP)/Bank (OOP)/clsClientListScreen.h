#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsClientListScreen : protected clsScreen
{
private:
    static inline void PrintClientRecordLine(clsBankClient& Client)
    {
        printf("| %-15s", Client.AccountNumber().c_str());
        printf("| %-20s", Client.FullName().c_str());
        printf("| %-12s", Client.Phone().c_str());
        printf("| %-20s", Client.Email().c_str());
        printf("| %-10s", Client.PinCode.c_str());
        printf("| %-12f", Client.AccountBalance);

    }
public:
    // Displays a screen with all existing clients in the database
    static void ShowClientList() {
        vector<clsBankClient> Clients = clsBankClient::GetClientList();

        PrintScreenTitle("Clients List", "Client List (" + to_string(Clients.size()) + ") Client(s).");

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        printf("| %-15s", "Account Number");
        printf("| %-20s", "Client Name");
        printf("| %-12s", "Phone");
        printf("| %-20s", "Email");
        printf("| %-10s", "Pin Code");
        printf("| %-12s", "Balance");
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (not Clients.size()) {

            cout << "\t\t\t\t\tNo Clients For Now";


            return;
        }
        for (clsBankClient& Client : Clients) {

            PrintClientRecordLine(Client);

            cout << endl;
        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
	

};

