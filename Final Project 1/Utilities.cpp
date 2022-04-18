// Name: Tareq Abdi
// Seneca Student ID: 123809196
// Seneca email: tabdi1@myseneca.ca
// Date of completion: 16/07/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Utilities.h"

namespace sdds {
	char Utilities::m_delimiter = {};
	//
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string token{};
		size_t cur_pos = next_pos;
		size_t end_pos = str.find(getDelimiter(), cur_pos);

		if (end_pos == std::string::npos) {
			more = false;
			token = str.substr(cur_pos);
		}
		else {
			more = true;
			next_pos = end_pos + 1u;
			if (end_pos == cur_pos) {
				more = false;
				throw std::string("No data available!");
			}
			token = str.substr(cur_pos, end_pos - cur_pos);
		}

		if (token.length() > m_widthField) {
			setFieldWidth(token.length());
		}
		return token;
	}

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}