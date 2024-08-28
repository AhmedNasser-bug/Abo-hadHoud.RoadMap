// B.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "C:\Users\orginal\source\repos\Header1.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define Sep "/--/"
#define ClientsPath "D:\\WEB\\Abo-hadHoud.RoadMap\\B\\B\\Clients.txt"
#define UsersPath "D:\\WEB\\Abo-hadHoud.RoadMap\\B\\B\\Users.txt"
#define cls system("cls");


enum enMainMenueOptions{ eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,eTransactionsList = 6 ,eManageUsers = 7 ,eLogOut = 8 };
enum enTrasactionsOptions{Deposit = 1 , withdraw = 2, showBalances = 3 , back = 4};
enum enPermisions{PermListClients = 1, PermAddClient = 2, PermDeleteClient = 4, PermUpdateClient = 8, PermFindClient = 16, PermTransactionList = 32, PermManageUsers = 64};
enum enManageUsers{eShowUsersList = 1, eAddUsers = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6};

struct stUser{
    string Name;
    string Password;
    short perms;
};


/* ------------------------------------------------------ USER UTILS ------------------------------------------------------ */

// Pops up when you try to modify admin account
inline void AdminError() {
    cout << "===========================================\n" << "\t\tCANT MODIFY ADMIN\n" << "===========================================\n";
}

// Prints user details as a row in a table
void PrintUser(stUser User){

    printf("| %-15s", User.Name.c_str());
    printf("| %-10s", User.Password.c_str());
    printf("| %-40d\n", User.perms);

}

// Prints user details as a card
void PrintUserDetails(stUser User) {
    cout << "Here are the user details: \n";
    printf("| User name: %s\n", User.Name.c_str());
    printf("| Password: %s\n", User.Password.c_str());
    printf("| Permissions: %s\n",to_string(User.perms).c_str());

}

// Returns a username (doesn't check if it already exists in record)
string GetUserName() {
    cout << "Enter User name: ";
    return myLib::GetString();
}

// Returns a password
string GetPassWord() {
    cout << "Enter Password: ";
    return myLib::GetString();
}

// Updates permissions of a user
void updatePerms(short& user) {
    user = 0;
    cout << "Do you want the user to be able to: \n";
    cout << "Everything?.. (1/0) ";
    short choice;
    choice = (short)myLib::GetRangedNum(0, 1);
    // Return if everything is granted for the new user
    if (choice) {
        user = -1;
        return;
    }

    short perms[] = {enPermisions::PermListClients, enPermisions::PermAddClient, enPermisions::PermDeleteClient, enPermisions::PermUpdateClient, enPermisions::PermFindClient, enPermisions::PermTransactionList, enPermisions::PermManageUsers};
    string messages[7] = { "List Users? (1/0) " , "Add Clients? (1/0) ", "Delete Client? (1/0) " , "Update Client? (1/0) " , "Find Client? (1/0) " , "Access Transactions List? (1/0) " , "Manage Users? (1/0) " };
    for (int i = 0; i < 7; i++) {
        // messeage is changed every iteration
        cout << messages[i];
        // new choice is taken every iteration
        choice = (short)myLib::GetRangedNum(0, 1);
        if (choice == true) {
            // set the ith bit to indicate that the permision is granted
            user |= perms[i];
        }
    }
    
}

// Returns the user with the given string representation as a stUser data type
stUser newUser(string string_repr, string sep) {
    stUser Temp;
    vector<string> data = myLib::WordsOf(string_repr, sep);
    Temp.Name = data[0];
    Temp.Password = data[1];
    Temp.perms = (short)stoi(data[2]);
    return Temp;

}

// Imports data from users record to the given vector 
void ImportDataToVec(string FileLocation, vector<stUser>& TheVectorThatWillHaveTheFileContentsUsingPush_Back) {
    fstream File;
    File.open(FileLocation, ios::in);
    if (File.is_open()) {
        string line;
        while (getline(File, line)) {
            TheVectorThatWillHaveTheFileContentsUsingPush_Back.push_back(newUser(line, Sep));
        }
        File.close();
    }
}

// Returns true if the user with the given username is in the record
bool UserInRecord(string Name, string filePath) {
    vector<stUser> vUsers;
    ImportDataToVec(filePath, vUsers);
    for (stUser& User : vUsers) {
     
        if (Name == User.Name) {

            return true;
        }
    }
    return false;
}

// Returns a new user with data type stUser
stUser newUser() {

    stUser user;
    user.Name = GetUserName();
    // MAKE SURE USER NAME DOES NOT ALREADY EXIST
    while (UserInRecord(user.Name, UsersPath)) {
        printf("Already exists enter a different one: ");
        user.Name = myLib::GetString();

    }
    printf("\n");
    user.Password = GetPassWord();
    user.perms = 0;
    updatePerms(user.perms);
    cin.ignore(1, '\n');
    return user;
}

// Returns a user with the given user name
stUser GetByUserName(string Name, string filePath) {

    vector<stUser> vUser;
    ImportDataToVec(filePath, vUser);
    for (stUser& User : vUser) {
        if (Name == User.Name) {
            return User;
        }
    }



}

// Returns a string representation of a given user
string strUser(stUser& user, string sep) {
    string ret = "";
    ret.append(user.Name + sep);
    ret.append(user.Password + sep);
    ret.append(to_string(user.perms));
    return ret;
}

// Returns a string representation of a new user
string newStrUser(){
    stUser user = newUser();
    return strUser(user, Sep);
}

// Deletes a user with the given username from the record
void DeleteByUserName(string Name){
    if (!UserInRecord(Name, UsersPath)) {
        cout << "User not found!! \n";
        return; 
    }
    stUser user = GetByUserName(Name, UsersPath);
    
    if (user.Name == "Admin") { AdminError(); return; }
    
    PrintUserDetails(user);

    printf("Are you sure you want to delete it???? 1 if yes , 0 if no: ");
    bool choice = myLib::GetRangedNum(0, 1);
    if (choice) {
        myLib::DeleteRecordfromFile(UsersPath, strUser(user, Sep));
        cout << "Successfully deleted the user.. ";

    }
    
    
}

// Updates the details of the user with the given username 
void UpdateByUserName(string Name){
    if (!UserInRecord(Name, UsersPath)) { cout << "User not found!! \n"; return; }
    stUser user = GetByUserName(Name, UsersPath);
    
    if (UserInRecord(user.Name, UsersPath)) {

        if (user.Name == "Admin") { AdminError(); return; }
            
        PrintUserDetails(user);
        printf("Are you sure you want to update the user???? 1 if yes , 0 if no: ");

        bool choice = myLib::GetRangedNum(0 , 1);
        if (choice) {

            // GET THE MODIFIED USER
            stUser neww;
            neww.Name = Name;
            cout << "New: \n";
            neww.Password = GetPassWord();
            updatePerms(neww.perms);

            myLib::UpdateRecordfromFile(UsersPath, strUser(user, Sep), strUser(neww, Sep));
            cout << "User successfully updated!\n";
        }
    }
    
}

// Validate user credintials    
bool ValidUser(string username , string password){
    
    if (UserInRecord(username , UsersPath)) {
        stUser user = GetByUserName(username, UsersPath);
        if (user.Password == password) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

// Returns true if user have access to the given action
bool HaveAccessTo(short perms, short action){
    return perms & action or perms == -1;
}

// Displays a table of all users with all thier detail
void ListUsers(){
    cls
    vector<stUser> users;
    ImportDataToVec(UsersPath, users);
    cout << "\n\t\t\t\t\tUsers List (" << users.size() << ") User(s).";
    cout << "\n_______________________________________________________" << endl << "_________________________________________\n" << endl;
    printf("| %-15s", "User Name");
    printf("| %-10s", "Password");
    printf("| %-40s", "Permissions");
    cout << "\n_______________________________________________________" << endl << "_________________________________________\n" << endl;
    
    

    for (stUser& user : users) {
        PrintUser(user);
    }

    cout << "Press any key to go back..."; system("pause>0");
}

// Adds a user to a users vector
void AddUser(vector<string>& users){
    stUser NewUser; 
    NewUser = newUser();
    PrintUserDetails(NewUser);
    users.push_back(strUser(NewUser ,Sep));
}

// Delete several users with given username from the existing users record
void DeleteUsers(){
    cls
    short choice;
    cout << "===========================================\n";
    cout << "\t\tDelete Users Screen\n";
    cout << "===========================================\n";
    choice = myLib::GetRangedNum(0, 1, "Delete a user? (1/0) ");

    while (choice) {
        string name = GetUserName();
        DeleteByUserName(name);
        choice = myLib::GetRangedNum(0 , 1, "Do you want to delete another user? (1/0) ");
    }

    cout << "Press any key to go back..."; system("pause>0");
}

// Displays adding users screen , lets you add several users to the users record
void AddUsers(){
    cls
    short choice;
    cout << "===========================================\n";
    cout << "\t\tAdd Users Screen\n";
    cout << "===========================================\n";

    vector<string> users;
    myLib::ImportDataToVec(UsersPath, users);

    printf("Add user? (1/0)\n");
    choice = myLib::GetRangedNum(0, 1);

    while (choice) {
        AddUser(users);
        choice = myLib::GetRangedNum(0, 1 , "Do you want to add anothe user? (1/0) ");
    }
    
    myLib::SaveVecToFile(UsersPath, users);
    cout << "Press any key to go back..."; system("pause>0");
}

// Displays a screen that enables you to update several users 
void UpdateUsers(){
    cls
    short choice;
    string name;
    cout << "===========================================\n";
    cout << "\t\tUpdate Users Screen\n";
    cout << "===========================================\n";

    choice = myLib::GetRangedNum(0, 1, "Update a user? (1/0) ");
    while (choice) {
        name = GetUserName();
        UpdateByUserName(name);
        choice = myLib::GetRangedNum(0, 1, "Update another user? (1/0)");
    }
    cout << "Press any key to go back..."; system("pause>0");
}

// Display user details if and only if the user exists in record
void FindUser(string name){
    if (UserInRecord(name, UsersPath)) {
        PrintUserDetails(GetByUserName(name, UsersPath));
    }
    else {
        cout << "User not found!! \n";
    }
}

// Find users based on username
void FindUsers(){
    cls
    short choice;
    string name;
    cout << "===========================================\n";
    cout << "\t\tFind Users Screen\n";
    cout << "===========================================\n";
    cout << "Find a user? (1/0) ";
    choice = myLib::GetRangedNum(0, 1);
    while (choice) {
        name = GetUserName();
        FindUser(name);
        cout << "Find another user ? (1 / 0)";
        choice = myLib::GetRangedNum(0, 1);
    }
    cout << "Press any key to go back..."; system("pause>0");
}

// Control and modify each user in the users record
void ManageUsersScreen(){
    cls
    cout << "===========================================\n";
    cout << "\t\tManage Users Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===========================================\n";

    short choice = myLib::GetRangedNum(1, 6);

    switch (choice)
    {
    case enManageUsers::eShowUsersList:
        ListUsers();
        ManageUsersScreen();
        break;
    case enManageUsers::eAddUsers:
        AddUsers();
        ManageUsersScreen();
        break;
    case enManageUsers::eDeleteUser:
        DeleteUsers();
        ManageUsersScreen();
        break;
    case enManageUsers::eUpdateUser:
        UpdateUsers();
        ManageUsersScreen();
        break;
    case enManageUsers::eFindUser:
        FindUsers();
        ManageUsersScreen();
        break;

    default:
        break;
    }

}

/* ------------------------------------------------------ CLIENT UTILS ------------------------------------------------------ */

// Returns a new client with data type stClient
stClient newClient(){
    stClient c;
    cout << "enter PinCode: ";
    c.PinCode = myLib::GetString();
    cout << "enter Account Number: ";
    c.AccountNumber = myLib::GetString();
    cout << "enter Name: ";
    c.Name = myLib::GetString();
    cout << "enter Phone: ";
    c.Phone = myLib::GetString();
    cout << "enter Account Balance: ";
    c.AccountBalance = myLib::GetNum();
    return c;
}

// Returns the client with the given string representation with data type stClient
stClient newClient(string stringRepr, string sep){
    stClient c;
    vector<string> data = myLib::WordsOf(stringRepr, sep);
    c.Name = data[0];
    c.Phone = data[1];
    c.AccountNumber = data[2];
    c.PinCode = data[3];
    c.AccountBalance = stoi(data[4]);

    return c;
}

// Imports data from clients record to the given vector
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

// Returns the string representation of the given client
string strClient(stClient& c, string seprator){
    string ret = "";
    ret.append(c.Name + seprator);
    ret.append(c.Phone + seprator);
    ret.append(c.AccountNumber + seprator);
    ret.append(c.PinCode + seprator);
    ret.append(to_string(c.AccountBalance));
    return ret;
}

// Returns true if the client with the given account number exists in the record otherwise returns false
bool ClientInRecord(string accNum, string filePath) {
    vector<stClient> vClients;
    ImportDataToVec(filePath, vClients);
    for (stClient client : vClients) {
        if (accNum == client.AccountNumber) {

            return true;
        }
    }
    return false;
}

// Returns the string representation of a new Client
string newStrClient(){
    stClient c;
    cout << "enter PinCode: ";
    c.PinCode = myLib::GetString();
    cout << "enter Account Number: ";
    c.AccountNumber = myLib::GetString();
    while (ClientInRecord(c.AccountNumber, ClientsPath)) {
        printf("Already exists enter a different one: ");
        c.AccountNumber = myLib::GetString();
        
    }
    cout << "enter Name: ";
    c.Name = myLib::GetString();
    cout << "enter Phone: ";
    c.Phone = myLib::GetString();
    cout << "enter Account Balance: ";
    c.AccountBalance = myLib::GetNum();
  
    return strClient(c, Sep);
}

// Returns the client with the specified Account number
stClient GetByAccNum(string Name, string filePath) {

    vector<stClient> vClient;
    ImportDataToVec(filePath, vClient);
    for (stClient& Client : vClient) {
        if (Name == Client.Name) {
            return Client;
        }
    }



}

// Displays the full client details of the given client
void ShowRecord(stClient client){

    printf("| %-15s", client.AccountNumber.c_str());
    printf("| %-10s", client.PinCode.c_str());
    printf("| %-40s", client.Name.c_str());
    printf("| %-12s", client.Phone.c_str());
    printf("| %-12d\n", client.AccountBalance);
}

// Displays the balance of the given client
void ShowBalance(stClient client){

    printf("| %-15s", client.AccountNumber.c_str());
    printf("| %-40s", client.Name.c_str());
    printf("| %-12d\n", client.AccountBalance);
}

// Displays UI that lets you add new clients to the clients record
void UpdateClientsfile(){
    vector<string> Records  ; bool open = true;
    myLib::ImportDataToVec(ClientsPath, Records);
    cout << "Add records: " << endl;
    while (open) {
       
        Records.push_back(newStrClient());
        cout << "Add more? 1 yes , 0 no:  ";
        open = myLib::GetNum();


    }
    myLib::SaveVecToFile("Clients.txt", Records);
    cout << "Press any key to go back..."; system("pause>0");
}

// Displays the full details of all clients in the clients record
void ShowFullRecord(string RecordPath){
    vector<string> Records;
    myLib::ImportDataToVec(RecordPath, Records);

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
    cout << "Press any key to go back..."; system("pause>0");
}

// Displays the full balances of all clients
void showBalanceList(string RecordPath){
    vector<string> Records;
    myLib::ImportDataToVec(RecordPath, Records);
    cout << "\n\t\t\t\t\tClient List (" << Records.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    printf("| %-15s", "Account Number");
    printf("| %-40s", "Client Name");
    printf("| %-12s", "Balance");

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (string cl : Records){
        ShowBalance(newClient(cl, Sep));
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "Press any key to go back..."; system("pause>0");
}

// Withdraw money from the given client
void Withdraw(stClient  Client){
    string old = strClient(Client, Sep);
    cout << "Available Balance : " << Client.AccountBalance <<"\n Enter Amount : ";
    unsigned int amount = myLib::GetRangedNum(0 , Client.AccountBalance);
    Client.AccountBalance -= amount;
    cout << "withdrawal done!!\nAvailable Balance: " << Client.AccountBalance;
    myLib::UpdateRecordfromFile(ClientsPath , old , strClient(Client , Sep));
    cout << "Press any key to go back..."; system("pause>0");
}

// Deposit money to the given client
void deposit(stClient Client){
    string old = strClient(Client, Sep);
    cout << "Available Balance : " << Client.AccountBalance << "\n Enter Amount : ";
    unsigned int amount = myLib::GetPNum();
    Client.AccountBalance += amount;
    cout << "depsit done!!\nAvailable Balance: " << Client.AccountBalance;
    myLib::UpdateRecordfromFile(ClientsPath, old, strClient(Client, Sep));
    cout << "Press any key to go back..."; system("pause>0");;
}

// Displays a list that enables the user to do several transactions
void TransactionsLst(){
    system("cls");
    printf("==================================================================\n                           Transactions\n==================================================================");
    cout << "\n[1] Deposit \n[2] Withdraw\n[3] Show Balance list\n[4] Back to MainMenu \nenter choice: ";
    int choice = myLib::GetRangedNum(0, 5);
    string accNum;
    switch (choice) {
    case enTrasactionsOptions::Deposit:
        system("cls");
        printf("==================================================================\n                           Deposit\n==================================================================\n");
        cout << "Enter Account number: ";
        accNum = myLib::GetString();
        while (!ClientInRecord(accNum, ClientsPath)) {
            cout << "Not Found!!! \n[1] Try again\n[2] Go back";
            choice = myLib::GetRangedNum(0 , 3);
            if (choice == 1) {
                accNum = myLib::GetString();
            }
            else {
                TransactionsLst();
            }
        }
        deposit(GetByAccNum(accNum, ClientsPath));
        TransactionsLst();
        
        break;
    case enTrasactionsOptions::withdraw:
        system("cls");
        printf("==================================================================\n                           Withdraw\n==================================================================\n");
        cout << "Enter Account number: ";
        accNum = myLib::GetString();
        while (!ClientInRecord(accNum, ClientsPath)) {
            cout << "Not Found!!! \n[1] Try again\n[2] Go back";
            choice = myLib::GetRangedNum(0, 3);
            if (choice == 1) {
                accNum = myLib::GetString();
            }
            else {
                TransactionsLst();
            }
        }
        Withdraw(GetByAccNum(accNum , ClientsPath));
        TransactionsLst();
        break;
    case enTrasactionsOptions::showBalances:
        system("cls");
        showBalanceList(ClientsPath);
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

// Displays the details of the given client account number
void searchByAccNum(string accNum, string filePath){
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
        cout << "Press any key to go back..."; system("pause>0");
        return;
    }
    else {
        cout << "Client not found!!" << endl;
        cout << "Press any key to go back..."; system("pause>0");
    }
}

// Deletes the client with the given account number from the clients record 
void DeleteByAccNum(string accNum, string filePath){
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
                myLib::DeleteRecordfromFile(filePath, strClient(client, Sep));
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

// Updates the details of given client's account number
void UpdateByAccNum(string accNum, string filePath){
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
            bool choice = myLib::GetNum();

            if (choice) {
                stClient temp = newClient();
                myLib::UpdateRecordfromFile(filePath, strClient(client, Sep), strClient(temp, Sep));
            }
            found = true;
        }
    }
    if (found) {
        cout << "Press any key to go back..."; system("pause>0");
        return;
    }
    else {
        cout << "Client not found!!" << endl;
        cout << "Press any key to go back..."; system("pause>0");
    }
    
}

/* ------------------------------------------------------ MAIN UI ------------------------------------------------------ */

// Displays a permission error message
void ErrorMessage(){
    cls
    cout << "NO ACCESS TO THIS ACTION!\n";
    cout << "Press any key to go back...";
    system("pause>0");

}

// Displays the main menu of the app
void MainMenu(stUser user){
    cls

    printf("==================================================================\n                           Main Menu\n==================================================================");
    cout << "\n[1] for Showing client list \n[2] for Adding new client\n[3] for Deleting client from list\n[4] for Updating a client record\n[5] for Finding a client by accNumber\n[6] Transactions List  \n[7] Manage Users  \n[8] Log Out  \nenter choice: ";

    int choice = myLib::GetRangedNum(1 , 8);
    switch (choice) {

    case enMainMenueOptions::eListClients:
        cls
        if (!HaveAccessTo(user.perms, enPermisions::PermListClients)) {ErrorMessage(); MainMenu(user); break;}

        ShowFullRecord(ClientsPath);

        MainMenu(user);
        break;

    case enMainMenueOptions::eAddNewClient:
        cls
        if (!HaveAccessTo(user.perms, enPermisions::PermAddClient)) { ErrorMessage(); MainMenu(user); break; }

        printf("==================================================================\n                           Adding Client(s)\n==================================================================\n");
        UpdateClientsfile();

        MainMenu(user);
        break;

    case enMainMenueOptions::eUpdateClient:
        cls
        if (!HaveAccessTo(user.perms, enPermisions::PermUpdateClient)) { ErrorMessage(); MainMenu(user); break; }

        printf("==================================================================\n                          Updating Client(s)\n==================================================================\n");
        cout << "enter account number: ";
        UpdateByAccNum(myLib::GetString(), ClientsPath);

        MainMenu(user);
        break;

    case enMainMenueOptions::eDeleteClient:
        cls
        if (!HaveAccessTo(user.perms, enPermisions::PermDeleteClient)) { ErrorMessage(); MainMenu(user); break; }

        printf("==================================================================\n                           Deleting Client(s)\n==================================================================\n");
        cout << "enter account number: ";
        DeleteByAccNum(myLib::GetString(), ClientsPath);

        MainMenu(user);
        break;

    case enMainMenueOptions::eFindClient:
        cls
        if (!HaveAccessTo(user.perms, enPermisions::PermFindClient)) { ErrorMessage(); MainMenu(user); break; }

        printf("==================================================================\n                           Finding Client(s)\n==================================================================\n");
        cout << "enter account number: ";
        searchByAccNum(myLib::GetString() , ClientsPath);

        MainMenu(user);
        break;
    case enMainMenueOptions::eLogOut:
        return;

    case enMainMenueOptions::eTransactionsList:
        if (!HaveAccessTo(user.perms,enPermisions::PermTransactionList)) { ErrorMessage(); MainMenu(user); break; }

        TransactionsLst();

        MainMenu(user);
        break;
    case enMainMenueOptions::eManageUsers:
        if (!HaveAccessTo(user.perms, enPermisions::PermManageUsers)) { ErrorMessage(); MainMenu(user); break; }

        ManageUsersScreen();

        MainMenu(user);
        break;
    }

    
}

// Displays the login screen
void LoginScreen(){
    cls 
    cout << "\n---------------------------------\n";
    cout << "\tLogin Screen";  
    cout << "\n---------------------------------\n";

    string name = GetUserName();
    string password = GetPassWord();
    while (!ValidUser(name, password)) {
        cout << "INVALID USERNAME OR PASSWORD , TRY AGAIN!\n";
        name = GetUserName();
        password = GetPassWord();
    }
    
    MainMenu(GetByUserName(name , UsersPath));
    LoginScreen();
}

int main()
{
    LoginScreen();
}

