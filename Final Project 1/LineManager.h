#pragma once
#include "Workstation.h"

namespace sdds {
	class LineManager
	{
	public:
		LineManager() = default;
		~LineManager() = default;
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	private:
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder = 0;
		Workstation* m_firstStation = nullptr;
	};
}