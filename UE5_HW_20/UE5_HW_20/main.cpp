#include <iostream>
#include "Hero.h"

int main() {

	Hero *hero1 = new Hero("Rolland", 100, 15);
	Hero *hero2 = new Hero("Konan", 120, 12);

	hero1->Attack(*hero2);
	hero1->Attack(*hero2);

	hero1->Notify();
	hero2->Notify();

	hero1->Update();
	hero2->Update();

	hero2->RemoveObserver(hero1);
	hero2->Notify();
	hero2->Update();

	delete hero1;
	delete hero2;

	return 0;
}