// Header implementation file. Contains implementation of 3 constructors, destructor, members and overloaded functions
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

	// localization of the common code for copy constructor and copy assignment operator. 
	//
	void Contact::init(const Contact& source){
		phonesQuantity = source.phonesQuantity;
		strncpy(this->contName, source.contName, max_name);
		contName[max_name] = '\0';
		if (source.phoneNumber != nullptr){
			phoneNumber = new long long[phonesQuantity];
			for (int i = 0; i < phonesQuantity; i++){
				this->phoneNumber[i] = source.phoneNumber[i];
			}
		}
		else{
			phoneNumber = nullptr;
		}
	}

	// copy constructor. makes a copy of an existing instance
	//
	Contact::Contact(const Contact& src){
		init(src);
	}

	// copy assignment operator. Copies the content of received object into the current
	//
	Contact& Contact::operator=(const Contact& source){
		if (this != &source){
			delete [] phoneNumber;
			init(source);
		}
		return *this;
	}

	// if received number is valid resizes the phone number array and adds a new number
	//
	Contact& Contact::operator+=(long long source){
		if (validPhone(source)){
			long long *updatedNumbers = new long long[phonesQuantity + 1];
			for (int i = 0; i < phonesQuantity; i++){
				updatedNumbers[i] = phoneNumber[i];
			}
			updatedNumbers[phonesQuantity] = source;
			delete[] phoneNumber;
			phoneNumber = updatedNumbers;
			phonesQuantity++;
		}
		return *this;
	}
}
