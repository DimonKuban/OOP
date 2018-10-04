// Header file. Derives from Account class. Holds interest rate and member functions
// File SavingAccount.h
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#ifndef SICT_SAVINGS_ACCOUNT_H
#define SICT_SAVINGS_ACCOUNT_H

#include "Account.h"
namespace sict{
	class SavingsAccount : public Account{
		double interest;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif