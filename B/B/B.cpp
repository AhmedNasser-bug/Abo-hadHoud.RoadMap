// B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "C:\Users\orginal\source\repos\Header1.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include<map>
#define Sep "/--/"
#define path "Clients.txt"
enum enMainMenueOptions{ eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,eTransactionsList = 6 ,eExit = 7 };
enum enTrasactionsOptions{Deposit = 1 , withdraw = 2, showBalances = 3 , back = 4};
using namespace myLib;
bool isInRecord(string accNum, string filePath);
stClient newClient();
stClient newClient(string stringRepr, string sep);
void ImportDataToVec(string FileLocation, vector<stClient>& TheVectorThatWillHaveTheFileContentsUsingPush_Back) {
    fstream File;
    File.open(FileLocation, ios::in);
    if (File.is_open()) {
        string line;
        while (getline(File, line)) {
            TheVectorThatWillHaveTheFileContentsUsingPush_Back.push_back(newClient(line, Sep));
        }
        File.close();
    }
}


stClient newClient() {
    stClient c;
    cout << "enter PinCode: ";
    c.PinCode = GetString();
    cout << "enter Account Number: ";
    c.AccountNumber = GetString();
    cout << "enter Name: ";
    c.Name = GetString();
    cout << "enter Phone: ";
    c.Phone = GetString();
    cout << "enter Account Balance: ";
    cin >> c.AccountBalance;
    cin.ignore(1, '\n');

    return c;
}


stClient newClient(string stringRepr, string sep) {
    stClient c;
    vector<string> data = WordsOf(stringRepr, sep);
    c.Name = data[0];
    c.Phone = data[1];
    c.AccountNumber = data[2];
    c.PinCode = data[3];
    c.AccountBalance = stoi(data[4]);

    return c;
}


string strClient(stClient& c, string seprator) {
    string ret = "";
    ret.append(c.Name + seprator);
    ret.append(c.Phone + seprator);
    ret.append(c.AccountNumber + seprator);
    ret.append(c.PinCode + seprator);
    ret.append(to_string(c.AccountBalance));
    return ret;
}


string newStrClient() {
    stClient c;
    cout << "enter PinCode: ";
    c.PinCode = GetString();
    cout << "enter Account Number: ";
    c.AccountNumber = GetString();
    while (isInRecord(c.AccountNumber, path)) {
        printf("Already exists enter a different one: ");
        c.AccountNumber = GetString();
        
    }
    cout << "enter Name: ";
    c.Name = GetString();
    cout << "enter Phone: ";
    c.Phone = GetString();
    cout << "enter Account Balance: ";
    cin >> c.AccountBalance;
    cin.ignore(1, '\n');


    return strClient(c, Sep);
}

stClient GetByAccNum(string accNum ,  string filePath) {
    
    vector<stClient> vClients;
    bool found = false;
    ImportDataToVec(filePath, vClients);
    for (stClient client : vClients) {
        if (accNum == client.AccountNumber) {
            return client;
            
        }
    }
    cout << "Client not found!!" << endl;
    cout << "Press any key to go back...";
    system("pause>0");
    
    
}

void ShowRecord(stClient client) {

    printf("| %-15s", client.AccountNumber.c_str());
    printf("| %-10s", client.PinCode.c_str());
    printf("| %-40s", client.Name.c_str());
    printf("| %-12s", client.Phone.c_str());
    printf("| %-12d\n", client.AccountBalance);
}


void ShowBalance(stClient client) {

    printf("| %-15s", client.AccountNumber.c_str());
    printf("| %-40s", client.Name.c_str());
    printf("| %-12d\n", client.AccountBalance);
}


void UpdateClientsfile() {
    vector<string> Records  ; bool open = true;
    ImportDataToVec(path, Records);
    cout << "Add records: " << endl;
    while (open) {
       
        Records.push_back(newStrClient());
        cout << "Add more? 1 yes , 0 no:  ";
        open = GetNum();


    }
    SaveVecToFile("Clients.txt", Records);
    cout << "\nPress any key to go back...";
    system("pause>0");
}


void ShowFullRecord(string RecordPath) {
    vector<string> Records;
    ImportDataToVec(RecordPath, Records);

    cout << "\n\t\t\t\t\tClient List (" << Records.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    printf("| %-15s", "Account Number");
    printf("| %-10s", "Pin Code");
    printf("| %-40s", "Client Name");
    printf("| %-12s", "Phone");
    printf("| %-12s", "Balance");

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (string cl : Records) {
        ShowRecord(newClient(cl, Sep));
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "Press any key to go back...";
    system("pause>0");
}


void showBalanceList(string RecordPath) {
    vector<string> Records;
    ImportDataToVec(RecordPath, Records);
    cout << "\n\t\t\t\t\tClient List (" << Records.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    printf("| %-15s", "Account Number");
    printf("| %-40s", "Client Name");
    printf("| %-12s", "Balance");

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (string cl : Records) {
        ShowBalance(newClient(cl, Sep));
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "Press any key to go back...";
    system("pause>0");
}


void Withdraw(stClient  Client) {
    string old = strClient(Client, Sep);
    cout << "Available Balance : " << Client.AccountBalance <<"\n Enter Amount : ";
    unsigned int amount = GetRangedNum(0 , Client.AccountBalance);
    Client.AccountBalance -= amount;
    cout << "withdrawal done!!\nAvailable Balance: " << Client.AccountBalance;
    UpdateRecordfromFile(path , old , strClient(Client , Sep));
    cout << "\nPress any key to go back...";
    system("pause>0");
}


void deposit(stClient Client) {
    string old = strClient(Client, Sep);
    cout << "Available Balance : " << Client.AccountBalance << "\n Enter Amount : ";
    unsigned int amount = GetPNum();
    Client.AccountBalance += amount;
    cout << "depsit done!!\nAvailable Balance: " << Client.AccountBalance;
    UpdateRecordfromFile(path, old, strClient(Client, Sep));
    cout << "\nPress any key to go back...";
    system("pause>0");
}


void TransactionsLst() {
    system("cls");
    printf("==================================================================\n                           Transactions\n==================================================================");
    cout << "\n[1] Deposit \n[2] Withdraw\n[3] Show Balance list\n[4] Back to MainMenu \nenter choice: ";
    int choice = GetRangedNum(0, 5);
    string accNum;
    switch (choice) {
    case enTrasactionsOptions::Deposit:
        system("cls");
        printf("==================================================================\n                           Deposit\n==================================================================\n");
        cout << "Enter Account number: ";
        accNum = GetString();
        while (!isInRecord(accNum, path)) {
            cout << "Not Found!!! \n[1] Try again\n[2] Go back";
            choice = GetRangedNum(0 , 3);
            if (choice == 1) {
                accNum = GetString();
            }
            else {
                TransactionsLst();
            }
        }
        deposit(GetByAccNum(accNum, path));
        TransactionsLst();
        
        break;
    case enTrasactionsOptions::withdraw:
        system("cls");
        printf("==================================================================\n                           Withdraw\n==================================================================\n");
        cout << "Enter Account number: ";
        accNum = GetString();
        while (!isInRecord(accNum, path)) {
            cout << "Not Found!!! \n[1] Try again\n[2] Go back";
            choice = GetRangedNum(0, 3);
            if (choice == 1) {
                accNum = GetString();
            }
            else {
                TransactionsLst();
            }
        }
        Withdraw(GetByAccNum(accNum , path));
        TransactionsLst();
        break;
    case enTrasactionsOptions::showBalances:
        system("cls");
        showBalanceList(path);
        TransactionsLst();
        break;
    case enTrasactionsOptions::back:
        system("cls");
        return;
        break;
    default:
        return;
    }
}


void searchByAccNum(string accNum, string filePath) {
    vector<stClient> vClients;
    bool found = false;
    ImportDataToVec(filePath, vClients);
    for (stClient client : vClients) {
        if (accNum == client.AccountNumber) {
            cout << "The following are the client details: \n\n";
            printf("|Acount Number : %s\n", client.AccountNumber.c_str());
            printf("|Pin Code: %s\n", client.PinCode.c_str());
            printf("|Name: %s\n", client.Name.c_str());
            printf("|Phone: %s\n", client.Phone.c_str());
            printf("|Account balance: %d\n", client.AccountBalance);
            found = true;
        }
    }
    if (found) {
        cout << "Press any key to go back...";
        system("pause>0");
        return;
    }
    else {
        cout << "Client not found!!" << endl;
        cout << "Press any key to go back...";
        system("pause>0");
    }
}


bool isInRecord(string accNum, string filePath) {
    vector<stClient> vClients;
    ImportDataToVec(filePath, vClients);
    for (stClient client : vClients) {
        if (accNum == client.AccountNumber) {
           
            return true;
        }
    }
    return false;
}


void DeleteByAccNum(string accNum, string filePath) {
    vector<stClient> vClients;
    bool found = false;
    ImportDataToVec(filePath, vClients);
    for (stClient client : vClients) {
        if (accNum == client.AccountNumber) {
            cout << "The following are the client details: \n\n";
            printf("|Acount Number : %s\n", client.AccountNumber.c_str());
            printf("|Pin Code: %s\n", client.PinCode.c_str());
            printf("|Name: %s\n", client.Name.c_str());
            printf("|Phone: %s\n", client.Phone.c_str());
            printf("|Account balance: %d\n", client.AccountBalance);
            printf("Are you sure you want to delete it???? 1 if yes , 0 if no: ");
            bool choice;
            cin >> choice;
            cin.ignore(1, '\n');
            if (choice) {
                DeleteRecordfromFile(filePath, strClient(client, Sep));
            }
            found = true;
        }
    }
    if (found) {
        cout << "Press any key to go back...";
        system("pause>0");
        return;
    }
    else {
        cout << "Client not found!!" << endl;
        cout << "Press any key to go back...";
        system("pause>0");

    }
}


void UpdateByAccNum(string accNum, string filePath) {
    vector<stClient> vClients;
    bool found = false;
    ImportDataToVec(filePath, vClients);
    for (stClient client : vClients) {
        if (accNum == client.AccountNumber) {
            cout << "The following are the client details: \n\n";
            printf("|Acount Number : %s\n", client.AccountNumber.c_str());
            printf("|Pin Code: %s\n", client.PinCode.c_str());
            printf("|Name: %s\n", client.Name.c_str());
            printf("|Phone: %s\n", client.Phone.c_str());
            printf("|Account balance: %d\n", client.AccountBalance);
            printf("Are you sure you want to update it???? 1 if yes , 0 if no: ");
            bool choice = GetNum();

            if (choice) {
                stClient temp = newClient();
                UpdateRecordfromFile(filePath, strClient(client, Sep), strClient(temp, Sep));
            }
            found = true;
        }
    }
    if (found) {
        cout << "Press any key to go back...";
        system("pause>0");
        return;
    }
    else {
        cout << "Client not found!!" << endl;
        cout << "Press any key to go back...";
        system("pause>0");
    }
    
}


void MainMenu() {
    system("cls");
    printf("==================================================================\n                           Main Menu\n==================================================================");
    cout << "\n[1] for Showing client list \n[2] for Adding new client\n[3] for Deleting client from list\n[4] for Updating a client record\n[5] for Finding a client by accNumber\n[6] Transactions List  \n[7] Exit\nenter choice: ";
    int choice = GetRangedNum(1 , 7);
    switch (choice) {
    case enMainMenueOptions::eListClients:
        system("cls");
        ShowFullRecord(path);
        MainMenu();
        break;
    case enMainMenueOptions::eAddNewClient:
        system("cls");
        printf("==================================================================\n                           Adding Client(s)\n==================================================================\n");
        UpdateClientsfile();
        MainMenu();
        break;
    case enMainMenueOptions::eUpdateClient:
        system("cls");
        printf("==================================================================\n                          Updating Client(s)\n==================================================================\n");
        cout << "enter account number: ";
        UpdateByAccNum(GetString(), path);    
        MainMenu();
        break;
    case enMainMenueOptions::eDeleteClient:
        system("cls");
        printf("==================================================================\n                           Deleting Client(s)\n==================================================================\n");
        cout << "enter account number: ";
        DeleteByAccNum(GetString(), path);   
        MainMenu();
        break;
    case enMainMenueOptions::eFindClient:
        system("cls");
        printf("==================================================================\n                           Finding Client(s)\n==================================================================\n");
        cout << "enter account number: ";
        searchByAccNum(GetString() , path);        
        MainMenu();
        break;
    case enMainMenueOptions::eExit:
        printf("Good Bye  :-)");
        return;
    case enMainMenueOptions::eTransactionsList:
        TransactionsLst();
        MainMenu();
        break;
    
    
    }
}

int main()
{

    MainMenu();
}

