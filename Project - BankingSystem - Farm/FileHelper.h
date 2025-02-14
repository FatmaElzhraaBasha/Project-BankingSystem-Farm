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
class FileHelper {
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
        string fileName = "Clients.txt";
        fstream output(fileName, ios::app);
        if (!output.is_open()) {
            cout << "Error openening the file" << endl;
            return;
        }
        //output << c.getIdClient() << "&" << c.getName() << "&" << c.getPassword() << "&" << c.getBalance() << endl;
        output << c.getId() << "&" << c.getName() << "&" << c.getPassword() << "&" << c.getBalance() << endl;
        output.close();

    }
    static void saveEmployee(Employee e) {
        string fileName = "Employees.txt";
        fstream output(fileName, ios::app);
        if (!output.is_open()) {
            cout << "Error openening the file" << endl;
            return;
        }
        //output << e.getIdEmployee() << "&" << e.getName() << "&" << e.getPassword() << "&" << e.getSalary() << endl;
        output << e.getId() << "&" << e.getName() << "&" << e.getPassword() << "&" << e.getSalary() << endl;
        output.close();
    }
    static void saveAdmin(Admin a) {
        string fileName = "Admin.txt";
        fstream output(fileName, ios::app);
        if (!output.is_open()) {
            cout << "Error openening the file" << endl;
            return;
        }
        //output << a.getIdAdmin() << "&" << a.getName() << "&" << a.getPassword() << "&" << a.getSalary() << endl;
        output << a.getId() << "&" << a.getName() << "&" << a.getPassword() << "&" << a.getSalary() << endl;
        output.close();
    }
    static void getClients() {
        string fileName = "Clients.txt", line;
        fstream input(fileName, ios::in);
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
        string fileName = "Employees.txt", line;
        fstream input(fileName, ios::in);
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
        string fileName = "Admin.txt", line;
        fstream input(fileName, ios::in);
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

