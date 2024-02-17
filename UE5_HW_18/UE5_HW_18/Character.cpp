#include "Character.h"

int Character::nextCharacterId = 0;

Character::Character(const string& _name, float _health, float _basicDamage) : name{ _name }, health{ _health }, basicDamage{ _basicDamage } {
	this->name = _name;
	this->health = _health;
	this->maxHealth = _health;
	this->basicDamage = _basicDamage;
	this->characterId = nextCharacterId;
	this->currentWeapon = NULL;
	this->currentModifier = NULL;
	++this->nextCharacterId;
}

Character::~Character() {}

void Character::SetWeapon(Weapon* weapon) {
	this->currentWeapon = weapon;
}

void Character::SetDamageModifier(DamageModifier* modifier) {
	this->currentModifier = modifier;
}

float Character::GetModifiedDamage() const {
	if (this->currentModifier == NULL) {
		return GetFullDamage();
	}
	return this->basicDamage + this->currentModifier->GetTotalDamage(this->currentWeapon->GetDamage());
}

Weapon* Character::GetWeapon() const {
	return this->currentWeapon;
}

float Character::GetFullDamage() const {
	if (this->currentWeapon == NULL) {
		return this->basicDamage;
	}
	return this->basicDamage + this->currentWeapon->GetDamage();
}

void Character::ShowCharacter() const {
	cout << "\nOur character:\n" << "name: " << this->name << "\nhealth: " << this->health << "/" << this->maxHealth
		<< "\ndamage: " << GetModifiedDamage() << "\nid: " << this->characterId << endl;
}