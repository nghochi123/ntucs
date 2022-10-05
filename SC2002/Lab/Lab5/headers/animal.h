#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <string>
#include <iostream>
#include <string>
#include "color.h"

using namespace std;

class Animal
{
protected:
    string _name;
    COLOR _color;

public:
    Animal();
    Animal(string n, COLOR c);
    ~Animal();
    virtual void speak();
    virtual void move() = 0;
};

#endif