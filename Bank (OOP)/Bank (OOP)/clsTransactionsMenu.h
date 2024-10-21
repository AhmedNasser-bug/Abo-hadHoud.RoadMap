#pragma once
#include "MainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsBalancesList.h"
#include "clsTransferScreen.h"
#include "clsTransactionLogsScreen.h"

class clsTransactionsMenu : clsScreen
{
private:
    enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowBalances = 3, eTransfer = 4, eTransferLogs = 5, eBackToMainScreen = 6 };


    static inline void _ShowDepositScreen() {

        clsDepositScreen::ShowDepositScreen();

    }

    static inline void _ShowWithdrawScreen() {
        
        clsWithdrawScreen::ShowWithdrawScreen();

    }

    static inline void _ShowAllBalancesScreen() {

        clsBalancesList::ShowTotalBalances();
    }

    static inline void _ShowTransferScreen() {

        clsTransferScreen::ShowTransferScreen();

    }

    static inline void _ShowTransactionLogsScreen() {

        clsTransactionLogs::ShowTransactionLogsScreen();

    }
   
    static inline void _GetBackToTransactionsMenu() {

        UIEnd();
        ShowTransationsMenuScreen();

    }

    static inline short _GetTransationsMenuOption() {
        cout << "Please choose an Option: ";

        short Choice = InputValidation::ReadShortWithinRange(1, 5, "Please choose a number from 1 to 4");

        return Choice;
    }

    static inline void _PerformTransactionScreenOption(enTransactionsMenuOptions Choice) {

        cls

        switch (Choice)
        {
        case clsTransactionsMenu::eDeposit:
            
            _ShowDepositScreen();
            
            break;
        
        case clsTransactionsMenu::eWithdraw:
        
            _ShowWithdrawScreen();
            
            break;
        
        case clsTransactionsMenu::eShowBalances:
        
            _ShowAllBalancesScreen();
            
            break;
        case clsTransactionsMenu::eTransfer:

            _ShowTransferScreen();

            break;

        case clsTransactionsMenu::eTransferLogs:

            _ShowTransactionLogsScreen();

            break;

        case clsTransactionsMenu::eBackToMainScreen:
        
            return;
            
            break;
        
        default:
            break;
        }

        _GetBackToTransactionsMenu();

    }

public:

    static void ShowTransationsMenuScreen() {
        cls

        PrintScreenTitle("Transactions Menu");

        cout << "[1] Deposit" << endl;
        cout << "[2] Withdraw" << endl;
        cout << "[3] Show All balances" << endl;
        cout << "[4] Show Transfer Screen" << endl;
        cout << "[5] Back To main menu" << endl;

        
        _PerformTransactionScreenOption(enTransactionsMenuOptions(_GetTransationsMenuOption()));
        
    }
};