#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include "Date.h"

typedef long long lli;

using namespace std;


class Utils
{

public:
	 // Random index enum between: digits, capital letter, small letter, special, mix
	enum enCharType{Digit, Special, CapitalLetter, SmallLeter, MixChar};

	 // Seed randoms 
	static void Srand() {
		srand((unsigned)time(NULL));
	 }
	
	// Random number between low and high (inclusive)
	static long long int RandomNumber(long long int Low, long long int High) {
		return rand() % (High - Low + 1) + Low;
	}
	
	// Random Character between: digits, capital letter, small letter, special, mix
	static char RandomChar(enCharType CharType) {
		switch (CharType)
		{
		case Utils::Digit:
			return char(RandomNumber(48, 57));
			break;
		case Utils::Special:
			return char(RandomNumber(33, 47));
			break;
		case Utils::CapitalLetter:
			return char(RandomNumber(48, 57));
			break;
		case Utils::SmallLeter: 
			return char(RandomNumber(97, 122));
			break;
		default:
			return char(RandomNumber(33, 122));
		}
	}
	
	// Generate Word , with characters consists of: digits, capital letter, small letter, special, mix
	static string RandomWord(size_t Length, enCharType CharType) {
		string s = "";
		for (size_t i = 0; i < Length; i++) {
			s = s + RandomChar(CharType);
		}
		return s;
	}
	
	// Generate Key , with characters consists of: digits, capital letter, small letter, special, mix
	 static string GenerateKey(int Length, enCharType CharType) {
		 string s = "";
		 for (int i = 0; i < Length; i++) {
			 s = s + RandomWord(4, CharType) + "-";
		 }
		 s[(Length * 5) - 1] = ' ';
		 return s;

	 }
	
	 // Generate Keys , with characters consists of: digits, capital letter, small letter, special, mix
	 static void GenerateKeys(int NumberOfKeys, int LengthOfKey, enCharType CharType) {
		 for (int keyNum = 1; keyNum <= NumberOfKeys; keyNum++) {
			 printf("Ket[%d]: %s", keyNum, GenerateKey(LengthOfKey, CharType).c_str());
		 }
	}
	 
	 // Swap function for int, bool, string, char, Date
	 static void Swap(lli& Num1, lli& Num2) {
		 lli temp = Num1;
		 Num1 = Num2;
		 Num2 = temp;
	}
	 
	 // Swap function for string
	 static void Swap(string& Num1, string& Num2) {
		 string temp = Num1;
		 Num1 = Num2;
		 Num2 = temp;
	 }
	 
	 // Swap function for char
	 static void Swap(char& Num1, char& Num2) {
		 char temp = Num1;
		 Num1 = Num2;
		 Num2 = temp;
	 }
	 
	 // Swap function for  bool
	 static void Swap(bool& Num1, bool& Num2) {
		 bool temp = Num1;
		 Num1 = Num2;
		 Num2 = temp;
	 }
	 
	 // Swap function for  Date
	 static void Swap(Date& Num1, Date& Num2) {
		 Date temp = Num1;
		 Num1 = Num2;
		 Num2 = temp;
	 }
	 
	 template <typename T>
	 // Shuffle an iterable 
	 static void Shuffle(T Array[], size_t Length) {
		 for (int CurIndex = 0; CurIndex < Length; CurIndex++) {
			 Swap(Array[RandomNumber(0,Length-1 )], Array[RandomNumber(0, Length-1)]);
		 }
	 }

	 template <typename T>
	 // Shuffle an iterable
	 static void Shuffle(vector<T> Vector, size_t Length) {
		 for (size_t CurIndex = 0; CurIndex < Length; CurIndex++) {
			 Swap(Vector[RandomNumber(0, Length - 1)], Vector[RandomNumber(0, Length - 1)]);
		 }
	 }

	 // Shuffle an iterable
	 static void Shuffle(string Array, size_t Length) {
		 for (size_t CurIndex = 0; CurIndex < Length; CurIndex++) {
			 Swap(Array[RandomNumber(0, Length - 1)], Array[RandomNumber(0, Length - 1)]);
		 }
	 }
	 
	 // Fill array with random numbers parameters: array, length, range_low (inclusive) , range_high (inclusive)
	 static void FillArrayWithRandomNumber(lli* Arr, size_t Length,size_t RangeLow,size_t RangeHigh) {
		 for (size_t i = 0; i < Length; i++) {
			 Arr[i] = RandomNumber(RangeLow, RangeHigh);
		 }
	 }
	 
	 // Fill array with random words, parameters:  array, array_length, character_types , string_length
	 static void FillArrayWithRandomWord(string* Arr, size_t Length, enCharType CharType, size_t StringLength) {
		 for (size_t CurElementIndex = 0; CurElementIndex < Length; CurElementIndex++) {
			 Arr[CurElementIndex] = RandomWord(StringLength, CharType);
		 }
	 }
	 
	 // Fill array with random keys, parameters:  array, array_length, character_types 
	 static void FillArrayWithKeys(string* Arr, int Length, enCharType CharType) {
		 for (int CurElementIndex = 0; CurElementIndex < Length; CurElementIndex++) {
			 Arr[CurElementIndex] = GenerateKey(4, CharType) ;
		 }
	 }
	 
	 // Print X number of tabs
	 static void Tabs(int x) {
		 while (x--) {
			 cout << "   ";
		 }
	 }
	 
	 // Encrypt text using caesar cipher, raises an exception if the key is negative
	 static string Encrypted(string Text,size_t Key) {
		 for (size_t i = 0; i < Text.size(); i++) {
			 Text[i] = char((int(Text[i]) + Key));
		 }
		 return Text;
	 }
	 
	 // Decrypt text using caeser cipher
	 static string Decrypted(string EncryptedText,size_t Key) {
		 for (size_t i = 0; i < EncryptedText.size(); i++) {
			 EncryptedText[i] = char((int(EncryptedText[i]) - Key));
		 }
		 return EncryptedText;
	 }


	 
	 static int* Pcast_I(void* p) { return static_cast<int*>(p); }
	 static char* Pcast_C(void* p) { return static_cast<char*>(p); }
	 static float* Pcast_F(void* p) { return static_cast<float*>(p); }
	 static string* Pcast_S(void* p) { return static_cast<string*>(p); }
	 static bool* Pcast_B(void* p) { return static_cast<bool*>(p); }

     // prints a vector elements (What did you expect) 
	 template <typename Generic>
	 static void PrintVector(vector<Generic>& v) {
		 for (int i = 0; i < v.size(); i++) {
			 cout << v[i] << "\n";
		 }
	 }

     // Counts the number of digits in a number
     static int CountnumLength(lli num) {
         if (num == 0) {
             return 0;
         }
         int count = 0;
         while (num >= 1) {
             num /= 10;
             count++;
         }
         return count;
     }

     // Reverse the order of digits of a given number
     static lli ReverseNum(lli num) {
         lli  Reversed = 0;
         while (num > 0) {
             int LastDigit = num % 10;
             num = num / 10;
             Reversed = Reversed * 10 + LastDigit;

         }
         return Reversed;


     }

     // Returns the first X digits of a given number
     static lli GetFirstXdigits(lli num, int x) {
         lli  Reversed = 0;
         int length = CountnumLength(num);
         while (length != x) {

             num = num / 10;
             length = CountnumLength(num);
         }
         return num;


     }
     // Print the given number in its text form
     static void numToText(int64_t num) {
         int length = CountnumLength(num);


         //base case
         if (length == 2) {

             switch (num)
             {
             case 10:
                 printf("ten ");
                 return;
                 break;
             case 11:
                 printf("eleven ");
                 return;
                 break;
             case 12:
                 printf("twelve ");
                 return;
                 break;
             case 13:
                 printf("thirteen ");
                 return;
                 break;
             case 14:
                 printf("fourteen ");
                 return;
                 break;
             case 15:
                 printf("fifteen ");
                 return;
                 break;
             case 16:
                 printf("sixteen ");
                 return;
                 break;
             case 17:
                 printf("seventeen ");
                 return;
                 break;
             case 18:
                 printf("eighteen ");
                 return;
                 break;
             case 19:
                 printf("nineteen ");
                 return;
                 break;
             default:
                 break;
             }
             num = ReverseNum(num);
             switch (num % 10)
             {
             case 2:
                 printf("twenty ");
                 num /= 10;
                 numToText(num);
                 return;
             case 3:
                 printf("thirty ");
                 num /= 10;
                 numToText(num);
                 return;
             case 4:
                 printf("fourty ");
                 num /= 10;
                 numToText(num);
                 return;
             case 5:
                 printf("fifty ");
                 num /= 10;
                 numToText(num);
                 return;
             case 6:
                 printf("sixty ");
                 num /= 10;
                 numToText(num);
                 return;
             case 7:
                 printf("seventy ");
                 num /= 10;
                 numToText(num);
                 return;
             case 8:
                 printf("eighty ");
                 num /= 10;
                 numToText(num);
                 return;
             case 9:
                 printf("ninety ");
                 num /= 10;
                 numToText(num);
                 return;
             default:
                 break;
             }
         }
         //base case
         if (length == 1) {
             switch (num)
             {
             case 1:
                 printf("one ");
                 break;
             case 2:
                 printf("two ");
                 break;
             case 3:
                 printf("three ");
                 break;
             case 4:
                 printf("four ");
                 break;
             case 5:
                 printf("five ");
                 break;
             case 6:
                 printf("six ");
                 break;
             case 7:
                 printf("seven ");
                 break;
             case 8:
                 printf("eight ");
                 break;
             case 9:
                 printf("nine ");
                 break;
             default:
                 break;
             }
             return;
         }
         if (length == 3) {
             numToText(GetFirstXdigits(num, 1));
             cout << "hundred ";
             num = ReverseNum(num);
             num /= 10;
             num = ReverseNum(num);
             numToText(num);
             return;
         }
         if (length == 4 or length == 5 or length == 6) {
             num = ReverseNum(num);
             switch (length)
             {
             case 4:
                 numToText(num % 10);
                 cout << "thouthand ";
                 num /= 10;
                 num = ReverseNum(num);
                 numToText(num);
                 break;
             case 5:

                 numToText(GetFirstXdigits(ReverseNum(num), 2));
                 cout << "thouthand ";
                 num /= 100;
                 num = ReverseNum(num);
                 numToText(num);
                 break;
             case 6:
                 numToText(GetFirstXdigits(ReverseNum(num), 3));
                 cout << "thousand ";
                 num /= 1000;
                 num = ReverseNum(num);
                 numToText(num);
                 break;
             default:
                 break;
             }
             return;

         }
         if (length == 7 or length == 8 or length == 9) {
             num = ReverseNum(num);
             switch (length)
             {
             case 7:
                 numToText(num % 10);
                 cout << "million ";
                 num /= 10;
                 num = ReverseNum(num);
                 numToText(num);
                 break;
             case 8:
                 numToText(GetFirstXdigits(ReverseNum(num), 2));
                 cout << "million ";
                 num /= 100;
                 num = ReverseNum(num);
                 numToText(num);
                 break;
             case 9:
                 numToText(GetFirstXdigits(ReverseNum(num), 3));
                 cout << "million ";
                 num /= 1000;
                 num = ReverseNum(num);
                 numToText(num);
                 break;
             default:
                 break;
             }
             return;

         }



     }
};

