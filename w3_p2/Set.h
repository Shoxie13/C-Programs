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

namespace sdds {
	template<unsigned int N, class T>
	class Set {
	private:
		T m_class[N]{};
		size_t cnt = 0u;
	public:
		Set() = default;
		~Set() = default;
		size_t size() const;
		const T& get(size_t idx) const;
		void operator+=(const T& item);
	};
	template<unsigned int N, class T>
	inline size_t Set<N, T>::size() const
	{
		return N;
	}
	template<unsigned int N, class T>
	inline const T& Set<N, T>::get(size_t idx) const
	{
		return m_class[idx];
	}
	template<unsigned int N, class T>
	inline void Set<N, T>::operator+=(const T& item)
	{
		if (cnt < N)
		{
			m_class[cnt] = item;
			cnt++;
		}
	}
}