#include "Hero.h"

Hero::Hero(const string& _name, float _hp, float _attack) {
    this->name = _name;
    this->hitPointLimit = _hp;
    this->hitPoints = _hp;
    this->baseAttack = _attack;
}

Hero::~Hero() { cout << "Hero " << this->name << " removed" << endl; }

bool Hero::IsAlive() {
    return this->hitPoints > 0;
}

const string& Hero::GetName() const {
    return this->name;
}

float Hero::GetAttack() const {
    return this->baseAttack;
}

void Hero::AddHitPoints(float hp) {
    this->hitPoints += hp;
}

void Hero::TakeDamage(float dmg) {
    if (!this->IsAlive()) {
        cout << "Hero " << this->name << " is dead" << std::endl;
        return;
    }

    this->hitPoints -= dmg;
}

void Hero::CounterAttack(Hero& enemy) {
    enemy.TakeDamage(this->GetAttack());
}


void Hero::Attack(Hero& enemy) {
    enemy.TakeDamage(this->GetAttack());
    if (!enemy.IsAlive()) {
        cout << "Hero " << this->name << " has fallen" << std::endl;
        return;
    }

    IObserver* observer = this;
    enemy.AddObserver(observer);

    enemy.CounterAttack(*this);
}

void Hero::AddObserver(IObserver* _observer) {
    set<IObserver*>::iterator it = this->observers.find(_observer);

    if (it == this->observers.end()) {
        this->observers.insert(_observer);

        cout << "Hero " << this->name << " is observed" << endl;
    }
}


void Hero::RemoveObserver(IObserver* _observer) {
    set<IObserver*>::iterator it = this->observers.find(_observer);

    if (it != this->observers.end()) {
        this->observers.erase(_observer);

        cout << "Hero " << this->name << " is no longer observed" << endl;
    }
}

void Hero::Notify() {
    set<IObserver*>::iterator it = this->observers.begin();

    for (; it != this->observers.end(); it++) {
        cout << "Notified observer on " << this->name << endl;
    }
}

void Hero::Update() {
    set<IObserver*>::iterator it = this->observers.begin();

    for (; it != this->observers.end(); it++) {
        if (this->IsAlive()) {
            cout << "Hero " << this->name << " is still alive" << endl;
        }
    }
}