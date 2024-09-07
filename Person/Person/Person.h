#pragma once
#include <iostream>
using namespace std;
class Person {
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;
    class Address
    {
    public:
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
        Address() {
        }
        Address(string addressLine1, string addressLine2, string city, string country) {
            AddressLine1 = addressLine1;
            AddressLine2 = addressLine2;
            City = city;
            Country = country;
        }
        void Print()
        {
            cout << "\nAddress:\n";
            cout << AddressLine1 << endl;
            cout << AddressLine2 << endl;
            cout << City << endl;
            cout << Country << endl;
        }
    };

public:
    Address _Address;
    Person(int ID, string FirstName, string LastName, string Email, string Phone, string addressLine1, string addressLine2, string city, string country) {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
        _Address = Address(addressLine1, addressLine2, city, country);
    }


    int GetID() const {
        return _ID;
    }

    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    string FirstName() {
        return _FirstName;
    }

    void SetLastName(string LastName) {
        _LastName = LastName;
    }
    string LastName() {
        return _LastName;
    }

    void SetEmail(string Email) {
        _Email = Email;
    }
    string Email() {
        return _Email;
    }

    void SetPhone(string Phone) {
        _Phone = Phone;
    }
    string Phone() {
        return _Phone;
    }

    string FullName() {
        return _FirstName + " " + _LastName;
    }
    virtual void Print() {
        printf("--------------------------------------------------\n");
        printf("ID : %d\n", _ID);
        printf("First name : %s\n", _FirstName.c_str());
        printf("Last name : %s\n", _LastName.c_str());
        printf("Full name: %s %s\n", _FirstName.c_str(), _LastName.c_str());
        printf("Email : %s\n", _Email.c_str());
        printf("Phone : %s\n", _Phone.c_str());
        printf("--------------------------------------------------\n");
    }
    void SendEmail(string Subject, string Body) {
        printf("Successfully sent from the email : %s\n", _Email.c_str());
        printf("Subject : %s\n", Subject.c_str());
        printf("Body : %s\n", Body.c_str());
    }
    void SendSMS(string Body) {
        printf("Sent from phone : %s\n", _Phone.c_str());
        cout << Body << endl;

    }

};

