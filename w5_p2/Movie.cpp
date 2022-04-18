#include <iostream>
#include <iomanip>
#include "Movie.h"
#include "Utilities.h"

namespace sdds {
    Movie::Movie()
    {
        m_title = {};
        m_desc = {};
        m_year = 0u;
    }
    const std::string& Movie::title() const
    {
        return m_title;
    }
    Movie::Movie(const std::string& strMovie)
    {
		std::string str = strMovie;
		//
		std::string title = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);
        //
        std::string year = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);
		//
		std::string desc = str.substr(0, str.find('.') + 1);
		//
		m_title = trim(title);
		m_year = stoi(trim(year));
        m_desc = trim(desc);
    }
    std::ostream& operator<<(std::ostream& os, const Movie& mv)
    {
        os << std::setw(40) << mv.m_title << " | " 
            << std::setw(4) << mv.m_year << " | " 
            << mv.m_desc << std::endl;
        return os;
    }
}