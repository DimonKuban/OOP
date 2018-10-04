// Allocator implementation file. Contains implementation of allocator function
// File Allocator.cpp
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#include "SavingsAccount.h"

namespace sict{
	const double interestRate = 5;

	// Creates an account of particular type 
	//
	iAccount* CreateAccount(const char* type, double balance){
		iAccount *acc = nullptr;
		switch (*type){
		case 'S':
			acc = new SavingsAccount(balance, interestRate); break;
		default:
			acc = nullptr;
		};
		return acc;
	}
}