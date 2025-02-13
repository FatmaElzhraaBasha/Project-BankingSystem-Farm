#pragma once
#include "Employee.h"

class Admin : public Employee {
public:
    // Constructors
    //1-Defaule Cons
    //==========================
    Admin() :Employee() {

    }

    //2-Parameterized Cons
    //============================
    Admin(int id, const string& name, const string& password, double salary) : Employee(id, name, password, salary) {
        this->id = 1;

    }

    // Display Info (overrid)
    void displayInfo() {
        cout << "     ** Admin Info **" << endl;
        cout << "Admin ID     : " << id << endl;
        cout << "Admin Name   : " << name << endl;
        cout << "Admin Salary : " << salary << endl;
        cout << "\n==============================\n";
    }
};

