#pragma once
#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
#include "global.h"
using namespace std;

class AdminManager
{
public:
    static void printAdminMenu() {
        cout << "Admin Menu:\n";
        cout << "1. View Account Details\n";
        cout << "2. Make a Transaction\n";
        cout << "3. Logout\n";
    }

    static Admin* logIn(int id, string password) {
        for (aItr == adminInfo.begin(); aItr != adminInfo.end(); aItr++) {
            if (aItr->getId() == id && aItr->getPassword() == password) {
                cout << "\nLogin successful!\n";
                return aItr._Ptr;
            }
            else {
                cout << "\nInvalid ID or password.\n";
                return NULL;
            }
        }
    }

    static bool AdminOptions(Client* client) {
        if (client == nullptr) {
            cout << "No client found. Access denied.\n";
            return false;
        }

        cout << "Admin Options:\n";
        cout << "1. Reset Password\n";
        cout << "2. View Transactions\n";
        cout << "3. Logout\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Resetting password...\n";
            return true;
        case 2:
            cout << "Viewing transactions...\n";
            return true;
        case 3:
            cout << "Logging out...\n";
            return false;
        default:
            cout << "Invalid option.\n";
            return false;
        }
    }
};

