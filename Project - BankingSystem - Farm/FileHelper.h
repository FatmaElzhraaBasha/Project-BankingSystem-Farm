#pragma once
#include <stdio.h>
#include <string>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "global.h"

using namespace std;
class FileHelper {
private:
    static void saveLast(string fileName, int id) {
        ofstream output;
        output.open(fileName);
        if (!output.is_open()) {
            cout << "Error Openening The File !!" << endl;
            return;
        }
        output << id << endl;
        output.close();
    }

public:
    static int getLast(string fileName) {
        int lastId;
        ifstream input;
        input.open(fileName);
        input >> lastId;
        input.close();
        return lastId;
    }

    static void saveClient(Client c) {
        char delimiter = ',';
        int id = getLast("ClientLastId.txt");
        string fileName = "Clients.txt";
        fstream output(fileName, ios::app);

        if (!output.is_open()) {
            cout << "Error Openening The File !!" << endl;
            return;
        }

        output << id+1 << delimiter << c.getName() << delimiter << c.getPassword() << delimiter << c.getBalance() << endl;
        output.close();
    }

    static void saveEmployee(Employee e) {
        char delimiter = ',';
        int id = getLast("EmployeeLastId.txt");
        string fileName = "Employees.txt";
        fstream output(fileName, ios::app);

        if (!output.is_open()) {
            cout << "Error Openening The File !!" << endl;
            return;
        }

        output << id+1 << delimiter << e.getName() << delimiter << e.getPassword() << delimiter << e.getSalary() << endl;
        output.close();
    }

    static void saveMyAdmin(Admin a) {
        char delimiter = ',';
        string fileName = "Admin.txt";
        fstream output(fileName, ios::out);

        if (!output.is_open()) {
            cout << "Error Openening The File !!" << endl;
            return;
        }

        output << a.getId() << delimiter << a.getName() << delimiter << a.getPassword() << delimiter << a.getSalary() << endl;

        //To Know How many Lines In Admin File To check Sigleton Princible
        int lineCount = 0;
        string line;
        while (getline(output, line)) {
            Admin a = Parser::parseToAdmin(line);
            adminInfo.push_back(a);
            lineCount++;
        }
        (lineCount == 1) ? cout << "Data Correct" : cout << "Data Wrong";
        output.close();
    }

    static void getClients() {
        string fileName = "Clients.txt", line;
        fstream input(fileName, ios::in);

        if (!input.is_open()) {
            cout << "Error Openening The File !!" << endl;
            return;
        }

        while (getline(input, line)) {
            Client c = Parser::parseToClient(line);
            clientsInfo.push_back(c);
        }
        input.close();
    }

    static void getEmployees() {
        string fileName = "Employees.txt", line;
        fstream input(fileName, ios::in);

        if (!input.is_open()) {
            cout << "Error Openening The File !!" << endl;
            return;
        }

        while (getline(input, line)) {
            Employee e = Parser::parseToEmployee(line);
            employeesInfo.push_back(e);
        }
        input.close();
    }

    static void getMyAdmin() {
        string fileName = "Admin.txt", line;
        fstream input(fileName, ios::in);

        if (!input.is_open()) {
            cout << "Error Openening The File !!" << endl;
            return;
        }

        int lineCount = 0;
        while (getline(input, line)) {
            Admin a = Parser::parseToAdmin(line);
            adminInfo.push_back(a);
            lineCount++;
        }
        input.close();

        //To Know How many Lines In Admin File To check Sigleton Princible
        (lineCount == 1) ? cout << "Data Correct" : cout << "Data Wrong";
    }

    static void clearFile(string fileName, string lastIdFile) {
        ofstream output;
        output.open(fileName, ofstream::out | ofstream::trunc);
        output.close();
        output.open(lastIdFile);
        output << 0 << endl;
        output.close();
    }
};

