#pragma once
#include "Person.h"

class Client : public Person {
private:
    //Attributes:
    double balance;
    static int clientCounter; // Counter for unique ID generation
    static const string bankKey;
    int id;

public:
    // Constructors
    //1-Defaule Cons
    //==========================
    Client() :Person() {
        balance = 0;
        id = 0;
    }

    //2-Parameterized Cons
    //============================
    /*Client(int id, const string& name, const string& password, double balance) : Person(id, name, password){
        setBalance(balance);
    }*/

    Client(const string& name, const string& password, double balance)
        : Person(name, password) {
        setId(id);
        setBalance(balance);
    }

    //Setters
    void setBalance(double balance) {
        if (Validation::validateMinBalance(balance))
            this->balance = balance;
        else
            cout << "Invalid Balance" << endl;
    }
    void setId(int id) {
        this->id = stoi(bankKey + to_string(++clientCounter));
    }

    //Getters
    double getBalance() const {
        return this->balance;
    }
    int getId() const {
        return this->id;
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
        cout << "      ** Client Info **" << endl;
        cout << "Client ID      : " << id << endl;
        cout << "Cient Name     : " << name << endl;
        cout << "Client Balance : " << balance << endl;
        cout << "\n==============================\n";
    }
};

