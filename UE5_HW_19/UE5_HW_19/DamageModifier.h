#pragma once

class DamageModifier {
public:
	DamageModifier();
	~DamageModifier();

	virtual float CalculateDamage(float CurrentHealth, float Damage);
	virtual float GetTotalDamage(float Damage);

protected:
	int damageModifierId;
	static int nextDamageModifierId;
};