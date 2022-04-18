//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

//libraries
#include <iostream>
#include <typeinfo>
#include <iomanip>
//header files
#include "Car.h"
#include "Utilities.h"

namespace sdds {
	Car::Car()
	{
		m_brand = {};
		m_cond = {};
		m_speed = 0.0;
	}
	Car::Car(std::istream& in) : m_speed(0.0)
	{
		std::string s;
		std::string tag, brand, cond, speed;
		//
		getline(in, tag, ',');
		getline(in, brand, ',');
		getline(in, cond, ',');
		getline(in, speed, ',');
		//
		trim(brand);
		trim(cond);
		trim(speed);

		m_brand = brand;

		if (cond.empty()) {
			cond = "n";
			m_cond = Condition(cond[0]);
		}else if (cond[0] != 'n' && cond[0] != 'u' && cond[0] != 'b') {
			throw std::string("Invalid record!");
		}
		else {
			m_cond = Condition(cond[0]);
		}

		if (isNumber(speed)) {
			m_speed = stod(speed);
		}
		else {
			throw std::string("Invalid record!");
		}
	}
	std::string Car::condition() const
	{
		std::string c{};
		if (m_cond == Condition::BrandNew) {
			c = "new";
		}
		else if (m_cond == Condition::Used) {
			c = "used";
		}
		else if (m_cond == Condition::Broken) {
			c = "broken";
		}
		return c;
	}
	double Car::topSpeed() const
	{
		return m_speed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| " << std::right << std::setw(10) << m_brand << " | " 
			<< std::left << std::setw(6) << condition() << " | " 
			<< std::setw(6) << std::setprecision(2) << std::fixed << topSpeed() << " |";
	}
}