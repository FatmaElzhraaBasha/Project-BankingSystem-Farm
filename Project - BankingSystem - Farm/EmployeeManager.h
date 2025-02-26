#pragma once
#include "ClientManager.h"
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "FileHelper.h"
#include "Validation.h"
#include "FileManager.h"
using namespace std;

class EmployeeManager
{
private:
	static void printEmployeeMenu() {
		cout << "\n=== Employee Menu ===\n";
		cout << "1- Display my info\n";
		cout << "2- Add new client. \n";
		cout << "3- Search for client.\n";
		cout << "4- List all clients. \n";
		cout << "5- Edit client info.\n";
		cout << "6- View Client Detail\n";
		cout << "7- Approve Loan\n";
		cout << "8- Block Client\n";
		cout << "9- Update Client Balance\n";
		cout << "10- Update Password\n";
		cout << "11- Logout\n";
		cout << "Enter your choice: ";
	}

	//static void back(Employee* employee) {
	//	cout << "\n";
	//	system("pause");
	//	employeeOptions(employee);
	//}

public:
	// a method to clear input buffers (if someone entered wrong value or characters instead of numbers in cin, it resets the cin)
	static void clearInputBuffer() {
		cin.clear();
		//cin.ignore(numeric_limits<streamsize>);
	}

	//a method for updating Employees.txt file with the latest employee data
	static void updateEmployeeFile() {
		fstream file("Employees.txt", ios::trunc);
		for (const auto& employee : employeesInfo) {
			file << employee.getId() << "," << employee.getName() << ","
				<< employee.getPassword() << "," << employee.getSalary() << endl;
		}
		file.close();
	}

	// method for updating password (it checks if the password entered is not the same as the default password, also checks it with validation class)
	static void updatePassword(Employee& employee) {
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
			employee.setPassword(newPassword);
			FileHelper::getEmployees();

			for (auto& existingEmployee : employeesInfo) {
				if (existingEmployee.getId() == employee.getId()) {
					existingEmployee = employee;
					break;
				}
			}

			updateEmployeeFile();
			cout << "Password updated successfully!\n";
		}
	}

	static Employee* logIn(int id, string password) {
		for (eItr = employeesInfo.begin(); eItr != employeesInfo.end(); eItr++) {
			if (eItr->getId() == id && eItr->getPassword() == password) {
				cout << "\nLogin successful!\n";
				return eItr._Ptr;
			}
			else {
				cout << "\nInvalid ID Or Password.\n";
				return NULL;
			}
		}
	}

	static void addNewClient(Employee* employee) {
		Client client;
		client.setId(FileHelper::getLast("ClientLastId.txt" + 1));
		string password, name;
		double balance;
		cout << "Please enter a name of the Client: " << endl;
		cin >> name;
		client.setName(name);
		cout << "Please enter a password of the Client: " << endl;
		cin >> password;
		client.setPassword(password);
		cout << "Please enter the Balance of the Client: " << endl;
		cin >> balance;
		client.setBalance(balance);
		employee->addClient(client);
		FileManager::updateClients();
		cout << "\n Client Added Successfully :) \n";
	}

	static void searchForClient(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter Client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL)
			cout << "Client Not Found" << endl;
		else
			employee->searchClient(id)->displayInfo();
	}

	static void ListAllClient(Employee* employee) {
		system("cls");
		cout << "The List Of All Clients :-" << endl;
		employee->listClients();
	}

	static void editClientInfo(Employee* employee) {
		int id;
		system("cls");
		cout << "enter Client Id : ";
		cin >> id;
		string name, password;
		double balance;
		if (employee->searchClient(id) == NULL)
			cout << "Client Not Found" << endl;
		else {
			cout << "Enter Client New Name: ";
			cin >> name;
			cout << "Enter Client New Password: ";
			cin >> password;
			cout << "Enter Client New Balance: ";
			cin >> balance;
			/*employee->searchClient(id)->setName(name);
			employee->searchClient(id)->setPassword(password);
			employee->searchClient(id)->setBalance(balance);*/

			employee->editClient(id, name, password, balance);
		}
	}

	static void viewClientDetails(Employee* employee) {
		int id;
		cout << "Enter Clirnt Id To View: ";
		cin >> id;
		employee->viewClientDetails(id);
	}

	static void approveLoan(Employee* employee) {
		double amount;
		int id;
		cout << "Enter Client Id To Search: ";
		cin >> id;
		if (employee->searchClient(id)) {
			cout << "Enter Loan Amount To Test: ";
			cin >> amount;
			employee->approveLoan(amount);
		}

	}

	static void blockClient(Employee* employee) {
		int id;
		cout << "Please Enter Client Id To Block: ";
		cin >> id;
		employee->blockClient(id);
	}

	static void updateClientBalance(Employee* employee) {
		int id;
		double newBalance;
		cout << "Enter Client ID To Update Balance: ";
		cin >> id;
		if (employee->searchClient(id)) {
			cout << "Enter Client New Balance: ";
				cin >> newBalance;
				employee->updateClientBalance(id, newBalance);
		}

	}

	static bool employeeOptions(Employee* employee) {
		printEmployeeMenu();
		cout << "Enter Your Choice: ";
		int choice;
		string pass;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			employee->displayInfo();
			break;
		case 2:
			system("cls");
			addNewClient(employee);
			break;
		case 3:
			system("cls");
			searchForClient(employee);
			break;
		case 4:
			system("cls");
			ListAllClient(employee);
			break;
		case 5:
			system("cls");
			editClientInfo(employee);
			break;
		case 6:
			system("cls");
			viewClientDetails(employee);
			break;
		case 7:
			system("cls");
			approveLoan(employee);
			break;
		case 8:
			system("cls");
			blockClient(employee);
			break;
		case 9:
			system("cls");
			updateClientBalance(employee);
			break;
		case 10:
			system("cls");
			updatePassword(*employee);
			break;
		case 11:
			system("cls");
			cout << "Logging out...\n";
			return false;
			break;

		default:
			cout << "You Enter Invalid Number, Try Again !!" << endl;
			break;
		}
		return true;
	}
};

