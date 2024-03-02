#pragma once
#include <iostream>
#include <set>
#include "ISubject.h"
#include "IObserver.h"

using namespace std;

class Hero: public ISubject, public IObserver {
public:
    Hero(const string& _name, float _hp, float _attack);
    ~Hero();

    bool IsAlive();

    const string& GetName() const;

    float GetAttack() const;

    void AddHitPoints(float hp);
    void TakeDamage(float dmg);

    void Attack(Hero& enemy);
    void CounterAttack(Hero& enemy);
    void AddObserver(IObserver* _observer) override;
    void RemoveObserver(IObserver* _observer) override;
    void Notify() override;
    void Update() override;
private:
    string name;
    float hitPoints;
    float hitPointLimit;
    float baseAttack;

    set<IObserver*> observers;
};