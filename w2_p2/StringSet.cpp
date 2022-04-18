#include "StringSet.h"

namespace sdds {
	StringSet::StringSet() : m_size{0}
	{
		m_string = nullptr;
	}
	StringSet::~StringSet()
	{
		if (m_string != nullptr)
		{
			delete[] m_string;
			m_string = nullptr;
			//
			m_size = 0;
		}
	}
	StringSet::StringSet(const char* name)
	{
		setEmpty();
		//
		if (name != nullptr && name[0] != '\0')
		{
			std::string str;
			std::ifstream in{ name };
			//
			while (!in.eof())
			{
				getline(in, str, ' ');
				m_size++;
			}
			in.clear();
			in.seekg(0);
			//
			m_string = new std::string[m_size];
			//
			while (!in.eof())
			{
				for (size_t i = 0u; i < m_size; i++)
				{
					getline(in, m_string[i], ' ');
				}
			}
		}
	}
	//
	size_t StringSet::size()
	{
		return m_size;
	}
	//
	std::string StringSet::operator[](size_t s)
	{
		if (s >= m_size) {
			return "";
		}else
			return m_string[s];
			
	}
	//
	StringSet& StringSet::operator=(const StringSet& src)
	{
		if (this != &src) {
			m_size = src.m_size;
			//
			setEmpty();
			//
			m_string = new std::string[m_size];
			for (size_t i = 0u; i < m_size; i++)
			{
				m_string[i] = src.m_string[i];
			}
		}
		return *this;
	}
	//
	StringSet::StringSet(const StringSet& src)
	{
		setEmpty();
		//
		m_size = src.m_size;
		m_string = new std::string[m_size];
		for (size_t i = 0u; i < m_size; i++)
		{
			m_string[i] = src.m_string[i];
		}
	}
	//
	StringSet& StringSet::operator=(StringSet&& src) noexcept
	{
		if (this != &src) {
			setEmpty();
			//
			m_size = src.m_size;
			m_string = src.m_string;
			//
			src.m_size = 0;
			src.m_string = nullptr;
		}
		return *this;
	}
	//
	StringSet::StringSet(StringSet&& src) noexcept : m_string(nullptr), m_size{ 0 }
	{
		m_size = src.m_size;
		m_string = src.m_string;
		//
		src.m_size = 0;
		src.m_string = nullptr;
	}
	//
	void StringSet::setEmpty()
	{
		if (m_string != nullptr) {
			delete[] m_string;
			m_string = nullptr;
			m_size = 0;
		}
	}
	//
}