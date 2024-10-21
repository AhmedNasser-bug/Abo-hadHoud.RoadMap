#pragma once
#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
class clsCurrencyExchangeMenu :
    public clsScreen
{
private:
    enum enCurrenciesMainMenueOptions {
        enListCurrencies = 1, enFindCurrencies = 2, enUpdateRate = 3, enCurrencyCalculator = 4, enBackMainMenu = 5
    };

    static void ShowCurrenciesListScreen() {

        // List will be here

    }

    static void ShowFindCurrenciesScreen() {

    }

    static void ShowUpdateRateScreen() {

    }

    static void ShowCurrencyCalculatorScreen() {

    }

    void _BackToCurrencyExchangeMenu() {
        UIEnd();
        ShowCurrencyExchangeMenu();
    }

    short ReadCurrenciesMenuOption() {
        cout << "Please enter a number between 1 and 5 (inclusive): ";
        short Choice = InputValidation::ReadShortWithinRange(1, 5);
        return Choice;
    }

    void _PerformCurrenciesMenuOptions(enCurrenciesMainMenueOptions Choice) {
        cls

            switch (Choice)
            {
            case clsCurrencyExchangeMenu::enListCurrencies:
                ShowCurrenciesListScreen();
                break;
            case clsCurrencyExchangeMenu::enFindCurrencies:
                ShowFindCurrenciesScreen();
                break;
            case clsCurrencyExchangeMenu::enUpdateRate:
                ShowUpdateRateScreen();
                break;
            case clsCurrencyExchangeMenu::enCurrencyCalculator:
                ShowCurrencyCalculatorScreen();
                break;
            case clsCurrencyExchangeMenu::enBackMainMenu:
                return;
                break;
            default:
                break;
            }
        _BackToCurrencyExchangeMenu();
    }
public:
    void ShowCurrencyExchangeMenu() {
        PrintScreenTitle("Currency Exchange");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMenuOptions((enCurrenciesMainMenueOptions)ReadCurrenciesMenuOption());
    }
};

