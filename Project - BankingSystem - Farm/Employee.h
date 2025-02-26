#pragma once
#include "Client.h"

class Employee : public Person {
protected:
    //Attributes
    double salary;
    int id;
    static int employeeCounter;        // Counter for unique ID generation

public:
    // Constructors
    //1-Defaule Cons
    //==========================
    Employee() {
        salary = 0;
        id = 0;
    }

    //2-Parameterized Cons
    //============================
    Employee(const string& name, const string& password, double salary)
        : Person(name, password) {
        setId(id);
        setSalary(salary);
    }

    // Setters
    void setSalary(double salary) {
        if (Validation::validateMinSalary(salary))
            this->salary = salary;
        else
            cout << "Invalid Salary" << endl;
    }

    void setId(int id) {
        this->id = employeeCounter++;
    }

    // Getters
    double getSalary() const {
        return this->salary;
    }
    int getId() const {
        return this->id;
    }

    //Methods:
    // To add new client
    void addClient(Client& client) {
        clientsInfo.push_back(client);
        saveClientsToFile();
    }

    // To save client data at file
    void saveClientsToFile() {
        ofstream file("Clients.txt", ios::trunc);
        for (auto& client : clientsInfo) {
            file << to_string(client.getId()) << "," << client.getName() << "," << 
                client.getPassword() << "," << client.getBalance() << endl;
        }
        file.close();
        cout << "Clients data saved to file." << endl;
    }

    // Search for client by id
    Client* searchClient(int id) {
        for (auto& client : clientsInfo) {
            if (client.getId() == id) {
                return &client;
            }
        }
        return nullptr; // Return null if client not found
    }

    // Search for client by Name
    Client* searchClient(string name) {
        for (auto& client : clientsInfo) {
            if (client.getName() == name) {
                return &client;
            }
        }
        return nullptr; // Return null if client not found
    }

    // list of clients to print
    void listClients() {
        if (clientsInfo.empty()) {
            cout << "No clients available." << endl;
            return;
        }
        cout << "List of Clients:" << endl;
        for (auto& client : clientsInfo) {
            cout << "ID: " << to_string(client.getId()) << ", Name: " << client.getName()
                << ", Balance: " << client.getBalance() << " EGP" << endl;
        }
    }

    // editing client name , id , pass or balance 
    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            saveClientsToFile();
            cout << "Client information updated successfully." << endl;
        }
        else {
            cout << "Client with ID " << id << " not found in the system." << endl;
        }
    }

    //Extra Methods
    // Read client details from Clients.txt
    void viewClientDetails(int id) {
        cout << "Viewing details for client ID: " << id << endl;
        searchClient(id);
        for (auto& client : clientsInfo) {
            if (client.getId() == id) {
                cout << "ID: " << to_string(client.getId()) << ", Name: " << client.getName()
                    << ", Balance: " << client.getBalance() << " EGP" << endl;
            }
        }
    }

    // Update loan data in client file
    void approveLoan(double amount) {
        Client client;
        if (amount <= client.getBalance() * 5) {
            client.deposit(amount);
            cout << "Loan approved for Client ID: " << client.getId() << " Amount: " << amount << endl;
        }
        else {
            cout << "Loan denied for Client ID: " << client.getId() << endl;
        }
    }

    // Function to block an account
    void blockClient(int & id) {
        fstream ClientsFile("Clients.txt"); // Original clients file
        fstream tempFile("temp.txt"); // Temporary file to store remaining customers
        fstream blockListFile("ClientsBlockList.txt", ios::app); // Append mode for blocked accounts

        if (!ClientsFile || !blockListFile || !tempFile) {
            cout << "Error opening files.\n";
            return;
        }

        string line;
        bool accountBlocked = false;

        while (getline(ClientsFile, line)) {
            if (line.find(id) != string::npos) {
                // Move the account to blockList.txt
                blockListFile << line << endl;
                accountBlocked = true;
            }
            else {
                // Keep other accounts in temp.txt
                tempFile << line << endl;
            }
        }

        ClientsFile.close();
        tempFile.close();
        blockListFile.close();

        // Replace original file with updated temp file
        remove("Clients.txt");
        rename("temp.txt", "Clients.txt");

        if (accountBlocked) {
            cout << "Client Who Has Id Number: " << id << " Has Been Blocked.\n";
        }
        else {
            cout << "Client Not Found!!.\n";
        }
    }

    // Update client balance in file
    void updateClientBalance(int id, double newBalance) {
        Client* client = searchClient(id);
        if (client) {
            client->setBalance(newBalance);
            saveClientsToFile();
            cout << "Updated balance for client ID: " << id << " New Balance: " << newBalance << " EGP" << endl;
        }
        else {
            cout << "Client with ID " << id << " not found in the system." << endl;
        }
    }

    // Display Info method (override)
    void displayInfo() {
        cout << "     ** Employee Info **" << endl;
        cout << "Employee ID     : " << id << endl;
        cout << "Employee Name   : " << name << endl;
        cout << "Employee Salary : " << salary << endl;
        cout << "\n==============================\n";
    }
};

//Global Vector
static vector <Employee> employeesInfo;
static vector <Employee>::iterator eItr;