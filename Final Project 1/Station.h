// Name: Tareq Abdi
// Seneca Student ID: 123809196
// Seneca email: tabdi1@myseneca.ca
// Date of completion: 16/07/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

namespace sdds {
	class Station
	{
	public:
		Station() = default;
		~Station() = default;
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	private:
		int m_id{};
		std::string m_itemName{}, m_desc{};
		size_t m_serialNumber{}, m_stock{};
		static size_t m_widthField;
		static int id_generator;
	};
}