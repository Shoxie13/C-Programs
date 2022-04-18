#pragma once

namespace sdds {
	class Book
	{
	public:
		Book() = default;
		~Book() = default;
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& bk);
		//
		template<typename T>
		void fixSpelling(T& spellChecker);
	private:
		std::string m_author{}, m_title{}, m_country{}, m_desc{};
		size_t m_year{};
		double m_price{};
	};
	//
	template<typename T>
	inline void Book::fixSpelling(T& spellChecker)
	{
		spellChecker(m_desc);
	}
}