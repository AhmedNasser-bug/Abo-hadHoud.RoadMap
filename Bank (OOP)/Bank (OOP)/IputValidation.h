#pragma once
#include <iostream>
#include "Date.h"
#include "Utils.h"

using namespace std;

template<class T>
class InputValidation
{
public:
	// Is number double in a given range
	static bool IsDoubleInRange(long double Num, long double RangeLow, long double RangeHigh) {
		return RangeLow <= Num and Num <= RangeHigh;
	}

	// Is Integer in a given range
	static bool IsIntInRange(int64_t Num, int64_t RangeLow, int64_t RangeHigh) {
		return RangeLow <= Num and Num <= RangeHigh;
	}

	// Is date between two dates
	static bool IsDateBetween(Date Date1, Date RangeLow, Date RangeHigh) {
		if (RangeLow.isAfter(RangeHigh)) Utils::Swap(RangeLow, RangeHigh);
		return (Date1.isEqualto(RangeLow) or Date1.isAfter(RangeLow)) and (Date1.isEqualto(RangeHigh) or Date1.isBefore(RangeHigh));
	}
	
	// Read Integer that takes an error message as an optional argument
	static int64_t ReadInt(string ErrorMessage = "INVALID , TRY AGAIN:") {
		while (true) {
			int64_t n;
			std::cin >> n;
			cin.ignore(1, '\n');
			if (typeid(n) == typeid(int64_t) ) {
				return n;
			}

			

			std::cout << ErrorMessage << endl;
		}
	}

	// Read short int that takes an error message as an optional argument
	static short ReadShort(string ErrorMessage = "INVALID , TRY AGAIN:") {
		while (true) {
			short n;
			std::cin >> n;
			cin.ignore(1, '\n');
			if (typeid(n) == typeid(short)) {
				return n;
			}



			std::cout << ErrorMessage << endl;
		}
	}
	
	// Returns a Positive Integer
	static size_t ReadPositiveInt() {
		
		size_t Number;
		
		cin >> Number;

		while (Number < 0 or typeid(Number) == typeid(const char *)) {
			
			cout << "Number Must be POSITIVE, try again: ";
			
			cin >> Number;

		}
		cin.clear();
		
		return Number;
	}

	// Returns a Positive Double
	static long double ReadPositiveDouble() {
		long double Number;
		cin >> Number;
		
		while (Number < 0) {
			
			
				cout << "Number Must be POSITIVE, try again: ";

				cin >> Number;
			
			

		}

		cin.clear();

		return Number;
	}

	// Read int within range (inclusive)
	static int64_t ReadIntWithinRange(int64_t RangeLow, int64_t RangeHigh, string ErrorMessage = "Number Not in Range!\nEnter another one: ") {

		int64_t Number = ReadInt();
        
		while (!IsIntInRange(Number, RangeLow, RangeHigh)) {
        
			cout << ErrorMessage;
            
			cin >> Number;
			
        }
        return Number;
    
	}
	// Read short within the given range
	static short ReadShortWithinRange(short RangeLow, short RangeHigh, string ErrorMessage = "Number Not in Range!\nEnter another one: ") {

		short Number = ReadShort();

		while (!IsIntInRange(Number, RangeLow, RangeHigh)) {

			cout << ErrorMessage;

			cin >> Number;

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
	static long double ReadDblWithinRange(long double RangeLow, long double RangeHigh, string ErrorMessage = "Invalid Number") {
		long double Number = ReadDouble();
		while (!IsDoubleInRange(Number, RangeLow, RangeHigh)) {
			cout << ErrorMessage;
			Number = ReadDouble();
		}
		cin.ignore(1, '\n');
		return Number;

	}
	
	// Check if a given date is valid
	static bool isDateValid(Date date) {
		return IsDoubleInRange(date.Month, 1, 12) and IsDoubleInRange(date.Day, 1, date.numberOfDaysInMonth());
	}

	static string ReadString() {
		string ret;
		getline(cin >> ws, ret);
		return ret;
	}
};

