// Interface. Contains 4 public memeber functions and helper function
// File iAccount.h
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#ifndef SICT_IACCOUNT
#define SICT_IACCOUNT

#include <iostream>
namespace sict{
	class iAccount{
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
	};

	iAccount* CreateAccount(const char*, double);
}

#endif