#pragma once
#include "Person.h"
#include <iostream>
using namespace std;
class Employee : public Person
{
private:
    string _Title;
    int _Salary;
    string _Department;
public:
    Employee(int ID, string FirstName, string LastName, string Title, int Salary, string Department, string Email, string Phone, string addressLine1, string addressLine2, string city, string country)
        :Person(ID, FirstName, LastName, Email, Phone, addressLine1, addressLine2, city, country)
    {
        _Title = Title;
        _Salary = Salary;
        _Department = Department;
    }
    void SetTitle(string Title) {
        _Title = Title;
    }
    string Title() {
        return _Title;
    }

    void SetSalary(int Salary) {
        _Salary = Salary;
    }
    int Salary() {
        return _Salary;
    }

    void SetDepartment(string Department) {
        _Department = Department;
    }
    string Department() {
        return _Department;
    }

    void Print() {
        printf("--------------------------------------------------\n");
        printf("ID : %d\n", GetID());
        printf("First name : %s\n", FirstName().c_str());
        printf("Last name : %s\n", LastName().c_str());
        printf("Full name: %s %s\n", FirstName().c_str(), LastName().c_str());
        printf("Title : %s\n", _Title.c_str());
        printf("Salary : %d\n", _Salary);
        printf("Department : %s\n", _Department.c_str());
        printf("Email : %s\n", Email().c_str());
        printf("Phone : %s\n", Phone().c_str());
        printf("--------------------------------------------------\n");
    }
};


