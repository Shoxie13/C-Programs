// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Tareq Abdi
// Seneca Student ID: 123809196
// Seneca email: tabdi1@myseneca.ca
// Date of completion: 23/07/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		Product* tmp = nullptr;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0u; i < desc.size(); i++)
		{
			for (size_t j = 0u; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code) {
					tmp = new Product(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += (tmp);

					delete tmp;
					tmp = nullptr;
				}
			}
		}
		//
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0u; i < desc.size(); i++)
		{
			for (size_t j = 0u; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> tmp(new Product(desc[i].desc, price[j].price));
					tmp->validate();
					priceList += (tmp);

					tmp = nullptr;
				}
			}
		}

		return priceList;
	}
}