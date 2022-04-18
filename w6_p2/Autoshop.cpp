//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

#include <iostream>
#include "Autoshop.h"

namespace sdds {
	Autoshop::~Autoshop() {
		for (auto& obj : m_vehicles) {
			delete obj;
		}
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
		{
			(*it)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}
}