// Header file. Contains definition of data members, member function and helper funcions for product class
// File Product.h 
// Date: 2018/04/16 
// Author: Dmitrii Korolevskii  

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include "Product.h"
#include "Date.h"
namespace AMA{
	class Perishable : public Product{
		Date expireDate;
	public:
		Perishable();
		std::fstream& store(std::fstream&, bool newLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		const Date& expiry() const;
	};
}
#endif