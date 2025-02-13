#pragma once
#include "DataSource.h"
#include "FilesHelper.h"
#include <fstream>
#include <stdio.h>
using namespace std;

class FileManager : public DataSource {
public:
    FileManager() {}
    void addClient(Client& client) {
        FilesHelper::saveClient(client);
    }
    void addEmployee(Employee& employee) {
        FilesHelper::saveEmployee(employee);
    }
    void addAdmin(Admin& admin) {
        FilesHelper::saveAdmin(admin);
    }
    vector<Client> getAllClients() {
        FilesHelper::getClients();
        return clientVector;
    }
    vector<Employee>getAllEmployees() {
        FilesHelper::getEmployees();
        return EmployeeVector;
    }
    vector<Admin>getAllAdmins() {
        FilesHelper::getAdmins();
        return AdminVector;
    }
    void removeAllClients() {
        FilesHelper::clearFile("Clients", "ClientsLast");
    }
    void removeAllEmployees() {
        FilesHelper::clearFile("Employee", "EmployeeLast");

    }
    void removeAllAdmins() {
        FilesHelper::clearFile("Admin", "AdminLast");

    }
};

