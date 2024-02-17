#include "Weapon.h"

int Weapon::nextWeaponId = 0;

Weapon::Weapon(const string& _name, float _damage) : name{ _name }, damage{ _damage } {
	this->name = _name;
	this->damage = _damage;
	this->weaponId = nextWeaponId;
	++this->nextWeaponId;
}

Weapon::~Weapon() {};

float Weapon::GetDamage() const {
	return this->damage;
}

string Weapon::GetName() const {
	return this->name;
}

void Weapon::ShowWeapon() const {
	cout << "\nWeapon: \n" << "name: " << GetName() << "\ndamage: " << GetDamage() << "\nid: " << this->weaponId << endl;
}