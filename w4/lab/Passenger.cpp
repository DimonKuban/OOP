// Header implementation file. Contains implementation of 2 member functions: isEmpty and display. Also, emplements 2 constructors: no-argument and 2-argument
// File Passenger.cpp
// Date: 2018/02/12
// Author: Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;
namespace sict{

	// no-argument constructor. Sets the Passenger object to a safe empty state
	//
	Passenger::Passenger(){
		this->name[0] = '\0';
		this->destination[0] = '\0';
	}
	
	// 2-arguments constructor. If data is valid, copies the data. Otherwise, sets object to an empty state
	//
	Passenger::Passenger(const char* name, const char* destination){
		bool valid = name != nullptr && name[0] != '\0' && destination != nullptr && destination[0] != '\0';
			if (valid){
			strncpy(this->name, name, max_name);
			this->name[max_name] = '\0';
			strncpy(this->destination, destination, max_destination);
			this->destination[max_destination] = '\0';
		}
		else{
			*this = Passenger();
		}
	}

	// check if a query is an empty state
	//
	bool Passenger::isEmpty() const{
		return ((name[0] == '\0') || (destination[0] == '\0'));
	}
	
	// displays the content of an object
	//
	void Passenger::display() const{
		if (isEmpty()){
			cout << "No passenger!" << endl;
		}
		else{
			cout << name << " - " << destination << endl;
		}
	}
}
