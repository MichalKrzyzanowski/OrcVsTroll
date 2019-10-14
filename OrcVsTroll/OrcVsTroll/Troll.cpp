#include "Troll.h"

/// <summary>
/// default constructor, sets up stats
/// </summary>
/// <param name="t_MAX_HP"> max hp</param>
/// <param name="t_hp">current hp</param>
/// <param name="t_meleeDmg">attack</param>
/// <param name="t_magic_dmg">magic</param>
Troll::Troll(const int t_MAX_HP, int t_hp, int t_meleeDmg, int t_magic_dmg) :
	m_maxHp{ t_MAX_HP },
	m_hp{ t_hp },
	m_meleeDmg{ t_meleeDmg },
	m_magicDmg{ t_magic_dmg }
{
}


/// <summary>
/// displays hp in combat()
/// </summary>
void Troll::displayHp()
{
	std::cout << "troll: " << m_hp << "/" << m_maxHp << "hp" << std::endl;
}


/// <summary>
/// reduces hp and checks if troll is still alive
/// </summary>
/// <param name="t_damage">damage taken</param>
void Troll::takeDamage(int t_damage)
{
	m_hp -= t_damage;

	if (m_hp <= 0)
	{
		m_alive = false;
	}
}


/// <summary>
/// display message and deal physical damage to target
/// </summary>
/// <param name="t_player">player of game</param>
void Troll::attack(Character* t_player)
{
	std::cout << "troll deals " << m_meleeDmg << "dmg to you" << std::endl;
	t_player->takeDamage(m_meleeDmg);
}


/// <summary>
/// display message and deal magical damage to target
/// </summary>
/// <param name="t_target">target of attack</param>
void Troll::castSpell(Character* t_target)
{
	std::cout << "troll casted minor fire ball" << std::endl;
	std::cout << "troll deals " << m_magicDmg << "dmg to you" << std::endl;
	t_target->takeDamage(m_magicDmg);
	m_spellUses--;
}
