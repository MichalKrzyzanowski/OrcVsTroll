/// <summary>
/// Author: Michal Krzyzanowski
/// Date: 07/10/19
/// Login: C00240696
/// ----------------------------------------------------
/// turn-based combat game where orcs and trolls fight.
/// ----------------------------------------------------
/// Known Bugs: N/A
/// References:
/// </summary>


#include <iostream>
#include "Character.h"
#include "Troll.h"
#include "Orc.h"

using namespace std;


int main()
{
	cout << "Let go virtual" << endl;

	cout << "Let go create an Orc" << endl;
	Orc orc;
	orc.walk();
	orc.fly();
	orc.flip();

	cout << "Let go create an Troll" << endl;
	Troll troll;
	troll.walk();
	troll.fly();
	troll.flip();

	Character* npc = &orc;
	npc->flip();
	npc->fly();
	npc->walk();

	npc = &troll;
	npc->flip();
	npc->fly();
	npc->walk();

	cin.get();
}
