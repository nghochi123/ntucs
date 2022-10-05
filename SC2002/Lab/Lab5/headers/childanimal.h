#ifndef ZOO_CHILDANIMAL_H
#define ZOO_CHILDANIMAL_H

#include "mammal.h"

class Dog : public Mammal
{
private:
    string _owner;

public:
    Dog(string n, COLOR c, string owner);
    ~Dog();
    void speak();
    void move();
};

class Cat : public Mammal
{
private:
    string _owner;

public:
    Cat(string n, COLOR c, string owner);
    ~Cat();
    void speak();
    void move();
};

class Lion : public Mammal
{
private:
    string _owner;

public:
    Lion(string n, COLOR c, string owner);
    ~Lion();
    void speak();
    void move();
};

#endif