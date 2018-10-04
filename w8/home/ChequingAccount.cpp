// Header implementation file. Contains implementation of 5 member functions
// File ChequingAccount.h
// Date: 2018/02/26
// Author: Dmitrii Korolevskii

#include <iostream>
using namespace std;
#include "ChequingAccount.h"
namespace sict{
	
	// 3-arg constructor. Stores balance, transaction fees and month end fees if valid
	//
	ChequingAccount::ChequingAccount(double initialBalance, double transactionFee, double monthEndFee){
		Account::credit(initialBalance);
		if (transactionFee > 0){
			this->transactionFee = transactionFee;
		}
		else{
			this->transactionFee = 0.0;
		}
		if (monthEndFee > 0){
			this->monthEndFee = monthEndFee;
		}
		else{
			this->monthEndFee = 0.0;
		}
	}

	// adds credit amount if valid and substracts transaction fee
	//
	bool ChequingAccount::credit(double credit_){
		if (Account::credit(credit_)){
			Account::debit(transactionFee);
			return true;
		}
		else{
			return false;
		}
	}

	// subtracts debit amount if valid and substracts transaction fee
	//
	bool ChequingAccount::debit(double debit_){
		if (Account::debit(debit_)){
			Account::debit(transactionFee);
			return true;
		}
		else{
			return false;
		}
	}

	// calculates the interest, credits the account and substracts transaction fee
	//
	void ChequingAccount::monthEnd(){
		Account::debit(transactionFee + monthEndFee);
	}

	// inserts account information into received output object
	//
	void ChequingAccount::display(std::ostream& os) const{
		os << "Account type: Chequing" << endl;
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << transactionFee << endl;
		os << "Monthly Fee: " << monthEndFee << endl;
	}
}