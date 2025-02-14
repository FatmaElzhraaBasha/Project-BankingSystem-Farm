#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class Parser {
public:
    static vector<string> split(string& line, char delimiter) {
        delimiter = ',';
        vector<string> result;
        stringstream ss(line);
        string field;

        while (getline(ss, field, delimiter)) {
            result.push_back(field);
        }
        return result;
    }

    static Client parseToClient(string& line) {
        vector<string> tokens = split(line,',');

        if (tokens.size() != 4) {
            throw invalid_argument("Invalid client data format!");
        }

        return Client(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Employee parseToEmployee(string& line) {
        vector<string> tokens = split(line,',');

        if (tokens.size() != 4) {
            throw invalid_argument("Invalid employee data format");
        }

        return Employee(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Admin parseToAdmin(string& line) {
        vector<string> tokens = split(line,',');

        if (tokens.size() != 4) {
            throw invalid_argument("Invalid admin data format");
        }

        return Admin(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }


    //static vector<string> split(string line) {
    //    char del = '&';
    //    vector<string> personVector;
    //    auto start = 0;
    //    auto end = line.find(del);
    //    cout << end;
    //    while (end != string::npos) {
    //        personVector.push_back(line.substr(start, end - start));
    //        start = end + 1;
    //        end = line.find(del, start);
    //    }
    //    personVector.push_back(line.substr(start));
    //    return personVector;
    //}
    //static Client parseToClient(string line) {
    //    Client parsedClient;
    //    vector<string> clientVector;
    //    clientVector = split(line);

    //    if (!clientVector.empty() && clientVector.size() == 4) {
    //        parsedClient.setName(clientVector[1]);
    //        parsedClient.setPassword(clientVector[2]);
    //        parsedClient.setBalance(stod(clientVector[3]));
    //        //parsedClient.setIdClient(stoi(clientVector[0]));
    //        parsedClient.setId(stoi(clientVector[0]));
    //    }
    //    else {
    //        cout << "Please enter a valid client" << endl;
    //    }
    //    return parsedClient;
    //}
    //static Employee parseToEmployee(string line) {
    //    Employee parsedEmployee;
    //    vector<string> employeeVector;
    //    employeeVector = split(line);
    //    if (!employeeVector.empty() && employeeVector.size() == 4) {

    //        parsedEmployee.setName(employeeVector[1]);
    //        parsedEmployee.setPassword(employeeVector[2]);
    //        parsedEmployee.setSalary(stod(employeeVector[3]));
    //        //parsedEmployee.setIdEmployee(stoi(employeeVector[0]));
    //        parsedEmployee.setId(stoi(employeeVector[0]));

    //    }
    //    else {
    //        cout << "Please enter a valid employee" << endl;
    //    }
    //    return parsedEmployee;
    //}

    //static Admin parseToAdmin(string line) {
    //    Admin parsedAdmin;
    //    vector<string> adminVector;
    //    adminVector = split(line);
    //    parsedAdmin.setName(adminVector[0]);
    //    parsedAdmin.setPassword(adminVector[1]);
    //    parsedAdmin.setSalary(stod(adminVector[2]));
    //    //parsedAdmin.setIdAdmin(stoi(adminVector[0]));
    //    parsedAdmin.setId(stoi(adminVector[0]));
    //    return parsedAdmin;
    //}

};

