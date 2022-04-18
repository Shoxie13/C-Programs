#pragma once
#include <string>

namespace sdds {
	inline std::string& trim(std::string& s) {
		bool valid = true;
		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ') + 1);

		while (valid)
		{
			if (s.find("  ") != std::string::npos) {
				s.erase(s.find("  "), 1);
				valid = true;
			}if (s.find(" ,") != std::string::npos) {
				s.replace(s.find(" ,"), s.size(), ",");
				valid = true;
			}
			else
				valid = false;
		}

		return s;
	}
}