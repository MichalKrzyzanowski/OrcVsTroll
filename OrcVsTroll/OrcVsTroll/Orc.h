#include "Character.h"
#include <iostream>
#pragma once


class Orc : public Character {
public:
	void barrelRoll() { std::cout << "rooooooolllllllllllinggggggg\n"; }
	void walk() { std::cout << "Doopers have a really cool walk!\n"; }
	void fly() { std::cout << "Dooper is flapping and flying\n"; }
};