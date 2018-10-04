// Header file. Contains constants variables and class Passenger declaration
// File Passenger.h
// Date: 2018/02/12
// Author: Dmitrii Korolevskii

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict{
	const int max_name = 31;
	const int max_destination = 31;

	class Passenger{
			char name[max_name+1];
			char destination[max_destination+1];
		public:
			Passenger();
			Passenger(const char*, const char*);
			bool isEmpty() const;
			void display() const;
	};
}

#endif
