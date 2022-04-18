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
#include "Pair.h"
#include <iomanip>

namespace sdds {
	template<typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
	public:
		PairSummable() : Pair<V, K>() {};
		~PairSummable() = default;
		PairSummable(const K& key, const V& value = initial);
		bool isCompatibleWith(const PairSummable<V, K>& b) const;
		PairSummable& operator+=(const PairSummable& tk);
		void display(std::ostream& os) const;
	private:
		static inline V initial{};
		static inline size_t m_field = 0;
	};
	//
	template<typename V, typename K>
	inline PairSummable<V, K>::PairSummable(const K& key, const V& value) : Pair<V, K>(key, value)
	{
		if (key.size() > m_field) {
			m_field = key.size();
		}
	}
	//
	template<typename V, typename K>
	inline bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b) const
	{
		if (b.key() == this->key()) {
			return true;
		}
		else return false;
	}
	//
	template<typename V, typename K>
	inline PairSummable<V, K>& PairSummable<V, K>::operator+=(const PairSummable<V, K>& tk)
	{
		if (isCompatibleWith(tk)) {
			*this = PairSummable(tk.key(), this->value() + tk.value());
		}
		return *this;
	}
	//
	template<>
	inline PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& tk)
	{
		if (isCompatibleWith(tk)) {
			if (!this->value().empty()) {
				*this = PairSummable(tk.key(), this->value() + ", " + tk.value());
			}
			else {
				*this = PairSummable(tk.key(), this->value() + tk.value());
			}
		}
		return *this;
	}
	//
	template<typename V, typename K>
	inline void PairSummable<V, K>::display(std::ostream& os) const
	{
		os << std::left << std::setw(m_field);
		Pair<V, K>::display(os);
		os << std::right;
	}
	//
}