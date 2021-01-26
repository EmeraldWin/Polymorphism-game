#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include "Character.h"

class Wizard : public Character {
    private:
        int rank;
    
    public:
        Wizard(const string &, double, double, const int &);
        void attack(Character &);
};

#endif