#pragma once
#include <iostream>

class Building {
public:
	Building() = default;
	Building(int _initialCost = 100, int _maxAge = 50);

	~Building();

	int getCost();
	int getAge();
	int getId();

	void showBuilding();
	void toAge(int years);

private:
	void destroy();

private:
	int buildingId;
	int maxAge;
	int initialCost;
	static int nextBuildingId;
};