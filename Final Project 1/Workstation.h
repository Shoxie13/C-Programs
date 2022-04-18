#pragma once
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation : public Station
	{
	public:
		Workstation() = default;
		~Workstation() = default;
		Workstation(const std::string& str);
		//
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		//
		Workstation(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator=(Workstation&&) = delete;
	private:
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation = nullptr;
	};
}