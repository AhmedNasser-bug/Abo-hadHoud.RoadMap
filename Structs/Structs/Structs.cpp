#include <iostream>
#include <string>
using namespace std;

enum enColor { Red, Green, Yellow, Blue };
enum enGendor { Male, Female };
enum enMaritalStatus { Single, Married };
int y = stoi("123");

struct stAddress
{
    int x = ::y;
    string StreetName;
    string BuildingNo ;
    string POBox;
    string ZipCode;
    enMaritalStatus Operand;
    struct x {
        string whta;
        string why;
    };
};


struct stContactInfo
{
    string Phone;
    string Email;
    stAddress Address;
};


struct stPerson
{

    string FirstName;
    string LastName;

    stContactInfo ContactInfo;

    enMaritalStatus MaritalStatues;
    enGendor Gendor;
    enColor FavourateColor;
};


int main()
{
    stPerson Person1;
    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu-Hadhoud";
    Person1.ContactInfo.Email = "xyz@xyz.com";
    Person1.ContactInfo.Phone = "+961000000999";
    Person1.ContactInfo.Address.POBox = "7777";
    Person1.ContactInfo.Address.ZipCode = "11194";
    Person1.ContactInfo.Address.StreetName = "Queen1 Street";
    

    Person1.Gendor = enGendor::Male;
    Person1.MaritalStatues = enMaritalStatus::Married;
    Person1.FavourateColor = enColor::Green;

    cout << Person1.ContactInfo.Address.x << endl;


}