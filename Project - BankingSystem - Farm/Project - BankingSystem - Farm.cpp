
#include <iostream>
using namespace std;
int main()
{
    cout << "Bank System\n";
    cout << "Farm Bank\n";
    string clientData = "101,homosaa,33333,5000.50";
    string employeeData = "201,Amr,444444,3000.75";
    string adminData = "301,Mai,43333,7000.25";

    try {
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
    }

    return 0;

}

