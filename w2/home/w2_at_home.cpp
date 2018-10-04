/***********************************************************************
// Workshop 2: Dynamic Memory
// File	w2_at_home.cpp
// Version 1.0
// Date	2018/01/31
// Author	Dmitrii Korolevskii
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

void read(Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

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
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element
	//
	Kingdom *king = new Kingdom[count + 1];

	// copy elements from original array into this newly allocated array
	//
	for (int i = 0; i < count; i++){
		king[i] = pKingdom[i];
	}

	delete[] pKingdom;

	//copy the address of the newly allocated array into pKingdom pointer
	//
	pKingdom = king;

	// add the new Kingdom
	//
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count + 1 << ": " << endl;
	
	//accept input for the new element in the array
	//
	read(pKingdom[count]);
	count++;
	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	//
	display(pKingdom, count);
	cout << endl;
	// deallocate the dynamic memory
	//
	delete [] king;
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
