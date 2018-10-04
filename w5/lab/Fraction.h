// Header file. Contains class Fraction declaration
// File Fraction.h
// Date: 2018/02/23
// Author: Dmitrii Korolevskii

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
namespace sict{
	class Fraction {
		int numerator;
		int denumerator;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction&) const;
	};
}

#endif