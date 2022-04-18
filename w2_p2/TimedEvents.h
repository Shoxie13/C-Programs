#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

namespace sdds {
	class TimedEvents {
	private:
		size_t m_records = 0;
		std::chrono::steady_clock::time_point startTime{};
		std::chrono::steady_clock::time_point endTime{};
		//
		struct {
			std::string m_name{};
			std::string m_unit{};
			std::chrono::steady_clock::duration m_duration{};
		} m_event[10]{};
		//
	public:
		TimedEvents() = default;
		~TimedEvents() = default;
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream& , const TimedEvents& );
	};
}
