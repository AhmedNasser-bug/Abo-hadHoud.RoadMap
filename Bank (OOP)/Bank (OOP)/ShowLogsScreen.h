#pragma once
#include "clsScreen.h"
class ShowLogsScreen :
    public clsScreen
{
private:
    struct stLog {
        string LogDate;
        string UserName;
        string Password;
        string Permissions;
    };

    static stLog _ConvertLogStringtoStruct(string LogString) {
        vector<string> LogDetails = String::WordsOf(LogString, "#//#");
        stLog Log;

        Log.LogDate = LogDetails[0];
        Log.UserName = LogDetails[1];
        Log.Password = String::Decrypted(LogDetails[2], 5);
        Log.Permissions = LogDetails[3];

        return Log;
    }

    static  vector <stLog> _LoadLogsDataFromFile()
    {

        vector <stLog> vLogs;
        fstream MyFile;
        MyFile.open("LogFile.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                vLogs.push_back(_ConvertLogStringtoStruct(Line));
            }
            MyFile.close();

        }

        return vLogs;

    }

    static void _PrintLogLine(stLog Log) {
        
        cout << setw(20) << Log.LogDate << '|';
        cout << setw(15) << Log.UserName << '|';
        cout << setw(12) << Log.Password << '|';
        cout << setw(10) << Log.Permissions << '|';
       
        cout << endl;

    }
public:

    static void ShowLogs() {

        vector<stLog> UserLogs = _LoadLogsDataFromFile();

        PrintScreenTitle("Users logs", "List Size: (" + to_string(UserLogs.size()) + ") Client(s).");

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        printf("| %-20s", "Log date");
        printf("| %-15s", "User Name");
        printf("| %-12s", "Password");
        printf("| %-10s", "Pin Code");
        printf("| %-12s", "Permissions");
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        for (stLog& Log : UserLogs) {
            _PrintLogLine(Log);
        }

    }
};

