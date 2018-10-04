// Header implementation file. Contains implementation of 2 constructors, member functions, helper and friend function
// File Hero.cpp
// Date: 2018/03/19
// Author: Dmitrii Korolevskii

#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;
namespace sict{

	// no-argument constructor. Sets the Hero object to a safe empty state
	//
	Hero::Hero(){
		name[0] = '\0';
		health = 0;
		attack_strength = 0;
	}

	// 3-argument constructor. If received data is valid, the object accepts them. Otherwise, sets a safe empty state
	//
	Hero::Hero(const char* name, int health, int attack_strength){
		if (name != nullptr && name[0] != '\0' && health > 0 && attack_strength > 0){
			strncpy(this->name, name, max_name);
			this->name[max_name] = '\0';
			this->health = health;
			this->attack_strength = attack_strength;
		}
		else{
			*this = Hero();
		}
	}

	// if received value is positive, deducts it from the current object health. 
	//
	void Hero::operator-=(int attack){
		if (attack > 0){
			if (health > attack){
				health -= attack;
			}
			else{
				health = 0;
			}
		}
	}

	// returns true if the current object is healthy
	//
	bool Hero::isAlive() const{
		return (health>0);
	}

	// return the attack strength of the current object
	//
	int Hero::attackStrength() const{
		return attack_strength;
	}

	// inserts the name of hero into output stream and returns reference to that stream
	//
	ostream& operator<<(ostream& os, const Hero& hero){
		os << hero.name;
		if (!hero.attackStrength()){
			cout << "No hero";
		}
		return os;
	}

	// displays the names of the battle and returns a reference to the winner
	//
	const Hero& operator*(const Hero& first, const Hero& second){
		Hero first_temp = first;
		Hero second_temp = second;
		cout << "Ancient Battle! " << first << " vs " << second << " : " << "Winner is ";
		int round_num = 0;
		while (first_temp.isAlive() && second_temp.isAlive() && round_num < 100){
			round_num++;
			first_temp -= second.attackStrength();
			second_temp -= first.attackStrength();
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
