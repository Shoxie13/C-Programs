#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
#include "Utilities.h"

namespace sdds {
	size_t SpellChecker::t, SpellChecker::m, SpellChecker::b, 
		SpellChecker::f, SpellChecker::d, SpellChecker::h;
	//
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		std::string strWord;
		if (file) {
			for (size_t i = 0u; i < MAX_WORDS; i++) {

				std::getline(file, strWord);

				m_badWords[i] = strWord.substr(0, strWord.find(' '));
				m_goodWords[i] = strWord.substr(strWord.find(' '), strWord.length() - 1);

				trim(m_badWords[i]);
				trim(m_goodWords[i]);
			}
		}
		else {
			throw "Bad file name!\n";
		}
		file.close();
	}
	void SpellChecker::operator()(std::string& text)
	{
		if (!text.empty()) {
			for (size_t i = 0; i < MAX_WORDS; i++)
			{
				size_t start = text.find(m_badWords[i]);
				while (start != std::string::npos) {
					text.replace(start , m_badWords[i].size(), m_goodWords[i]);
					start = text.find(m_badWords[i]);
					if (m_badWords[i] == "teh") {
						t++;
					}
					else if (m_badWords[i] == "modiffied") {
						m++;
					}
					else if (m_badWords[i] == "begim") {
						b++;
					}
					else if (m_badWords[i] == "famillies") {
						f++;
					}
					else if (m_badWords[i] == "Dork") {
						d++;
					}
					else if (m_badWords[i] == "hibrid") {
						h++;
					}
				}
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		size_t i = 0;
		//
		out << "Spellchecker Statistics\n";
		//
		do {
			out << std::right << std::setw(15) << m_badWords[i] << ": ";
			if (m_badWords[i] == "teh") {
				out << t;
			}
			else if (m_badWords[i] == "modiffied") {
				out << m;
			}
			else if (m_badWords[i] == "begim") {
				out << b;
			}
			else if (m_badWords[i] == "famillies") {
				out << f;
			}
			else if (m_badWords[i] == "Dork") {
				out << d;
			}
			else if (m_badWords[i] == "hibrid") {
				out << h;
			}
			out << " replacements" << std::endl;

			i++;
		} while (i != MAX_WORDS);
	}
}