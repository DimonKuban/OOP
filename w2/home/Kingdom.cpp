// Contains overloaded function implementation of content displaying
// File Kingdom.cpp
// Date	2018/01/31
// Author Dmitrii Korolevskii

#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict{

	// displays a content of Kingdom structure
	//
	void display(const Kingdom &king){
		cout << king.m_name << ", population " << king.m_population << endl;
	}

	// displays all existing Kingdoms and total population of all Kingdoms
	//
	void display(const Kingdom king[], int numOfElements){
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		int total = 0;

		// printing all Kingdoms and count total population
		//
		for (int i = 0; i < numOfElements; i++){
			cout << i + 1 << ". " << king[i].m_name << ", population " << king[i].m_population << endl;
			total += king[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}
}
