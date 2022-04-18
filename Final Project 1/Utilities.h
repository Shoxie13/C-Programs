// Name: Tareq Abdi
// Seneca Student ID: 123809196
// Seneca email: tabdi1@myseneca.ca
// Date of completion: 16/07/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

namespace sdds {
	class Utilities
	{
	public:
		Utilities() = default;
		~Utilities() = default;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	private:
		size_t m_widthField = 1;
		static char m_delimiter;
	};
	
}
