#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Employee.h"
#include "Validation.h"
class Admin :public Employee
{
private:
	vector<Employee*> adms;
public:
	void addEmployee(Employee& employee) {
		adms.push_back(&employee);
	}
	Employee* searchEmployee(int id) {
		for (Employee* employee : adms) {
			if (employee->getId() == id) {
				return employee;
			}
		}
		return NULL;
	}
	void editEmployee(int id, string name, string password, double salary) {
		Employee* employee = searchEmployee(id);
		if (employee != NULL) {
			employee->setName(name);
			employee->setSalary(salary);
			employee->setPassword(password);
		}
		else cout << "Employee not found!\n";
	}
	void listEmployee() {
		cout << "List of Employee \n";
		for (Employee* employee : adms) {
			cout << "ID= " << employee->getId()<<"\n" << "Name= " << employee->getName()<<endl;
			cout << "Salary= " << employee->getSalary() << endl;
		}
	}
};

