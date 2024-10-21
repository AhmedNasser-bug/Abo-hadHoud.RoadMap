#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "IputValidation.h"
class clsAddUserScreen :
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

    static string _GetNewUserName() 
    {
        string UserName = InputValidation::ReadString();

        while (not clsUser::Find(UserName).IsEmpty())
        {
            cout << "User Already exists! choose another User name: ";

            UserName = InputValidation::ReadString();
        
        }

        return UserName;

    }

public:

    static void ShowAddNewUserScreen() 
    {
        PrintScreenTitle("Add New User Screen");
        
        cout << "Please Enter a User Name: ";

        string UserName = _GetNewUserName();

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserData(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::svFaildEmptyObject:

            cout << "\nError User was not saved because it's Empty";

            break;

        case clsUser::svSucceeded:
            
            cout << "\nUser Addeded Successfully :-)\n";
            
            _PrintUser(NewUser);
            
            break;

        case clsUser::svFailedAlreadyExists:
            
            cout << "\nError User was not saved because User name already exists";
            
            break;

        default:
            break;
        }

    }
};

 