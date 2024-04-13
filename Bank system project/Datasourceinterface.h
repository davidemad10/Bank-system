#pragma once
#include <string>
#include <iostream>
#include "Person.h"
#include "Validation.h"
#include "Employee.h"
#include "Client.h"
#include "Admin.h"
#include <vector>
class Datasourceinterface
{
	virtual void addClient(Client& client) = 0;
    virtual void addEmployee(Employee& employee) = 0;
	virtual void addAdmin(Admin& admin) = 0;
	virtual vector<string> getAllClients() = 0;
	virtual vector<string> getAllemployees() = 0;
	virtual vector<string> getAlladmins() = 0;
	virtual void removeAllclients() = 0;
	virtual void removeAllemployees() = 0;
	virtual void removeAlladmins() = 0;

};

