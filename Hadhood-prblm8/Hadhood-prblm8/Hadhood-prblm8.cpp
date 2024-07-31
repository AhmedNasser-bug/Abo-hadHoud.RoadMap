// Hadhood-prblm8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string number;
	char freqOF;
	cin >> number;
	cin >> freqOF;
	int frequency = 0;
	for (int i = 0; i < number.length(); i ++) {
		if (number[i] == freqOF) {
			frequency++;
		}
	}
	cout << frequency;

	

}

