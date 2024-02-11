#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum Actions { damage, heal };

float maxDamage(const vector<float>& v) {
	float maxDam = v[0];

	for (float num: v) {
		if (num > 0) {
			if (maxDam < num) {
				maxDam = num;
			}
		}
	}

	if (maxDam <= 0) {
		cout << "\nNo damage dealt\n";
		return NAN;
	}

	return maxDam;
}

float minDamage(const vector<float>& v) {
	vector<float> damage;

	for (float num : v) {
		if (num > 0) {
			damage.push_back(num);
		}
	}

	if (damage.size() == 0) {
		cout << "\nNo damage dealt\n";
		return NAN;
	}

	float minDam = damage[0];

	for (float num : damage) {
		if (num > 0) {
			if (minDam > num) {
				minDam = num;
			}
		}
	}

	return minDam;
}

vector<int> maxDamageArrayPositions(const vector<float>& v) {
	float maxDam = maxDamage(v);
	vector<int> positions;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == maxDam) {
			positions.push_back(i);
		}
	}

	return positions;
}

vector<int> minDamageArrayPositions(const vector<float>& v) {
	float minDam = minDamage(v);
	vector<int> positions;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == minDam) {
			positions.push_back(i);
		}
	}

	return positions;
}

vector<int> healingArrayPositions(const vector<float>& v) {
	vector<int> positions;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0) {
			positions.push_back(i);
		}
	}

	return positions;
}

float totalHealthChange(const vector<float>& v, Actions act) {
	float hitpointsChange = 0;

	if (act == Actions::damage) {
		for (float num : v) {
			if (num > 0) {
				hitpointsChange += num;
			}
		}
	}

	if (act == Actions::heal) {
		for (float num : v) {
			if (num < 0) {
				hitpointsChange += abs(num);
			}
		}

	}

	return hitpointsChange;
}

bool doneNothing(const vector<float>& v) {
	for (float num: v) {
		if (num == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	int manipulationNumbers;
	cout << "Enter number you want to heal / deal damage: \n";
	cin >> manipulationNumbers;


	vector<float> healthChange;

	for (int i = 0; i < manipulationNumbers; i++) {
		float temp;
		cout << "Enter positive number to deal damage, otherwise to heal: \n";
		cin >> temp;
		healthChange.push_back(temp);
	}
	
	vector<int> maxDam = maxDamageArrayPositions(healthChange);
	cout << "\n\nMaximum damage dealt on positions of array: \n";
	for (int num: maxDam) {
		cout << num << ' ';
	}
	
	vector<int> minDam = minDamageArrayPositions(healthChange);
	cout << "\n\nMinimal damage dealt on positions of array: \n";
	for (int num : minDam) {
		cout << num << ' ';
	}

	vector<int> healing = healingArrayPositions(healthChange);
	cout << "\n\nHealing HP on positions of array: \n";
	for (int num : healing) {
		cout << num << ' ';
	}

	cout << "\n\nTotal damage dealt/HP healed: " << totalHealthChange(healthChange, Actions::damage) << " / " << totalHealthChange(healthChange, Actions::heal) << endl;

	bool dealtZeroDam = doneNothing(healthChange);
	if (!dealtZeroDam) {
		cout << "\nEvery health change has it`s result!\n";
	}

	return 0;
}