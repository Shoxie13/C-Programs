#pragma once
#include <iostream>
#include <string>
#include <utility>

namespace sdds {
	template<typename T>
	class Collection {
	public:
		Collection();
		~Collection();
		Collection(const std::string& name);
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
		//copy
		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;
		//move
		Collection(Collection&& src);
		Collection& operator=(Collection&& src);
		//friend
		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& co) {
			for (size_t i = 0u; i < co.size(); ++i) {
				os << co.m_arr[i];
			}
			return os;
		};
	private:
		std::string m_name;
		T* m_arr;
		size_t m_size;
		void (*observer)(const Collection<T>&, const T&);
	};

	template<typename T>
	inline Collection<T>::Collection()
	{
		m_name = {};
		m_arr = nullptr;
		m_size = 0u;
		void (*observer)(const Collection<T>&, const T&) { nullptr };
	}
	template<typename T>
	inline Collection<T>::~Collection()
	{
		delete[] m_arr;
		m_arr = nullptr;
	}
	template<typename T>
	inline Collection<T>::Collection(const std::string& name)
	{
		m_name = name;
		m_arr = nullptr;
		m_size = 0u;
		observer = nullptr;
	}
	template<typename T>
	inline const std::string& Collection<T>::name() const
	{
		return m_name;
	}
	template<typename T>
	inline size_t Collection<T>::size() const
	{
		return m_size;
	}
	template<typename T>
	inline void Collection<T>::setObserver(void(*observer)(const Collection<T>&, const T&))
	{
		this->observer = observer;
	}
	template<typename T>
	inline Collection<T>& Collection<T>::operator+=(const T& item)
	{
		bool exist = false;

		for (size_t i = 0; i < m_size; ++i) {
			if (m_arr[i].title() == item.title()) {
				exist = true;
			}
		}

		if (!exist) {
			if (m_size == 0) {
				m_size++;
				m_arr = new T[m_size];
				m_arr[0] = item;
			}
			else {
				T* temp = new T[m_size];
				for (size_t i = 0; i < m_size; ++i) {
					temp[i] = m_arr[i];
				}
				delete[] m_arr;
				m_size++;
				m_arr = new T[m_size];
				for (size_t j = 0; j < m_size - 1; ++j) {
					m_arr[j] = temp[j];
				}
				delete[] temp;
				m_arr[m_size - 1] = item;
				if (this->observer != nullptr) {
					this->observer(*this, item);
				}
			}
		}
		return *this;
	}
	template<typename T>
	inline T& Collection<T>::operator[](size_t idx) const
	{
		if (idx >= m_size || idx < 0) {
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. " + "Collection has [" + std::to_string(m_size) + "] items.");
		}
		else {
			return m_arr[idx];
		}
	}
	template<typename T>
	inline T* Collection<T>::operator[](const std::string& title) const
	{
		int idx = -1;
		for (size_t i = 0; i < m_size; ++i) {
			if (m_arr[i].title() == title) {
				idx = i;
			}
		}
		if (idx == -1) {
			return nullptr;
		}
		else {
			return &m_arr[idx];
		}
	}
	template<typename T>
	inline Collection<T>::Collection(Collection&& src)
	{
		*this = std::move(src);
	}
	template<typename T>
	inline Collection<T>& Collection<T>::operator=(Collection&& src)
	{
		if (this != &src) {
			m_arr = src.m_arr;
			m_name = src.m_name;
			m_size = src.m_size;
			observer = src.observer;

			src.m_arr = nullptr;
			src.m_name = {};
			src.m_size = 0u;
			src.observer = nullptr;
		}
		return *this;
	}
}