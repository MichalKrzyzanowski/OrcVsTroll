#include "Character.h"
#include <iostream>
#pragma once


class Troll : public Character {
public:
	void fly() { std::cout << "Average Dooper is flapping and flying\n"; }
};