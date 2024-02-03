#include <iostream>
#include <string>

using namespace std;

enum possibleClasses
{ mage, warrior };

struct Hero {
	string name = "Zhora";
	float maxHitpoints = 100;
	float hitpoints = maxHitpoints;
	int power = 5;
	possibleClasses heroClass = possibleClasses::warrior;
};

void heroDamage(Hero &pl, float damage) {
	if (pl.heroClass == possibleClasses::warrior) {
		if (pl.hitpoints <= 0.3f * pl.maxHitpoints) {
			pl.hitpoints = pl.hitpoints + pl.power - damage;
		} else {
			pl.hitpoints -= damage;
		}
	}

	if (pl.heroClass == possibleClasses::mage) {
		if (damage > 2 * pl.power) {
			char avoidedDam = rand() % 2;
			if (avoidedDam != 1) {
				pl.hitpoints -= damage;
			}
		} else {
			pl.hitpoints -= damage;
		}
	}

	cout << "\nDealing " << damage << " damage points\n";

	if (pl.hitpoints <= 0) {
		cout << "\nYour Hero is dead!\n";
		delete& pl;
		exit(0);
	}
}

void heroParams(Hero pl) {
	string heroCl;

	if (pl.heroClass == possibleClasses::warrior) {
		heroCl = "warrior";
	}	else { heroCl = "mage"; }

	cout << "\n=======================\nHero '" << pl.name << "' the " << heroCl << "\nHero hitpoints: " 
	<< pl.hitpoints << "/" << pl.maxHitpoints << "\nHero power: " << pl.power << "\n=======================" << endl;
}



int main() {

	Hero *player = new Hero();
	char playerClass;
	float damageQuene[5] = {20, 50, 100, 7, 2};

	cout << "Type your hero name: \n";
	cin >> player->name;
	cout << "Type your hero health: \n";
	cin >> player->maxHitpoints;
	player->hitpoints = player->maxHitpoints;
	cout << "Type your hero power: \n";
	cin >> player->power;
	cout << "Choose your class: \n type 'm' to choose Mage or \n type 'w' to choose warrior \n";
	cin >> playerClass;

	if (playerClass == 'm') {
		player->heroClass = possibleClasses::mage;
	} else if (playerClass == 'w') {
		player->heroClass = possibleClasses::warrior;
	} else {
		cout << "\nYou were supposed to enter a specific letter and you`ve done it wrong!\n\n";
		return NULL;
	}

	heroParams(*player);

	for (float damage : damageQuene) {
		heroDamage(*player, damage);
		heroParams(*player);
	}

	delete player;
	return 0;
}