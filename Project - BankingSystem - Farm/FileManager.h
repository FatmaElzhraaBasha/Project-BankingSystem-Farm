#pragma once
#include "DataSource.h"
#include "FileHelper.h"
#include <fstream>
#include <stdio.h>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class FileManager : public DataSource {
public:
    FileManager() {}
    void addClient(Client& client) {
        FileHelper::saveClient(client);
    }
    void addEmployee(Employee& employee) {
        FileHelper::saveEmployee(employee);
    }
    void addAdmin(Admin& admin) {
        FileHelper::saveAdmin(admin);
    }
    vector<Client> getAllClients() {
        FileHelper::getClients();
        return clientVector;
    }
    vector<Employee>getAllEmployees() {
        FileHelper::getEmployees();
        return EmployeeVector;
    }
    vector<Admin>getAllAdmins() {
        FileHelper::getAdmins();
        return AdminVector;
    }
    void removeAllClients() {
        FileHelper::clearFile("Clients", "ClientsLast");
    }
    void removeAllEmployees() {
        FileHelper::clearFile("Employee", "EmployeeLast");

    }
    void removeAllAdmins() {
        FileHelper::clearFile("Admin", "AdminLast");

    }
};

