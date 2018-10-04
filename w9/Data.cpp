#include <cstring>
#include "Data.h"


namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

	/*bool readRow(std::istream& input, const char* name, double* data, int n) {
	char rowname[2000];
	bool ok = !input.bad();

	// row format is
	// name,1,2,3,4,5,6

	if (ok) {
	// read the name first

	input.get(rowname, 2000, ',');
	// note: get will read a string upto the , character
	// it will leave the , character in the input buffer

	// check that the caller is reading the correct row (name)
	// - if the user is reading the wrong row, return an error
	if (std::strcmp(rowname, name) != 0) {
	// wrong row
	std::cout << "Cannot parse row for " << name << std::endl;
	input.ignore(2000, '\n');
	ok = false;
	}
	}

	if (ok)
	// read the data array
	ok = read(input, data, n);

	// finish the line
	input.ignore(2000, '\n');
	return ok;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n) {
	char rowname[2000];
	bool ok = !input.bad();

	// row format is
	// name,1,2,3,4,5,6

	if (ok) {
	// read the name first

	input.get(rowname, 2000, ',');
	// note: get will read a string upto the , character
	// it will leave the , character in the input buffer

	// check that the caller is reading the correct row (name)
	// - if the user is reading the wrong row, return an error
	if (std::strcmp(rowname, name) != 0) {
	// wrong row
	std::cout << "Cannot parse row for " << name << std::endl;
	input.ignore(2000, '\n');
	ok = false;
	}
	}

	if (ok)
	// read the data array
	ok = read(input, data, n);

	// finish the line
	input.ignore(2000, '\n');
	return ok;
	}*/

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		
		double popChangeMillions = ((double)(population[n - 1] - population[0]))/1000000;
		cout << "Population change from " << year[0] << " to " << year[n-1] << " is ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << popChangeMillions << " million" << endl;
		cout.unsetf(ios::fixed);
		cout.precision(6);
		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		char desc[5] = "";
		if ((violentCrimeRate[0] - violentCrimeRate[n - 1]) > 0){
			strcpy(desc, "down");
			desc[4] = '\0';
		}
		else if ((violentCrimeRate[0] - violentCrimeRate[n - 1]) < 0){
			strcpy(desc, "up");
			desc[2] = '\0';
		}
		else{
			strcpy(desc, "same");
			desc[4] = '\0';
		}
		cout << "Violent Crime trend is " << desc << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		cout << "There are ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << (average(grandTheftAuto, n))/1000000;
		cout.unsetf(ios::fixed);
		cout.precision(6);
		cout << " million Grand Theft Auto incidents on average a year" << endl;
		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << ((int)min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << ((int)max(violentCrimeRate, n)) << endl;
		for (int i = 0; i < n - 1; i++) {
			max(violentCrime, n);
		}

	}
}