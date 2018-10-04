// Header file. Contains declaration of 2 constructors, destructor and member functions
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
	public:
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif
