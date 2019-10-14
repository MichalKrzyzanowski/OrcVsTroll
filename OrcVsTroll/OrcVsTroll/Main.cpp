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
#include "Player.h"
#include <random>
#include <ctime>


void combat(Player& t_player, Character* t_enemy);

/// <summary>
/// main game function
/// </summary>
/// <returns></returns>
int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	// objects used in game
	Orc orcFodder(50, 50, 10, 2);
	Troll trollFodder(25, 25, 2, 15);
	Player player;

	// create a class choices
	int raceChoice = 0;
	int shieldChoice = 0;
	int spellChoice = 0;
	int weaponChoice = 0;

	// race choice
	std::cout << "Choose your race\n1. Orc(high hp, high attack) \n2. Troll(low hp, very high magic)\n";
	std::cin >> raceChoice;
	system("cls");

	if (raceChoice == Race::ORC)
	{
		player.setupBaseStats(50, 50, 10, 2, "troll");
	}

	else
	{
		player.setupBaseStats(25, 25, 2, 15, "orc");
	}

	// shield choice
	std::cout << "\n\n\nChoose your shield \n1. buckler(low hp inc) \n2. standard shield(hp inc, low dmg decr)"
			<<"\n3. greatshield(high hp inc, dmg decr)\n";
	std::cin >> shieldChoice;
	system("cls");

	player.equipShield(shieldChoice);

	// spell choice
	std::cout << "\n\n\nChoose your spell\n1. fire ball(high uses, low dmg)\n2. cure(1 use, full heal)"
			<< "\n3. ice javelin(low uses, high damage)\n"
			<< "4. ultimate devotion(sucks out all of your life force to use spell, 1 use, causes catastrophic damage,\n\t "
			<< "only the truly devoted to the dark arts should use this spell)"
			<< "\n5. rage(1 use, double weapon dmg, half max hp)\n";
	std::cin >> spellChoice;
	system("cls");

	player.equipSpell(spellChoice);

	// weapon choice
	std::cout << "\n\n\nChoose your weapon\n1. fists(decr in attack, inc in hp) \n2. dagger(dmg inc) \n"
			<< "3. dual blades(high dmg inc, low hp decr) \n"
			<< "4. greatsword(low hp decr, large dmg inc) \n5. greataxe(hp decr, large dmg inc) \n6. club(high dmg inc, normal hp decr) \n"
			<< "7. rapier(finnese and style my friend! high dmg inc, low hp decr)\n";
	std::cin >> weaponChoice;
	system("cls");

	player.equipWeapon(weaponChoice);

	// character created, final stats displayed
	std::cout << "character created! final stats:\n\n";

	player.displayStats();
	system("pause");
	system("cls");

	// pre-battle message
	std::cout << "as the battle rages on, you have seen a sneaky enemy\n prowling around the keep gates!\n"
			<< "you decide to chase him down and duel with him, for the kingdom!\n\n\n";
	system("pause");
	system("cls");

	// enemy chosen based on  player race
	if (raceChoice == Race::ORC)
	{
		combat(player, &trollFodder);
	}

	else
	{
		combat(player, &orcFodder);
	}

	return 0;
}


/// <summary>
/// function that deals with the battle
/// player and enemies can deal damage with melee damage or cast spells
/// both parties can take damage and have limit use of spells
/// enemy uses very simple A.I to choose either to attack or cast a spell
/// </summary>
/// <param name="t_player"></param>
/// <param name="t_enemy"></param>
void combat(Player &t_player, Character* t_enemy)
{
	// combat repeats itself indefinitly until either the player or enemy dies
	while (true)
	{
		int playerChoice = 0;
		int enemyChoice = 0;
		std::cout << "vs. " << t_player.getEnemy() << "\n\n";

		t_player.displayHp();

		t_enemy->displayHp();

		std::cout << "\n\n1. attack \n2. cast spell(" << t_player.displaySpellStats() << ")\n\n";
		std::cin >> playerChoice;
		enemyChoice = rand() % 2 + 1;
		
		std::cout << "\n\n\n";
		
		// player choices
		if (playerChoice == 2 && t_player.getSpellUses() > 0)
		{
			t_player.castSpell(t_enemy);
		}

		else
		{
			t_player.attack(t_enemy);
		}
		system("pause");
		std::cout << "\n\n\n";

		// check if enemy has been defeated
		if (!t_enemy->getAlive())
		{
			system("cls");
			std::cout << t_player.getEnemy() << " has been slain!\n\n" << std::endl;
			t_player.rollLoot();
			system("pause");
			break;
		}

		// enemy choices
		if (enemyChoice == 2 && t_enemy->getSpellUses() > 0)
		{
			t_enemy->castSpell(&t_player);
		}

		else
		{
			t_enemy->attack(&t_player);
		}
		system("pause");
		system("cls");
		std::cout << "\n\n\n";

		// check if player has been defeated
		if (!t_player.getAlive())
		{
			system("cls");
			std::cout << "you have been slain!" << std::endl;
			system("pause");
			break;
		}

	}

	// display final gold value
	system("cls");
	t_player.finalGold();
	system("pause");
	system("cls");
}
