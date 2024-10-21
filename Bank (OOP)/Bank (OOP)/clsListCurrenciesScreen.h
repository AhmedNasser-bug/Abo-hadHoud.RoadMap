#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"

class clsListCurrenciesScreen :
    public clsScreen
{
public:

    static inline void _PrintCurrencyLine(clsCurrency Currency) {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();

    }

private:

    static void ShowCurrenciesListScreen() {

        PrintScreenTitle("Currencies List");

        vector<clsCurrency> AllCurrencies = clsCurrency::GetCurrenciesList();

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        for (clsCurrency& Currency : AllCurrencies) {
            _PrintCurrencyLine(Currency);
        }

    }
};

