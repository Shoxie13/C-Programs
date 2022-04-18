#pragma once
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender
	{
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		//copy
		ConfirmationSender(const ConfirmationSender& cs);
		ConfirmationSender& operator=(const ConfirmationSender& cs);
		//move
		ConfirmationSender(ConfirmationSender&& cs) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& cs) noexcept;
		//
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
	private:
		void setEmpty();
		const sdds::Reservation** rs = nullptr;
		size_t cnt = 0;
	};
}