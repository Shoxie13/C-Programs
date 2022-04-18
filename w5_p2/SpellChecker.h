#pragma once

namespace sdds {
	const int MAX_WORDS = 6;
	//
	class SpellChecker {
	public:
		SpellChecker() = default;
		~SpellChecker() = default;
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	private:
		std::string m_badWords[MAX_WORDS]{};
		std::string m_goodWords[MAX_WORDS]{};
		static size_t t, m, b, f, d, h;
	};
}