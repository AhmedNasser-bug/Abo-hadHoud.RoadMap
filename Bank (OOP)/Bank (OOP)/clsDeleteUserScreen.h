#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsDeleteUserScreen :
    public clsScreen
{
private:

    static string _GetExistingUserName()
    {
        string UserName = InputValidation::ReadString();

        while (clsUser::Find(UserName).IsEmpty())
        {
            cout << "User IS NOT FOUND ! choose another User name: ";

            UserName = InputValidation::ReadString();

        }

        return UserName;

    }

    inline static void _PrintUser(clsUser& User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName();
        cout << "\nLastName    : " << User.LastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email();
        cout << "\nPhone       : " << User.Phone();
        cout << "\nUser Name   : " << User.UserName();
        cout << "\nPassword    : " << User.Password();
        cout << "\nPermissions : " << User.Permissions();
        cout << "\n___________________\n";

    }

public:

    static void ShowDeleteUserScreen() {

        PrintScreenTitle("Delete User Screen");

        cout << "Please Enter User Name: ";
        string UserName = _GetExistingUserName();

        clsUser UserToDelete = clsUser::Find(UserName);

        _PrintUser(UserToDelete);
        cout << "Here are the user's details are you sure you want to delete it? (1/0): ";

        bool Agree = InputValidation::ReadShortWithinRange(0, 1);

        if (Agree) {

            if (UserToDelete.Delete()) {
                
                cout << "User Deleted Successfully!";
                
                _PrintUser(UserToDelete);

            }
            else {

                cout << "Deletetion Failed..";

            }
        }
        

    }

};

