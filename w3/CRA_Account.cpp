// Header implementation file. Contains implementation of 3 class functions: isEmpty, display, set
// File CRA_Account.css
// Date: 2018/02/04
// Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;
namespace sict{

	// check if SIN inputed correctly. If correct - returns 0, else return 1
	//
	bool CRA_Account::isEmpty() const{
		if ((SIN == 0) || (theFamilyName[0] == '\0') || (theGivenName[0] == '\0')) {
			return 1;
		}
		else{
			return 0;
		}
	}

	// if all 3 variables: SIN, last and first names exist - display them. Else show a message that the object is empty
	//
	void CRA_Account::display() const{
		if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}
		else{
			cout << "Family Name: " << theFamilyName << endl;
			cout << "Given Name : " << theGivenName << endl;
			cout << "CRA Account: " << SIN << endl;
		}
	}

	// setter function. Checks if sin is in a range. If so, set inputed data, else set them to empty state
	//
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
		if ((sin >= min_sin) && (sin <= max_sin)){
			strncpy(theFamilyName, familyName, max_name_length);
			strncpy(theGivenName, givenName, max_name_length);	
			theFamilyName[max_name_length] = '\0';
			theGivenName[max_name_length] = '\0';
			SIN = sin;
		}
		else{
			theFamilyName[0] = '\0';
			theGivenName[0] = '\0';
			SIN = 0;
		}
	}


}
