#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender()
	{
		rs = nullptr;
		cnt = 0;
	}
	//
	ConfirmationSender::~ConfirmationSender()
	{
		setEmpty();
	}
	//
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool valid = false;

		for (size_t i = 0u; i < cnt; ++i)
		{
			if (&res == rs[i]) {
				valid = true;
			}
		}

		if (!valid) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [cnt + 1];
			for (size_t i = 0; i < cnt; ++i)
			{
				temp[i] = rs[i];
			}
			temp[cnt] = &res;
			cnt++;
			delete[] rs;
			rs = temp;
		}
		return *this;
	}
	//
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool valid = false;
		size_t n = 0;
		//
		for (size_t i = 0u; i < cnt; ++i)
		{
			if (&res == rs[i]) {
				valid = true;
				n = i;
			}
		}

		if (valid) {
			const Reservation** temp = nullptr;
			if (cnt > 0) {
				temp = new const Reservation * [cnt - 1];
				for (size_t i = 0; i < cnt - 1; ++i)
				{
					if (i < n) {
						temp[i] = rs[i];
					}
					else {
						temp[i] = rs[i + 1];
					}
				}
			}
			cnt--;
			delete[] rs;
			rs = temp;
		}
		return *this;
	}
	//
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs)
	{
		*this = cs;
	}
	//
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs)
	{
		if (this != &cs) {
			cnt = cs.cnt;
			delete[] rs;
			rs = new const Reservation*[cnt];
			for (size_t i = 0u; i < cnt; i++)
			{
				rs[i] = cs.rs[i];
			}
		}
		return *this;
	}
	//
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) noexcept
	{
		*this = std::move(cs);
	}
	//
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) noexcept
	{
		if (this != &cs) {
			cnt = cs.cnt;
			rs = cs.rs;

			cs.rs = nullptr;
			cs.cnt = 0;
		}
		return *this;
	}
	//
	void ConfirmationSender::setEmpty()
	{
		if (rs != nullptr)
		{
			delete[] rs;
			rs = nullptr;
			cnt = 0;
		}
	}
	//
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs)
	{
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";
		if (cs.rs) {
			for (size_t i = 0; i < cs.cnt; ++i)
			{
				os << *cs.rs[i];
			}
		}
		else {
			os << "There are no confirmations to send!\n";
		}
		os << "--------------------------\n";
		return os;
	}
}