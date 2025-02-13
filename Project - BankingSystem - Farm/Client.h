#pragma once
#include "Person.h"
#include "Validation.h"

class Client : public Person {
public:
    // Constructors
    Client() {}

    Client(const string& name, const string& password, double balance) : Person(name, password, balance) {

    }

    // Methods

    // Deposit method (with deposit validation method)
    void deposit(double amount) {
        Validation::validateDeposit(amount);
        balance += amount;
    }

    // Withdraw method (with withdrawal validation method)
    void withdraw(double amount) {
        Validation::validateWithdraw(amount, balance);
        balance -= amount;
    }

    // Transfer to another Client method
    void transferTo(double amount, Client& recipient) {
        Validation::validateTransfer(amount, balance);
        withdraw(amount);
        recipient.deposit(amount);
    }

    // Check balance method
    void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }

    // Display Info method (overrid)
    void displayInfo() {
        cout << "Client Info: " << endl;
        Person::displayInfo();
    }
};