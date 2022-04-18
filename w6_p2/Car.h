//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

#pragma once
#include "Vehicle.h"

namespace sdds {
	enum class Condition : char {
		BrandNew = 'n',
		Used = 'u',
		Broken = 'b'
	};

	class Car : public Vehicle {
	public:
		Car();
		~Car() = default;
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	private:
		std::string m_brand{};
		Condition m_cond{};
		double m_speed = 0.0;
	};
}