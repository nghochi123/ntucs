#include "../headers/childanimal.h"

Lion::Lion(string n, COLOR c, string owner) : Mammal(n, c), _owner(owner)
{
    cout << "Lion created with owner " << _owner << " with name " << Animal::_name << endl;
}
Lion::~Lion()
{
    cout << "Destroying Lion object" << endl;
}
void Lion::speak()
{
    cout << "Lion Roar" << endl;
}
void Lion::move()
{
    cout << "Lion Walk" << endl;
}
