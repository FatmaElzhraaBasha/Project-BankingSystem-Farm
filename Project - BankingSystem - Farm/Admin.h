#pragma once
#include "Employee.h"

class Admin : public Employee {
private:
    // Constructors
    //1-Defaule Cons
    //==========================
    // Private constructor to prevent object creation from outside
    Admin() {
        this->id = 1;
    }

    //2-Parameterized Cons
    //============================
    Admin(const string& name, const string& password, double salary) : Employee(name, password, salary) {
        this->id = 1;
    }

    // The single instance of Admin (Singleton Pattern)
    static Admin* myAdmin;

public:
    // Delete copy constructor and assignment operator to prevent duplication
    /*Admin(const Admin&) = delete;
    Admin& operator=(const Admin&) = delete;*/

    // Static method to get the single instance of Admin
    static Admin* getMyAdmin() {
        if (myAdmin == nullptr) {
            myAdmin = new Admin();
        }
        return myAdmin;
    }

    //Methods
    // Adding new Employee
    void addEmployee(Employee& employee) {
        employeesInfo.push_back(employee);
        saveEmployeeToFile();
    }

    // To save employee data at file
    void saveEmployeeToFile() {
        fstream file("Employee.txt", ios::trunc);
        for (const auto& employee : employeesInfo) {
            file << employee.getId() << "," << employee.getName() << "," 
                << employee.getPassword()<<","<<employee.getSalary() << endl;
        }
        file.close();
        cout << "Employee data saved to file." << endl;
    }

    // search for Employee by id
    Employee* searchEmployee(int id) {
        for (auto& employee : employeesInfo) {
            if (employee.getId() == id)
                return &employee;
        }
        return nullptr;
    }

    // Editing Employee data
    void editEmployee(int id, string name, string password, double salary) {
        Employee* employee = searchEmployee(id);
        if (employee) {
            employee->setName(name);
            employee->setPassword(password);
            employee->setSalary(salary);
            cout << "Employee updated successfully.\n";
        }
        else {
            cout << "Insert valid employee data.\n";
        }
    }

    // All Employee list ready for print
    void listEmployee() {
        for (const auto& employee : employeesInfo) {
            //cout << "Employee ID: " << employee.getId() << ", Name: " << employee.getName()
             //   << ", Salary: " << employee.getSalary() << endl;

            cout << "Employee ID: " << employee.getId() << ", Password: " << employee.getPassword() <<
                ", Name: " << employee.getName() << ", Salary : " << employee.getSalary() << endl;
        }
    }

    void addInterest() {
        double interestRate = 7;
        //time_t now = time(0);
        //tm* ltm = localtime(&now);
        //if (ltm->tm_mday == 7) {
            for (auto& client : clientsInfo) {
                double interest = client.getBalance() * (interestRate / 100);
                client.setBalance(client.getBalance() + interest);
                cout << "Interest Added: " << interest << ", New Balance: " << client.getBalance() << endl;
                cout << "Interest Added Succefully ..." << endl;
            }
        }

    // Display Info (overrid)
    void displayInfo() {
        cout << "     ** Admin Info **" << endl;
        cout << "Admin ID     : " << id << endl;
        cout << "Admin Name   : " << name << endl;
        cout << "Admin Salary : " << salary << endl;
        cout << "\n==============================\n";
    }
};

//Global Vector
static vector <Admin> adminInfo;
static vector <Admin>::iterator aItr;