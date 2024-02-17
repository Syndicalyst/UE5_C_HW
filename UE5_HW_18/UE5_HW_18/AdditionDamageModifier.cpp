#include "AdditionDamageModifier.h"

AdditionDamageModifier::AdditionDamageModifier(float _addition) : addition{ _addition } {
	this->addition = _addition;
	this->damageModifierId = this->nextDamageModifierId;
	++this->nextDamageModifierId;
}

AdditionDamageModifier::~AdditionDamageModifier() {}

float AdditionDamageModifier::CalculateDamage(float CurrentHealth, float Damage) {
	return CurrentHealth - Damage - this->addition;
}

float AdditionDamageModifier::GetTotalDamage(float Damage) {
	return Damage + this->addition;
}