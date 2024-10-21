#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "MainScreen.h"
#include "GlobalUser.h"

class clsLoginScreen :
    public clsScreen
{
private:

    static void _AddDataLineToFile(string  DataLine)
    {
        fstream MyFile;
        MyFile.open("LogFile.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }

    }

    static void _AddLoginRecord() {
        Date CurrentDate = Date();

        string Log = Date::GetStringDate(CurrentDate, "dd/mm/yyyy") + "-" + CurrentDate.GetStringTime("hh:mm:ss") + "#//#" + CurrentUser.UserName() + "#//#" +String::Encrypted(CurrentUser.Password(), 5) + "#//#" + to_string(CurrentUser.Permissions());

        _AddDataLineToFile(Log);

    }

public:

    static void ShowLoginScreen() 
    {
        PrintScreenTitle("Login Screen");
        string UserName, Password;
        bool LoginFailed = false;

        short Trials = 3;

        do {

            if (LoginFailed) {
                if (not Trials) {
                    cls
                        cout << "YOU ARE NOT ALLOWED TO ENTER" << endl << "CONTACT YOUR ADMIN\n\n\n";
                    return;
         
                }
                cout << "\nUSER NOT FOUND! " << Trials << " Trials Left\n";
                
            }
            

            cout << "\nEnter User Name: ";
            UserName = InputValidation::ReadString();

            cout << "Enter Password: ";
            Password = InputValidation::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();

            Trials--;

        } while (LoginFailed);
  
        _AddLoginRecord();

        clsMainScreen::ShowMainMenu();
        
        ShowLoginScreen();

    }

};

