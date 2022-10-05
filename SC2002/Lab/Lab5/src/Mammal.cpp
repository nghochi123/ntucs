#include "../headers/mammal.h"

Mammal::Mammal() : Animal() {}
Mammal::Mammal(string n, COLOR c) : Animal(n, c) {}
Mammal::~Mammal()
{
    cout << "Destroying Mammal Object " << Animal::_name << endl;
}
void Mammal::move()
{
    cout << "Mammal Move " << Animal::_name << endl;
}
void Mammal::eat() const
{
    cout << "Mammal eat " << endl;
}
