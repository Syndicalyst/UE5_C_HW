#include "Building.h"

using namespace std;

int Building::nextBuildingId = 0;

Building::Building(int _initialCost, int _maxAge) : initialCost{ _initialCost }, maxAge{_maxAge} {
	this->initialCost = _initialCost;
	this->maxAge = _maxAge;
	this->buildingId = this->nextBuildingId;
	++nextBuildingId;
}

Building::~Building() {}

int Building::getCost() {
	return this->initialCost;
}

int Building::getAge() {
	return this->maxAge;
}

int Building::getId() {
	return this->buildingId;
}

void Building::toAge(int years) {
	this->initialCost -= this->initialCost / this->maxAge * years;
	this->maxAge -= years;

	if (this->maxAge <= 0) {
		this->destroy();
	}
}

void Building::showBuilding() {
	cout << "\nOur building:" << "\nBuilding id: " << this->getId() << "\nBuilding age: " << this->getAge() << "\nBuilding cost: " << this->getCost() << endl;
}

void Building::destroy() {
	cout << "\nDestroyed buiding id: " << this->buildingId << endl;
}