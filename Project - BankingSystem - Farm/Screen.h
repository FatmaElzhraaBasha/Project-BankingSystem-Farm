#pragma once
#include <stdio.h>
#include <windows.h>
#include "iostream"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "FileManager.h"
#include "stdio.h"
#include "Welcome.h"
using namespace std;

class Screen {
public:
    // 1️⃣ Display login options menu
    static void logInOptions() {
        system("cls");
        cout << "\n=== Welcome to the Banking System ===\n";
        cout << "1- Log in as Client\n";
        cout << "2- Log in as Employee\n";
        cout << "3- Log in as Admin\n";
        cout << "4- Exit\n";
        cout << "Enter your choice: ";
    }

    // 2️⃣ Get user choice and validate input
    static int logInAs() {
        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number between 1-4.\n";
            return -1;  // Indicates an invalid input
        }

        return choice;  // Return valid choice for further processing
    }

    // 3️⃣ Handle login attempts and limit them to 3 tries
    static bool invalid(int userType) {
        int id, attempts = 3;
        string password;

        while (attempts > 0) {
            cout << "\nEnter ID: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> password;

            // Attempt login based on user type
            if (userType == 1) {
                Client* client = ClientManager::logIn(id, password);
                if (client) {
                    while (ClientManager::clientOptions(client));
                    return true;
                }
            }
            else if (userType == 2) {
                Employee* employee = EmployeeManager::logIn(id, password);
                if (employee) {
                    while (EmployeeManager::employeeOptions(employee));
                    return true;
                }
            }
            else if (userType == 3) {
                Admin* admin = AdminManager::logIn(id, password);
                if (admin) {
                    while (AdminManager::adminOptions(admin));
                    return true;
                }
            }

            // Reduce attempts if login fails
            attempts--;
            cout << "Invalid credentials! Attempts left: " << attempts << "\n";
        }

        // Return to the main menu after 3 failed attempts
        cout << "Too many failed attempts! Returning to main menu...\n";
        system("pause");
        return false;
    }

    // 4️⃣ Logout and return to the main menu
    static void logOut() {
        cout << "Logging out...\n";
        system("pause");
    }

    // 5️⃣ Handle login screen based on user selection
    static void logInScreen(int userType) {
        if (!invalid(userType)) {
            return; // If login fails, return to the main menu
        }
    }

    // 6️⃣ Run the main application loop
    static void runApp() {
        FileManager::getAllData();
        Welcome::hello();
        Welcome::welcome();
        Welcome::message();
        while (true) {
            logInOptions();
            int userType = logInAs();

            if (userType == 4) { // Exit the system
                cout << "Exiting the system...\n";
                break;
            }

            if (userType != -1) {
                logInScreen(userType);
                logOut();
            }
        }
    }
};




