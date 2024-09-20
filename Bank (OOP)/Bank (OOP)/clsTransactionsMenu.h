#pragma once
#include "MainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsBalancesList.h"

class clsTransactionsMenu : clsScreen
{
private:
    enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowBalances = 3, eBackToMainScreen = 4 };


    static inline void _ShowDepositScreen() {

        clsDepositScreen::ShowDepositScreen();

    }

    static inline void _ShowWithdrawScreen() {
        
        clsWithdrawScreen::ShowWithdrawScreen();

    }

    static inline void _ShowAllBalancesScreen() {

        clsBalancesList::ShowTotalBalances();
    }
   
    static inline void _GetBackToTransactionsMenu() {

        UIEnd();

        ShowTransationsMenuScreen();

    }

    static inline short _GetTransationsMenuOption() {
        cout << "Please choose an Option: ";

        short Choice = InputValidation::ReadShortWithinRange(1, 4, "Please choose a number from 1 to 4");

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
        cout << "[4] Back To main menu" << endl;

        
        _PerformTransactionScreenOption(enTransactionsMenuOptions(_GetTransationsMenuOption()));
        
    }
};