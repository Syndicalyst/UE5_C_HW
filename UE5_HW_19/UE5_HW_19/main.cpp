#include <iostream>
#include <cmath>

#include "Character.h"
#include "DamageModifier.h"
#include "AdditionDamageModifier.h"
#include "MultiplicationDamageModifier.h"
#include "ParityDamageModifier.h"

using namespace std;

int main() {

	unique_ptr<Character> myChar = make_unique<Character>("Kolya", 100, 5.1f);
	unique_ptr<Character> otherChar = make_unique<Character>("Petro", 120, 4.0f);

	unique_ptr<Weapon> club = make_unique<Weapon>("Spiked club", 6.6f);
	unique_ptr<Weapon> sword = make_unique<Weapon>("Sword", 9.5f);

	shared_ptr<AdditionDamageModifier> addDam = make_shared<AdditionDamageModifier>(6.5f);
	shared_ptr<MultiplicationDamageModifier> multDam = make_shared<MultiplicationDamageModifier>(3.0f);
	shared_ptr<ParityDamageModifier> parDam = make_shared<ParityDamageModifier>(4.0f);

	myChar->ShowCharacter();
	otherChar->ShowCharacter();

	club->ShowWeapon();
	sword->ShowWeapon();

	myChar->SetWeapon(move(club));
	otherChar->SetWeapon(move(sword));

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

	myChar->SetWeapon(make_unique<Weapon>("Spear", 11.0f));
	myChar->ShowCharacter();

	myChar->GetWeapon()->ShowWeapon();

	return 0;
}