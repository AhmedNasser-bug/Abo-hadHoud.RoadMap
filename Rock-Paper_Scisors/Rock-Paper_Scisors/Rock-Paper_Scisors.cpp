// Rock-Paper_Scisors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum enChoice
{
	Rock = 1, Paper = 2, Scisors = 3
};
static int RandRange(int from, int to) {
	return rand() % (to - from + 1) + from;
}
enChoice PcChoice() {
	int choice = RandRange(1, 3);
	switch (choice)
	{
	case(enChoice::Rock):
		return enChoice::Rock;
		break;
	case(enChoice::Paper):
		return enChoice::Paper;
		break;
	case(enChoice::Scisors):
		return enChoice::Scisors;
		break;
	default:
		break;
	}
}
enChoice ReadChoice() {
	cout << "Enter Choice 1 for rock  , 2 for paper , 3 for scisors \n";
	int x;
	cin >> x;
	
	switch (x)
	{
	case(enChoice::Rock):
		return enChoice::Rock;
		break;
	case(enChoice::Paper):
		return enChoice::Paper;
		break;
	case(enChoice::Scisors):
		return enChoice::Scisors;
		break;
	default:
		break;
	}
}

void compare(enChoice choice1, enChoice choice2) {
	if (choice1 == choice2) {
		cout << "tie";

	}
	else if (choice1 == enChoice::Paper && choice2 == enChoice::Rock) {
		cout << "You Win";
	}
	else if (choice1 == enChoice::Rock && choice2 == enChoice::Paper) {
		cout << "Pc Wins";
	}
	else if(choice1 == enChoice::Scisors && choice2 == enChoice::Rock){
		cout << "Pc Wins";
	}
	else if (choice2 == enChoice::Scisors && choice1 == enChoice::Rock) {
		cout << "You Win";
	}
	else if (choice1 == enChoice::Scisors && choice2 == enChoice::Paper) {
		cout << "You Win";
	}
	else if (choice2 == enChoice::Scisors && choice1 == enChoice::Paper) {
		cout << "Pc Wins";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	compare(ReadChoice(), PcChoice());
}

