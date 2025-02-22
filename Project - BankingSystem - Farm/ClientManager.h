#pragma once
#include "Client.h"
#include <iostream>
#include "FileManager.h"
#include <limits>
#include "Validation.h"

class ClientManager {
private:
    static void printClientMenu() {
        cout << "\n=== Client Menu ===\n";
        cout << "1- Display my info\n";
        cout << "2- Check balance\n";
        cout << "3- Deposit\n";
        cout << "4- Withdraw\n";
        cout << "5- Transfer\n";
        cout << "6- Update Password\n";
        cout << "7- Logout\n";
        cout << "Enter your choice: ";
    }
public:
    // a method to clear input buffers (if someone entered wrong value or characters instead of numbers in cin, it resets the cin)
    static void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //a method for updating Clients.txt file with the latest client data
    static void updateClientFile(const vector<Client>& clients) {
        ofstream file("Clients.txt", ios::trunc);
        for (const auto& client : clients) {
            file << client.getId() << "&" << client.getName() << "&"
                << client.getPassword() << "&" << client.getBalance() << endl;
        }
        file.close();
    }

    // method for updating password (it checks if the password entered is not the same as the default password, also checks it with validation class)
    static void updatePassword(Client& client) {
        string newPassword, confirmPassword;
        clearInputBuffer();

        cout << "Enter new password: ";
        getline(cin, newPassword);

        cout << "Confirm new password: ";
        getline(cin, confirmPassword);

        if (newPassword != confirmPassword) {
            cout << "Passwords don't match!\n";
            return;
        }

        if (Validation::validatePassword(newPassword)) {
            client.setPassword(newPassword);
            vector<Client> allClients;
            FileHelper::getClients();

            for (auto& existingClient : clientsInfo) {
                if (existingClient.getId() == client.getId()) {
                    existingClient = client;
                    break;
                }
            }

            updateClientFile(clientsInfo);
            cout << "Password updated successfully!\n";
        }
    }

    // log in method 
    static Client* login(int id, const string& password) {
        FileHelper::getClients();
        for (const auto& client : clientsInfo) {
            if (client.getId() == id && client.getPassword() == password) {
                cout << "\nLogin successful!\n";
                return cItr._Ptr;
            }
        }
        cout << "\nInvalid ID or password.\n";
        return NULL;
    }

    //a method that ensures the user enters a valid numeric value
    static bool getNumericInput(double& value, const string& prompt) {
        cout << prompt;
        while (!(cin >> value) || value < 0) {
            cout << "Please enter a valid positive number: ";
            clearInputBuffer();
        }
        clearInputBuffer();
        return true;
    }
    //a method for updating the client’s data in memory and file
    static void updateClientData(Client& client) {
        FileHelper::getClients();
        for (auto& existingClient : clientsInfo) {
            if (existingClient.getId() == client.getId()) {
                existingClient = client;
                break;
            }
        }

        updateClientFile(clientsInfo);
    }

    // client menu options that gives the user choices on what to do
    static bool clientOptions(Client& client) {
        int choice;
        double amount;
        int recipientId;
        FileHelper::getClients();
        auto recipient = client.end();

        printClientMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            clearInputBuffer();
            return true;
        }

        switch (choice) {
        case 1:
            client.displayInfo();
            break;

        case 2:
            client.checkBalance();
            break;

        case 3:
            if (getNumericInput(amount, "Enter amount to deposit: ") && Validation::validateDeposit(amount)) {
                client.deposit(amount);
                updateClientData(client);
            }
            break;

        case 4:
            if (getNumericInput(amount, "Enter amount to withdraw: ") && Validation::validateWithdraw(amount, client.getBalance())) {
                client.withdraw(amount);
                updateClientData(client);
            }
            break;

        case 5:
            cout << "Enter recipient ID: ";
            if (!(cin >> recipientId)) {
                cout << "Invalid ID!\n";
                clearInputBuffer();
                break;
            }

            if (!getNumericInput(amount, "Enter amount to transfer: ") || !Validation::validateTransfer(amount, client.getBalance())) {
                break;
            }

            recipient = find_if(clients.begin(), clients.end(),
                [recipientId](const Client& c) { return c.getId() == recipientId; });

            if (recipient != clients.end()) {
                client.transferTo(amount, *recipient);
                updateClientFile(clients);
                cout << "Transfer successful!\n";
            }
            else {
                cout << "Recipient not found!\n";
            }
            break;

        case 6:
            updatePassword(client);
            break;

        case 7:
            cout << "Logging out...\n";
            return false;

        default:
            cout << "Invalid choice!\n";
        }

        return true;
    }
};
