#pragma once
#include <iostream>
#include <string>
using namespace std;

class Validation {
public:

    // Validate name
    // Must be between 5 and 20 characters in length 
    // The name should only contain alphabetic characters and spaces only

    static bool validateName(const string& name) {
        if (!(name.length() >= 5 && name.length() <= 20)) {
            cout << "Name must be between 5 and 20 characters\n";
            return false;
        }

        for (int i = 0; i < name.length(); i++) {
            if (!(isalpha(name[i]) || name[i] == ' ')) {
                cout << "Name must contain only alphabetic characters and spaces.";
                return false;
            }
            return true;
        }
    }

    // Validate password
    // Must be between 8 and 20 characters in length

    static bool validatePassword(const string& password) {
        if (!(password.length() >= 8 && password.length() <= 20)) {
            cout << "Password must be between 8 and 20 characters";
            return false;
        }

        //To check if password strong or not
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        string specialChars = "@$!%*?&";

        for (char ch : password) {
            if (isupper(ch))
                hasUpper = true;
            else if (islower(ch))
                hasLower = true;
            else if (isdigit(ch))
                hasDigit = true;
            else if (specialChars.find(ch) != string::npos)  //To search is special char is found or not
                hasSpecial = true;
        }
        return true;
        //return hasUpper && hasLower && hasDigit && hasSpecial;
    }

    // Validate minimum balance amount (must be more than 1500)
    static bool validateMinBalance(double balance) {
        if (balance < 1500) {
            cout << "Balance must be at least 1500.";
            return false;
        }
        return true;
    }

    // Validate minimum salary amount (must be more than 5000)
    static bool validateMinSalary(double salary) {
        if (salary < 5000) {
            cout << "Salary must be at least 5000.";
            return false;
        }
        return true;
    }

    // Validate deposit amount (must be positive)
    static bool validateDeposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be greater than 0.";
            return false;
        }
        return true;
    }

    // Validate withdrawal amount (must be positive and not exceed balance)
    static bool validateWithdraw(double amount, double balance) {
        if (amount <= 0) {
            cout << "Deposit amount must be greater than 0.";
            return false;
        }
        return true;

        if (amount > balance) {
            cout << "Insufficient balance.";
            return false;
        }
        return true;
    }

    // Validate transfer amount (must be positive and not exceed balance)
    static bool validateTransfer(double amount, double balance) {
        if (amount <= 0) {
            cout << "Transfer amount must be greater than 0.";
            return false;
        }
        return true;

        if (amount > balance) {
            cout << "Insufficient balance.";
            return false;
        }
        return true;
    }
};
