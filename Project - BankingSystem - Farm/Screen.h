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
    // 1️⃣ عرض خيارات تسجيل الدخول
    static void logInOptions() {
        system("cls");
        cout << "\n=== Welcome to the Banking System ===\n";
        cout << "1- Log in as Client\n";
        cout << "2- Log in as Employee\n";
        cout << "3- Log in as Admin\n";
        cout << "4- Exit\n";
        cout << "Enter your choice: ";
    }

    // 2️⃣ تنفيذ تسجيل الدخول بناءً على اختيار المستخدم
    static int logInAs() {
        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number between 1-4.\n";
            return -1;  // إشارة إلى خطأ في الإدخال
        }

        return choice;  // إرجاع الرقم لاستخدامه لاحقاً
    }

    // 3️⃣ التعامل مع محاولات تسجيل الدخول الفاشلة
    static bool invalid(int userType) {
        int id, attempts = 3;
        string password;

        while (attempts > 0) {
            cout << "\nEnter ID: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> password;

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

            attempts--;
            cout << "Invalid credentials! Attempts left: " << attempts << "\n";
        }

        cout << "Too many failed attempts! Returning to main menu...\n";
        system("pause");
        return false;
    }

    // 4️⃣ تسجيل الخروج والعودة للقائمة الرئيسية
    static void logOut() {
        cout << "Logging out...\n";
        system("pause");
    }

    // 5️⃣ شاشة تسجيل الدخول بناءً على نوع المستخدم
    static void logInScreen(int userType) {
        if (!invalid(userType)) {
            return; // إذا فشل تسجيل الدخول، يرجع للقائمة الرئيسية
        }
    }

    // 6️⃣ تشغيل التطبيق
    static void runApp() {
        while (true) {
            logInOptions();
            int userType = logInAs();

            if (userType == 4) {
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



