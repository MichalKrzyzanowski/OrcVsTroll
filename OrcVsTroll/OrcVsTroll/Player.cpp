#include "Player.h"

/// <summary>
/// default constructor, sets up stats
/// </summary>
/// <param name="t_MAX_HP"> max hp</param>
/// <param name="t_hp">current hp</param>
/// <param name="t_meleeDmg">attack</param>
/// <param name="t_magic_dmg">magic</param>
void Player::setupBaseStats(int t_maxHp, int t_hp, int t_meleeDmg, int t_magicDmg, std::string t_enemy)
{
	m_maxHp = t_maxHp;
	m_hp = t_hp;
	m_meleeDmg = t_meleeDmg;
	m_magicDmg = t_magicDmg;
	m_enemy = t_enemy;
}

/// <summary>
/// changes stats according to the shield chosen
/// </summary>
/// <param name="t_shieldType">chosen shield</param>
void Player::equipShield(int t_shieldType)
{
	if (t_shieldType == Shield::BUCKLER)
	{
		m_maxHp += 5;
		m_hp = m_maxHp;
	}

	else if (t_shieldType == Shield::STANDARD_SHIELD)
	{
		m_maxHp += 10;
		m_hp = m_maxHp;
		m_meleeDmg -= 1;
	}

	else if (t_shieldType == Shield::GREATSHIELD)
	{
		m_maxHp += 20;
		m_hp = m_maxHp;
		m_meleeDmg -= 5;
	}
}


/// <summary>
/// changes stats according to the spell chosen
/// </summary>
/// <param name="t_spellType">chosen spell</param>
void Player::equipSpell(int t_spellType)
{
	if (t_spellType == Spell::FIRE_BALL)
	{
		m_spellUses = 10;
		m_magicDmg += 5;
		m_spellName = "fire ball";
	}

	else if (t_spellType == Spell::CURE)
	{
		m_spellUses = 3;
		m_magicDmg = 1;
		m_spellName = "cure";
	}

	else if (t_spellType == Spell::ICE_JAVELIN)
	{
		m_spellUses = 3;
		m_magicDmg += 20;
		m_spellName = "ice javelin";
	}

	else if (t_spellType == Spell::ULTIMATE_DEVOTION)
	{
		m_spellUses = 1;
		m_maxHp = 1;
		m_hp = m_maxHp;
		m_magicDmg = 9999;
		m_spellName = "ultimate devotion";
	}

	else if (t_spellType == Spell::RAGE)
	{
		m_spellUses = 1;
		m_maxHp += 10;
		m_hp = m_maxHp;
		m_spellName = "rage";
	}
}


/// <summary>
/// changes stats according to the weapon chosen
/// </summary>
/// <param name="t_weaponType">chosen weapon</param>
void Player::equipWeapon(int t_weaponType)
{
	if (t_weaponType == Weapon::FISTS)
	{
		m_meleeDmg -= 5;
		m_maxHp += 10;
		m_hp = m_maxHp;
	}

	else if (t_weaponType == Weapon::DAGGER)
	{
		m_meleeDmg += 5;
	}

	else if(t_weaponType == Weapon::DUAL_BLADES)
	{
		m_meleeDmg += 10;
		m_maxHp -= 2;
		m_hp = m_maxHp;
	}

	else if (t_weaponType == Weapon::GREATSWORD)
	{
		m_meleeDmg += 20;
		m_maxHp -= 5;
		m_hp = m_maxHp;
	}

	else if (t_weaponType == Weapon::GREATAXE)
	{
		m_meleeDmg += 25;
		m_maxHp -= 10;
		m_hp = m_maxHp;
	}

	else if (t_weaponType == Weapon::CLUB)
	{
		m_meleeDmg += 15;
		m_maxHp -= 4;
		m_hp = m_maxHp;
	}

	else if (t_weaponType == Weapon::RAPIER)
	{
		m_meleeDmg += 12;
		m_maxHp -= 2;
		m_hp = m_maxHp;
	}
}


/// <summary>
/// display players stats
/// </summary>
void Player::displayStats()
{
	if (m_maxHp <= 0)
	{
		m_maxHp = 1;
		m_hp = m_maxHp;
	}

	if (m_meleeDmg <= 0)
	{
		m_meleeDmg = 1;
	}

	if (m_magicDmg <= 0)
	{
		m_magicDmg = 1;
	}

	if (m_enemy == "orc")
	{
		std::cout << "race: troll" << std::endl;
	}

	else
	{
		std::cout << "race: Orc" << std::endl;
	}

	std::cout << "hp: " << m_hp << "/" << m_maxHp << std::endl;
	std::cout << "attack: " << m_meleeDmg << std::endl;
	std::cout << "magic: " << m_magicDmg << std::endl;
}


/// <summary>
/// displays spell stats in combat()
/// </summary>
/// <returns></returns>
std::string Player::displaySpellStats()
{
	std::string spellStats = "";
	spellStats = m_spellName + ": Uses:" + std::to_string(m_spellUses);
	return spellStats;
}

/// <summary>
/// displays hp in combat
/// </summary>
void Player::displayHp()
{
	std::cout << "Player: " << m_hp << "/" << m_maxHp << "hp" << std::endl;
}


/// <summary>
/// display message and deal physical damage to target
/// </summary>
/// <param name="t_player">enemy player is facing</param>
void Player::attack(Character* t_enemy)
{
	std::cout << "you deal " << m_meleeDmg << "dmg to the " << m_enemy << std::endl;
	t_enemy->takeDamage(m_meleeDmg);
}


/// <summary>
/// reduces hp and checks if player is still alive
/// </summary>
/// <param name="t_damage">damage taken</param>
void Player::takeDamage(int t_damage)
{
	m_hp -= t_damage;

	if (m_hp <= 0)
	{
		m_alive = false;
	}
}


/// <summary>
/// checks which spell the player has chosen and uses the according spell's functionality
/// </summary>
/// <param name="t_target">target spell is directed at</param>
void Player::castSpell(Character* t_target)
{
	std::cout << "you casted " << m_spellName << std::endl;

	if (m_spellName == "fire ball")
	{
		std::cout << "you deal " << m_magicDmg << "dmg to the " << m_enemy << std::endl;
		t_target->takeDamage(m_magicDmg);
		m_spellUses--;
	}

	else if (m_spellName == "cure")
	{
		std::cout << "health fully restored!" << std::endl;
		m_hp = m_maxHp;
		m_spellUses--;
	}

	else if (m_spellName == "ice javelin")
	{
		std::cout << "you deal " << m_magicDmg << "dmg to the " << m_enemy << std::endl;
		t_target->takeDamage(m_magicDmg);
		m_spellUses--;
	}

	else if (m_spellName == "ultimate devotion")
	{
		std::cout << "you deal " << m_magicDmg << "dmg to the " << m_enemy << std::endl;
		t_target->takeDamage(m_magicDmg);
		m_spellUses--;
	}

	else if (m_spellName == "rage")
	{
		std::cout << "you enpowered your weapon at the cost of hp!" << std::endl;
		m_meleeDmg *= 2;
		m_maxHp /= 2;
		m_hp = m_maxHp;
		m_spellUses--;
	}
}


/// <summary>
/// simple loot table, used after winning battle
/// </summary>
void Player::rollLoot()
{
	int lootRoll = rand() % 10 + 1;
	int goldRoll = rand() % 50 + 1;
	std::cout << "found " << goldRoll << "g" << std::endl;
	m_gold += goldRoll;

	// 40% chance
	if (lootRoll >= 1 && lootRoll <= 4)
	{
		std::cout << "\nfound golden goblet!(100g)" << std::endl;
		m_gold += 100;
	}

	// 10% chance
	if (lootRoll == 9)
	{
		std::cout << "\nRARE: found ancient tablet!!(2500g)\n" << std::endl;
		m_gold += 2500;
	}
}

/// <summary>
/// displays post-game messages and final gold amount
/// </summary>
void Player::finalGold()
{
	if (!m_alive)
	{
		std::cout << "with you gone, the keep is vulnerable,\n you fought well...\n\n";
	}

	else
	{
		std::cout << "with the challenger vanquished,\n you rejoin the battle,\n to protect the keep!\n\n";
	}
	std::cout << "you accumulated " << m_gold << "g!\n\n";
}
