#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Player {
	string name;
	string clan;
	float strength = 10;
};

float clanStrength(const vector<Player>& clanMembers) {
	float totalStrength = 0;
	
	for (Player pl: clanMembers) {
		totalStrength += pl.strength;
	}

	return totalStrength;
}

map<string, vector<Player>> initializeClansAndPlayers() {
	map<string, vector<Player>> clans;
	int playerQuantity;
	cout << "\nEnter player quantity: ";
	cin >> playerQuantity;

	for (int i = 0; i < playerQuantity; i++) {
		Player temp;
		cout << "\nEnter your player name: ";
		cin >> temp.name;
		cout << "\nEnter your clan: ";
		cin >> temp.clan;
		cout << "\nEnter your current strength: ";
		cin >> temp.strength;

		vector<Player> playerClan;
		bool clanExists = true;

		try {
			playerClan = clans.at(temp.clan);

		} catch (out_of_range& e) { clanExists = false; }

		if (clanExists) {
			clans.at(temp.clan).push_back(temp);
		} else {
			playerClan.push_back(temp);
			clans.insert(make_pair(temp.clan, playerClan));
		}
	}

	return clans;
}

int GetPlayerCount(const string& ClanName, const map<string, vector<Player>>& clans) {
	int clanMembersQuantity = 0;

	try {
		clanMembersQuantity = clans.at(ClanName).size();
	}
	catch (out_of_range& e) { 
		cout << "There is no such clan!";
		return 0;
	}

	return clanMembersQuantity;
}

int ClanFight(const string& firstClanName, const string& secondClanName, const map<string, vector<Player>>& clans) {
	float firstClanStrength = 0;
	float secondClanStrength = 0;

	try {
		firstClanStrength = clanStrength(clans.at(firstClanName));
	}
	catch (out_of_range& e) {
		cout << "There is no such clan!";
		throw e;
	}

	try {
		secondClanStrength = clanStrength(clans.at(secondClanName));
	}
	catch (out_of_range& e) {
		cout << "There is no such clan!";
		throw e;
	}

	if (firstClanStrength > secondClanStrength) return 1;
	if (firstClanStrength < secondClanStrength) return -1;
	if (firstClanStrength == secondClanStrength) return 0;
}

void clansParams(const map<string, vector<Player>>& clans) {
	for (auto it = clans.cbegin(); it != clans.cend(); ++it) {
		cout << "\n\nClan name: '" << it->first << "'";
		for (auto itk = it->second.begin(); itk != it->second.end(); ++itk) {
			cout << "\nMember name: '" << itk->name << "' strength: " << itk->strength;
		}
		cout << "\nTotal clan strength: " << clanStrength(it->second);
		cout << "\nClan members quantity: " << GetPlayerCount(it->first, clans) << endl;
	}

	return;
}

int main() {

	map<string, vector<Player>> clans = initializeClansAndPlayers();

	clansParams(clans);

	string firstClanName;
	string secondClanName;
	cout << "\nClan fighting is preparing. Enter first clan name to fight: ";
	cin >> firstClanName;
	cout << "\nEnter second clan name to fight: ";
	cin >> secondClanName;

	if (ClanFight(firstClanName, secondClanName, clans) == 1) {
		cout << "\n'" << firstClanName << "' wins!\n";
	}
	if (ClanFight(firstClanName, secondClanName, clans) == -1) {
		cout << "\n'" << secondClanName << "' wins!\n";
	}
	if (ClanFight(firstClanName, secondClanName, clans) == 0) {
		cout << "\nIt`s draw\n";
	}

	return 0;
}