#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsUpdateUserScreen :
    public clsScreen
{
private:

    static int _ChooseUserPermissions()
    {
        int Permissions = 0;

        bool Agree = 0;

        cout << "Do you want to give full access? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            return clsUser::PermAll;
        }

        cout << "Do you want to give access to : \nShow client list (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermListClients;
        }

        cout << "Add new client? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermAddClient;
        }

        cout << "Delete clients? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermDeleteClient;
        }

        cout << "Update clients? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermUpdateClient;
        }

        cout << "Find clients? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermFindClient;
        }

        cout << "Transactions ? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermTransactionList;
        }

        cout << "Manage users? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermManageUsers;
        }

        cout << "Show Logs? (1/0): ";

        Agree = InputValidation::ReadShortWithinRange(0, 1);
        if (Agree) {
            Permissions &= clsUser::PermShowLogs;
        }


        return Permissions;

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

    static void _ReadUserData(clsUser& User)
    {
        cout << "Enter First Name: ";
        User.SetFirstName(InputValidation::ReadString());

        cout << "Enter Last Name: ";
        User.SetLastName(InputValidation::ReadString());

        cout << "Enter Email: ";
        User.SetEmail(InputValidation::ReadString());

        cout << "Enter Phone: ";
        User.SetPhone(InputValidation::ReadString());

        cout << "Enter Password: ";
        User.SetPassword(InputValidation::ReadString());

        cout << "Select Permissions: ";
        User.SetPermissions(_ChooseUserPermissions());
    }

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

public:

    static void ShowUpdateUserScreen() {

        PrintScreenTitle("Update User Screen");

        cout << "Please Enter the User Name: ";
        string UserName = _GetExistingUserName();

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);

        cout << "Do you want to update this user? (1/0): ";

        bool Agree = InputValidation::ReadShortWithinRange(0, 1);

        if (Agree) {

            _ReadUserData(User);

            clsUser::enSaveResults SaveResult = User.Save();

            switch (SaveResult)
            {
            case clsUser::svFaildEmptyObject:
                
                cout << "Cant update an empty user!";
                break;

            case clsUser::svSucceeded:
                
                cout << "User Updated Successfully!";
                break;

            case clsUser::svFailedAlreadyExists:
                
                cout << "USER ALREADY EXISTS error";    
                break;

            default:
                break;
            }
        }


    }


};

