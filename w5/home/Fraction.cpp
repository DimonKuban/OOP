// Header implementation file. Contains implementation of member functions and constructors 
// File Fraction.cpp
// Date: 2018/02/23
// Author: Dmitrii Korolevskii

#include <iostream>
#include "Fraction.h"
using namespace std;
namespace sict{

	// no-argument constructor. Sets the Fraction object to a safe empty state
	//
	Fraction::Fraction(){
		this->numerator = -1;
		this->denumerator = -1;
	}

	// 2-argument constructor. If received data is valid, copies the data. Otherwise, sets object to an empty state
	//
	Fraction::Fraction(int numerator, int denumerator){
		if ((numerator >= 0) && (denumerator > 0)){
			this->denumerator = denumerator;
			this->numerator = numerator;
			reduce();
		}
		else{
			*this = Fraction();
		}
	}

	// returns the greater of the numerator and denominator
	//
	int Fraction::max() const{
		return (this->denumerator > this->numerator) ? this->denumerator : this->numerator;
	}

	// returns the lesser of the numerator and denominator
	//
	int Fraction::min() const{
		return (this->denumerator > this->numerator) ? this->numerator : this->denumerator;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	//reduces the numerator and denominator by deviding on greatest common divisor
	//
	void Fraction::reduce(){
		int gcdTemp = gcd();
		this->denumerator /= gcdTemp;
		this->numerator /= gcdTemp;
	}

	// check if a query is an empty state
	//
	bool Fraction::isEmpty() const{
		return (numerator == -1 || denumerator == -1);
	}

	// returns a copy of the addition operation in reducen form if valid
	//
	Fraction Fraction::operator+(const Fraction& rhs) const{
		Fraction temp;
		if (!rhs.isEmpty() && !this->isEmpty()){
			temp.numerator = this->numerator * rhs.denumerator + this->denumerator * rhs.numerator;
			temp.denumerator = this->denumerator * rhs.denumerator;
			temp.reduce();
		}
		return temp;
	}

	// displays a fraction
	//
	void Fraction::display() const{
		if (this->isEmpty()){
			cout << "no fraction stored";
		}
		else if (this->denumerator == 1){
			cout << this->numerator;
		}
		else{
			cout << this->numerator << "/" << this->denumerator;
		}
	}

	// multiply fractions if valid
	//
	Fraction Fraction::operator*(const Fraction& fraction) const{
		Fraction tempFraction;
		if (!this->isEmpty() && !fraction.isEmpty()){
			tempFraction.numerator = fraction.numerator * this->numerator;
			tempFraction.denumerator = fraction.denumerator * this->denumerator;
		}
		tempFraction.reduce();
		return tempFraction;
	}

	// return true if objects are not empty and not unique. Othervise, returns false
	//
	bool Fraction::operator==(const Fraction& fraction) const{
		return this->numerator == fraction.numerator
			&& this->denumerator == fraction.denumerator
			&& !this->isEmpty()
			&& !fraction.isEmpty();
	}

	// return true if objects are not empty and unique. Othervise, returns false
	//
	bool Fraction::operator!=(const Fraction& fraction) const{
		return this->numerator != fraction.numerator
			&& this->denumerator != fraction.denumerator
			&& !this->isEmpty()
			&& !fraction.isEmpty();
	}

	// stores the result of the addition operation in reduced form if fractions are not empty
	//
	Fraction& Fraction::operator+=(const Fraction& fraction){
		if (!this->isEmpty() && !fraction.isEmpty()){
			*this = fraction + *this;
		}
		return *this;
	}
}