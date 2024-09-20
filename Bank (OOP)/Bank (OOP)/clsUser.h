#pragma once
#include "Person.h"
#include "clsBankClient.h"
class clsUser :
    public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
    
    string _UserName;
    
    string _Password;
    
    short _Permissions;

    bool _MarkedForDelete = false;

    enMode _Mode;


    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#") {
        
        vector<string> vUserData;
        vUserData = String::WordsOf(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static clsUser _GetEmptyUser(){
    
        return clsUser(EmptyMode, "", "", "", "", "", "", 0);

    }

    static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string strUserRecord = "";
        strUserRecord += User.FirstName() + Seperator;
        strUserRecord += User.LastName() + Seperator;
        strUserRecord += User.Email() + Seperator;
        strUserRecord += User.Phone() + Seperator;
        strUserRecord += User.UserName() + Seperator;
        strUserRecord += User.Password() + Seperator;
        strUserRecord += to_string(User.Permissions());

        return strUserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;

        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser User : vUsers)
            {
                DataLine = _ConvertUserObjectToLine(User);
                if (not User.MarkedForDeleted()) { MyFile << DataLine << endl; }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> vUsers;
        vUsers = _LoadUsersDataFromFile();

        for (size_t UserIndex = 0; UserIndex < vUsers.size(); UserIndex++)
        {

            if (vUsers[UserIndex].UserName() == UserName())
            {
                vUsers[UserIndex] = *this;

                break;
            }

        }

        _SaveUsersDataToFile(vUsers);

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew() {

        _AddDataLineToFile(_ConvertUserObjectToLine(*this));

    }

public:

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, short Permissions):
    clsPerson(FirstName, LastName, Email, Phone)
    {

        _Mode = Mode;

        _UserName = UserName;

        _Password = Password;

        _Permissions = Permissions;

    }
    
    bool IsEmpty() {
        
        return _Mode == EmptyMode;
    
    }

    bool MarkedForDeleted() {
        
        return _MarkedForDelete;

    }
    
    string UserName() {
        
        return _UserName;

    }

    void SetUserName(string UserName) {

        _UserName = UserName;

    }

    string Password() {

        return _Password;

    }

    void SetPassword(string Password){
    
        _Password = Password;

    }

    short Permissions() {

        return _Permissions;

    }

    short SetPermissions(short Permissions) {

        _Permissions = Permissions;

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);

        return (not User.IsEmpty());

    }

    static clsUser Find(string UserName)
    {

        fstream MyFile;

        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                if (User.UserName() == UserName)
                {

                    MyFile.close();

                    return User;

                }

            }

            MyFile.close();

        }

        return _GetEmptyUser();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;

        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                if ( User.UserName() == UserName and User.Password() == Password )
                {

                    MyFile.close();

                    return User;

                }

            }

            MyFile.close();

        }

        return _GetEmptyUser();
    }

    enum enSaveResults{ svFaildEmptyObject = 0, svSucceeded = 1, svFailedAlreadyExists };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {

            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case enMode::AddNew:

            if (IsUserExist(_UserName)) {
                return enSaveResults::svFailedAlreadyExists;
            }
            else {
                _AddNew();
                return enSaveResults::svSucceeded;
            }
            break;
        }

        return enSaveResults::svFaildEmptyObject;
    }

    bool Delete() {

        vector <clsUser> vUsers = _LoadUsersDataFromFile();

        for (size_t UserIndex = 0; UserIndex < vUsers.size(); UserIndex++) {

            if (vUsers[UserIndex].UserName() == _UserName) {

                vUsers[UserIndex]._MarkedForDelete = true;

                _SaveUsersDataToFile(vUsers);

                *this = _GetEmptyUser();

                return true;

            }
        }

        return false;

    }
    
    static vector<clsUser> GetUsersList() {

        return _LoadUsersDataFromFile();
    
    }
    

};

