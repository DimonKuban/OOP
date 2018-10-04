// Header file. Contains definition of data members, member function and helper funcions for product class
// File Product.h 
// Date: 2018/04/09
// Author: Dmitrii Korolevskii  

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#define max_sku_length 7
#define max_unit_length 10
#define max_name_length 75
#define TAX_RATE 13
#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"
namespace AMA{
	class Product: public iProduct{
		char type;
		char sku_[max_sku_length + 1];
		char unit_[max_unit_length + 1];
		char* name_;
		int unitsQuantity;
		int productNeeded;
		double price_;
		bool taxable;
		void init(const Product&);
		ErrorState errorState;
	protected:
		void name(const char*);
		const char* name() const;
		double cost() const;
		double price() const;
		const char* sku() const;
		bool taxed() const;
		const char* unit() const;
		void message(const char*);
		bool isClear() const;
	public:
		Product(const char type = 'N');
		Product(const char*, const char*, const char*, int unitsQuantity = 0, bool taxable = true, double price = 0, int productNeeded = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
}
#endif
