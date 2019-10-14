#include <iostream>
#pragma once

/// <summary>
/// enumerators for races
/// </summary>
enum Race
{
	ORC = 1,
	TROLL
};

/// <summary>
/// enumerators for shield types
/// </summary>
enum Shield
{
	BUCKLER	 = 1,
	STANDARD_SHIELD,
	GREATSHIELD
};

/// <summary>
/// enumerators for spell types
/// </summary>
enum Spell
{
	FIRE_BALL = 1,
	CURE,
	ICE_JAVELIN,
	ULTIMATE_DEVOTION,
	RAGE,
	NONE
};

/// <summary>
/// enumerators for weapon types
/// </summary>
enum Weapon
{
	FISTS = 1,
	DAGGER,
	DUAL_BLADES,
	GREATSWORD,
	GREATAXE,
	CLUB,
	RAPIER
};

/// <summary>
/// abstract class, every class inherits from it
/// </summary>
class Character
{
public:
	// pure virtual functions(inherited from every class)
	virtual void displayHp() = 0; 
	virtual void takeDamage(int t_damage) = 0;
	virtual void attack(Character* t_target) = 0;
	virtual bool getAlive() = 0;
	virtual void castSpell(Character* t_target) = 0;
	virtual int getSpellUses() = 0;
};