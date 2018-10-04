// Allocator implementation file. Contains implementation of allocator function
// File Allocator.cpp
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict{
	const double interestRate = 0.05;
	const double transFee = 0.50;
	const double monthlyFee = 2.00;

	// Creates an account of particular type 
	//
	iAccount* CreateAccount(const char* type, double balance){
		iAccount *acc = nullptr;
		switch (*type){
		case 'S':
			acc = new SavingsAccount(balance, interestRate); break;
		case 'C':
			acc = new ChequingAccount(balance, transFee, monthlyFee); break;
		default:
			acc = nullptr;
		};
		return acc;
	}
}