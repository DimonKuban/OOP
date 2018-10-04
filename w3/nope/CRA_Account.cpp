// Header implementation file. Contains implementation of 3 class functions: isEmpty, display, set
// File CRA_Account.css
// Date: 2018/02/04
// Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sict{
	bool check(int SIN);
	// check if SIN inputed correctly. If correct - returns 0, else 1
	//
	bool CRA_Account::isEmpty() const{
		if ((SIN == 0) || (theFamilyName[0] == '\0') || (theGivenName[0] == '\0')) {
			return 1;
		}
		else{
			return 0;
		}
	}
	// if all 3 variables: SIN, last and first names exist, display them. Else show that object is empty
	//
	void CRA_Account::display() const{
		if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}
		else{
			cout << "Family Name : " << theFamilyName << endl;
			cout << "Given Name :  " << theGivenName << endl;
			cout << "CRA Account : " << SIN << endl;
			for (int i = 0; i < max_yrs; i++){

				if (balance[i] > 2){
					cout << "(Year) " << year[i] << " balance owing: " << balance[i] << endl;
				}
				else if (balance[i] < -2){
					cout << "(Year) " << year[i] << " refund due: " << balance[i] << endl;
				}
				else{
					cout << "(Year) " << year[i] << " No balance owing or refund due! " << endl;
				}
			}
		}
	}

	//
	//setter function. set year and balance if object has a valid SIN and has room for data
	void CRA_Account::set(int year, double balance){
		
		bool flag = 1;
		for (int i = 0; i < max_yrs && flag; i++){
			//cout << CRA_Account::balance[i] << "????????????????";
			if (!((CRA_Account::balance[i] > -1000000) && (CRA_Account::balance[i] < 1000000))){ //**************************8исправить проверку на 0
				//cout << "INSIDE***************** i = "<< i << endl;
				
				CRA_Account::balance[i] = balance;
				//cout << "balance should be " << balance << "and its: " << CRA_Account::balance[i];
				CRA_Account::year[i] = year;
				flag = 0;
			}
		}
	}

		// setter function. Checks if sin is in a range. If so, set inputed data, else set them to empty
		//
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
			if (((sin >= min_sin) && (sin <= max_sin)) && (familyName[0] != '\0') && (givenName[0] != '\0') && check(sin)){
				strncpy(theFamilyName, familyName, 40);
				strncpy(theGivenName, givenName, 40);
				theFamilyName[40] = '\0';
				theGivenName[40] = '\0';
				SIN = sin;
				yearNumber = 0;
			}
			else{
				theFamilyName[0] = '\0';
				theGivenName[0] = '\0';
				SIN = 0;
				yearNumber = 0;
				for (int i = 0; i < max_yrs; i++){
					year[i] = 0;
					balance[i] = 0;
				}
			}
		}

		// chech if inputed SIN is in valid range
		//
	bool check(int SIN){

			if ((SIN >= 1000000000) || (SIN <= 99999999)){
				return 0;
			}
			else{
				//поставить коменты к переменным
				int weightSum = 0;
				int weightSumMult = 0;
				int numbSum = 0;
				int mult = 1;

				for (int i = 10; i <= 10000000; i *= 100){
					weightSum = weightSum + (SIN / i % 10)*mult;
					mult *= 10;
				}

				mult = 1;
				for (int i = 1; i <= 1000; i *= 10){
					if ((weightSum / i % 10) < 5){
						weightSumMult = weightSumMult + ((weightSum / i % 10)) * 2 * mult;
						mult *= 10;
					}
					else{
						weightSumMult = weightSumMult + (((weightSum / i % 10)) % 10) * 2 * mult;
						mult *= 10;
						weightSumMult = weightSumMult + (((weightSum / i % 10)) / 10) * 2 * mult;
						mult *= 10;
					}
				}

				while ((weightSumMult / 10) != 0){
					numbSum += weightSumMult % 10;
					weightSumMult /= 10;
					if ((weightSumMult / 10) == 0){
						numbSum += weightSumMult % 10;
					}
				}

				int otherAlterSum = 0;
				for (int i = 100; i <= 100000000; i *= 100){
					otherAlterSum += SIN / i % 10;
				}

				int total = numbSum + otherAlterSum;

				int nextHighestMultInt = total;

				while ((nextHighestMultInt % 10) != 0){
					nextHighestMultInt++;
				}

				int difference = nextHighestMultInt - total;

				if ((SIN % 10) == difference){
					return 1;
				}
				else{
					return 0;
				}
			}
		}

	/*bool hasRoom(double balance[]){
		for (int i = 0; i < sizeof(balance); i++){
			if (balance[0] == 0){
				return 1;
			}
		}
		return 0;
	}*/
}
