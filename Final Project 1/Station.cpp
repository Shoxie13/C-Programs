// Name: Tareq Abdi
// Seneca Student ID: 123809196
// Seneca email: tabdi1@myseneca.ca
// Date of completion: 16/07/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;
	//

	Station::Station(const std::string& str)
	{
		Utilities util;
		bool more = true;
		size_t pos = 0u;

		while (more)
		{
			try
			{
				m_itemName = util.extractToken(str, pos, more);
				m_serialNumber = std::stoi(util.extractToken(str, pos, more));
				m_stock = std::stoi(util.extractToken(str, pos, more));
				m_widthField = std::max(m_widthField, util.getFieldWidth());
				m_desc = util.extractToken(str, pos, more);
			}
			catch (...) { throw std::string("No token to extract!"); }
		}
		id_generator++;
		m_id = id_generator;
	}

	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}

	size_t Station::getQuantity() const
	{
		return m_stock;
	}

	void Station::updateQuantity()
	{
		if (m_stock > 0)
		{
			m_stock--;
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "] " << std::setfill(' ') 
			<< "Item: " << std::setw(m_widthField) << std::left << getItemName();
		os << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ');
		if (full) {
			os << " Quantity: " << std::setw(m_widthField) << std::left << getQuantity() <<
				" Description: " << m_desc << std::endl;
		}
		else
			os << std::endl;
	}
}