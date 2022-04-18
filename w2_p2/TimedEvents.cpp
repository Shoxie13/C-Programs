#include "TimedEvents.h"

namespace sdds {
	void TimedEvents::startClock() {
		startTime = std::chrono::steady_clock::now();
	};
	//
	void TimedEvents::stopClock() {
		endTime = std::chrono::steady_clock::now();
	}
	//
	void TimedEvents::addEvent(const char* name) {
		if (m_records < 10)
		{
			m_event[m_records].m_name = name;
			m_event[m_records].m_unit = " nanoseconds";
			m_event[m_records].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
			m_records++;
		}
	}
	//
	std::ostream& operator<<(std::ostream& os, const TimedEvents& src) {
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;

		for (size_t i = 0; i < src.m_records; i++)
		{
			os << std::left << std::setw(21) << src.m_event[i].m_name
				<< std::right << std::setw(13) << src.m_event[i].m_duration.count() 
				<< src.m_event[i].m_unit << std::endl;
			os << "--------------------------\n";
		}
		return os;
	}
}