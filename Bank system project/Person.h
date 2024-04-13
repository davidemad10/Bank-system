#pragma once
#include <string>
#include <iostream>
#include "Validation.h"
using namespace std;
class Person
{
protected:
		int id;
		string name;
		string password;
	public:
		Person(){}
		Person(int id, string name, string password) {
			this->id = id;
			this->name = name;
			this->password = password;
		}
		void setId(int id) {
			this->id = id;
		}
		void setName(string name) {

			while(!Validation::isValidName(name)) {
				cout << "Invalid name!" << endl;
				cout << "The name must be alphabetic chars and min size 5 and max size 20" << endl;
				cin >> name;
			}
			 	this->name = name;
			
		}
		void setPassword(string password) {
			while (!Validation::isValidPassword(password)) {
				cout << "Invalid password" << endl;
				cout << "Password must be with min size 8 and max size 20" << endl;
				cin >> password;
			}
			this->password = password;
			
		}
		int getId() {
			return this->id;
		}
		string getName() {
			return this->name;
		}
		string getPassword() {
			return this->password;
		}
	};


