#include "Character.h"
#include <iostream>
#pragma once

/// <summary>
/// orc npc class, inherits from character
/// </summary>
class Orc : public Character
{
public:
	Orc(const int t_MAX_HP, int t_hp, int t_meleeDmg, int t_magic_dmg);
	void displayHp() override;
	void takeDamage(int t_damage) override;
	void attack(Character* t_player) override;
	bool getAlive() override { return m_alive; }
	void castSpell(Character* t_target) override;
	int getSpellUses() override { return m_spellUses; }

private:
	// stats
	int m_maxHp;
	int m_hp;
	int m_meleeDmg;
	int m_magicDmg;
	int m_spellUses{ 1 };
	bool m_alive{ true };
};