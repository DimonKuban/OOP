/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	w1_in_lab.cpp
// Version 1.0
// Date	2016/01/10
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Workshop 2: Dynamic Memory. Contains 2 function: main and read with it's prototype.
// File w2_in_lab.cpp. 
// 29.01.2018
// Dmitrii Korolevskii
#include <iostream>
#include "Kingdom.h"
using namespace std;
using namespace sict;
void read(sict::Kingdom&);
int main() {

	int count = 0; 
	Kingdom *pKingdom = NULL;

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();
	if (count < 1) return 1;

	// allocate dynamic memory for the pKingdom pointer
	//
	pKingdom = new Kingdom[count];
	
	// Accept user input for Kingdom i times	
	//
	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	//
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;
	
	// deallocate the dynamic memory
	//
	delete [] pKingdom;
	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(sict::Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
