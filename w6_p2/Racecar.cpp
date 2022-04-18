//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

#include <iostream>
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar()
	{
		m_booster = 0.0;
	}
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		in >> m_booster;
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return (Car::topSpeed() + (Car::topSpeed() * m_booster));
	}
}