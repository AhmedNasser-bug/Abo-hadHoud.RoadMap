#pragma once
#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include<map>
#define Sep "/--/"

using namespace std;

struct stClient {
    string PinCode;
    string AccountNumber;
    string Name;
    string Phone;
    unsigned int AccountBalance;
    
};
namespace myLib {
   
    vector<string> WordsOf(string S1, string seprator = " ") {
        vector<string> vString; short pos = 0; string sWord;
        // define a string variable 
        // use find() function to get the position of the delimiters 
        while ((pos = S1.find(seprator)) != std::string::npos) 
        {         sWord = S1.substr(0, pos); // store the word 
        if (sWord != "")
        {    vString.push_back(sWord);         } 
        S1.erase(0, pos + seprator.length());       }
        if (S1 != "")  
        {         vString.push_back(S1); // it adds last word of the string. 
        } return vString;
    }    
    string TrimLeft(string S1) 
    { for (short i = 0; i < S1.length(); i++)
    { if (S1[i] != ' ')
    { return S1.substr(i, S1.length() - i); }
    } return""; } 
    string TrimRight(string S1)
    { for (short i = S1.length() - 1; i >= 0; i--)
    { if (S1[i] != ' ') 
    { return S1.substr(0, i + 1); }
    } return""; }
    bool VectorSearchbool(std::vector<char>& v, char target) { //make overloads for other datatypes
        for (char& x : v) {
            if (x == target)return true;
        }
        return false;
    }
    bool VectorSearchint(std::vector<int>& v, int target) { //make overloads for other datatypes
        for (int& x : v) {
            if (x == target)return true;
        }
        return false;
    }
    int ReadPositive() {
        while (true) {
            int n;
            std::cout << " PLEASE Enter a positive number : ";
            std::cin >> n;
            cin.ignore(1, '\n');

            if (n > 0) {
                return n;
            }

        }
    }
    void printRec(int m, int n) {
        if (m >= n) {
            std::cout << m << std::endl;

            printRec(m - 1, n);
        }
    }
    int sumRange(int lower, int end) {
        return ((end * (end + 1)) / 2) - (((lower - 1) * ((lower - 1) + 1)) / 2);
    }
    bool compareStrings(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();
        if (s1Size != s2Size) {
            return false;
        }
        else {
            for (int i = 0; i < s2Size; i++) {
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
    int power(int n, int m, int i = 1) {
        // Make sure m is positive and integer using assertion
        if (m == 0) {
            return 1;
        }
        if (m == 1) {
            return n;
        }
        if (m > 1) {

            return n * power(n, m - 1, i + 1);

        }
    }
    void fill2DArrayWithNum(int A[10][10]) {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                A[i][j] = i * j;
            }
        }
    }
    void fill2DArrayWithOrdNum(int A[3][3]) {
        int stop = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                A[i][j] = stop;
                stop++;
            }
        }
    }
    void fill2DArrayWithOrdNum(int A[4][4]) {
        int stop = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                A[i][j] = stop;
                stop++;
            }
        }
    }
    void fill2DArrayWithOrdNum(int A[5][5]) {
        int stop = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                A[i][j] = stop;
                stop++;
            }
        }
    }
    void print2DArr(int A[3][3], int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << A[i][j] << " ";
            }
            printf("\n");
        }
        printf("\n");
    }
    void print2DArr(int A[4][4], int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << A[i][j] << " ";
            }
            printf("\n");
        }
        printf("\n");
    }
    void print2DArr(int A[5][5], int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << A[i][j] << " ";
            }
            printf("\n");
        }
        printf("\n");
    }
    static int RandRange(int from, int to) {
        return rand() % (to - from + 1) + from;
    }
    void PrintArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " , ";
        }
    }
    void Transpose(int A[3][3], int rows, int cols, int increments = 0) {
        /*
        can be edited for further usage
        */
        if (rows == 2 && cols == 2) {
            int temp = A[increments + 1][increments];
            A[increments + 1][increments] = A[increments][1 + increments];
            A[increments][1 + increments] = temp;
        }
        else {
            for (int i = 1; i < cols; i++) {
                int temp = A[increments + i][0];
                A[increments + i][0] = A[increments][i];
                A[increments][i] = temp;
            }
            Transpose(A, --rows, --cols, ++increments);
        }

    }
    void PrintVector(vector<int>& v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << "\n";
        }
    }
    template <typename Generic>
    void PrintVector(vector<Generic>& v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << "\n";
        }
    }
    
    int max(string list) {
        int  Max = int(list[0] - '0');
        for (int x = 0; x < list.size(); x++) {
            if (int(list[x] - '0') > Max) {
                Max = int(list[x] - '0');
            }
        }
        return Max;
    }
    static vector<int>  frequncy(string list) {  // frequency array maker from string
        vector<int> freq_array(max(list) + 9);

        for (int i = 0; i < list.size(); i++) {
            int x = int(list[i] - '0');
            freq_array[x] += 1;

        }
        return freq_array;
    }
    int GetIndex_str(char test, string testingOn) {
        for (int i = 0; i < testingOn.length(); i++) {
            if (testingOn[i] == test) {
                return i;

            }

        }
        return -1;
    }
    void SRand() {
        srand((unsigned)time(NULL));

    }
    void FillArrayWithRand(int Arr[100], int length) {

        for (int i = 0; i < length; i++) {
            Arr[i] = RandRange(0, 100);
        }
    }
    void Fill2dArrRand(int Arr[3][3]) {
        for (int i = 0; i < 3; i++) {
            FillArrayWithRand(Arr[i], 3);
        }
    }
    void FillArrayWithRandOdds(int Arr[100], int length) {
        int i = 0;
        while (i < length) {
            int  n = RandRange(-100, 100);
            if (n % 2 != 0) {
                Arr[i] = n;
                i++;
            }
        }
    }
    int arrSum(int* A, int length) {
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += *(A + i);
        }
        return sum;
    }
    void arrSum2D(int A[3][3]) {
        for (int i = 0; i < 3; i++) {
            printf("Sum of %d Row : %d", i + 1, arrSum(A[i], 3));
            printf("\n");
        }
    }
    int arrSum2D(int A[3][3], bool RETURNSUM) {
        
        int s = 0;
        for (int i = 0; i < 3; i++) {
            s += arrSum(A[i], 3);
        }
        return s;
    }
    bool areEqual(int A1[3][3], int A2[3][3]) {
        return arrSum2D(A1, true) == arrSum2D(A2, true);
    }
    bool areTypical(int A1[3][3], int A2[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A1[i][j] != A2[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isScalar(int A[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 2 && j == 2))) {
                    if (A[i][j] > 0)return false;
                }
            }
        }
        return A[0][0] > 1 && A[1][1] > 1 && A[2][2] > 1;
    }
    bool Min2D(int A[3][3]) {
        int min = INT32_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] < min) {
                    min = A[i][j];
                }
            }
        }
        return min;

    }
    bool Max2D(int A[3][3]) {
        int max = INT32_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] > max) {
                    max = A[i][j];
                }
            }
        }
        return max;

    }
    bool isPalindrom2D(int A[3][3]) {
        for (int i = 0; i < 3; i++) {
            if (A[i][0] != A[i][2]) {
                return false;
            }
        }
        return true;
    }
    bool isIdentity(int A[3][3]) {
        if (arrSum2D(A, true) > 3)return false;
        return A[0][0] == 1 && A[1][1] == 1 && A[2][2] == 1;
    }
    void Print_midRow(int A[3][3]) {
        for (int i = 0; i < 3; i++) {
            cout << A[1][i] << endl;
        }
        printf("\n");
    }
    void Print_midCol(int A[3][3]) {
        for (int i = 0; i < 3; i++) {
            cout << A[i][1] << endl;
        }
        printf("\n");
    }
    void arrSum2Dcols(int A[3][3])
    {
        int sum;
        for (int i = 0; i < 3; i++) {
            sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += A[j][i];
            }
            printf("Sum of %d Column : %d", i + 1, sum);
            printf("\n");
        }
    }
    int Count(int A[3][3], int target) {
        int c = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] == target)c++;
            }
        }
        return c;
    }
    int Count(int* A, int target, int length) {
        int c = 0;
        for (int i = 0; i < length; i++) {
            if (A[i] == target)c++;
        }
        return c;
    }
    int isSparse(int A[3][3]) {
        return Count(A, 0) >= 5;
    }
    int Found2D(int A[3][3], int target) {
        return Count(A, target) > 0;
    }
    vector<int> Intersection(int A1[3][3], int  A2[3][3]) {
        vector<int> intersection;
        int c = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (Count(A2, A1[i][j]) > 0 && VectorSearchint(intersection, A1[i][j]) != true) {
                    intersection.push_back(A1[i][j]);
                }
            }
        }
        return intersection;
    }
    void FillarrSum2Dcols(int A[3][3], int A2[3]) {
        int sum;
        for (int i = 0; i < 3; i++) {
            sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += A[j][i];
            }
            A2[i] = sum;
        }
    }
    void FillarrSum2D(int A[3][3], int A2[3]) {
        for (int i = 0; i < 3; i++) {
            A2[i] = arrSum(A[i], 3);
        }
    }
    int CountPositive(int Arr[100], int length) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (Arr[i] > 0)count++;

        }
        return count;
    }
    int CountnumLength( int num) {
        int count = 0;
        while (num >= 1) {
            num /= 10;
            count++;
        }
        return count;
    }
    int CountNeggative(int Arr[100], int length) { // question 45
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (Arr[i] < 0)count++;

        }
        return count;
    }
    int absolute(int num) {//question 46
        if (num > 0) {
            return num;
        }
        else {
            return num * -1;
        }

    }
    float GetFractionOf(float num) {
        return num - int(num);
    }
    int myRound(float num) {
        if (abs(GetFractionOf(num)) >= 0.5 && int(num) < 0) {
            return int(num) - 1;
        }
        else if (abs(GetFractionOf(num)) < 0.5 && int(num) < 0) {
            return int(num);

        }
        if (GetFractionOf(num) < 0.5) {
            return int(num);
        }
        else {
            return int(num) + 1;
        }

    }
    int myFloor(float num) {
        if (int(num) < 0) {
            return int(num) - 1;
        }
        if (num > 0) {
            return int(num);
        }
        return 0;
    }
    int myCeil(float num) {

        if (abs(GetFractionOf(num)) > 0) {
            if (int(num) < 0) {
                return int(num);
            }
            if (num > 0) {
                return int(num) + 1;
            }
        }
        return (int)num;
    }
    double mySqrt(float num) {
        return pow(num, 0.5);
    }
    string RandWord(int length) {
        string s = "";
        for (int i = 0; i < length; i++) {
            s = s + char(RandRange(65, 90));
        }
        return s;
    }
    string RndKey(int length) {
        string s = "";
        for (int i = 0; i < length; i++) {
            s = s + RandWord(4) + "-";
        }
        s[(length * 5) - 1] = ' ';
        return s;

    }
    int ReverseNum(int num) {
        int  Reversed = 0;
        while (num > 0) {
            int LastDigit = num % 10;
            num = num / 10;
            Reversed = Reversed * 10 + LastDigit;

        }
        return Reversed;


    }
    
    void printFileContent(string fileName) {
        fstream File;
        File.open(fileName, ios::in);
        if (File.is_open()) {
            string line;
            while (getline(File, line)) {
                cout << line << "\n";
            }
            File.close();
        }
    }
    void ImportDataToVec(string FileLocation, vector<string>& TheVectorThatWillHaveTheFileContentsUsingPush_Back) {
        fstream File;
        File.open(FileLocation, ios::in);
        if (File.is_open()) {
            string line;
            while (getline(File, line)) {
                TheVectorThatWillHaveTheFileContentsUsingPush_Back.push_back(line);
            }
            File.close();
        }
    }
    
    void SaveVecToFile(string FilePath, vector<string>& Vector) {
        fstream fl;
        fl.open(FilePath, ios::out);
        if (fl.is_open()) {
            for (string& x : Vector) {
                if (x != "")fl << x << endl;
            }
            fl.close();
        }

    }
    void DeleteRecordfromFile(string FilePath, string record) {
        vector<string> v;
        ImportDataToVec(FilePath, v);
        for (string& x : v) {
            if (x == record) {
                x = "";
            }
        }
        SaveVecToFile(FilePath, v);
    }
    void UpdateRecordfromFile(string FilePath, string record, string replacement) {
        vector<string> v;
        ImportDataToVec(FilePath, v);
        for (string& x : v) {
            if (x == record) {
                x = replacement;
            }
        }
        SaveVecToFile(FilePath, v);
    }
  
 
    std::vector<char> visited;
    char ClosestNode(map<char, int> graph)
    {
        map<char, int>::iterator nItr;
        char ClosestNode = 'x';
        int min = INT32_MAX;
        for (nItr = graph.begin(); nItr != graph.end(); ++nItr) {
            if (nItr->second < min && !VectorSearchbool(visited, nItr->first)) {
                min = nItr->second;
                ClosestNode = nItr->first;

            }
        }
        return ClosestNode;
    }
    void VisualiseWGraph(map<char, map<char, int>> graph) {
        map<char, map<char, int>>::iterator itr;
        for (itr = graph.begin(); itr != graph.end(); ++itr) {
            cout << itr->first << "-->";
            map<char, int>::iterator itr2;
            for (itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2) {
                printf("  %c : %d  ", itr2->first, itr2->second);
            }
            cout << "\n";
        }
    }
    void printPath(const map<char, char>& parent, char finalNode) {
        if (parent.find(finalNode) == parent.end()) {
            std::cout << "No path found from first node to " << finalNode << std::endl;
            return;
        }

        // Reconstruct the path by following the parent nodes
        vector<char> path;
        path.push_back(finalNode);
        char currentNode = finalNode;
        while (currentNode != '\0') { // Use a null character for source node
            auto it = parent.find(currentNode);
            if (it != parent.end()) {
                currentNode = it->second;
                path.push_back(currentNode);
            }
            else {
                currentNode = '\0';
            }
        }

        // Print the path in reverse order (final node to first node)
        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << "->";
        }
        cout << endl;
    }
    void Fibo(int seqs) {
        int fib1 = 0;
        int fib2 = 1;
        cout << fib1 << ",";
        for (int i = 0; i < seqs; i++) {
            int temp = fib2;
            fib2 = fib1 + fib2;
            fib1 = temp;
            cout << fib1 << ",";

        }
    }
    void RecursiveFibo(int limit, int fib1, int fib2) {
        if (limit > 0) {
            int temp = fib2;
            fib2 = fib1 + fib2;
            fib1 = temp;
            cout << fib1 << ",";
            RecursiveFibo(--limit, fib1, fib2);
        }
    }
    void printStringFirsts(string str) {
        if (int(str[0]) != int(' ')) cout << str[0] << endl;
        for (int i = 0; i < str.length(); i++) {

            if (int(str[i]) == int(' ')) {
                int itr2 = 1;
                while (int(str[i + itr2]) == int(' ')) {
                    itr2++;
                }
                cout << str[i + itr2] << endl;
            }
        }
    }
    char Upper(char c) {
        if (int(c) < 123 && int(c) > 96) {
            if (int(c) != int(' ')) { return char(int(c) - 32); }
        }
        else {
            if (int(c) != int(' ')) return c;
        }
    }
    char Lower(char c) {
        if (int(c) < 91 && int(c) > 64) {
            if (int(c) != int(' ')) { return char(int(c) + 32); }
        }
        else {
            if (int(c) != int(' ')) return c;
        }
    }
    bool isLower(char c) {
        if (int(c) < 123 && int(c) > 96) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isUpper(char c) {
        if (int(c) < 91 && int(c) > 64) {
            return true;
        }
        else {
            return false;
        }
    }
    int upperFreq(string S) {
        int c = 0;
        for (char& x : S)
        {
            if (isUpper(x)) {
                c++;
            }
        }
        return c;
    }
    int lowerFreq(string S) {
        int c = 0;
        for (char& x : S)
        {
            if (islower(x)) {
                c++;
            }
        }
        return c;
    }
    int FreqOf(char c, string s) {
        int counter = 0;
        for (char& x : s) {
            if (int(c) == int(x)) {
                counter++;
            }
        }
        return counter;
    }
    char Inverted(char c) {
        if (int(c) < 91 && int(c) > 64) {
            if (int(c) != int(' ')) { return char(int(c) + 32); }
        }
        else {
            if (int(c) != int(' ')) return char(int(c) - 32);
        }
    }
    bool isVowel(char c) {
        char vowels[] = { 'a' , 'o' , 'i' , 'e' , 'u' };
        for (char x : vowels) {
            if (int(x) == int(c) || int(Inverted(c)) == int(x))return true;
        }
        return false;
    }
    int FreqOfmatchCase(char c, string s) {
        int counter = 0;
        for (char& x : s) {
            if (int(c) == int(x) || int(Inverted(c)) == int(x)) {
                counter++;
            }
        }
        return counter;
    }
    int FreqOfVowel(string s) {
        int counter = 0;
        for (char& x : s) {
            if (isVowel(x)) {
                counter++;
            }
        }
        return counter;
    }
    void printVowels(string s) {
        for (char& x : s) {
            if (isVowel(x)) {
                cout << x << "  ";
            }
        }
    }
    void PringALLlower(string s) {
        cout << "all lower: " << endl;
        for (char& x : s) {
            cout << Lower(x);
        }
        cout << endl;
    }
    void PringALLInverted(string s) {
        cout << "all Inverted: " << endl;
        for (char& x : s) {
            cout << Inverted(x);
        }
        cout << endl;
    }
    void PringALLUpper(string s) {
        cout << "all upper : " << endl;
        for (char& x : s) {
            cout << Upper(x);
        }
        cout << endl;
    }
    string ALLlower(string s) {
        string ans = "";
        for (char& x : s) {
            string temp = "";
            temp[0] = Lower(x);
            ans.append(temp);
        }
        return ans;
    }
    string ALLInverted(string s) {
        string ans = "";
        for (char& x : s) {
            string temp = "";
            temp[0] = Inverted(x);
            ans.append(temp);
        }
        return ans;
    }
    string ALLUpper(string s) {
        string ans = "";
        for (char& x : s) {
            string temp = "";
            temp[0] = Upper(x);
            ans.append(temp);
        }
        return ans;
    }
    void printStringFirstUppers(string str) {
        if (int(str[0]) != int(' ')) { cout << Upper(str[0]); }
        for (int i = 1; i < str.length(); i++) {
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
    void printWords(string s) {
        int i = 0; bool space = false;
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
    int CountWords(string s) {
        int i = 1;
        int c = (int(s[0]) != int(' ')) ? 1 : 0;
        while (i < s.length()) {
            if (int(s[i - 1]) == int(' ') && int(s[i]) != int(' ')) {
                c++;
            }
            i++;
        }
        return c;
    }
    string reversedWords(string s) {
        vector<string> words = WordsOf(s); string ans = "";
        for (short i = words.size()-1; i >= 0; i--) {
            ans.append(words[i] + " ");
        }
        return ans;

    }
    string itrToStr(vector<string> v, string delim) {
        string ans;
        for (string& x : v) {
            ans.append(x + delim);
        }
        return ans.substr(0 , ans.length() - delim.length());
    }
    string itrToStr(string v[], short length, string delim) {
        string ans;
        for (short i = 0; i < length; i++) {
            ans.append(v[i] + delim);
        }
        return ans;
    }
    void replaceStrWord(string &s , string replacethis , string WithThis) {
       vector<string> words = WordsOf(s);
       for (short i = 0; i < words.size(); i++) {

            if (words[i] == replacethis) {
               words[i] = WithThis;
            }
       }
       s = itrToStr(words, " ");
    }
    void replaceStrWordUncased(string& s, string replacethis, string WithThis) {
        vector<string> words = WordsOf(s);
        for (short i = 0; i < words.size(); i++) {
            if ( ALLlower(words[i]) == replacethis || ALLUpper(words[i]) == replacethis) {
                words[i] = WithThis;
            }
        }
        s = itrToStr(words, " ");
    }
    string removedPunctuation(string s) {
        int cur = 0;
        for (char& c : s) {
            if (!((int(c) < 123 && int(c) > 96) || (int(c) < 91 && int(c) > 64)) && int(c) != int(' ')) {
                s[cur] ='\0';
            }
            cur++;
        }
        return s;
    }
    string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo) {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);      
            pos = S1.find(StringToReplace);//find next 
        } return S1;
    }
    void printStringFirstLowers(string str) {
            if (int(str[0]) != int(' ')) { cout << Lower(str[0]); }
            for (int i = 1; i < str.length(); i++) {
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
    string GetString() {
            //cout << "Enter String: ";
            string temp = "";
            while(temp == "")getline(cin, temp);
           //Alternative: getline(cin, temp);
            return temp;
        }
    int GetNum() {
        int n;
        cin >> n;
        cin.ignore(1, '\n');
        return n;
    }
    int GetPNum() {
        unsigned int n;
        cin >> n;
        while (n < 0) {
            cout << "Enter A positive: ";
            cin >> n;
        }
        cin.ignore(1, '\n');
        return n;
    }
    
    bool isLeapYear(short Year) {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    void printFullTime(short year) {
        if (isLeapYear(year)) {
            printf("months: %d \nweeks: %f\ndays: %d\nhours: %d\nminutes: %d\nseconds: %d", 12, 366 / 7.0, 366, 366 * 24, 366 * 24 * 60, 366 * 24 * 60 * 60);
        }
        else {
            printf("months: %d \nweeks: %f\ndays: %d\nhours: %d\nminutes: %d\nseconds: %d", 12, 365 / 7.0, 365, 365 * 24, 365 * 24 * 60, 365 * 60 * 24 * 60);
        }
    }
    short numberOfDaysInMonth(short month, short year) {
        if (month < 1 || month > 12) {
            return 0;
        }
        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        return (month == 2) ? ((isLeapYear(year)) ? 29 : 28) : arrdays[month - 1];

    }
    int numberOfhoursInMonth(short month, short year) {
        return numberOfDaysInMonth(month, year) * 24;
    }
    int numberOfMinutesinMonth(short month, short year) {
        return numberOfhoursInMonth(month, year) * 60;
    }
    int numberOfSecondsinMonth(short month, short year) {
        return numberOfMinutesinMonth(month, year) * 60;
    }
    void Dijkstra_Algo(map<char, map<char, int>>&graph, map<char, int>&costs, map<char, char>&parent) {
            map<char, map<char, int>>::iterator itr;
            char closestOne = ClosestNode(graph['s']);


            for (itr = graph.begin(); itr != graph.end(); ++itr) {

                int cost = costs[closestOne];
                map<char, int>::iterator neighbors;
                for (neighbors = graph[closestOne].begin(); neighbors != graph[closestOne].end(); ++neighbors) {
                    int newCost = graph[closestOne][neighbors->first] + cost;
                    if (newCost < costs[neighbors->first]) {
                        costs[neighbors->first] = newCost;
                        parent[neighbors->first] = closestOne;


                    }
                }
                visited.push_back(closestOne);
                closestOne = ClosestNode(costs);
            }
        }
    }


