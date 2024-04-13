#pragma once
#include <string>
#include <iostream>
#include "Person.h"
#include "Validation.h"
class Client:public Person
{
private:
		double balance;
public:
	Client(){}
	Client(int id , string name , string password ,double balance){
		this->balance = balance;
		this->id = id;
		this->name = name;
		this->password = password;
	}
	Client(int id, string name, double balance) {
		this->balance = balance;
		this->id = id;
		this->name = name;
	}
		void setBalance(double balance) {
			if (Validation::isValidBalance(balance)) {
				this->balance = balance;
			}
			else
				cout << "Min balance must be 1500" << endl;
		}
		double getBalance() {
			return balance;
		}
		void deposit(double amount) {
			balance += amount;
		}
		void withdrow(double amount) {
			if (amount < balance) {
				balance -= amount;
			}
			else cout << "Insufficient balance!" << endl;
		}
		void transferto(double amount, Client& recipient) {
			if (amount < balance) {
				balance -= amount;
				recipient.deposit(amount);
			}
			else cout << "Insufficient balance!" << endl;
		}
		void checkbalance() {
			cout << "Current balance is: " << balance << endl;
		}
		void display() {
			cout << "ID is: " << id << endl;
			cout << "Name is: " << name << endl;
			cout << "Your Balance is: " << balance << endl;
		}
	};


