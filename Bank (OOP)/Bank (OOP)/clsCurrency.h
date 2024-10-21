#pragma once
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "String.h"
#include <vector>

class clsCurrency
{
private:
	enum enMode {EmptyMode, UpdateMode};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#") {

        vector<string> vCurrencies;
        vCurrencies = String::WordsOf(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencies[0], vCurrencies[1], vCurrencies[2],
            stof(vCurrencies[3]));

    }

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {

        string strCurrencyLine = "";
        strCurrencyLine += Currency.Country() + Seperator;
        strCurrencyLine += Currency.CurrencyCode() + Seperator;
        strCurrencyLine += Currency.CurrencyName() + Seperator;
        strCurrencyLine += Currency.Rate();

        return strCurrencyLine;

    }

    static  vector <clsCurrency> _LoadCurrenciessDataFromFile()
    {

        vector <clsCurrency> vUsers;

        fstream MyFile;

        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsCurrency User = _ConvertLinetoCurrencyObject(Line);
               

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsCurrency> vCurrencies)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency& Currency : vCurrencies)
            {
                DataLine = _ConvertCurrencyObjectToLine(Currency);
                MyFile << DataLine << endl; 

            }

            MyFile.close();

        }

    }

	void _Update() {

	}

    static clsCurrency _GetEmptyCurrencyObject() {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:
    

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Country = Country;
		_Mode = Mode;
		_CurrencyName = CurrencyName;
		_CurrencyCode = CurrencyCode;
		_Rate = Rate;
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

    float Rate() {
        return _Rate;
    }

	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}

    static clsCurrency FindByCode(string Code) {
        vector<clsCurrency> vCurrencies = _LoadCurrenciessDataFromFile();
        
        Code = String::AllUpper(Code);

        for (clsCurrency Currency : vCurrencies) {
            if (Currency.CurrencyCode() == Code) {

                return Currency;

            }

        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country) {
        vector<clsCurrency> vCurrencies = _LoadCurrenciessDataFromFile();

        Country = String::AllUpper(Country);

        for (clsCurrency Currency : vCurrencies) {
            if (String::AllUpper(Currency.CurrencyCode()) == Country) {

                return Currency;

            }

        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode) {
        return not FindByCode(CurrencyCode).IsEmpty();
        }

    static vector<clsCurrency> GetCurrenciesList() {
        return _LoadCurrenciessDataFromFile();
    }
};


