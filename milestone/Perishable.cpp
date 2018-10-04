// Header implementation file. Contains implementation of constructor, member functions, helper operator
// File ErrorState.cpp
// Date: 2018/04/16
// Author: Dmitrii Korolevskii

#include <iostream>
#include "Perishable.h"
#ifdef DELIM
#undef DELIM
#endif
#define DELIM ','
#ifndef TAG
#undef TAG
#endif
#define TAG 'P'

namespace AMA{

	// no-arg constructor. Passes the file record tag to base class
	//
	Perishable::Perishable() : Product(TAG){}

	// stores a single file record for the current object
	//
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const{
		Product::store(file, false);
		file << DELIM << expiry();
		if (newLine){ file << std::endl; }
		return file;
	}

	// extracts the data fields for a single file record from the fstream object
	//
	std::fstream& Perishable::load(std::fstream& file){
		Product(TAG);
		Product::load(file);
		file.ignore();
		expireDate.read(file);
		return file;
	}

	// inserts the expiry date into the ostream object
	//
	std::ostream& Perishable::write(std::ostream& os, bool linear) const{
		Product::write(os, linear);
		if (!this->isEmpty() && this->isClear()){
			if (linear){ os << expiry(); }
			else{ os << "\n Expiry date: " << expiry();	}
		}
		return os;
	}

	// populates the current object with the data extracted from the istream object
	//
	std::istream& Perishable::read(std::istream& is){
		Product::read(is);
			Date tempDate;
			if (!is.fail()){
				std::cout << " Expiry date (YYYY/MM/DD): ";
				is >> tempDate;
				switch (tempDate.errCode()){
				case 1: Product::message("Invalid Date Entry"); break;
				case 2: Product::message("Invalid Year in Date Entry"); break;
				case 3: Product::message("Invalid Month in Date Entry"); break;
				case 4: Product::message("Invalid Day in Date Entry"); break;
				default: this->expireDate = tempDate; break;
				}
			}
		if (tempDate.errCode() != NO_ERROR) { is.setstate(std::ios::failbit); }
		return is;
	}

	// stores the appropriateerror message in the base class’ error object
	//
	const Date& Perishable::expiry() const{
		return expireDate;
	}
	
}