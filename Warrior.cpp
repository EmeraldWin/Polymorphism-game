#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, 
                 const string &allegianceName) 
    : Character(WARRIOR, name, health, attackStrength), allegiance(allegianceName) {
}

void Warrior::attack(Character& opponent) {
    if (opponent.getType() != WARRIOR) {
        double d;
        
        d = ((this-> health / MAX_HEALTH) * this-> attackStrength);
        opponent.damage(d);
        
        cout << "Warrior " << this-> name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
    }
    
    else if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        
        if (allegiance == opp.allegiance) {
            cout << "Warrior " << this-> name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << this-> allegiance << "." << endl;
            }
        else {
            double d;
            
            d = ((this-> health / MAX_HEALTH) * this-> attackStrength);
            opponent.damage(d);

            cout << "Warrior " << this-> name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << d << " damage." << endl;            
        }
    }
    
}