#include <iostream>
#pragma once


class Character
{
public:
	void flip() { std::cout << "I know how to flip and I will flipping do it\n"; }
	virtual void walk() { std::cout << "just in case they are too young to walk yet\n"; }
	virtual void fly() = 0; // pure virtual function
};