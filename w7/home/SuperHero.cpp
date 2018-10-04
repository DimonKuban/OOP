// Header implementation file. Extends SuperHero class. Contains implementation of 2 constructors, member functions and helper function
// File SuperHero.cpp
// Date: 2018/03/22
// Author: Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "SuperHero.h"
using namespace std;
namespace sict{

	// no-argument constructor. Sets the SuperHero object to a safe empty state
	//
	SuperHero::SuperHero() : Hero(){
		this->bonus = 0;
		this->defense = 0;
	}

	// 5-argument constructor. If received data is valid, the object accepts them. Otherwise, sets a safe empty state
	//
	SuperHero::SuperHero(const char* name, int health, int attack_strength, int bonus, int defense) : Hero(name, health, attack_strength){
		if (bonus > 0 && defense > 0 && name != nullptr && name[0] != '\0' && health > 0 && attack_strength > 0){
			this->bonus = bonus;
			this->defense = defense;
		}
		else{
			*this = SuperHero();
		}
	}

	// returns the attack strength of the current object including super power bonus
	//
	int SuperHero::attackStrength() const{
		if (isAlive()){
			return (Hero::attackStrength() + this->bonus);
		}
		else{
			return 0;
		}
	}

	// returns the defend strength of the current object
	//
	int SuperHero::defend() const{
		if (isAlive()){
			return defense;
		}
		else{
			return 0;
		}
	}

	// displays the names of the battle and returns a reference to the winner
	//
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
		SuperHero first_temp = first;
		SuperHero second_temp = second;
		cout << "Super Fight! " << first << " vs " << second << " : " << "Winner is ";
		int round_num = 0;
		while (first_temp.isAlive() && second_temp.isAlive() && round_num < 100){
			round_num++;
			first_temp -= second.attackStrength()-first.defend();
			second_temp -= first.attackStrength()-second.defend();
		}
		if (!first_temp.isAlive() && second_temp.isAlive()){
			cout << second << " in " << round_num << " rounds." << endl;
			return second;
		}
		else
		{
			cout << first << " in " << round_num << " rounds." << endl;
			return first;
		}
	}
}