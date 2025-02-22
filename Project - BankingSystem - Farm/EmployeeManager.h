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
		system("cls");
		cout << "\n=== Employee Menu ===\n";
		cout << "(1) Display Info.\n" << "(2) Update Password\n" << "(3) Add New Client\n"
			"(4) Search For Client\n" << "(5) List All Clients\n" << "(6) Edit Client Info\n"
			"(7) LogOut!! \n";
	}

	//static void back(Employee* employee) {
	//	cout << "\n";
	//	system("pause");
	//	employeeOptions(employee);
	//}

public:
	static void addNewClient(Employee* employee) {
		Client client;
		client.setId(FileHelper::getLast("ClientLastId.txt" + 1));
		string pass, name;
		client.setName(name);
		client.setPassword(pass);
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
		string name, pass;
		double balance;
		if (employee->searchClient(id) == NULL)
			cout << "Client Not Found" << endl;
		else {
			/*employee->searchClient(id)->setName(name);
			employee->searchClient(id)->setPassword(pass);
			employee->searchClient(id)->setBalance(balance);*/

			employee->editClient(id, name, pass, balance);
		}
	}

	static Employee* logIn(int id, string password) {
		for (eItr == employeesInfo.begin(); eItr != employeesInfo.end(); eItr++) {
			if (eItr->getId() == id && eItr->getPassword() == password)
				return eItr._Ptr;
			else
				return NULL;
		}
	}

	static bool employeeOptions(Client* client) {
		printEmployeeMenu();
		cout << "Enter Your Choice: ";
		int choice;
		string pass;
		Employee employee;
		cin >> choice;
		switch (choice) {
		case1:
			system("cls");
			employee.displayInfo();
			break;
		case2:
			system("cls");
			employee.setPassword(pass);
			break;
		case3:
			system("cls");
			EmployeeManager::addNewClient(&employee);
			break;
		case4:
			system("cls");
			EmployeeManager::searchForClient(&employee);
			break;
		case5:
			system("cls");
			EmployeeManager::ListAllClient(&employee);
			break;
		case6:
			system("cls");
			EmployeeManager::editClientInfo(&employee);
			break;
		case7:
			system("cls");
			break;

		}
	}
};

