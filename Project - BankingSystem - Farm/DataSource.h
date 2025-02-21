#pragma once
#include "global.h"

class DataSource {
protected:
    virtual void addClient(Client& client) = 0;
    virtual void addEmployee(Employee& employee) = 0;
    virtual void addAdmin(Admin& admin) = 0;
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee>getAllEmployees() = 0;
    virtual vector<Admin>getMyAdmin() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeMyAdmin() = 0;
};

