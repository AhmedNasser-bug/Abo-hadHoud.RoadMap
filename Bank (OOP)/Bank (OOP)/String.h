#pragma once
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
class String 
{
private:
	string _val;
		
	static char Upper(char c) {
		if (int(c) < 123 && int(c) > 96) {
			if (int(c) != int(' ')) { return char(int(c) - 32); }
		}
		else {
			if (int(c) != int(' ')) return c;
		}
	}
	static char Lower(char c) {
		if (int(c) < 91 && int(c) > 64) {
			if (int(c) != int(' ')) { return char(int(c) + 32); }
		}
		else {
			if (int(c) != int(' ')) return c;
		}
	}
	static bool isLower(char c) {
		if (int(c) < 123 && int(c) > 96) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool isUpper(char c) {
		if (int(c) < 91 && int(c) > 64) {
			return true;
		}
		else {
			return false;
		}
	}
	static char Inverted(char c) {
		if (int(c) < 91 && int(c) > 64) {
			if (int(c) != int(' ')) { return char(int(c) + 32); }
		}
		else {
			if (int(c) != int(' ')) return char(int(c) - 32);
		}
	}
	static bool isVowel(char c) {
		char vowels[] = { 'a' , 'o' , 'i' , 'e' , 'u' };
		for (char x : vowels) {
			if (int(x) == int(c) || int(Inverted(c)) == int(x))return true;
		}
		return false;
	}
	static string itrToStr(vector<string> v, string delim) {
		string ans;
		for (string& x : v) {
			ans.append(x + delim);
		}
		return ans.substr(0, ans.length() - delim.length());
	}
	
public:
	// Constructor
	String() {
		_val = "";
	}
	String(const char* val) {
		_val = val;
	}
	String(string val) {
		_val = val;
	}
	
	// Returns the value of the string
	string GetVal() {
		return _val;
	}
	void SetVal(string val) {
		_val = val;
	}
	_declspec(property(put = SetVal, get = GetVal)) string val;

	// Appends another string to the current one
	void append(string s2) {
		_val += s2;
	}
	void append(String s2) {
		_val += s2.val;
	}

	// Adds a character to the end of the string
	void push_back(char c) {
		_val += c;
	}	

	// Returns the length of the string
	size_t length() {
		return _val.length();
	}
	
	// Returns the character found at the given index
	char at(size_t ind) {
		return _val[ind];
	}

	// Trims the string from all spaces from the left
	static string TrimLeft(string S1)
	{
		for (size_t i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		} return"";
	}
	string TrimLeft() {
		return TrimLeft(_val);
	}

	// Trims the string from all spaces from the right
	static string TrimRight(string S1)
	{
		for (long long i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		} return"";
	}
	string TrimRight() {
		return TrimRight(_val);
	}

	// Returns true if the strings are equals , returns false otherwise
	static bool isEqual(string s1, string s2) {
		size_t s1Size = s1.size();
		size_t s2Size = s2.size();
		if (s1Size != s2Size) {
			return false;
		}
		else {
			for (size_t i = 0; i < s2Size; i++) {
				if (s1[i] != s2[i]) {
					return false;
				}
				else if (i == s1Size && s1[i] == s2[i]) {
					return true;

				}
				else {
					continue;
				}

			}
			return true;
		}
	}
	bool isEqual(string s2) {
		return isEqual(_val, s2);
	}
	bool isEqual(const char* s2) {
		return isEqual(_val, s2);
	}
	bool isEqual(String s2) {
		return isEqual(_val, s2.val);
	}

	// Returns the words found in the string
	static vector<string> WordsOf(string S1, string seprator = " ") {
		vector<string> vString; size_t pos = 0; string sWord;
		// define a string variable 
		// use find() function to get the position of the delimiters 
		while ((pos = S1.find(seprator)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word 
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + seprator.length());
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string. 
		} return vString;
	}
	vector<string> WordsOf(string seprator = " ") {
		return WordsOf(_val, seprator);
	}

	// Returns the frequency of upper letters in the string
	static int upperFreq(string S) {
		int c = 0;
		for (char& x : S)
		{
			if (isUpper(x)) {
				c++;
			}
		}
		return c;
	}
	int upperFreq() {
		return upperFreq(_val);
	}

	// Returns the frequency of lower letter in the string
	static int lowerFreq(string S) {
		int c = 0;
		for (char& x : S)
		{
			if (islower(x)) {
				c++;
			}
		}
		return c;
	}
	int lowerFreq() {
		return lowerFreq(_val);
	}

	// Returns the frequency of the given character in the string
	static int FreqOf(char c, string s) {
		int counter = 0;
		for (char& x : s) {
			if (int(c) == int(x)) {
				counter++;
			}
		}
		return counter;
	}
	int FreqOf(char c) {
		return FreqOf(c, _val);
	}
	
	// Returns the frequency of the given character in the string (not case sensetive)
	static int FreqOfmatchCase(char c, string s) {
		int counter = 0;
		for (char& x : s) {
			if (int(c) == int(x) || int(Inverted(c)) == int(x)) {
				counter++;
			}
		}
		return counter;
	}
	int FreqOfmatchCase(char c) {
		return FreqOfmatchCase(c, _val);
	}

	// Returns the frequency of vowels in the string
	static int FreqOfVowel(string s) {
		int counter = 0;
		for (char& x : s) {
			if (isVowel(x)) {
				counter++;
			}
		}
		return counter;
	}
	int FreqOfVowel() {
		return FreqOfVowel(_val);
	}

	// Prints the vowels in the string
	static void printVowels(string s) {
		for (char& x : s) {
			if (isVowel(x)) {
				cout << x << "  ";
			}
		}
	}
	void printVowels() {
		printVowels(_val);
	}

	// Prints all lowercase letters in the string
	static void PrintAllLower(string s) {
		cout << "all lower: " << endl;
		for (char& x : s) {
			cout << Lower(x);
		}
		cout << endl;
	}
	void PrintAlllower() {
		PrintAllLower(_val);
	}

	// Print the string with all cases inverted
	static void PrintAllInverted(string s) {
		cout << "all Inverted: " << endl;
		for (char& x : s) {
			cout << Inverted(x);
		}
		cout << endl;
	}
	void PrintAllInverted() {
		PrintAllInverted(_val);
	}

	// Prints all of the string in uppercase 
	static void PrintAllUpper(string s) {
		cout << "all upper : " << endl;
		for (char& x : s) {
			cout << Upper(x);
		}
		cout << endl;
	}
	void PrintAllUpper() {
		PrintAllUpper(_val);
	}
	
	// Returns the string in all lowercase letters
	static string AllLower(string s) {
		string ans = "";
		for (char& x : s) {
			string temp = "";
			temp[0] = Lower(x);
			ans.append(temp);
		}
		return ans;
	}
	string AllLower() {
		return AllLower(_val);
	}

	// Returns the string in all uppercase letters
	static string AllUpper(string s) {
		string ans = "";
		for (char& x : s) {
			string temp = "";
			temp[0] = Upper(x);
			ans.append(temp);
		}
		return ans;
	}
	string AllUpper() {
		return AllUpper(_val);
	}

	// Returns the string in all inverted case letters
	static string AllInverted(string s) {
		string ans = "";
		for (char& x : s) {
			string temp = "";
			temp[0] = Inverted(x);
			ans.append(temp);
		}
		return ans;
	}
	string AllInverted() {
		return AllInverted(_val);
	}

	// Prints the string with all first letters uppercase
	static void printStringFirstUppers(string str) {
		if (int(str[0]) != int(' ')) { cout << Upper(str[0]); }
		for (size_t i = 1; i < str.length(); i++) {
			if (int(str[i]) == int(' ')) {
				int itr2 = 1;
				while (int(str[i + itr2]) == int(' ')) {
					itr2++;
				}
				int Spaces = 0;
				while (Spaces < itr2) {
					cout << " ";
					Spaces++;
				}
				cout << Upper(str[i + itr2]);
				i += itr2;
			}
			else {
				cout << str[i];
			}

		}
	}
	void printStringFirstUppers() {
		printStringFirstUppers(_val);
	}

	// Prints the words of a string seprated by spaces
	static void printWords(string s) {
		size_t i = 0; bool space = false;
		while (i < s.length()) {
			if (int(s[i]) != int(' ')) {
				cout << s[i];
				space = false;
			}
			else {
				if (not space)cout << endl;
				space = true;
			}
			i++;
		}
	}
	void printWords() {
		printWords(_val);
	}

	// Returns the number of words in a string seprated by spaces
	static int CountWords(string s) {
		size_t i = 1;
		int c = (int(s[0]) != int(' ')) ? 1 : 0;
		while (i < s.length()) {
			if (int(s[i - 1]) == int(' ') && int(s[i]) != int(' ')) {
				c++;
			}
			i++;
		}
		return c;
	}
	int CountWords() {
		return CountWords(_val);
	}

	// Returns a string with reversed words
	static string reversedWords(string s) {
		vector<string> words = WordsOf(s, " "); string ans = "";
		for (long long  i = words.size() - 1; i >= 0; i--) {
			ans.append(words[i] + " ");
		}
		return ans;

	}
	string reversedWords() {
		return reversedWords(_val);
	}

	// Replaces a word in a string
	static void replaceWord(string& s, string replacethis, string WithThis, string Seperator = " ") {
		vector<string> words = WordsOf(s, Seperator);
		for (size_t i = 0; i < words.size(); i++) {

			if (words[i] == replacethis) {
				words[i] = WithThis;
			}
		}
		s = itrToStr(words, " ");
	}
	void replaceWord(string replacethis, string WithThis, string Seperator = " ") {
		replaceWord(_val, replacethis, WithThis, Seperator);
	}

	// Replaces a word in a string (not case sensetive)
	static void replaceWordUncased(string& s, string replacethis, string WithThis, string Seperator = " ") {
		vector<string> words = WordsOf(s, Seperator);
		for (size_t i = 0; i < words.size(); i++) {
			if (isEqual(words[i], replacethis)) {
				words[i] = WithThis;
			}
		}
		s = itrToStr(words, " ");
	}
	void replaceWordUncased(string replacethis, string WithThis, string Seprator = " ") {
		replaceWordUncased(_val, replacethis, WithThis, Seprator);
	}
	
	// Replaces a substring in the string using a builtin function
	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo) {
		size_t pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
			pos = S1.find(StringToReplace);//find next 
		} return S1;
	}
	string ReplaceWordInStringUsingBuiltInFunction(string StringToReplace, string sRepalceTo) {
		return ReplaceWordInStringUsingBuiltInFunction(_val, StringToReplace, sRepalceTo);
	}

	// Returns a string with removed punctuation
	static string removedPunctuation(string s) {
		int cur = 0;
		for (char& c : s) {
			if (!((int(c) < 123 && int(c) > 96) || (int(c) < 91 && int(c) > 64)) && int(c) != int(' ')) {
				s[cur] = '\0';
			}
			cur++;
		}
		return s;
	}
	string removedPunctuation() {
		return removedPunctuation(_val);
	}

	// Prints the string with all first letters lowercase
	static void printStringFirstLowers(string str) {
		if (int(str[0]) != int(' ')) { cout << Lower(str[0]); }
		for (size_t i = 1; i < str.length(); i++) {
			if (int(str[i]) == int(' ')) {
				int itr2 = 1;
				while (int(str[i + itr2]) == int(' ')) {
					itr2++;
				}
				int Spaces = 0;
				while (Spaces < itr2) {
					cout << " ";
					Spaces++;
				}
				cout << Lower(str[i + itr2]);
				i += itr2;
			}
			else {
				cout << str[i];
			}

		}
	}
	void printStringFirstLowers() {
		printStringFirstLowers(_val);
	}

	friend ostream& operator<<(std::ostream& out, const String& str);

	// Returns the given string multiplied by x
	static inline string MultiplyString(string String, size_t Multiple) {
		string Self = String;
		while (Multiple--) {
			String += Self;
		}
		return String;
	}

	// modifies the string using caesar cipher 
	static inline string Encrypted(string Word, short Key) {
		// modify the string
		for (size_t index = 0; index < Word.size(); index++) {
			Word[index] = char(int(Word[index]) + Key);
		}

		return Word;
	}
	inline void Encrypted(short key) {
		_val = Encrypted(_val, key);
	}

	// modify the string using caesar cipher
	static inline string Decrypted(string Word, short Key) {
		// modify the string
		for (size_t index = 0; index < Word.size(); index++) {
			Word[index] = char(int(Word[index]) - Key);
		}

		return Word;
	}
	inline void Decrypt(short key) {
		_val = Decrypted(_val, key);;
	}
};
ostream & operator<<(std::ostream & out, const String & str)
{
	// do your output here.
	return out << str._val;
}


