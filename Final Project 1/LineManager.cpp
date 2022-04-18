#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "Utilities.h"
#include "LineManager.h"

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream in(file);
		if (!in.is_open()) {
			throw "File could not be opened";
		}

		Utilities ext;

		while (!in.eof()) {
			std::string s;
			size_t next_pos = 0;
			bool more = true;
			//

			getline(in, s);
			//
			s.erase(s.find_last_not_of("\r") + 1);
			std::string str = ext.extractToken(s, next_pos, more);
			auto exportFrom = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
				return station->getItemName() == str;
				});
			activeLine.push_back(exportFrom);

			if (!more) {
				continue;
			}

			std::string ctr = ext.extractToken(s, next_pos, more);
			auto importTo = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
				return station->getItemName() == ctr;
				});

			exportFrom->setNextStation(importTo);
		}

		Workstation* cur_stat = nullptr;
		//
		for_each(stations.begin(), stations.end(), [&](Workstation* tmp) {
			cur_stat = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
				return station->getNextStation() == cur_stat;
				});
			});
		//
		m_firstStation = cur_stat;
	}

	void LineManager::linkStations()
	{
		const Workstation* stat = m_firstStation;
		size_t i = 0;
		while (stat != nullptr) {
			activeLine[i++] = const_cast<Workstation*>(stat);
			stat = stat->getNextStation();
		}
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t it = 0;
		//
		os << "Line Manager Iteration: " << ++it << std::endl;
		//
		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
			m_cntCustomerOrder++;
		}
		//
		for (auto& o : activeLine) {
			o->fill(os);
		}
		for (auto& o : activeLine) {
			o->attemptToMoveOrder();
		}
		//
		return completed.size() + incomplete.size() == m_cntCustomerOrder;
	}

	void LineManager::display(std::ostream& os) const
	{
		for (auto& o : activeLine) {
			if (o != nullptr) {
				o->display(os);
			}
		}
	}
}