

#include <iostream>
using namespace std;
bool checkPerfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum =sum + i;
		}
	}
	if (n == sum) {
		return true;
	}

		return false;
	}

int main()
{
	int n;
	while (true) {
		cin >> n;
		if (checkPerfect(n)) {
			cout << "Perfect number!!" << endl;

		}
		else {
			cout << "Not Perfect :(" << endl;
		}
	}
}
