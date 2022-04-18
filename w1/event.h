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

extern size_t g_sysClock;

namespace sdds {
	class Event
	{
	public:
		Event() = default;
		~Event();
		Event& operator=(const Event& src);
		Event(const Event& src);
		void display() const;
		void set(const char* src = 0);
		void setEmpty();
	private:
		char* m_desc = nullptr;
		size_t m_time = 0;
	};
}