#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsFindUserScreen :
    public clsScreen
{
private:

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

    static void ShowFindUserScreen() {

        PrintScreenTitle("Find User Screen");

        cout << "Enter User Name: ";
        string UserName = InputValidation::ReadString();

        clsUser User = clsUser::Find(UserName);
            
        while (User.IsEmpty())
        {
            cout << "User IS NOT FOUND ! choose another User name or go back : (1/0)";

            bool Choice = InputValidation::ReadShortWithinRange(0, 1);
            if (Choice) {

                UserName = InputValidation::ReadString();
                
                User = clsUser::Find(UserName);

                continue;
            }
            return;

        }

        _PrintUser(User);
        
    }
};

