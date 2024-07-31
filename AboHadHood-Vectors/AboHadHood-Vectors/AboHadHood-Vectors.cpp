// AboHadHood-Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "C:\Users\orginal\source\repos\Header1.h"
#include <string>
using namespace myLib;
struct stEmployee
{
	int id;
	string name;
	string role;
};
int main()
{
	
	vector<stEmployee> vec;
	int n;
	while (n != 0) {
		stEmployee temp;
		cout << "enter Employee id \n";
		cin >> temp.id;
		cout << "enter Employee name \n";
		getline(cin , temp.name);
		cout << "Enter employee role \n";
		getline(cin, temp.role);
		vec.push_back(temp);
		printf("to add again press any key , to exit insert 0: ");
		cin >> n;
	}
}
