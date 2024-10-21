#pragma once

#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenu.h"
#include "clsManageUsersScreen.h"
#include "ShowLogsScreen.h"
#include "clsLoginScreen.h"

#include "GlobalUser.h"


class clsMainScreen : protected clsScreen
{
private:    

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eShowLogs = 8, eCurrencyExchange = 9,  eExit = 10
    };

    static short _ReadMainMenuOption() {
        cout << "Choose a number between 1 and 9...";
        short Choice = InputValidation::ReadShortWithinRange(1, 10, "PLEASE choose a number between 1 and 8");
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
       
        clsTransactionsMenu::ShowTransationsMenuScreen();
    }

    static void _ShowManageUsersMenue()
    {
        
        clsManageUsersScreen::ShowManageUsersScreen();

    }

    static void _ShowLogs() {
        
        ShowLogsScreen::ShowLogs();
    }

    static void _ShowCurrencyExchangeMenu() {

        // call to currency exchange will be here

    }
    
    static void _ShowErrorMessage() {
        cls
        cout << "NOT PERMITTED TO DO THIS ACTION" << endl;

    }

    static void _LogOut()
    {
        CurrentUser = clsUser::Find("", "");
        
       

    }

    static void _PerforMainMenuOption(enMainMenueOptions Choice) {
        cls
        switch (Choice)
        {
        case clsMainScreen::eListClients:
            if(CurrentUser.IsPermittedTo(eListClients))_ShowAllClientsScreen();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eAddNewClient:
            if (CurrentUser.IsPermittedTo(eAddNewClient))_ShowAddNewClientsScreen();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eDeleteClient:
            if (CurrentUser.IsPermittedTo(eDeleteClient))_ShowDeleteClientScreen();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eUpdateClient:
            if (CurrentUser.IsPermittedTo(eUpdateClient))_ShowUpdateClientScreen();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eFindClient:
            if (CurrentUser.IsPermittedTo(eFindClient))_ShowFindClientScreen();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eShowTransactionsMenue:
            if (CurrentUser.IsPermittedTo(eShowTransactionsMenue))_ShowTransactionsMenue();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eManageUsers:
            if (CurrentUser.IsPermittedTo(eManageUsers))_ShowManageUsersMenue();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eShowLogs:
            if (CurrentUser.IsPermittedTo(eShowLogs))_ShowLogs();
            else {
                _ShowErrorMessage();
            }
            break;
        case clsMainScreen::eExit:
            _LogOut();
            return;
        default:
            break;
        }

        _GoBackToMainMenu();
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
        cout << "" << "[8] Show Logs.\n";
        cout << "" << "[9] Currency Exchange.\n";
        cout << "" << "[10] Logout.\n";
        cout << "" << "===========================================\n";
        _PerforMainMenuOption((enMainMenueOptions)_ReadMainMenuOption());

   }

};

