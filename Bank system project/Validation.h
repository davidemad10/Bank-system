#pragma once
#include <string>
using namespace std;
class Validation
{	public:
		static bool isValidName(const string& name) {
			if (name.length() < 5 || name.length() > 20)
				return false;
			for (char c : name) {
				if (!isalpha(c))
					return false;
			}
			return true;
		}
		static bool isValidPassword(const string& password) {
			if (password.length() >= 8 && password.length() <= 20) {
				return true;
			}
			return false;
		}
		static bool isValidBalance(double balance) {
			if (balance < 1500) {
				return false;
			}
			return true;
		}
		static bool isValidsalary(double balance) {
			if (balance < 5000) {
				return false;
			}
			return true;
		}
	};


