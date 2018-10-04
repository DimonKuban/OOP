// Header implementation file. Contains implementation of 3 member functions, including constructor
// File SavingAccount.h
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#include <iostream>
#include "SavingsAccount.h"
namespace sict{

	// 2-arg constructor. Stores rate and sets balance
	//
	SavingsAccount::SavingsAccount(double balance, double interest){
		Account::credit(balance);
		if (interest > 0){
			this->interest = interest;
		}
		else{
			this->interest = 0.0;
		}
	}

	// calculates the interest and credits the account
	//
	void SavingsAccount::monthEnd(){
		Account::credit(this->interest * Account::balance());
	}

	// inserts account information into received output object
	//
	void SavingsAccount::display(std::ostream& os) const{
		os << "Account type: Savings" << std::endl;
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Balance: $" << Account::balance() << std::endl;
		os << "Interest Rate (%): " << this->interest*100 << std::endl;
		os.unsetf(std::ios::fixed);
		os.precision(6);
	}

}