#include <iostream>
#include <string>
#include <stdexcept>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
using namespace std;

int Client::clientCounter = 0;
const string Client::bankKey = "2025";
int Employee::employeeCounter = 1;
//Admin* Admin::myAdmin = nullptr;


static void runTests() {
    cout << "Running Tests...\n";

    // Test Client
    Client client1("Alice", "pass123", 5000);
    client1.displayInfo();
    client1.deposit(1000);
    client1.withdraw(500);
    cout << "Balance after transactions: " << client1.getBalance() << "\n";

    // Test Employee
    Employee emp1("Bob", "empPass", 10000);
    emp1.displayInfo();
    emp1.addClient(client1);
    emp1.listClients();

    // Test Admin (Singleton)
    Admin* admin = Admin::getmyAdmin();
    admin->displayInfo();
    admin->addEmployee(emp1);
    admin->listEmployee();

    // Test Transfer
    Client client2("Charlie", "charliePass", 3000);
    client1.transferTo(1000, client2);
    cout << "Client1 Balance: " << client1.getBalance() << "\n";
    cout << "Client2 Balance: " << client2.getBalance() << "\n";

    cout << "All tests completed successfully!\n";
}

int main()
{
    cout << "Bank System\n";
    cout << "Farm Bank\n";

    runTests();

    // Get the single instance of Admin (Singleton)
    /*Admin* admin = Admin::getmyAdmin();

    Client c(0, "Mai Othman", "Mai@Othman", 5000);

    Employee e(0, "Rozana Abbas", "Rozana@Abbas", 10000);
    Employee e1(0, "Amr Maged", "Amr@Maged", 10000);

    Admin a(0, "Mohamed Mahmoud", "Mohamed@Mahmoud", 10000);
    Admin a1(0, "Fatma Elzhraa", "Fatma@Elzhraa", 10000);

    c.displayInfo();
    e.displayInfo();
    e1.displayInfo();
    a.displayInfo();
    a1.displayInfo();*/

    /*string clientData = "101,homosaa,33333,5000.50";
    string employeeData = "201,Amr,444444,3000.75";
    string adminData = "301,Mai,43333,7000.25";*/

    /*try {
        Client client = Parser::parseToClient(clientData);
        Employee employee = Parser::parseToEmployee(employeeData);
        Admin admin = Parser::parseToAdmin(adminData);

        cout << "Client Data:\n";
        cout << "ID: " << client.id << "\n";
        cout << "Name: " << client.name << "\n";
        cout << "Password: " << client.password << "\n";
        cout << "Balance: " << client.balance << "\n\n";

        cout << "Employee Data:\n";
        cout << "ID: " << employee.id << "\n";
        cout << "Name: " << employee.name << "\n";
        cout << "Password: " << employee.password << "\n";
        cout << "Salary: " << employee.salary << "\n\n";

        cout << "Admin Data:\n";
        cout << "ID: " << admin.id << "\n";
        cout << "Name: " << admin.name << "\n";
        cout << "Password: " << admin.password << "\n";
        cout << "Salary: " << admin.salary << "\n";
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }*/

    return 0;

}

