#pragma once

#include "DamageModifier.h"

class ParityDamageModifier : public DamageModifier {
public:
	ParityDamageModifier(float _multiplicator = 2);
	~ParityDamageModifier();

	virtual float CalculateDamage(float CurrentHealth, float Damage);
	virtual float GetTotalDamage(float Damage);

private:
	float multiplicator;
};