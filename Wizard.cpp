#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, const int &_rank)
      : Character(WIZARD, name, health, attackStrength), rank(_rank) {
}

void Wizard::attack(Character &opponent) {
    double d;
    double ratio;

    if (opponent.getType() != WIZARD) {
        d = this-> attackStrength;
        opponent.damage(d);
        
        cout << "Wizard " << this-> name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
    }
    
    else if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        ratio = static_cast<double>(rank) / opp.rank;
        d = (ratio * this-> attackStrength);
        opp.damage(d);

        cout << "Wizard " << this-> name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
    }
}