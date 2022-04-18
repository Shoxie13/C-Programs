//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* temp = nullptr;
		std::string s;
		std::stringstream ss;

		std::getline(in, s);

		if (!s.empty()) {
			s.erase(0, s.find_first_not_of(' '));
			s.erase(s.find_last_not_of(' ') + 1);

			ss << s;

			if (ss.str().at(0) == 'c' || ss.str().at(0) == 'C') {
				temp = new Car(ss);
			}
			else if (ss.str().at(0) == 'r' || ss.str().at(0) == 'R') {
				temp = new Racecar(ss);
			}
			else {
				throw std::string("Unrecognized record type: [") + ss.str().at(0) + ("]");
			}
		}
		else {
			return nullptr;
		}
		return temp;
	}
	std::string& trim(std::string& s)
	{
		bool valid = true;
		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ') + 1);

		while (valid)
		{
			if (s.find("  ") != std::string::npos) {
				s.erase(s.find("  "), 1);
				valid = true;
			}if (s.find(" ,") != std::string::npos) {
				s.replace(s.find(" ,"), s.size(), ",");
				valid = true;
			}
			else
				valid = false;
		}

		return s;
	}
	bool isNumber(std::string s) {
		for (size_t i = 0; i < s.length(); i++)
			if (isdigit(s[i]) == false)
				return false;

		return true;
	}
}


