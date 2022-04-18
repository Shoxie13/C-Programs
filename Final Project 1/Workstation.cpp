#include <iostream>
#include "Workstation.h"

namespace sdds {
	std::deque<CustomerOrder> pending = {};
	std::deque<CustomerOrder> completed = {};
	std::deque<CustomerOrder> incomplete = {};

	Workstation::Workstation(const std::string& str) : Station(str)
	{
		m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os)
	{
		while (!m_orders.empty() && !m_orders.front().isItemFilled(getItemName()) && getQuantity() > 0) {
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{
		if (m_orders.empty()) {
			return false;
		}

		if (m_orders.front().isItemFilled(getItemName())) {
			if (m_orders.front().isFilled()) {
				completed.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
				return true;
			}
			else if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());
				m_orders.pop_front();
				return true;
			}
			else {
				return false;
			}
		}
		else if (getQuantity() == 0) {
			incomplete.push_back(std::move(m_orders.front()));
			m_orders.pop_front();
			return true;
		}
		return false;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation != nullptr) {
			os << getItemName() << " --> " << m_pNextStation->getItemName();
		}
		else {
			os << getItemName() << " --> End of Line";
		}
		os << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}