#pragma once
#include <iostream>
#include "fstream"
#include "Person.h"
#include "Client.h"
using namespace std;
class Employee : public Person
{
private:
	double salary,balance;
	vector <Client*> clients;
public:
	void setSalary(double salary) {
			if (Validation::isValidsalary(salary)) {
				this->salary = salary;
			}
			else cout << "Min Salary must be 5000";
		}
	double getSalary() {
			return this->salary;
		}
	void display() {
			cout << "ID: " << id << endl;
			cout << "Name: " << name << endl;
			cout << "Salary: " << salary << endl;
		}
	void addClient(Client& client) {
		clients.push_back(&client);
	}
	
	Client* searchClient(int clientid) {
		ifstream file("Clients.txt");
		if (file.is_open()) {
			while (file >> id >> name >> balance) {
				if (id == clientid) {
					file.close();
					return new Client(id, name, balance);
				}
			}
			file.close(); 
			cout << "Client with ID " << clientid << " not found" << endl; 
		}
		else {
			cout << "Unable to open Clients.txt" << endl;
			return nullptr;
		}
		
	}
	void listClients() {
		cout << "List of clients: " << endl;
		for (Client* client : clients) {
			cout << "ID: " << client->getId() << "Name:" << client->getName() << "Balance:" << client->getBalance() << endl;
		}
	}
	void editClient(int id , string name , string password , double balance) {
		Client* client=searchClient(id);
		if (client != nullptr) {
			client->setName(name);
			client->setPassword(password);
			client->setBalance(balance);
			cout << client->getId();
			cout << client->getName();
			cout << client->getBalance();
		}
		else cout << "Client not found";

	}
	

};


