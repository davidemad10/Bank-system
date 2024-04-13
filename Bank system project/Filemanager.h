#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Person.h"
#include "Validation.h"
#include "Employee.h"
#include "Client.h"
#include "Admin.h"
#include <vector>
#include "Datasourceinterface.h"

class Filemanager :public Datasourceinterface
{
public:
      void addClient(Client& client) override {
		fstream file;
		file.open("Clients.txt", ios::out | ios::app);
		if (file.is_open()) {
			file << client.getId() << endl;
			file << client.getName() << endl;
			file << client.getBalance() << endl;
			file.close();
			cout << "Client added successfully" << endl;
		}
		else cout << "Unable to open Client.txt" << endl;
		}
	  void addEmployee(Employee& employee)override {
		fstream employeefile;
		employeefile.open("Employees.txt", ios::out | ios::app);
		if (employeefile.is_open()) {
			employeefile << employee.getId() << endl;
			employeefile << employee.getName() << endl;
			employeefile << employee.getPassword() << endl;
			employeefile << employee.getSalary() << endl;
			employeefile.close();
			cout << "Client added successfully" << endl;
		}
		else cout << "Unable to open Employees.txt" << endl;
		}
	  void addAdmin(Admin& admin)override {
		fstream adminfile;
		adminfile.open("Admins.txt", ios::out | ios::app);
		if (adminfile.is_open()) {
			adminfile << admin.getId() << endl;
			adminfile << admin.getName() << endl;
			adminfile << admin.getPassword() << endl;
			adminfile << admin.getSalary() << endl;
			adminfile.close();
			cout << "Client added successfully" << endl;
		}
		else cout << "Unable to open Admins.txt" << endl;
		}
	  
	  void loaddatatovector(string filename, vector<string>& vfile) {
		fstream Myfile;
		Myfile.open(filename, ios::in);
		if (Myfile.is_open()) {
			string line;
			while (getline(Myfile, line)) {
				vfile.push_back(line);
			}

			Myfile.close();
		}
		}

	  vector<string> getAllClients()override {
		vector<string> clients;
		loaddatatovector("Clients.txt", clients);
		for (string& line : clients) {
			cout << line << endl;
		}
		return clients;
		}
	 
	  vector<string> getAllemployees()override {
		vector<string> employee;
		loaddatatovector("Employees.txt", employee);
		for (string& line : employee) {
			cout << line << endl;
		}
		return employee;
		}
	  vector<string> getAlladmins()override {
		vector<string> admins;
		loaddatatovector("Admins.txt", admins);
		for (string& line : admins) {
			cout << line << endl;
		}
		return admins;
		}
	  void removeAllclients() {
		ofstream files;
		files.open("Clients.txt", ios::trunc);
		if (files.is_open()) {
			files.close();
			cout << "All clients removed successfully" << endl;
		}
		else cout << "Unable to open client.txt" << endl;
		}
	  void removeAllemployees() {
		ofstream files;
		files.open("Employees.txt", ios::trunc);
		if (files.is_open()) {
			files.close();
			cout << "All Emmployees removed successfully" << endl;
		}
		else cout << "Unable to open Employee.txt" << endl;
		}
	  void removeAlladmins() {
		ofstream files;
		files.open("Admins.txt", ios::trunc);
		if (files.is_open()) {
			files.close();
			cout << "All Admins removed successfully" << endl;
		}
		else cout << "Unable to open Admins.txt" << endl;
		}
	
};

