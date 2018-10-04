// Contains one function implementation of content displaying
// File Kingdom.cpp
// 29.01.2018
// Dmitrii Korolevskii

#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict{

	//displays a content of Kingdom structure
	//
	void display(const Kingdom &king){
		cout << king.m_name << ", population " << king.m_population << endl;
	}
}
