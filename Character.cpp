#include <iostream>
#include <string>

using namespace std;

#include "Character.h"

Character::Character(HeroType _type, const string &_name, double _health, double _attackStrength)
    : type(_type), name(_name), health(_health), attackStrength(_attackStrength) {
}

HeroType Character::getType() const {
    return type;
}

const string &Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast<int>(health);
}

void Character::damage(double d) {
    this-> health -= d;
}

bool Character::isAlive() const {
    if (getHealth() > 0) {
        return true;
    }
    return false;
}
