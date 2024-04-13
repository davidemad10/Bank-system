#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Filemanager.h"
using namespace std;

int main()
{
	while (true) {
		int ID,newID=0, choise, num, iD;
		string name, password, clientadded, clientpass, newname, newpass;
		double balance, salary, bal,newbalance;
		Client client; Filemanager filemanager;
		Employee employee;
		Admin admin;
		cout << "Welcome sir please select number" << endl;
		cout << "\n 1-Client \n 2-Employee \n 3-Admin \n 4-Exit App" << endl;
		cin >> choise;
		switch (choise) {
			
		case 1:
			cout << "please Enter your ID" << endl;
			cin >> ID;
			client.setId(ID);
			cout << "please Enter your Name" << endl;
			while (true) {
				cin >> name;
				if (Validation::isValidName(name)) {
					client.setName(name);
					break;
				}
				else {
					cout << "Wrong Name!!" << endl;
					cout << "The Name must be alphabetic chars with min size 5 and max size 20" << endl;
					cout << "please Enter your Name" << endl;
				}
			}
			cout << "please Enter your password" << endl;
			while (true) {
				cin >> password;
				if (Validation::isValidPassword(password)) {
					client.setPassword(password);
					break;
				}
				else {
					cout << "Password must be with min size 8 and max size 20" << endl;
					cout << "please try anthor password" << endl;
				}
			}
			cout << "please Enter your Balance" << endl;
			while (true) {
				cin >> balance;
				if (Validation::isValidBalance(balance)) {
					client.setBalance(balance);
					break;
				}
				else {
					cout << "Min balance must be 1500" << endl;
					cout << "please try again" << endl;
				}
			}
			client.deposit(1000);
			client.withdrow(1000);
			cout << "=============================" << endl;
			client.display();
			break;
		case 2:
			cout << "please Enter Employee ID" << endl;
			cin >> ID;
			employee.setId(ID);
			cout << "please Enter Employee Name" << endl;
			while (true) {
				cin >> name;
				if (Validation::isValidName(name)) {
					employee.setName(name);
					break;
				}
				else {
					cout << "Wrong Name!!" << endl;
					cout << "The Name must be alphabetic chars with min size 5 and max size 20" << endl;
					cout << "please Enter Employee Name" << endl;
				}
			}
			cout << "please Enter Employee password" << endl;
			while (true) {
				cin >> password;
				if (Validation::isValidPassword(password)) {
					employee.setPassword(password);
					break;
				}
				else {
					cout << "Password must be with min size 8 and max size 20" << endl;
					cout << "please try anthor password" << endl;
				}
			}
			cout << "please Enter Employee salary" << endl;
			while (true) {
				cin >> salary;
				if (Validation::isValidBalance(salary)) {
					employee.setSalary(salary);
					break;
				}
				else {
					cout << "Min salary must be 5000" << endl;
					cout << "please try again" << endl;
				}
			}
			cout << "=============================" << endl;
			employee.display();
			cout << "=============================" << endl;
			cout << "Welcome " << employee.getName() << endl;
			cout << "Please select a number" << endl;
			cout << "\n 1-Add clients \n 2-Remove All clients \n 3-search client \n 4-Edit client 5-View client\n";
			cin >> choise;
			switch (choise) {
			case 1:
				cout << "How many client Do u want to add?" << endl;
				cin >> num;

				for (int i = 0; i < num; i++) {
					cout << "Enter client name" << endl;
					cin >> clientadded;
					client.setName(clientadded);
					cout << "Enter client ID" << endl;
					cin >> iD;
					client.setId(iD);
					cout << "Enter client pass" << endl;
					cin >> clientpass;
					client.setPassword(clientpass);
					cout << "Enter client Balance" << endl;
					cin >> bal;
					client.setBalance(bal);
					filemanager.addClient(client);
					employee.addClient(client);
				}
				cout << "========================" << endl;
				filemanager.getAllClients();
				break;
			case 2:
				filemanager.removeAllclients();
				break;
		/*	case 3:
				cout << "Please enter the ID of client to search: " << endl;
				cin >> ID;
				Client* client = employee.searchClient(ID);
				if (client !=nullptr) {
					cout << "Client found:" << endl;
					cout << "ID: " << client->getId() << endl;
					cout << "Name: " << client->getName() << endl;
					cout << "Balance: " << client->getBalance() << endl;
				}
				else cout << "Client not found." << endl;
				break;*/
		/*	case 4:
				cout << "Please Enter the ID of client to edit" << endl;
				cin >> newID;
				cout << "please Enter the new name \n";
				cin >> newname;
				cout << "please enter new password\n";
				cin >> newpass;
				cout << "please enter new balance \n";
				cin >> newbalance;
				employee.editClientInFile(newID,newname,newbalance);
				break;*/
			default:
				cout << "wrong choice" << endl;
				break;
			}
			break;
		case 3:
			cout << "please Enter Admin ID" << endl;
			cin >> ID;
			admin.setId(ID);
			cout << "please Enter admin Name" << endl;
			while (true) {
				cin >> name;
				if (Validation::isValidName(name)) {
					admin.setName(name);
					break;
				}
				else {
					cout << "Wrong Name!!" << endl;
					cout << "The Name must be alphabetic chars with min size 5 and max size 20" << endl;
					cout << "please Enter admin Name" << endl;
				}
			}
			cout << "please Enter admin password" << endl;
			while (true) {
				cin >> password;
				if (Validation::isValidPassword(password)) {
					admin.setPassword(password);
					break;
				}
				else {
					cout << "Password must be with min size 8 and max size 20" << endl;
					cout << "please try anthor password" << endl;
				}
			}
			cout << "please Enter admin salary" << endl;
			while (true) {
				cin >> salary;
				if (Validation::isValidBalance(salary)) {
					admin.setSalary(salary);
					break;
				}
				else {
					cout << "Min salary must be 5000" << endl;
					cout << "please try again" << endl;
				}
			}
			cout << "=============================" << endl;
			admin.display();
			cout << "=============================" << endl;
			cout << "Welcome " << admin.getName() << endl;

			cout << "Please select a number" << endl;
			cout << "\n 1-Add clients \n 2-Remove All clients \n 3-Add Employee \n 4-Remove All Employeess \n 5-Add admins \n 6-Remove All Admins \n";
			cin >> choise;
			switch (choise) {
			case 1:
				cout << "How many client Do u want to add?" << endl;
				cin >> num;

				for (int i = 0; i < num; i++) {
					cout << "Enter client name" << endl;
					cin >> clientadded;
					client.setName(clientadded);
					cout << "Enter client ID" << endl;
					cin >> iD;
					client.setId(iD);
					cout << "Enter client pass" << endl;
					cin >> clientpass;
					client.setPassword(clientpass);
					cout << "Enter client Balance" << endl;
					cin >> bal;
					client.setBalance(bal);
					filemanager.addClient(client);
				}
				cout << "========================" << endl;
				filemanager.getAllClients();
				break;
			case 2:
				filemanager.removeAllclients();
				break;
			case 3:
				cout << "How many Employee Do u want to add?" << endl;
				cin >> num;

				for (int i = 0; i < num; i++) {
					cout << "Enter Employee name" << endl;
					cin >> clientadded;
					employee.setName(clientadded);
					cout << "Enter Employee ID" << endl;
					cin >> iD;
					employee.setId(iD);
					cout << "Enter employee pass" << endl;
					cin >> clientpass;
					employee.setPassword(clientpass);
					cout << "Enter employee salary" << endl;
					cin >> bal;
					employee.setSalary(bal);
					filemanager.addEmployee(employee);
				}
				cout << "========================" << endl;
				filemanager.getAllemployees();
				break;
			case 4:
				filemanager.removeAllemployees();
				break;
			case 5:
				cout << "How many Admin Do u want to add?" << endl;
				cin >> num;

				for (int i = 0; i < num; i++) {
					cout << "Enter Admin name" << endl;
					cin >> clientadded;
					admin.setName(clientadded);
					cout << "Enter Admin ID" << endl;
					cin >> iD;
					admin.setId(iD);
					cout << "Enter Admin pass" << endl;
					cin >> clientpass;
					admin.setPassword(clientpass);
					cout << "Enter admin salary" << endl;
					cin >> bal;
					admin.setSalary(bal);
					filemanager.addAdmin(admin);
				}
				cout << "========================" << endl;
				filemanager.getAlladmins();
				break;
			case 6:
				filemanager.removeAlladmins();
				break;
			default:
				cout << "wrong choise" << endl;
			}
			break;
			case 4:
				exit(0);
				break;

		default:
			cout << "wrong choise!" << endl;
		}
	}
}
