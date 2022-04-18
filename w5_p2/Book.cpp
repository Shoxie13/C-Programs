#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"
#include "Utilities.h"

namespace sdds {
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}
	Book::Book(const std::string& strBook)
	{
		std::string str = strBook;
		//
		std::string author = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		//
		std::string title = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		//
		std::string country = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		//
		std::string price = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		//
		std::string year = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
		//
		std::string summary = str.substr(0, str.find('.') + 1);
		//
		m_author = trim(author);
		m_title = trim(title);
		m_country = trim(country);
		m_price = stod(trim(price));
		m_year = stoi(trim(year));
		m_desc = trim(summary);
	}
	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		os << std::setw(20) << bk.m_author << " | " 
			<< std::setw(22) << bk.title() << " | " 
			<< std::setw(5) << bk.country() << " | " 
			<< std::setw(4) << bk.year() << " | " 
			<< std::setw(6) << std::fixed << std::setprecision(2) << bk.m_price << " | " 
			<< bk.m_desc << std::endl;
		return os;
	}
}