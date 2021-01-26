#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, const string &familyName) 
    : Character(ELF, name, health, attackStrength), family(familyName) {
}

void Elf::attack(Character& opponent) {
    double d;
    d = ((this-> health / MAX_HEALTH) * this-> attackStrength);
    
    if (opponent.getType() != ELF) {
        opponent.damage(d);
        
        cout << "Elf " << this-> name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
    }
    
    else if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        
        if (this-> family == opp.family) {
            cout << "Elf " << this-> name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << this-> family << " family." << endl;
        }
        
        else {
            opponent.damage(d);
            
            cout << "Elf " << this-> name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << d << " damage." << endl;
        }
    }
}