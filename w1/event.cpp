 //==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
//==============================================
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"

size_t g_sysClock = 0;

namespace sdds {
	void Event::display() const
	{
		static int count = 1;
		int hh = 0, mm = 0, ss = 0;
		hh = m_time / 3600;
		mm = m_time / 60 % 60;
		ss = m_time % 60;

		if (m_desc == nullptr || m_desc[0] == '\0')
		{
			std::cout << std::setw(2) << std::setfill(' ') << count++ << ". " << "| No Event |" << std::endl;
		}
		else 
		{
			std::cout << std::setw(2) << std::setfill(' ')
				<< count++ << ". "
				<< std::setw(2) << std::setfill('0') << hh << ":"
				<< std::setw(2) << std::setfill('0') << mm << ":"
				<< std::setw(2) << std::setfill('0') << ss << " => "
				<< m_desc << std::endl;
		}
	}
	//
	void Event::set(const char* src)
	{
		setEmpty();
		//
		if (src)
		{
			m_desc = new char[strlen(src) + 1];
			strcpy(m_desc, src);
			m_time = g_sysClock;
		}
		else 
		{
			setEmpty();
		}
	}
	//
	void Event::setEmpty()
	{
		if (m_desc != nullptr)
		{
			delete[] m_desc;
			m_desc = nullptr;
			m_time = 0;
		}
	}
	//
	Event::~Event()
	{
		setEmpty();
	}
	//
	Event& Event::operator=(const Event& src)
	{
		setEmpty();
		if (this != &src) 
		{
			delete[] m_desc;
			m_desc = nullptr;
			//
			set(src.m_desc);
			m_time = src.m_time;
		}
		return *this;
	}
	//
	Event::Event(const Event& src)
	{
		set(src.m_desc);
		m_time = src.m_time;
	}
	//
}