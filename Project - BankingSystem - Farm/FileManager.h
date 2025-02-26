#pragma once
#include "DataSource.h"
#include "FileHelper.h"

class FileManager : public DataSource {
private:
    static void addClient(Client& client) {
        FileHelper::saveClient(client);
    }

    static void addEmployee(Employee& employee) {
        FileHelper::saveEmployee(employee);
    }

    static void addAdmin(Admin& admin) {
        FileHelper::saveMyAdmin(admin);
    }

    static void getAllClients() {
        FileHelper::getClients();
    }

    static void getAllEmployees() {
        FileHelper::getEmployees();
    }

    static void getMyAdmin() {
        FileHelper::getMyAdmin();
    }

    static void removeAllClients() {
        FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }

    static void removeAllEmployees() {
        FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
    }

    static void removeMyAdmin() {
        FileHelper::clearFile("Admin.txt", "AdminId.txt");
    }

public:
    static void getAllData() {
        getAllClients();
        getAllEmployees();
        getMyAdmin();
    }

    static void updateClients() {
        removeAllClients();
        for (cItr = clientsInfo.begin(); cItr != clientsInfo.end(); cItr++)
            addClient(*cItr);
    }

    static void updateEmployees() {
        removeAllEmployees();
        for (eItr = employeesInfo.begin(); eItr != employeesInfo.end(); eItr++)
            addEmployee(*eItr);
    }
    
    static void updateMyAdmin() {
        removeMyAdmin();
        for (aItr = adminInfo.begin(); aItr != adminInfo.end(); aItr++)
            addAdmin(*aItr);
    }

};

