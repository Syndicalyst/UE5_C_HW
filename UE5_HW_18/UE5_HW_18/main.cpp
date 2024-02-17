#include <iostream>
#include <cmath>

#include "Character.h"
#include "DamageModifier.h"
#include "AdditionDamageModifier.h"
#include "MultiplicationDamageModifier.h"
#include "ParityDamageModifier.h"

using namespace std;

int main() {

	Character* myChar = new Character("Kolya", 100, 5.1f);
	Character* otherChar = new Character("Petro", 120, 4.0f);

	Weapon* club = new Weapon("Spiked club", 6.6f);
	Weapon* sword = new Weapon("Sword", 9.5f);

	AdditionDamageModifier* addDam = new AdditionDamageModifier(6.5f);
	MultiplicationDamageModifier* multDam = new MultiplicationDamageModifier(3.0f);
	ParityDamageModifier* parDam = new ParityDamageModifier(4.0f);

	myChar->ShowCharacter();
	otherChar->ShowCharacter();

	club->ShowWeapon();
	sword->ShowWeapon();

	myChar->SetWeapon(club);
	otherChar->SetWeapon(sword);

	myChar->ShowCharacter();
	otherChar->ShowCharacter();

	myChar->SetDamageModifier(addDam);
	otherChar->SetDamageModifier(multDam);

	myChar->ShowCharacter();
	otherChar->ShowCharacter();

	myChar->SetDamageModifier(parDam);
	myChar->ShowCharacter();

	otherChar->SetDamageModifier(parDam);
	otherChar->ShowCharacter();

	delete myChar;
	delete club;
	delete otherChar;
	delete sword;
	delete addDam;
	delete multDam;
	delete parDam;

	return 0;
}