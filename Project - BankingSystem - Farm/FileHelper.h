#pragma once
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "global.h"
#include <string>

using namespace std;
class FilesHelper {
public:
    static void saveLast(string fileName, int id) {
        ofstream output;
        output.open(fileName);
        if (!output.is_open()) {
            cout << "Error openening the file" << endl;
            return;
        }
        output << id << endl;
        output.close();
    }
    static int getLast(string fileName) {
        int lastId;
        ifstream input;
        input.open(fileName);
        input >> lastId;
        input.close();
        return lastId;
    }
    static void saveClient(Client c) {
        ofstream output;
        output.open("Clients.txt");
        if (!output.is_open()) {
            cout << "Error openening the file" << endl;
            return;
        }
        output << c.getLastClientId() << " & " << c.getName() << " & " << c.getBalance() << endl;
        output.close();

    }
    static void saveEmployee(Employee e) {
        ofstream output;
        output.open("Employees.txt");
        if (!output.is_open())
        {
            cout << "Error openening the file" << endl;
            return;
        }
        output << e.getLastEmployeeId() << " & " << e.getName() << " & " << e.getSalary() << endl;
        output.close();
    }
    static void saveAdmin(Admin a) {
        ofstream output;
        output.open("Admin.txt");
        if (!output.is_open())
        {
            cout << "Error openening the file" << endl;
            return;
        }
        output << a.getLastEmployeeId() << " & " << a.getName() << " & " << a.getSalary() << endl;
        output.close();
    }
    static void getClients() {
        ifstream input;
        string fileName = "Clients.txt", line;
        input.open(fileName);
        if (!input.is_open()) {
            cout << "Error openening the file" << endl;
            return;
        }
        while (getline(input, line)) {
            Client c = Parser::parseToClient(line);
            clientVector.push_back(c);
        }
    }
    static void getEmployees() {
        ifstream input;
        input.open("Employees.txt");
        string line;
        if (!input.is_open()) {
            cout << "Error opening the file" << endl;
            return;
        }
        while (getline(input, line)) {
            Employee e = Parser::parseToEmployee(line);
            EmployeeVector.push_back(e);
        }
    }
    static void  getAdmins() {
        ifstream input;
        input.open("Admin.txt");
        string line;
        if (!input.is_open()) {
            cout << "Error opening the file" << endl;
            return;
        }
        while (getline(input, line)) {
            Admin a = Parser::parseToAdmin(line);
            AdminVector.push_back(a);
        }
    }
    static void clearFile(string fileName, string lastIdFile) {
        ofstream output;
        output.open(fileName, ofstream::out | ofstream::trunc);
        output.close();
        output.open(lastIdFile);
        output << 0 << endl;
        output.close();
        ////Todo reset the static id = 0;
    }
};

