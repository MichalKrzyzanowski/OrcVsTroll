#include "Orc.h"


/// <summary>
/// default constructor, sets up stats
/// </summary>
/// <param name="t_MAX_HP"> max hp</param>
/// <param name="t_hp">current hp</param>
/// <param name="t_meleeDmg">attack</param>
/// <param name="t_magic_dmg">magic</param>
Orc::Orc(const int t_MAX_HP, int t_hp, int t_meleeDmg, int t_magic_dmg) :
	m_maxHp{ t_MAX_HP },
	m_hp{ t_hp },
	m_meleeDmg{ t_meleeDmg },
	m_magicDmg{ t_magic_dmg }
{
}


/// <summary>
/// displays hp in combat()
/// </summary>
void Orc::displayHp()
{
	std::cout << "orc: " << m_hp << "/" << m_maxHp << "hp" << std::endl;
}


/// <summary>
/// reduces hp and checks if orc is still alive
/// </summary>
/// <param name="t_damage">damage taken</param>
void Orc::takeDamage(int t_damage)
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
void Orc::attack(Character* t_player)
{
	std::cout << "orc deals " << m_meleeDmg << "dmg to you" << std::endl;
	t_player->takeDamage(m_meleeDmg);
}


/// <summary>
/// display message and buff self with rage spell
/// </summary>
/// <param name="t_target">target of attack</param>
void Orc::castSpell(Character* t_target)
{
	std::cout << "orc casted " << std::endl;
	std::cout << "orc enpowered his weapon at the cost of hp!" << std::endl;
	m_meleeDmg *= 2;
	m_maxHp /= 2;
	m_hp = m_maxHp;
	m_spellUses--;
	
}
