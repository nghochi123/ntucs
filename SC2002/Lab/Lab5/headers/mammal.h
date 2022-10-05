#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H

#include "animal.h"

class Mammal : public Animal
{
public:
    Mammal();
    Mammal(string n, COLOR c);
    ~Mammal();
    void move();
    void eat() const;
};

#endif