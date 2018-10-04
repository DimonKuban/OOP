// Header file. Contains constants variables and class declaration
// File CRA_Account.h
// Date: 2018/02/04
// Dmitrii Korolevskii

#ifndef SICT_CRA_ACCOUNT
#define SICT_CRA_ACCOUNT
namespace sict{
	const int max_yrs = 4;
	const int max_name_length = 41;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	class CRA_Account{
	private:
		int year[max_yrs];
		double balance[max_yrs];
		int yearNumber;
		char theFamilyName[max_name_length];
		char theGivenName[max_name_length];
		int SIN;
	public:
		void set(int, double);
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
