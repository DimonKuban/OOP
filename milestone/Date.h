// Final Project Milestone 1
//
// Version 1.0
// Date 2018/03/16
// Author Dmitrii Korolevskii  
// Description Header file: 
// Contains declaration of constructors, overloaded operators, member functions
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

// Header file. Contains declaration of constructors, overloaded operators, member functions
// File Date.h 
// Date: 2018/03/16 
// Author: Dmitrii Korolevskii  

#include <iostream>
#ifndef AMA_DATE_H
#define AMA_DATE_H
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
	class Date {
		int mdays(int, int)const;
		void errCode(int);
		int year;
		int month;
		int day;
		int comparator;
		int error;
		void validator(int, int, int);
	public:
		Date();
		Date(int, int, int);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream &, const Date  &);
	std::istream& operator>>(std::istream &, Date  &);

}
#endif