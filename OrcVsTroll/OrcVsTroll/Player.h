#include <string>
#include "Character.h"
#pragma once

/// <summary>
/// player class, inherits from Character
/// </summary>
class Player : public Character
{
public:
	Player() = default;
	void setupBaseStats(int m_maxHp, int m_hp, int m_meleeDmg, int m_magicDmg, std::string t_enemy);
	void equipShield(int t_shieldType);
	void equipSpell(int t_spellType);
	void equipWeapon(int t_weaponType);
	void displayStats();
	std::string getEnemy() { return m_enemy; }
	int getMaxHp() { return m_maxHp; }
	int getHp() { return m_hp; }
	std::string displaySpellStats();
	void displayHp() override;
	void attack(Character* t_target) override;
	void takeDamage(int t_damage) override;
	bool getAlive() override { return m_alive; }
	void castSpell(Character* t_target) override;
	int getSpellUses() override { return m_spellUses; }
	void rollLoot();
	void finalGold();

private:
	// stats and miscellaneous strings
	int m_maxHp{ 0 };
	int m_hp{ 0 };
	int m_meleeDmg{ 0 };
	int m_magicDmg{ 0 };
	int m_spellUses{ 0 };
	std::string m_enemy{ "" };
	std::string m_spellName{ "" };
	bool m_alive{ true };
	int m_gold{ 0 };
};

