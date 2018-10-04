// Header implementation file. Contains implementation of 3 class functions: isEmpty, display, set and sinIsValid function
// File CRA_Account.cpp
// Date: 2018/02/09
// Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;
namespace sict{

	// prototype of the function which checks if SIN if in a valid range
	//
	bool sinIsValid(int SIN);

	// check if an object holds valid SIN
	//
	bool CRA_Account::isEmpty() const{
		return (SIN == 0);
	}

	// if all 3 variables: SIN, last and first names exist, display them. Else show that object is empty
	//
	void CRA_Account::display() const{
		if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}
		else{
			cout << "Family Name: " << theFamilyName << endl;
			cout << "Given Name : " << theGivenName << endl;
			cout << "CRA Account: " << SIN << endl;
			for (int i = 0; i < max_yrs; i++){
				cout.setf(ios::fixed);
				cout.precision(2);
				if (balance[i] > 2){
					cout << "Year (" << year[i] << ") balance owing: " << balance[i] << endl;
				}
				else if (balance[i] < -2){
					cout << "Year (" << year[i] << ") refund due: " << -balance[i] << endl;
				}
				else{
					cout << "Year (" << year[i] << ") No balance owing or refund due!" << endl;
				}
				cout.unsetf(ios::fixed);
				cout.precision(6);
			}
		}
	}

	// setter function. set balance if object has a valid SIN and has a room for data
	//
	void CRA_Account::set(int theYear, double theBalance){
		if ((yearNumber < 4) && (sinIsValid(SIN))){
			balance[yearNumber] = theBalance;
			year[yearNumber++] = theYear;
		}
	}

	// setter function. Checks if sin is in a range. If so, set inputed data, else set them to empty
	//
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
		for (int i = 0; i < max_yrs; i++){
			year[i] = 0;
			balance[i] = 0;
		}
		theFamilyName[0] = '\0';
		theGivenName[0] = '\0';
		SIN = 0;
		yearNumber = 0;

		if ((familyName[0] != '\0') && (givenName[0] != '\0') && sinIsValid(sin)){
			strncpy(theFamilyName, familyName, 40);
			theFamilyName[40] = '\0';
			strncpy(theGivenName, givenName, 40);
			theGivenName[40] = '\0';
			SIN = sin;
		}
	}

	// chech if inputed SIN is in valid range
	//
	bool sinIsValid(int SIN){
		bool result = false;
		if ((SIN >= min_sin) && (SIN <= max_sin)){

			// weighted sum - the sum of digits starting from the left digit of checking (the most right) digit and each second digit leftward
			//
			int weightSum = 0;

			// the number for multiplication
			//
			int bitNum = 1;
			for (int i = 10; i <= min_sin / 10; i *= 100){
				weightSum += (SIN / i % 10)*bitNum;
				bitNum *= 10;
			}

			// Weight sum of even positioned digits 
			//
			int evenWeightSum = 0;
			bitNum = 1;
			for (int i = 1; i <= min_sin / 10; i *= 10){

				// represents the number which is currently checking for adding
				//
				int currentNumber = weightSum / i % 10;
				if (currentNumber < 5){
					evenWeightSum += currentNumber * 2;
				}
				else{
					evenWeightSum += (currentNumber * 2 % 10) + (currentNumber * 2 / 10);
				}
			}

			// counts the sum of other numbers, not included in previous calculations
			//
			int otherAlterSum = 0;
			for (int i = 100; i <= min_sin; i *= 100){
				otherAlterSum += SIN / i % 10;
			}

			// calculates the sum of alternatives and weight sum
			//
			int total = evenWeightSum + otherAlterSum;

			// calculate the difference between total and next integer multiple of 10
			//
			int difference = 10 - (total % 10);

			if ((SIN % 10) == difference){
				result = true;
			}

			// weighted sum of all digits
			//
			int sum = 0;
			while (SIN != 0){
				sum += SIN % 10;
				SIN /= 10;
			}
			if ((sum % 10) != 0){
				result = false;
			}
		}
		return result;
	}
}
