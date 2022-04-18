#pragma once

namespace sdds {
	class Movie {
	public:
		Movie();
		~Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& mv);
		//
		template<typename T>
		void fixSpelling(T& spellChecker);
	private:
		std::string m_title{}, m_desc{};
		size_t m_year = 0u;
	};
	template<typename T>
	inline void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(m_title);
		spellChecker(m_desc);
	}
}