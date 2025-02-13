#pragma once
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

class Validation {
public:

    // Validate name (must be between 5 and 20 characters in length / the name should only contain alphabetic characters and spaces only)
    static void validateName(const string& name) {
        if (name.length() < 5 || name.length() > 20) {
            throw invalid_argument("Name must be between 5 and 20 characters");
        }

        for (int i = 0; i < name.length(); i++) {
            if (!(isalpha(name[i]) || name[i] == ' ')) {
                throw invalid_argument("Name must contain only alphabetic characters and spaces.");
            }
        }
    }

    // Validate password (must be between 8 and 20 characters in length)
    static void validatePassword(const string& password) {
        if (password.length() < 8 || password.length() > 20) {
            throw invalid_argument("Password must be between 8 and 20 characters");
        }
    }

    // Validate minimum balance amount (must be more than 1500)
    static void validateMinBalance(double balance) {
        if (balance < 1500) {
            throw invalid_argument("Balance must be at least 1500.");
        }
    }

    // Validate minimum salary amount (must be more than 5000)
    static void validateMinSalary(double salary) {
        if (salary < 5000) {
            throw invalid_argument("Salary must be at least 5000.");
        }
    }

    // Validate deposit amount (must be positive)
    static void validateDeposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be greater than 0.");
        }
    }

    // Validate withdrawal amount (must be positive and not exceed balance)
    static void validateWithdraw(double amount, double balance) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be greater than 0.");
        }
        if (amount > balance) {
            throw invalid_argument("Insufficient balance.");
        }
    }

    // Validate transfer amount (must be positive and not exceed balance)
    static void validateTransfer(double amount, double balance) {
        if (amount <= 0) {
            throw invalid_argument("Transfer amount must be greater than 0.");
        }
        if (amount > balance) {
            throw invalid_argument("Insufficient balance.");
        }
    }

};