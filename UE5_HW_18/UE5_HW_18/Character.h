#pragma once
#include <iostream>
#include "Weapon.h"
#include "DamageModifier.h"

using namespace std;

class Character {
public:
	Character(const string& _name = "Vasya", float _health = 100, float _basicDamage = 1);

	~Character();

	void SetWeapon(Weapon* weapon);
	void SetDamageModifier(DamageModifier* modifier);

	Weapon* GetWeapon() const;
	float GetModifiedDamage() const;
	float GetFullDamage() const;

	void ShowCharacter() const;

private:
	string name;
	float health;
	float maxHealth;
	float basicDamage;
	int characterId;
	static int nextCharacterId;
	Weapon* currentWeapon;
	DamageModifier* currentModifier;
};
