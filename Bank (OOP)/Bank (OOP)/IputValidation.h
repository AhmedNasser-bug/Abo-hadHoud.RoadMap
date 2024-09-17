#pragma once
#include <iostream>
#include "Date.h"
#include "Utils.h"

using namespace std;

class InputValidation
{
public:
	// Is number(int, float, double , long) in a range
	static bool IsNumberInRange(long double Num, long double RangeLow, long double RangeHigh) {
		return RangeLow <= Num and Num <= RangeHigh;
	}

	// Is date between two dates
	static bool IsDateBetween(Date Date1, Date RangeLow, Date RangeHigh) {
		if (RangeLow.isAfter(RangeHigh)) Utils::Swap(RangeLow, RangeHigh);
		return (Date1.isEqualto(RangeLow) or Date1.isAfter(RangeLow)) and (Date1.isEqualto(RangeHigh) or Date1.isBefore(RangeHigh));
	}
	
	// Read Integer that takes an error message as an optional argument
	static long long int ReadInt(string ErrorMessage = "INVALID , TRY AGAIN:") {
		while (true) {
			int n;	
			std::cin >> n;
			cin.ignore(1, '\n');
			if (typeid(n) == typeid(int) ) {
				return n;
			}
			std::cout << ErrorMessage << endl;
		}
	}
	
	// Read int within range (inclusive)
	static long long int ReadIntWithinRange(long long int RangeLow, long long int RangeHigh, string ErrorMessage) {
		long long int Number = ReadInt();
        while (!IsNumberInRange(Number, RangeLow, RangeHigh)) {
            cout << ErrorMessage;
            cin >> Number;
            cout << endl;
        }
        return Number;
    
	}
	
	// Read double that takes an error message as an optional argument
	static long double ReadDouble(string ErrorMessage = "INVALID , TRY AGAIN:") {
		while (true) {
			long double Number;
			std::cin >> Number;
			cin.ignore(1, '\n');
			if (typeid(Number) != typeid(string) ) {
				return Number;
			}
			std::cout << ErrorMessage << endl;
		}
	}
	
	// Read double within a range (inclusive)
	static long double ReadDblWithinRange(long double RangeLow, long double RangeHigh, string ErrorMessage) {
		long double Number = ReadDouble();
		while (!IsNumberInRange(Number, RangeLow, RangeHigh)) {
			cout << ErrorMessage;
			Number = ReadDouble();
			cout << endl;
		}
		cin.ignore(1, '\n');
		return Number;

	}
	
	// Check if a given date is valid
	static bool isDateValid(Date date) {
		return IsNumberInRange(date.Month, 1, 12) and IsNumberInRange(date.Day, 1, date.numberOfDaysInMonth());
	}

	static string ReadString() {
		string ret;
		getline(cin >> ws, ret);
		return ret;
	}
};

