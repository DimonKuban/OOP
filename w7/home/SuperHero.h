// Header file. Extends Hero class. Contains additional variables, 2 constructors, member functions and helper function
// File SuperHero.h
// Date: 2018/03/22
// Author: Dmitrii Korolevskii

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"
namespace sict{
	class SuperHero: public Hero{
		int bonus;
		int defense;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif