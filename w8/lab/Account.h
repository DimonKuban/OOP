// Header file. Derives from iAccount interface. Contains 3 member functions, constructor and user balance
// File Account.h
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"
namespace sict{
	class Account : public iAccount{
		double userBalance;
	protected:
		double balance() const;
	public:
		Account(double balance = 0.0);
		bool credit(double);
		bool debit(double);
	};
}
#endif