// Final Project Milestone 1 
// 
// Version 1.0 
// Date 2018/03/16
// Author Dmitrii Korolevskii
// Description 
// 
// 
// 
// 
// Revision History 
// —-------------------------------------------------------— 
// Name Date Reason 
///////////////////////////////////////////////////////////////// 

// Header implementation file. Contains implementation of constructors, overloaded operators, member functions
// File Date.cpp 
// Date: 2018/03/16 
// Author: Dmitrii Korolevskii 

#include "Date.h" 
#include <iostream> 
#include <iomanip>
using namespace std;
namespace AMA {

	// number of days in month mon_ and year year_ 
	// 
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	// no-argument constructor. Sets the Contact object to a safe empty state 
	// 
	Date::Date() {
		this->year = 0;
		this->month = 0;
		this->day = 0;
		this->error = NO_ERROR;
	}

	// overloaded operator ==. Returns true if year, month and date of received object is the same as current object
	//
	bool Date::operator==(const Date& rhs) const {
		return (rhs.year == this->year &&
			rhs.month == this->month &&
			rhs.day == this->day);
	}

	// overloaded operator !=. Returns true if eather year or month or day of received object is not equal current object
	//
	bool Date::operator!=(const Date& rhs) const {
		return (rhs.year != this->year ||
			rhs.month != this->month ||
			rhs.day != this->day);
	}

	// overloaded operator <. Returns true if current date < received
	//
	bool Date::operator<(const Date& rhs) const {
		return (this->comparator < rhs.comparator);
	}

	// overloaded operator >. Returns true if current date > received
	//
	bool Date::operator>(const Date& rhs) const {
		return (this->comparator > rhs.comparator);
	}

	// overloaded operator <=. Returns true if current date <= received
	//
	bool Date::operator<=(const Date& rhs) const {
		return (this->comparator <= rhs.comparator);
	}

	// overloaded operator >=. Returns true if current date >= received
	//
	bool Date::operator>=(const Date& rhs) const {
		return (this->comparator >= rhs.comparator);
	}

	// returns true if the error state is not NO_ERROR
	//
	bool Date::bad() const{
		return (this->error != NO_ERROR);
	}

	// checks if received data is valid
	//
	void Date::validator(int y, int m, int d){
		this->year = y;
		this->month = m;
		this->day = d;
		this->comparator = y * 372 + m * 13 + d;
		if ((y < min_year || y > max_year)) {
			errCode(2);
		}
		else if ((m < 1 || m > 12)) {
			errCode(3);
		}
		else if (d < 1 || d > mdays(m, y)) {
			errCode(4);
		}
	}

	// 3-argument constructor. If received data is valid, stores data and calculates comparator value. Othervise, sets error code and safe empty state
	//
	Date::Date(int y, int m, int d) {
		(validator(y, m, d));
	}

	// sets particular type of error depending on received error code
	//
	void Date::errCode(int errorCode) {
		switch (errorCode) {
		case 0: this->error = NO_ERROR; break;
		case 1: this->error = CIN_FAILED; break;
		case 2: this->error = YEAR_ERROR; break;
		case 3: this->error = MON_ERROR; break;
		case 4: this->error = DAY_ERROR; break;
		}

	}

	// returns error code
	//
	int Date::errCode() const {
		return this->error;
	}

	// reads the data in YYYY?MM?DD format. 
	//
	std::istream& Date::read(std::istream& istr) {
		char junk = ' ';
		int temp_year;
		int temp_month;
		int temp_day;
		istr >> temp_year >> junk >> temp_month >> junk >> temp_day;
		if (istr.fail()){ error = CIN_FAILED; }
		else{ validator(temp_year, temp_month, temp_day); }
		return istr;
	}

	// the query. Writes the date in YYYY/MM/DD format
	//
	std::ostream& Date::write(std::ostream& ostr) const {
		if (!bad()){
			ostr << year;
			ostr << "/" << setw(2) << setfill('0') << month;
			ostr << "/" << setw(2) << setfill('0') << day;
		}
		else{
			cout << "0/00/00";
		}
		return ostr;
	}

	// operator << works with ostream to print a date
	//
	std::ostream& operator<<(std::ostream &os, const Date &o)
	{
		o.write(os);
		return os;
	}

	// operator >> works with istream to read a date
	//
	std::istream& operator>>(std::istream& istr, Date &d)
	{
		d.read(istr);
		return istr;
	}
}