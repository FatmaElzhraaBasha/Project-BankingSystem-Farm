#pragma once
#include "Client.h"
#include "FileManager.h"
#include <limits>

class ClientManager {
private:
    static void printClientMenu() {
        cout << "\n=== Client Menu ===\n";
        cout << "1- Display my info\n";
        cout << "2- Deposit\n";
        cout << "3- Withdraw\n";
        cout << "4- Transfer\n";
        cout << "5- Check balance\n";
        cout << "6- Currency Exchange\n";
        cout << "7- Take Loan\n";
        cout << "8- Account Statement\n";
        cout << "9- Update Password\n";
        cout << "10- Logout\n";
        cout << "Enter your choice: ";
    }
public:
    // a method to clear input buffers (if someone entered wrong value or characters instead of numbers in cin, it resets the cin)
    static void clearInputBuffer() {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>);
    }

    //a method for updating Clients.txt file with the latest client data
    static void updateClientFile() {
        fstream file("Clients.txt", ios::trunc);
        for (const auto& client : clientsInfo) {
            file << client.getId() << "," << client.getName() << ","
                << client.getPassword() << "," << client.getBalance() << endl;
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
            FileHelper::getClients();

            for (auto& existingClient : clientsInfo) {
                if (existingClient.getId() == client.getId()) {
                    existingClient = client;
                    break;
                }
            }

            updateClientFile();
            cout << "Password updated successfully!\n";
        }
    }

    // log in method 
    static Client* logIn(int id, const string& password) {
        FileHelper::getClients();
        for (const auto& client : clientsInfo) {
            if (client.getId() == id && client.getPassword() == password) {
                cout << "\nLogin Successful!\n";
                return cItr._Ptr;
            }
        }
        cout << "\nInvalid ID Or Password.\n";
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
    //static void updateClientData(Client* client) {
    //    FileHelper::getClients();
    //    for (auto& existingClient : clientsInfo) {
    //        if (existingClient.getId() == client->getId()) {
    //           // existingClient = client;
    //            client = existingClient;
    //            break;
    //        }
    //    }

    //    updateClientFile(clientsInfo);
    //}

    static void depoistAmount(Client* client) {
        double amount;
        cout << "Enter Amount To Deposit: ";
        cin >> amount;
        client->deposit(amount);
    }

    static void withdrawAmount(Client* client) {
        double amount;
        cout << "Enter Amount To withdraw: ";
        cin >> amount;
        client->withdraw(amount);
    }

    static void takeLoan (Client* client) {
        double amount;
        cout << "Enter Amount To loan: ";
        cin >> amount;
        client->takeLoan(amount);
    }

    // client menu options that gives the user choices on what to do
    static bool clientOptions(Client* client) {
        int choice;
        double amount;
        int recipientId;
        FileHelper::getClients();
        auto recipient = clientsInfo.end();

        printClientMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            clearInputBuffer();
            return true;
        }

        switch (choice) {
        case 1:
            system("cls");
            client->displayInfo();
            break;

        case 2:
            system("cls");
            depoistAmount(client);
            break;

        case 3:
            withdrawAmount(client);
            break;

        case 4:
            cout << "Enter recipient ID: ";
            if (!(cin >> recipientId)) {
                cout << "Invalid ID!\n";
                clearInputBuffer();
                break;
            }

            if (!getNumericInput(amount, "Enter amount to transfer: ") || !Validation::validateTransfer(amount, client->getBalance())) {
                break;
            }

            recipient = find_if(clientsInfo.begin(), clientsInfo.end(),
                [recipientId](const Client& c) { return c.getId() == recipientId; });

            if (recipient != clientsInfo.end()) {
                client->transferTo(amount, *recipient);
                updateClientFile();
                cout << "Transfer successful!\n";
            }
            else {
                cout << "Recipient not found!\n";
            }
            break;

        case 5:
            system("cls");
            client->checkBalance();
            break;

        case 6:
            system("cls");
            client->currencyExchange();
            break;

        case 7:
            system("cls");
            takeLoan(client);
            break;

        case 8:
            system("cls");
            client->accountStatement();
            break;

        case 9: 
            system("cls");
            updatePassword(*client);
            break;

        case 10:
            system("cls");
            cout << "Logging out...\n";
            return false;
            break;

        default:
            cout << "Invalid choice!\n";
        }

        return true;
    }
};
