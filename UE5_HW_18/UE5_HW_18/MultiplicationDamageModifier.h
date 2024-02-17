#pragma once

#include "DamageModifier.h"

class MultiplicationDamageModifier : public DamageModifier {
public: 
	MultiplicationDamageModifier(float _multiplicator = 2.0f);
	~MultiplicationDamageModifier();

	virtual float CalculateDamage(float CurrentHealth, float Damage);
	virtual float GetTotalDamage(float Damage);

private:
	float multiplicator;
};