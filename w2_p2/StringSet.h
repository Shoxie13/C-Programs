#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace sdds {
	class StringSet
	{
	public:
		StringSet();
		~StringSet();
		StringSet(const char* name);
		size_t size();
		std::string operator[](size_t);
		StringSet& operator=(const StringSet& src);
		StringSet(const StringSet& src);
		//
		StringSet& operator=(StringSet&& src) noexcept;
		StringSet(StringSet&& src) noexcept;
	private:
		void setEmpty();
		std::string* m_string = nullptr;
		size_t m_size = 0;
	};
}