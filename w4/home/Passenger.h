// Header file. Contains constants variables and class Passenger declaration
// File Passenger.h
// Date: 2018/02/16
// Author: Dmitrii Korolevskii

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict{
	const int max_name = 31;
	const int max_destination = 31;

	class Passenger{
		char passName[max_name + 1];
		char passDestination[max_destination + 1];
		int depYear;
		int depMonth;
		int depDay;
	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, const int, const int, const int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}

#endif
