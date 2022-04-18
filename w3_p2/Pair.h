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
#include <iostream>

namespace sdds {
	template<typename V, typename K>
	class Pair {
	private:
		V m_value{};
		K m_key{};
	public:
		Pair() = default;
		~Pair() = default;
		Pair(const K& key, const V& value);
		const V& value() const;
		const K& key() const;
		virtual void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			if (!pair.key().empty()) {
				pair.display(os);
				return os;
			}
			else {
				return os;
			}
		};
	};
	template<typename V, typename K>
	inline Pair<V, K>::Pair(const K& key, const V& value)
	{
		m_key = key;
		m_value = value;
	}
	//
	template<typename V, typename K>
	inline const V& Pair<V, K>::value() const
	{
		return m_value;
	}
	//
	template<typename V, typename K>
	inline const K& Pair<V, K>::key() const
	{
		return m_key;
	}
	//
	template<typename V, typename K>
	inline void Pair<V, K>::display(std::ostream& os) const
	{
		os << m_key << " : " << m_value << std::endl;
	}
}