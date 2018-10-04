// Header file. Derives from Account class. Holds transaction fee, month end fee and has 5 member functions
// File ChequingAccount.h
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#ifndef SICT_CHEQUING_ACCOUNT_H
#define SICT_CHEQUING_ACCOUNT_H

#include "Account.h"
namespace sict{
	class ChequingAccount : public Account{
		double transactionFee;
		double monthEndFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif