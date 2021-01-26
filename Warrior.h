#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "Character.h"

class Warrior : public Character {
    private:
        string allegiance;
    
    public:
        Warrior(const string &, double, double, const string &);
        void attack(Character&);
};

#endif