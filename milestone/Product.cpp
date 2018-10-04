// Header implementation file. Contains implementation of data members, member function and helper funcions for product class
// File Product.cpp 
// Date: 2018/04/09
// Author: Dmitrii Korolevskii 

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Product.h"
#ifdef DELIM
#undef DELIM
#endif
#define DELIM ','
using namespace std;
namespace AMA{

	// stores received name in dynamically allocated memory
	//
	void Product::name(const char* n_){
		if (n_ != nullptr){
			if (this->name_ != nullptr){
				delete[] this->name_;
				this->name_ = nullptr;
				this->name_ = new char[max_name_length + 1];
				strcpy(name_, n_);
			}
			else{
				this->name_ = new char[max_name_length + 1];
				strcpy(name_, n_);
			}
		}
		else{
			this->name_ = nullptr;
		}
	}

	// returns the name of the product
	//
	const char* Product::name() const{
		if (name_ != nullptr)
			return name_;
		else
			return nullptr;
	}

	// returns the sku of the product
	//
	const char* Product::sku() const{
		return sku_;
	}

	// returns unit of the product
	//
	const char* Product::unit() const{
		return unit_;
	}

	// return taxable status of the product
	//
	bool Product::taxed() const{
		return taxable;
	}

	// returns the price of a single item of the product
	//
	double Product::price() const{
		return price_;
	}

	// returns price plus tax appliable to the product
	//
	double Product::cost() const{
		if (taxable){
			return price_ * (((double)TAX_RATE / 100) + 1);
		}
		else{
			return price_;
		}
	}

	// stores an error message in the ErrorState object
	//
	void Product::message(const char* error){
		this->errorState.message(error);
	}

	// returns of the ErrorState object is clear
	//
	bool Product::isClear() const{
		return (this->errorState.isClear());
	}

	// stores type (if received) and sets object to safe empty state
	//
	Product::Product(const char type){
		this->type = type;
		sku_[0] = '\0';
		unit_[0] = '\0';
		name_ = nullptr;
		unitsQuantity = 0;
		productNeeded = 0;
		price_ = 0;
		taxable = false;
		this->errorState.clear();
	}

	// calls name function to allocate memory for name and sets received data to the current object
	//
	Product::Product(const char* sku_, const char* n, const char* units_, int unitsQuantity_, bool taxable_, double price_, int productNeeded_){
		this->type = 'N';
		if (sku_ != nullptr){
			strncpy(this->sku_, sku_, max_sku_length);
			this->sku_[max_sku_length] = '\0';
		}
		this->name_ = nullptr;
		name(n);
		strncpy(this->unit_, units_, max_unit_length);
		this->unit_[max_unit_length] = '\0';
		this->unitsQuantity = unitsQuantity_;
		this->taxable = taxable_;
		this->price_ = price_;
		this->productNeeded = productNeeded_;
		if (isEmpty()) {
			name_ = nullptr;
			*this = Product();
		}
	}

	// localizes the common code to be called from copy constructor and copy assignment operator
	//
	void Product::init(const Product& product){
		this->type = product.type;
		strncpy(sku_, product.sku_, max_sku_length);
		this->sku_[max_sku_length] = '\0';
		strncpy(unit_, product.unit_, max_unit_length);
		this->unit_[max_unit_length] = '\0';
		this->unitsQuantity = product.unitsQuantity;
		this->productNeeded = product.productNeeded;
		this->price_ = product.price_;
		this->taxable = product.taxable;
		this->name_ = nullptr;
		name(product.name_);
	}

	// copies received object to the current object
	//
	Product::Product(const Product& product){
		init(product);
	}

	// replaces current object with a copy of the object referenced
	//
	Product& Product::operator=(const Product& product){
		if (this != &product){
			delete[] name_;
			this->name_ = nullptr;
			init(product);
		}
		else{
			this->name_ = nullptr;
		}
		return *this;
	}

	// deallocates previousely allocated memory of product name
	//
	Product::~Product(){
		delete[] this->name_;
		this->name_ = nullptr;
	}

	// inserts into fstream data from current object in comma separated field
	//
	std::fstream& Product::store(std::fstream& file, bool newLine) const{
		file << type << DELIM << sku_ << DELIM;
		this->name_ == nullptr ? file << "" : file << this->name_;
		file << DELIM << unit_ << DELIM << taxable << DELIM;
		file << price_ << DELIM << unitsQuantity << DELIM << productNeeded;
		if (newLine)
			file << endl;
		return file;
	}

	// extracts the fields from fstream to temporary object and copies that object to the current object
	//
	std::fstream& Product::load(std::fstream& file){
		
		char sku_[max_sku_length + 1];
		string skuStrTemp;
		char name[max_name_length + 1];
		string nameStrTemp;
		char unit[max_unit_length + 1];
		string unitStrTemp;
		char taxTempChar;
		int quantityTemp, qtyNeededTemp;
		double priceTemp;
		bool taxTemp;

		getline(file, skuStrTemp, DELIM);
		strcpy(sku_, skuStrTemp.c_str());

		getline(file, nameStrTemp, DELIM);
		strcpy(name, nameStrTemp.c_str());
		
		getline(file, unitStrTemp, DELIM);
		strcpy(unit, unitStrTemp.c_str());
		
		file >> taxTempChar; file.ignore();
		file >> priceTemp; file.ignore();
		file >> quantityTemp; file.ignore();
		file >> qtyNeededTemp;
		
		taxTemp = (taxTempChar == '1');
		Product productTemp(sku_, name, unit, quantityTemp, taxTemp, priceTemp, qtyNeededTemp);
		*this = productTemp;
		return file;
	}

	// insert current object's fields into ostream in particular format
	//
	std::ostream& Product::write(std::ostream& os, bool linear) const{
		if (!errorState.isClear()){ os << errorState.message(); }
		else if (linear){
			cout.fill(' '); os.setf(ios::left);	os.width(max_sku_length); 
			os << sku_ << "|"; os.width(20);
			if (name_ == nullptr){ os << "" << "|";	}
			else{ os << name_ << "|"; }
			os.unsetf(ios::left); 
			os.setf(ios::fixed); os.width(7); os.precision(2);
			os << cost() << "|";
			os.width(4); os << unitsQuantity << "|";
			os.setf(ios::left); os.width(10);
			os << unit() << "|";
			os.unsetf(ios::left); os.width(4); 
			os << productNeeded << "|"; 
		}
		else{
			os << " Sku: " << sku_ << endl;
			os << " Name (no spaces): " << name_ << endl;
			os << " Price: " << price_ << endl;
			if (taxable)
				os << " Price after tax: " << cost() << endl;
			else
				os << " Price after tax: N/A" << endl;
			os << " Quantity on Hand: " << unitsQuantity << " " << unit() << endl;
			os << " Quantity needed: " << productNeeded;
		}
		return os;
	}

	// extracts the data field for the current object from istream
	//
	std::istream& Product::read(std::istream& is){
		errorState.clear();
		char sku[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit_[max_unit_length + 1];
		int  unitsQuantity, productNeeded;
		double price_;
		char taxable;
		bool realTaxable = false;
		bool end = false;
		this->message("");
		while (end == false){
			end = true;
			cout << " Sku: "; is.getline(sku, max_sku_length);
			cout << " Name (no spaces): "; is.getline(name, max_name_length);
			cout << " Unit: "; is.getline(unit_, max_unit_length);
			cout << " Taxed? (y/n): "; is >> taxable;
			if ((taxable == 'Y' || taxable == 'y') || taxable == 'n' || taxable == 'N') {
				if (taxable == 'Y' || taxable == 'y')
					realTaxable = true;
				else if (taxable == 'n' || taxable == 'N')
					realTaxable = false;
			}
			else{
				errorState.message("Only (Y)es or (N)o are acceptable");
				is.setstate(ios::failbit);
				break;
			}
			cout << " Price: ";
			is >> price_;
			if (is.fail()){
				errorState.message("Invalid Price Entry");
				break;
			}
			cout << " Quantity on hand: ";
			is >> unitsQuantity;
			if (is.fail()){
				errorState.message("Invalid Quantity Entry");
				break;
			}
			cout << " Quantity needed: ";
			is >> productNeeded;
			if (is.fail()){
				errorState.message("Invalid Quantity Needed Entry");
				break;
			}
			is.clear();
			is.ignore();
		}
		if (!is.fail()){
			strcpy(this->sku_, sku);
			this->name(name);
			strcpy(this->unit_, unit_);
			this->unitsQuantity = unitsQuantity;
			this->taxable = realTaxable;
			this->price_ = price_;
			this->productNeeded = productNeeded;
		}
		else{
			name_ = nullptr;
			*this = Product();
		}
		return is;
	}

	// returns true if the string is identical to the sku of the current object
	//
	bool Product::operator==(const char* sku) const{
		return strcmp(sku, sku_);
	}

	// returns the total cost of all items of the product on hand including tax
	//
	double Product::total_cost() const{
		if (taxable)
			return price_*unitsQuantity*(((double)TAX_RATE / 100) + 1);
		else
			return price_*unitsQuantity;
	}

	// resets the number of units that are on hand to the received number
	//
	void Product::quantity(int units_){
		unitsQuantity = units_;
	}

	// returns true if the object is in a safe empty state
	//
	bool Product::isEmpty() const{
		return (name_ == nullptr || name_[0] == '\0' || sku_[0] == '\0');
	}

	// returns the number of units of the product that are needed
	//
	int Product::qtyNeeded() const{
		return productNeeded;
	}

	// returns the number of units of the product that are on hand
	//
	int Product::quantity() const{
		return unitsQuantity;
	}

	// returns true if the sku of the current object is greater than received
	//
	bool Product::operator>(const char* dSku) const{
		return (sku()>dSku);
	}

	// returns true if the name of the current object is greater than the name of the referenced
	//
	bool Product::operator>(const iProduct& product) const{
		return (strlen(name_)>strlen(product.name()));
	}

	// adds receivet int (if positive) to quantity on hand
	//
	int Product::operator+=(int fUnits){
		if (fUnits > 0 && unitsQuantity > 0){
			unitsQuantity += fUnits;
		}
		return unitsQuantity;
	}

	// insert a Product record into the ostream
	//
	ostream& operator<<(std::ostream& os, const iProduct& pr){
		pr.write(os, true);
		return os;
	}

	// extracts the Product record from the istream
	//
	istream& operator>>(istream& is, iProduct& pr){
		pr.read(is);
		return is;
	}

	// adds the	total cost of the Product object to the double received
	//
	double operator+=(double& d, const iProduct& pr){
		d += pr.total_cost();
		return d;
	}

}
