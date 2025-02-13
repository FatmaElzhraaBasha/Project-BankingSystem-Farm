#pragma once
#include "Employee.h"

class Admin : public Employee {
public:
    // Constructors
    Admin() {

    }

    Admin(const string& name, const string& password, double balance, double salary) : Employee(name, password, balance, salary) {

    }

    // Display Info (overrid)
    void displayInfo() {
        cout << "Admin Info:" << endl;
        Employee::displayInfo();
    }
};