// Header implementation file. Contains implementation of constructor, member functions, helper operator
// File ErrorState.cpp
// Date: 2018/03/22
// Author: Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "ErrorState.h"
using namespace std;
namespace AMA{

	// receives the address of errorMessage and allocates memory for it if not a nullptr
	//
	ErrorState::ErrorState(const char* errorMessage){
		ErrorState::message(errorMessage);
	}

	// de-allocates memory for errorMessage
	//
	ErrorState::~ErrorState(){
		delete[] errorMessage;
	}

	// cleares stored message
	//
	void ErrorState::clear(){
		errorMessage = nullptr;
	}

	// returns true if current object in a safe empty state
	//
	bool ErrorState::isClear() const{
		return (errorMessage == nullptr || errorMessage[0] == '\0');
	}

	// stores a copy of C-style string pointer
	//
	void ErrorState::message(const char* str){
		if (str == nullptr){
			this->errorMessage = nullptr;
		}
		else{
			this->errorMessage = new char[strlen(str) + 1];
			strncpy(this->errorMessage, str, (strlen(str)));
			this->errorMessage[strlen(str)] = '\0';
		}
	}

	// returns the address of the message
	//
	const char* ErrorState::message() const{
		return this->errorMessage;
	}

	// if error message exists sends it to ostream
	//
	std::ostream& operator<<(std::ostream& os, ErrorState& er){
		if (!er.isClear()){
			os << er.message();
		}
		return os;
	}
}