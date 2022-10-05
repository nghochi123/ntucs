#include <string>
#include <iostream>
#include <string>
#include "../headers/animal.h"

using namespace std;

Animal::Animal() : _name("unknown")
{
    cout << "Constructing Animal Object " << _name << endl;
}
Animal::Animal(string n, COLOR c) : _name(n), _color(c)
{
    cout << "Constructing Animal Object with name " << _name << " and color " << _color << endl;
}
Animal::~Animal()
{
    cout << "Destroying Animal Object " << _name << endl;
}
void Animal::speak()
{
    cout << "Animal speaks " << endl;
}
