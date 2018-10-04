// Header file. Contains declaration of 3 constructors, destructor, members and overloaded functions
// File Contact.h 
// Date: 2018/03/16
// Author: Dmitrii Korolevskii 

#ifndef SICT_CONTACT_H 
#define SICT_CONTACT_H 

namespace sict{
	const int max_name = 19;

	class Contact{
		int phonesQuantity;
		char contName[max_name+1];
		long long *phoneNumber;
		bool validPhone(const long long);
		void init(const Contact&);
	public:
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
		Contact(const Contact&);
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif