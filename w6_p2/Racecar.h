//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

#pragma once
#include "Car.h"

namespace sdds {
	class Racecar : public Car
	{
	public:
		Racecar();
		~Racecar() = default;
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	private:
		double m_booster = 0.0;
	};
}