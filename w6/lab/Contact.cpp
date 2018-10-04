// Header implementation file. Contains implementation of 2 constructors, destructor and member functions
// File Passenger.cpp 
// Date: 2018/03/16 
// Author: Dmitrii Korolevskii 

#include <iostream> 
#include <cstring> 
#include "Contact.h" 
using namespace std;
namespace sict {

	// no-argument constructor. Sets the Contact object to a safe empty state 
	// 
	Contact::Contact() {
		this->contName[0] = '\0';
		this->phoneNumber = nullptr;
		this->phonesQuantity = 0;
	}

	// 3-argument constructor. If received data is valid, allocates enouth memory to store phone numbers and stores data
	//
	Contact::Contact(const char* name, const long long* phone, int quantity) {
		bool valid = name != nullptr && name[0] != '\0';
		if (valid){
			int counter = 0;
			for (int i = 0; i < quantity; i++){
				if (validPhone(phone[i])){
					counter++;
				}
			}
			strncpy(this->contName, name, max_name);
			contName[max_name] = '\0';
			this->phonesQuantity = counter;
			phoneNumber = new long long[counter];
			int recorded = 0;
			for (int i = 0; i < quantity; i++){
				if (validPhone(phone[i])){
					this->phoneNumber[recorded] = phone[i];
					recorded++;
				}
			}
		}
		else{
			this->phoneNumber = nullptr;
			*this = Contact();
		}
	}

	// checks if received phone number is valid or not
	//
	bool Contact::validPhone(const long long number){
		return ((number >= 10000000000) && (number <= 1000000000000 - 1) && (number / 1000000 % 10 != 0) && (number / 1000000000 % 10 != 0));
	}

	// destructor. Deallocates memory allocated for phone numbers
	//
	Contact::~Contact() {
		delete[] phoneNumber;
	}


	// check if a query is an empty state
	//
	bool Contact::isEmpty() const {
		return (this->contName[0] == '\0');
	}

	// displays data
	//
	void Contact::display() const {
		if (this->isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << this->contName << endl;
			for (int i = 0; i < phonesQuantity; i++){
				cout << "(+" << (phoneNumber[i] / 10000000000) << ") ";
				cout << phoneNumber[i] / 10000000 % 1000 << " ";
				cout << phoneNumber[i] / 10000 % 1000 << "-";
				cout.width(4);
				cout.fill('0');
				cout << phoneNumber[i] % 10000 << endl;
			}
		}
	}

}
