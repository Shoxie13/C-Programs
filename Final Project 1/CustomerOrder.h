// Name: Tareq Abdi
// Seneca Student ID: 123809196
// Seneca email: tabdi1@myseneca.ca
// Date of completion: 24/07/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include "Station.h"

namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
	public:
		CustomerOrder();
		~CustomerOrder();
		//custom arg
		CustomerOrder(const std::string& s);
		//move
		CustomerOrder(CustomerOrder&& src) noexcept;
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;
		//copy operations deleted
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		// extra member functions
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	private:
		std::string m_name, m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
	};
}