#include <iostream>
#include <vector>

using namespace std;

enum charClass { warrior, mage, healer, vampire };

struct Character {
	int id;
	float meleeAttack;
	float rangedAttack;
	charClass cl;
};

int strongestCharId(const vector<Character>& characters) {
	Character strongestChar = characters[0];

	for (Character hero: characters) {
		if (strongestChar.meleeAttack + strongestChar.rangedAttack < hero.meleeAttack + hero.rangedAttack) {
			strongestChar = hero;
		}
	}

	return strongestChar.id;
}

vector<pair<charClass, Character>> strongestCharByClass(const vector<Character>& characters) {
	vector<pair<charClass, Character>> champChars;

	charClass classes[4] = { warrior, mage, healer, vampire };
	for (int i = 0; i < 4; i++) {
		Character strongestInClass {0, 0, 0, classes[i]};
		for (Character ch: characters) {
			if (ch.cl == classes[i]) {
				if (strongestInClass.meleeAttack + strongestInClass.rangedAttack < ch.meleeAttack + ch.rangedAttack) {
					strongestInClass = ch;
				}
			}
		}
		champChars.push_back(make_pair(strongestInClass.cl, strongestInClass));
	}

	return champChars;
}

int main() {

	vector<Character> heroes = { 
		{1, 23, 0, charClass::warrior},  {2, 16, 0, charClass::warrior}, 
		{3, 2, 30, charClass::mage}, {4, 2, 20, charClass::mage}, 
		{5, 5, 5, charClass::healer}, {6, 5, 10, charClass::healer}, 
		{7, 15, 12, charClass::vampire},   {8, 15, 11, charClass::vampire} };

	cout << "Strongest Character id is: " << strongestCharId(heroes) << endl;

	vector<pair<charClass, Character>> champChars = strongestCharByClass(heroes);

	for (pair<charClass, Character> chrt: champChars) {
		string charClass;

		if (chrt.first == 0) charClass = "warrior";
		if (chrt.first == 1) charClass = "mage";
		if (chrt.first == 2) charClass = "healer";
		if (chrt.first == 3) { charClass = "vampire"; }

		cout << "Strongest " << charClass << " id is " << chrt.second.id << endl;
	}


	return 0;
}