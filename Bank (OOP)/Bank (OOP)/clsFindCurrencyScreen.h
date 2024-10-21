#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen :
    public clsScreen
{
private:
    enum enChoice { eFindWithCountry = 1, eFindWithCode = 2 };

    static inline void _PrintCurrencyLine(clsCurrency Currency) {

        if (Currency.IsEmpty()) {
            cout << "NO CURRENCY WITH THIS CODE/COUNTRY";
            return;
        }

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country() << endl;
        cout << "| " << setw(8) << left << Currency.CurrencyCode() << endl;
        cout << "| " << setw(45) << left << Currency.CurrencyName() << endl;
        cout << "| " << setw(10) << left << Currency.Rate();

    }

public:

    static inline void ShowFindCurrencyScreen() {

        PrintScreenTitle("Find Currency Screen");

        cout << "Find With Country [1] or with Code [2]: (1/2)";
        enChoice Choice = (enChoice)InputValidation::ReadShortWithinRange(1, 2);


        string Country, CountryCode;

        switch (Choice)
        { 
        case clsFindCurrencyScreen::eFindWithCountry:

            cout << endl << "Enter Country Name: ";
             Country = InputValidation::ReadString();

            _PrintCurrencyLine(clsCurrency::FindByCountry(Country));
            
            break;
        
        case clsFindCurrencyScreen::eFindWithCode:

            cout << endl << "Enter Country Name: ";
            CountryCode = InputValidation::ReadString();
            _PrintCurrencyLine(clsCurrency::FindByCountry(CountryCode));
            break;

        default:
            return;
            
        }


    }
};

