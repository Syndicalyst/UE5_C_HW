#pragma once

#include "DamageModifier.h"

class AdditionDamageModifier : public DamageModifier {
public:
	AdditionDamageModifier(float _addition = 5);
	~AdditionDamageModifier();

	virtual float CalculateDamage(float CurrentHealth, float Damage);
	virtual float GetTotalDamage(float Damage);

private:
	float addition;
};