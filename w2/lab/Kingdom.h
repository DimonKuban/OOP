// Contains declarating of Kingdom structure and prototype of display function
// File Kingdom.h header file. 
// 29.01.2018
// Dmitrii Korolevskii

#ifndef KINGDOM_H
#define KINGDOM_H
namespace sict{
	struct Kingdom{
		char m_name[32];
		int m_population;
	};

	void display(const Kingdom&);
}
#endif
