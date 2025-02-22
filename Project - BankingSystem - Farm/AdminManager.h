#pragma once
#include <iostream>
#include "Client.h"
using namespace std;

class AdminManager
{
public:
    static void printClientMenu() {
        cout << "Client Menu:\n";
        cout << "1. View Account Details\n";
        cout << "2. Make a Transaction\n";
        cout << "3. Logout\n";
    }

    static Client* login(int id, string password) {

        // For testing i create a sample client.
        Client* sampleClient = new Client(1234, "password123");

        if (sampleClient->authenticate(id, password)) {
            cout << "Login successful!\n";
            return sampleClient;
        }
        else {
            cout << "Invalid Password or Id.\n";
            delete sampleClient; // Clean up memory
            return nullptr;
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

