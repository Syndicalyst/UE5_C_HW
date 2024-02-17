#pragma once
#include <iostream>

using namespace std;

class Weapon {
public:
	Weapon(const string& _name = "Sword", float _damage = 20);

	~Weapon();

	float GetDamage() const;
	string GetName() const;
	void ShowWeapon() const;

private:
	string name;
	float damage;
	int weaponId;
	static int nextWeaponId;
};