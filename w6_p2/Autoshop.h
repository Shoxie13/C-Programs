//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	         09/07/2021
//==============================================

#pragma once
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
	public:
		Autoshop() = default;
		~Autoshop();
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
	private:
		std::vector<Vehicle*> m_vehicles;
	};
	template<typename T>
	inline void Autoshop::select(T test, std::list<const Vehicle*>& vehicles)
	{
		for (auto& obj : m_vehicles) {
			if (test(obj)) {
				vehicles.push_back(obj);
			}
		}
	}
}