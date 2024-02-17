#include "ParityDamageModifier.h"
#include <string>
#include <cmath>

using namespace std;

ParityDamageModifier::ParityDamageModifier(float _multiplicator) : multiplicator{ _multiplicator } {
	this->multiplicator = _multiplicator;
	this->damageModifierId = this->nextDamageModifierId;
	++this->nextDamageModifierId;
}

ParityDamageModifier::~ParityDamageModifier() {}

bool lastFloatNumIsEven(float _num) {
	string temp = to_string(_num);

	for (int i = temp.size() - 1; i > 0; --i) {
		if (int(temp[i] - '0') == 0) {
			continue;
		}
		if (int(temp[i] - '0') % 2 == 0) {
			return true;
		}
		else { break; }
	}
	return false;
}

float ParityDamageModifier::CalculateDamage(float CurrentHealth, float Damage) {
	if (lastFloatNumIsEven(Damage)) {
		return CurrentHealth - Damage * this->multiplicator;
	}
	return CurrentHealth - Damage;
}

float ParityDamageModifier::GetTotalDamage(float Damage) {
	if (lastFloatNumIsEven(Damage)) {
		return Damage * this->multiplicator;
	}
	return Damage;
}
