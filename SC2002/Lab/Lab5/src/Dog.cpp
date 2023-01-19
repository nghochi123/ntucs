#include "../headers/childanimal.h"

Dog::Dog(string n, COLOR c, string owner) : Mammal(n, c), _owner(owner)
{
    cout << "Dog created with owner " << _owner << " with name " << Animal::_name << endl;
}
Dog::~Dog()
{
    cout << "Destroying Dog object :( " << endl;
}
void Dog::speak()
{
    cout << "Dog Woof! " << endl;
}
void Dog::move()
{
    cout << "Dog Walk " << endl;
}