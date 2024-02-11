#include <iostream>
#include "Building.h"

using namespace std;

int main() {

	Building b1 (100, 50);
	Building b2 (100, 55);
	Building b3 (200, 30);
	Building b4 (40, 120);

	b1.showBuilding();
	b1.toAge(6);
	b1.showBuilding();

	b2.showBuilding();
	b3.showBuilding();
	b4.showBuilding();
	b2.toAge(55);
	b3.toAge(29);
	b3.showBuilding();

	return 0;
}