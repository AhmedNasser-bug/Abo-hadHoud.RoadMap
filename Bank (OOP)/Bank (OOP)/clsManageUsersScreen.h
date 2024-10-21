#pragma once
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen :
    protected clsScreen
{
private:
    enum enManageUsersMenuOptions { eShowUsersList = 1, eAddUsers = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6 };
    

    static void _ShowUsersListScreen() {

        clsUsersListScreen::ShowUsersListScreen();

    }


    static void _ShowAddUsersScreen() {

        clsAddUserScreen::ShowAddNewUserScreen();

    }

   
    static void _ShowDeleteUsersScreen() {

        clsDeleteUserScreen::ShowDeleteUserScreen();

    }


    static void _ShowUpdateUsersScreen() {

        clsUpdateUserScreen::ShowUpdateUserScreen();
    
    }


    static void _ShowFindUsersScreen() {

        clsFindUserScreen::ShowFindUserScreen();

    }


    static void _GetBackToManageUsersScreen() {
        
        UIEnd();
        
        ShowManageUsersScreen();

    }

    static short _GetManageUsersMenuOption() {

        cout << "Please choose an Option: ";

        short Choice = InputValidation::ReadShortWithinRange(1, 6, "Please choose a number from 1 to 6");

        return Choice;

    }

    static void _PerformManageUsersMenuOption(enManageUsersMenuOptions Option) {

        cls

        switch (Option)
        {
        case clsManageUsersScreen::eShowUsersList:
            
            _ShowUsersListScreen();

            break;

        case clsManageUsersScreen::eAddUsers:
            
            _ShowAddUsersScreen();

            break;

        case clsManageUsersScreen::eDeleteUser:
            
            _ShowDeleteUsersScreen();
            
            break;

        case clsManageUsersScreen::eUpdateUser:
            
            _ShowUpdateUsersScreen();
            
            break;

        case clsManageUsersScreen::eFindUser:
            
            _ShowFindUsersScreen();
            
            break;

        case clsManageUsersScreen::eMainMenue:
            
            return;
            
            break;

        default:
            break;
        }

        _GetBackToManageUsersScreen();

    }
public:
    static void ShowManageUsersScreen() {

        cls

        PrintScreenTitle("Manage Users Menu");

        cout << "[1] Show users list" << endl;
        cout << "[2] Add user" << endl;
        cout << "[3] Delete user" << endl;
        cout << "[4] Update user" << endl;
        cout << "[5] Find user" << endl;
        cout << "[6] Back to Main Menu" << endl;

        _PerformManageUsersMenuOption((enManageUsersMenuOptions)_GetManageUsersMenuOption());

    }
};

