#pragma once
#include "Person.h"
#include <vector>
#include <fstream>

class Client : public Person {
private:
    //Attributes:
    double balance;
    static int clientCounter; // Counter for unique ID generation
    static const string bankKey;
    int id;
    static vector <string> transactions;

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
    //To Record Transaction History In Vector
    void recordTransaction(const string& transaction) {
        transactions.push_back(transaction);
    }

     //To save client data at file
    void saveTransactionToFile() {
        ofstream actionFile("Transactions.txt"); // Open file for writing

        if (!actionFile) {
            cout << "Error opening file: " << "Transaction.txt" << endl;
            return;
        }

        for (const string& item : transactions) {
            actionFile << item << endl; // Write each item in a new line
        }

        actionFile.close();
        cout << "Data saved successfully to " << "Transaction.txt" << endl;
    }

    // Deposit method (with deposit validation method)
    void deposit(double amount) {
        Validation::validateDeposit(amount);
        balance += amount;
        recordTransaction("Deposit: +" + to_string(amount));
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    // Withdraw method (with withdrawal validation method)
    void withdraw(double amount) {
        Validation::validateWithdraw(amount, balance);
        balance -= amount;
        recordTransaction("Withdraw: -" + to_string(amount));
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }

    // Transfer to another Client method
    void transferTo(double amount, Client& recipient) {
        Validation::validateTransfer(amount, balance);
        withdraw(amount);
        recipient.deposit(amount);
        recordTransaction("Transfer: -" + to_string(amount) + " to Client ID " + to_string(recipient.getId()));
        recipient.recordTransaction("Transfer: +" + to_string(amount) + " from Client ID " + to_string(getId()));
        cout << "Transfer successful." << endl;
    }

    // Check balance
    void checkBalance() const {
        cout << "Current balance: " << this->balance << endl;
    }

    // To Exchange Currency To From Egyption Pound
    void currencyExchange() {
        // Exchange rates (1 EGP to other currencies)
        const double USD = 0.019;  // US Dollar
        const double EUR = 0.018;  // Euro
        const double GBP = 0.015;  // British Pound
        const double SAR = 0.074;   // Saudi Riyal
        const double AED = 0.072;   // UAE Dirham

        int choice;
        double amount, convertedAmount;
        double exchangeRate = 1.0;  // Default exchange rate

        cout << "Select conversion type:\n";
        cout << "1. Convert from Egyptian Pound (EGP) to another currency\n";
        cout << "2. Convert from another currency to Egyptian Pound (EGP)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << "\nSelect the target currency:\n";
        cout << "1. US Dollar (USD)\n";
        cout << "2. Euro (EUR)\n";
        cout << "3. British Pound (GBP)\n";
        cout << "4. Saudi Riyal (SAR)\n";
        cout << "5. UAE Dirham (AED)\n";
        cout << "Enter your choice: ";

        int currencyChoice;
        cin >> currencyChoice;

        // Set exchange rate based on user choice
        switch (currencyChoice) {
        case 1: exchangeRate = USD; break;
        case 2: exchangeRate = EUR; break;
        case 3: exchangeRate = GBP; break;
        case 4: exchangeRate = SAR; break;
        case 5: exchangeRate = AED; break;
        default:
            cout << "Invalid choice.\n";
            return;
        }

        cout << "Enter the amount: ";
        cin >> amount;

        // Perform conversion
        if (choice == 1) {
            convertedAmount = amount * exchangeRate;
            cout << "Converted amount: " << convertedAmount << endl;
        }
        else if (choice == 2) {
            convertedAmount = amount / exchangeRate;
            cout << "Converted amount in Egyptian Pounds: " << convertedAmount << " EGP" << endl;
        }
        else {
            cout << "Invalid choice.\n";
            return;
        }
        //recordTransaction("Currency Exchange: " + to_string(convertedAmount));
    }

    bool takeLoan(double amount) {
        if (amount <= balance * 5) {
            balance += amount;
            recordTransaction("Loan Taken: " + to_string(amount));
            cout << "Loan approved! New balance: " << balance << endl;
            return true;
        }
        cout << "Loan request denied." << endl;
        return false;
    }

    void statementOfAccount() {
        cout << "Statement of Account for Client ID: " << getId() << endl;
        for (auto& transaction : transactions) {
            cout << transaction << endl;
        }
    }

    void accountStatement() {
        ifstream file("Transactions.txt");
        cout << "Account Statement for " << name << " (ID: " << id << ")\n";
        cout << "Current Balance: " << balance << endl;
        cout << "-----------------------------------\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
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

//Global Vector
static vector <Client> clientsInfo;
static vector <Client>::iterator cItr;


