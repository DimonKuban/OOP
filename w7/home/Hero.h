// Header file. Contains declaration of 2 constructors, member functions, helper and friend function
// File Hero.h
// Date: 2018/03/19
// Author: Dmitrii Korolevskii

#ifndef SICT_HERO_H
#define SICT_HERO_H
namespace sict{
	const int max_rounds = 100;
	const int max_name = 40;
	class Hero{
		char name[max_name + 1];
		int health;
		int attack_strength;
	public:
		void operator-=(int);
		bool isAlive() const;
		int attackStrength() const;
		Hero();
		Hero(const char*, int, int);
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};
	const Hero& operator*(const Hero&, const Hero&);
}
#endif