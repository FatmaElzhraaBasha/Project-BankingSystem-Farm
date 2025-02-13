#pragma once
#include <iostream>
#include "Validation.h"

using namespace std;

class Person {
protected:
    int id;
    string name;
    string password;
    double balance;
    static int idCounter;

public:
    // Constructors
    Person() {
        id = ++idCounter;
        balance = 0;
    }

    Person(const string& name, const string& password, double balance) {
        this->id = ++idCounter;
        this->name = name;
        this->password = password;
        this->balance = balance;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(const string& name) {
        Validation::validateName(name);
        this->name = name;
    }

    void setPassword(const string& password) {
        Validation::validatePassword(password);
        this->password = password;
    }

    void setBalance(double balance) {
        Validation::validateMinBalance(balance);
        this->balance = balance;
    }

    // Getters
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getPassword() const {
        return password;
    }

    double getBalance() const {
        return balance;
    }

    // Methods
    virtual void displayInfo() const {
        cout << "ID     : " << id << endl;
        cout << "Name   : " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};