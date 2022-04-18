//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

#pragma once
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string& trim(std::string& s);
	bool isNumber(std::string s);
}