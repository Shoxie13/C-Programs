//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
//==============================================
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------

#pragma once
#include "Set.h"
#include <string>

namespace sdds {
	template<unsigned int N, typename T>
	class SetSummable : public Set<N, T>
	{
	public:
		SetSummable() = default;
		~SetSummable() = default;
		T accumulate(const std::string& filter) const;
	private:

	};
	template<unsigned int N, typename T>
	inline T SetSummable<N, T>::accumulate(const std::string& filter) const
	{
		T acc(filter);
		for (size_t i = 0; i < this->size(); i++) {
			acc += this->get(i);
		}
		return acc;
	}
}