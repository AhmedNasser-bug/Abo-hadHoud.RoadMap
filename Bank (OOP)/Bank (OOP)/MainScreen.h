#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#define cls system("cls");

class clsMainScreen : protected clsScreen
{
private:    
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenuOption() {
        cout << "Choose a number between 1 and 8...";
        short Choice = InputValidation::ReadIntWithinRange(1, 8, "PLEASE choose a number between 1 and 8");
        return Choice;
    }

    static void _GoBackToMainMenu() {

        UIEnd();

        ShowMainMenu();
        
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddClientScreen::DisplayAddClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::FindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        cout << "\nTransactions Menue Will be here...\n";

    }

    static void _ShowManageUsersMenue()
    {
        cout << "\nUsers Menue Will be here...\n";

    }

    static void _ShowEndScreen()
    {
        PrintScreenTitle("THANKS FOR USING OUR SOFTWARE", "nah");

    }

    static void _PerforMainMenuOption(enMainMenueOptions Choice) {
        cls
        switch (Choice)
        {
        case clsMainScreen::eListClients:
            _ShowAllClientsScreen();
            break;
        case clsMainScreen::eAddNewClient:
            _ShowAddNewClientsScreen();
            break;
        case clsMainScreen::eDeleteClient:
            _ShowDeleteClientScreen();
            break;
        case clsMainScreen::eUpdateClient:
            _ShowUpdateClientScreen();
            break;
        case clsMainScreen::eFindClient:
            _ShowFindClientScreen();
            break;
        case clsMainScreen::eShowTransactionsMenue:
            _ShowTransactionsMenue();
            break;
        case clsMainScreen::eManageUsers:
            _ShowManageUsersMenue();
            break;
        case clsMainScreen::eExit:
            _ShowEndScreen();
            return;
        default:
            break;
        }
        _GoBackToMainMenu();
    }

    inline void PrintBalanceRecordLine(clsBankClient& Client) {
        printf("| %-15s", Client.AccountNumber().c_str());
        printf("| %-20s", Client.FullName().c_str());
        printf("| %-12f", Client.AccountBalance);
    }

    
    // Displays a screen with all existing clients balances in the database
    void ShowTotalBalances() {
        cls
        vector <clsBankClient> Clients = clsBankClient::GetClientList();
        cout << "\n\t\t\t\t\tBalances List (" << Clients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        long double TotalBalances = clsBankClient::GetTotalBalances();

        for (clsBankClient& Client : Clients) {
            PrintBalanceRecordLine(Client);
            cout << endl;
        }

        long double TotalBalance = clsBankClient::GetTotalBalances();
        cout << "\nTotal Balances: " << TotalBalance << endl;
        Utils::numToText((lli)TotalBalance);

        UIEnd();
    }


public:

    

    static void ShowMainMenu() {
        cls
        clsScreen::PrintScreenTitle("Main Menu", "Choose what to do...");
        cout << "" << "[1] Show Client List.\n";
        cout << "" << "[2] Add New Client.\n";
        cout << "" << "[3] Delete Client.\n";
        cout << "" << "[4] Update Client Info.\n";
        cout << "" << "[5] Find Client.\n";
        cout << "" << "[6] Transactions.\n";
        cout << "" << "[7] Manage Users.\n";
        cout << "" << "[8] Logout.\n";
        cout << "" << "===========================================\n";
        _PerforMainMenuOption((enMainMenueOptions)_ReadMainMenuOption());

   }
};

