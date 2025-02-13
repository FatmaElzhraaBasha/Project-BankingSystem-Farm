#pragma once
#include "Person.h"


class Employee : public Person {
protected:
    double salary;

public:
    // Constructors
    Employee() {
        salary = 0;
    }

    Employee(const string& name, const string& password, double balance, double salary) : Person(name, password, balance) {
        this->salary = salary;
    }

    // Setters
    void setSalary(double salary) {
        Validation::validateMinSalary(salary);
        this->salary = salary;
    }

    // Getters
    double getSalary() {
        return salary;
    }

    // Display Info method (override)
    void displayInfo() {
        cout << "Employee Info:" << endl;
        Person::displayInfo();
        cout << "Salary : " << salary << endl;
    }
};