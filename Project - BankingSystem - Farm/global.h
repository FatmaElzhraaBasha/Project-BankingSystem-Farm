#pragma once
#include <stdio.h>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>

extern std::vector <Client> clientsInfo;
extern std::vector <Client>::iterator cItr;

extern std::vector <Employee> employeesInfo;
extern std::vector <Employee>::iterator eItr;

extern std::vector <Admin> adminInfo;
extern std::vector <Admin>::iterator aItr;

