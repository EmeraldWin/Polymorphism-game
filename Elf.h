#ifndef ELF_H
#define ELF_H

#include <string>
#include "Character.h"

class Elf : public Character {
    private: 
        string family;
    
    public:
        Elf(const string &, double, double, const string &);
        void attack(Character&);
};

#endif