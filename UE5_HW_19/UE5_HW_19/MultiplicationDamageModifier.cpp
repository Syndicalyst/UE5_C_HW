#include "MultiplicationDamageModifier.h"

MultiplicationDamageModifier::MultiplicationDamageModifier(float _multiplicator) : multiplicator{ _multiplicator } {
	this->multiplicator = _multiplicator;
	this->damageModifierId = nextDamageModifierId;
	++this->nextDamageModifierId;
}

MultiplicationDamageModifier::~MultiplicationDamageModifier() {}

float MultiplicationDamageModifier::CalculateDamage(float CurrentHealth, float Damage) {
	return CurrentHealth - Damage * this->multiplicator;
}

float MultiplicationDamageModifier::GetTotalDamage(float Damage) {
	return Damage * this->multiplicator;
}