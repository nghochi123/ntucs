#include "../headers/childanimal.h"

Cat::Cat(string n, COLOR c, string owner) : Mammal(n, c), _owner(owner)
{
    cout << "Cat created with owner " << _owner << " with name " << Animal::_name << endl;
}
Cat::~Cat()
{
    cout << "Destroying Cat object" << endl;
}
void Cat::speak()
{
    cout << "Cat Meow" << endl;
}
void Cat::move()
{
    cout << "Cat Walk" << endl;
}
