#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsUsersListScreen :
    public clsScreen
{
private:

    static inline void PrintUserRecordLine(clsUser &User)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone();
        cout << "| " << setw(20) << left << User.Email();
        cout << "| " << setw(10) << left << User.Password();
        cout << "| " << setw(12) << left << User.Permissions();
    }

public:

    static void ShowUsersListScreen()
    {
        vector<clsUser> Users = clsUser::GetUsersList();

        size_t UsersListSize = Users.size();

        string Title = "Users List";
        string SubTitle = "[" + to_string(UsersListSize) + "] User(s)";

        PrintScreenTitle(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        for (clsUser &User : Users) {

            PrintUserRecordLine(User);

            cout << endl;

        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

    }

};

