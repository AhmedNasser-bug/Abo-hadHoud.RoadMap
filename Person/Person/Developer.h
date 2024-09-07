#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;

class Developer : public Employee
{
private:
    string _MainProgrammingLanguage;
public:
    Developer(int ID, string FirstName, string LastName, string Title, int Salary, string Department, string Email, string Phone, string MainProgrammingLanguage, string addressLine1, string addressLine2, string city, string country)
        : Employee(ID, FirstName, LastName, Title, Salary, Department, Email, Phone, addressLine1, addressLine2, city, country)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    void SetMainProgrammingLanguage(string MainProgrammingLanguage) {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }
    string MainProgrammingLanguage() {
        return _MainProgrammingLanguage;
    }

    void Print() {
        printf("--------------------------------------------------\n");
        printf("ID : %d\n", GetID());
        printf("First name : %s\n", FirstName().c_str());
        printf("Last name : %s\n", LastName().c_str());
        printf("Full name: %s %s\n", FirstName().c_str(), LastName().c_str());
        printf("Title : %s\n", Title().c_str());
        printf("Salary : %d\n", Salary());
        printf("Department : %s\n", Department().c_str());
        printf("Main programming Language : %s\n", MainProgrammingLanguage().c_str());
        printf("Email : %s\n", Email().c_str());
        printf("Phone : %s\n", Phone().c_str());
        printf("--------------------------------------------------\n");
    }
};

