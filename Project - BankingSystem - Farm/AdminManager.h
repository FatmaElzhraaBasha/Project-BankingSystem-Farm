#pragma once
#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
#include "FileHelper.h"
#include "FileManager.h"
#include "EmployeeManager.h"
using namespace std;

class AdminManager
{
private:
    static void printAdminMenu() {
        cout << "\n=== Admin Menu ===\n";
        cout << "1- Display my info. " << endl;
        cout << "2- Add new client. " << endl;
        cout << "3- Search for client." << endl;
        cout << "4- List all clients. " << endl;
        cout << "5- Edit client info." << endl;
        cout << "6- Add Interest." << endl;
        cout << "7- Add new Employee. " << endl;
        cout << "8- Search for Employee." << endl;
        cout << "9- List all Employees. " << endl;
        cout << "10- Edit Employee info." << endl;
        cout << "11- Update Password\n";
        cout << "12- Logout\n";
        cout << "Enter your choice: ";
    }
public:
    // a method to clear input buffers (if someone entered wrong value or characters instead of numbers in cin, it resets the cin)
    static void clearInputBuffer() {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>);
    }

    //a method for updating Admin.txt file with the latest admin data
    static void updateAdminFile() {
        fstream file("Admin.txt", ios::trunc);
        for (const auto& admin : adminInfo) {
            file << admin.getId() << "," << admin.getName() << ","
                << admin.getPassword() << "," << admin.getSalary() << endl;
        }
        file.close();
    }

    // method for updating password (it checks if the password entered is not the same as the default password, also checks it with validation class)
    static void updatePassword(Admin& admin) {
        string newPassword, confirmPassword;
        clearInputBuffer();

        cout << "Enter new password: ";
        getline(cin, newPassword);

        cout << "Confirm new password: ";
        getline(cin, confirmPassword);

        if (newPassword != confirmPassword) {
            cout << "Passwords don't match!\n";
            return;
        }

        if (Validation::validatePassword(newPassword)) {
            admin.setPassword(newPassword);
            FileHelper::getMyAdmin();

            for (auto& existingEmployee : adminInfo) {
                if (existingEmployee.getId() == admin.getId()) {
                    existingEmployee = admin;
                    break;
                }
            }

            updateAdminFile();
            cout << "Password updated successfully!\n";
        }
    }

    static Admin* logIn(int id, string password) {
        id = 1;
        for (aItr = adminInfo.begin(); aItr != adminInfo.end(); aItr++) {
            if (aItr->getId() == id && aItr->getPassword() == password) {
                cout << "\nLogin Successful!\n";
                return aItr._Ptr;
            }
            else {
                cout << "\nInvalid ID or password.\n";
                return NULL;
            }
        }
    }

    static void addNewEmployeeInfo(Admin* admin) {
        Employee e = Employee();
        string name, password;
        double salary;
        cout << "Please enter a name of the Employee: " << endl;
        cin >> name;
        e.setName(name);
        cout << "Please enter a password of the Employee: " << endl;
        cin >> password;
        e.setPassword(password);
        cout << "Please enter a salary of the Employee: " << endl;
        cin >> salary;
        e.setSalary(salary);
        admin->addEmployee(e);
    }

    static void searchForEmployee(Admin* admin) {
        int id;
        system("cls");
        cout << "Enter Client id: ";
        cin >> id;
        if (admin->searchEmployee(id) == NULL)
            cout << "Employee Not Found" << endl;
        else
            admin->searchEmployee(id)->displayInfo();
    }

    static void editEmployeeInfo() {
        int id;
        string name, password;
        double salary;
        cout << "Please Enter Employee Id To Edit: " << endl;
        cin >> id;
        Admin* admin;
        admin->searchEmployee(id);
        if (admin) {
            cout << "Please Enter An Employee New Name: " << endl;
            cin >> name;
            cout << "Please Enter An Employee New Password: " << endl;
            cin >> password;
            cout << "Please Enter An Employee New Salary: " << endl;
            cin >> salary;
            employeesInfo[id].setName(name);
            employeesInfo[id].setPassword(password);
            employeesInfo[id].setSalary(salary);
            cout << "Employee updated successfully.\n";
        }
        else {
            cout << "Insert valid employee data.\n";
        }
    }

    static void AddToFile() {
        FileHelper::clearFile("Admin.txt", "LastAdminId.txt");
        FileManager::updateMyAdmin();
    }

    static bool AdminOptions(Admin* admin) {
        Employee* employee;
        while (true) {
            printAdminMenu();
            int option;
            cout << "Your choice is: " << endl;
            cin >> option;
            if (option > 0 && option < 12) {
                switch (option) {
                case 1:
                    system("cls");
                    admin->displayInfo();
                    break;
                case 2:
                    system("cls");
                    EmployeeManager::addNewClient(employee);
                    break;
                case 3:			
                    system("cls");
                    EmployeeManager::searchForClient(employee);
                    break;
                case 4: 
                    system("cls");
                    EmployeeManager::ListAllClient(employee);
                    break;
                case 5:
                    system("cls");
                    EmployeeManager::editClientInfo(employee);
                    break;
                case 6:
                    system("cls");
                    admin->addInterest();
                    break;
                case 7:
                    system("cls");
                    addNewEmployeeInfo(admin);
                    break;
                case 8:
                    system("cls");
                    searchForEmployee(admin);
                    break;
                case 9:
                    system("cls");
                    admin->listEmployee();
                    break;
                case 10: 
                    system("cls");
                    editEmployeeInfo();
                    break;
                case 11:
                    system("cls");
                    updatePassword(*admin);
                    break;
                case 12:
                    system("cls");
                    cout << "Logging out...\n";
                    return false;
                    break;
                default:
                    cout << "You Enter Invalid Number, Try Again !!" << endl;
                    break;
                }
            }
            else {
                cout << "Please enter a valid option" << endl;
                continue;
            }
        }
        return true;
    }
};

