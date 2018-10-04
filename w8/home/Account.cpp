// Account.h implementation file. Contains implementation of 3 member functions and constructor
// File Account.cpp
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#include <iostream>
#include "Account.h"
namespace sict{

	// 1-argument constructor. Stores balance
	//
	Account::Account(double balance){
		balance > 0 ? userBalance = balance : userBalance = 0.0;
	}

	// adds credit amount if valid
	//
	bool Account::credit(double credit_){
		if (credit_ > 0){
			userBalance += credit_;
			return true;
		}
		else{
			return false;
		}
	}

	// subtracts debit amount if valid
	//
	bool Account::debit(double debit_){
		if (debit_ > 0){
			userBalance -= debit_;
			return true;
		}
		else{
			return false;
		}
	}

	// returns user balance
	//
	double Account::balance() const{
		return userBalance;
	}
	
}