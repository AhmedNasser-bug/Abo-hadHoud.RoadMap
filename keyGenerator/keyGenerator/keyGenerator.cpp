// keyGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int RndNum(int from, int to) {
    return rand() % (to - from + 1) + from;
}
string RandWord(int length){
    string s = "";
    for (int i = 0; i < length; i++) {
        s = s + char(RndNum(65  , 90));
    }
    return s;
}
string RndKey(int length) {
    string s = "";
    for (int i = 0; i < length; i++) {
        s = s + RandWord(4)+ "-";
    }
    s[(length * 5) - 1] = ' ';
    return s;

}

int main()
{
    srand((unsigned)time(NULL));
    int l;
    cin >> l;
    for (int i = 0; i < l; i++) {
        cout << "key[" <<i << "] : " +  RndKey(4) << endl;
    }
}

