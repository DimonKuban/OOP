// Header implementation file. Contains implementation of 2 member functions: isEmpty and display. Also, emplements 2 constructors: no-argument and 5-argument
// File Passenger.cpp
// Date: 2018/02/16
// Author: Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;
namespace sict{

	// no-argument constructor. Sets the Passenger object to a safe empty state
	//
	Passenger::Passenger(){
		this->passName[0] = '\0';
		this->passDestination[0] = '\0';
		this->depYear = 0;
		this->depMonth = 0;
		this->depDay = 0;
	}

	// 5-argument constructor. If received data is valid, copies the data. Otherwise, sets object to an empty state
	//
	Passenger::Passenger(const char* passName, const char* passDestination, const int depYear = 0, const int depMonth = 0, const int depDay = 0){
		bool valid = passName != nullptr
			&& passDestination != nullptr
			&& !isEmpty()
			&& depYear >= 2017 && depYear <= 2020
			&& depMonth >= 1 && depMonth <= 12
			&& depDay >= 1 && depDay <= 31;

		if (valid){
			strncpy(this->passName, passName, max_name);
			this->passName[max_name] = '\0';
			strncpy(this->passDestination, passDestination, max_destination);
			this->passDestination[max_destination] = '\0';
			this->depYear = depYear;
			this->depMonth = depMonth;
			this->depDay = depDay;
		}
		else{
			*this = Passenger();
		}
	}

	// check if a query is an empty state
	//
	bool Passenger::isEmpty() const{
		return ((passName[0] == '\0') || (passDestination[0] == '\0'));
	}

	// displays the content of an object
	//
	void Passenger::display() const{
		if (isEmpty()){
			cout << "No passenger!" << endl;
		}
		else{
			cout << passName << " - " << passDestination << " on ";
			cout << depYear << "/";
			cout.width(2);
			cout.fill('0');			
			cout << depMonth;
			cout << "/" << depDay << endl;
		}
	}

	// returns an address of passanger name variable
	//
	const char* Passenger::name() const{
		return this->passName;
	}

	// checkes if passanger can travlel together or not
	//
	bool Passenger::canTravelWith(const Passenger& passenger) const{
		return (!strcmp(this->passDestination, passenger.passDestination) 
			   	&& this->depYear == passenger.depYear
				&& this->depMonth == passenger.depMonth
				&& this->depDay == passenger.depDay);
	}
}
