#include "DamageModifier.h"

int DamageModifier::nextDamageModifierId = 0;

DamageModifier::DamageModifier() {
	this->damageModifierId = nextDamageModifierId;
	++this->nextDamageModifierId;
}

DamageModifier::~DamageModifier() {};

float DamageModifier::CalculateDamage(float CurrentHealth, float Damage) {
	return CurrentHealth - Damage;
}

float DamageModifier::GetTotalDamage(float Damage) {
	return Damage;
}