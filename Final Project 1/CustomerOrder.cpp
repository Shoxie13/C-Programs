// Name: Tareq Abdi
// Seneca Student ID: 123809196
// Seneca email: tabdi1@myseneca.ca
// Date of completion: 24/07/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <algorithm>
#include <iomanip>

#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	//

	CustomerOrder::CustomerOrder()
	{
		m_name = {};
		m_product = {};
		m_lstItem = nullptr;
		m_cntItem = 0u;
	}

	CustomerOrder::~CustomerOrder()
	{
		if (m_lstItem != nullptr) {
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
		}
		delete[] m_lstItem;
	}

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities util;
		bool more = true;
		size_t next_pos = 0;
		size_t start_pos = 0;

		m_name = util.extractToken(str, next_pos, more);
		m_product = util.extractToken(str, next_pos, more);

		start_pos = next_pos;

		while (more) {
			util.extractToken(str, next_pos, more);
			m_cntItem++;
		}

		m_lstItem = new Item *[m_cntItem];
		more = true;

		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = new Item(util.extractToken(str, start_pos, more));
		}

		m_widthField = std::max(CustomerOrder::m_widthField, util.getFieldWidth());
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		m_lstItem = nullptr;
		m_cntItem = 0;
		//
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src) {
			if (m_lstItem != nullptr) {
				for (size_t i = 0; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
			}
			delete[] m_lstItem;

			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;

			m_lstItem = src.m_lstItem;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw std::string("*** Not allowed ***");
	}

	bool CustomerOrder::isFilled() const
	{
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled == false) {
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName) {
				return m_lstItem[i]->m_isFilled;
			}
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity() > 0) {
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;

		for (size_t i = 0u; i < m_cntItem; i++) {
			os << "[" << std::setfill('0') << std::setw(6) << std::right
				<< m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ');

			os << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName;
			//
			if (m_lstItem[i]->m_isFilled) {
				os << " - FILLED\n";
			}
			else {
				os << " - TO BE FILLED\n";
			}
		}
	}
}