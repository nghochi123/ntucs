#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum COLOR
{
    Green,
    Blue,
    White,
    Black,
    Brown
};

class Animal
{
protected:
    string _name;
    COLOR _color;

public:
    Animal() : _name("unknown")
    {
        cout << "Constructing Animal Object " << _name << endl;
    }
    Animal(string n, COLOR c) : _name(n), _color(c)
    {
        cout << "Constructing Animal Object with name " << _name << " and color " << _color << endl;
    }
    ~Animal()
    {
        cout << "Destroying Animal Object " << _name << endl;
    }
    virtual void speak()
    {
        cout << "Animal speaks " << endl;
    }
    // virtual void speak() const
    // {
    //     cout << "Animal speaks " << endl;
    // }
    // void move() const
    // {
    // }
    virtual void move() = 0;
};

class Mammal : public Animal
{
public:
    Mammal() : Animal() {}
    Mammal(string n, COLOR c) : Animal(n, c) {}
    ~Mammal()
    {
        cout << "Destroying Mammal Object " << Animal::_name << endl;
    }
    void move()
    {
        cout << "Mammal Move " << Animal::_name << endl;
    }
    void eat() const
    {
        cout << "Mammal eat " << endl;
    }
};

class Dog : public Mammal
{
private:
    string _owner;

public:
    Dog(string n, COLOR c, string owner) : Mammal(n, c), _owner(owner)
    {
        cout << "Dog created with owner " << _owner << " with name " << Animal::_name << endl;
    }
    ~Dog()
    {
        cout << "Destroying Dog object :( " << endl;
    }
    void speak()
    {
        cout << "Dog Woof! " << endl;
    }
    void move()
    {
        cout << "Dog Walk " << Animal::_name << endl;
    }
};

class Cat : public Mammal
{
private:
    string _owner;

public:
    Cat(string n, COLOR c, string owner) : Mammal(n, c), _owner(owner)
    {
        cout << "Cat created with owner " << _owner << " with name " << Animal::_name << endl;
    }
    ~Cat()
    {
        cout << "Destroying Cat object" << endl;
    }
    void speak()
    {
        cout << "Cat Meow" << endl;
    }
    void move()
    {
        cout << "Cat Walk" << endl;
    }
};
class Lion : public Mammal
{
private:
    string _owner;

public:
    Lion(string n, COLOR c, string owner) : Mammal(n, c), _owner(owner)
    {
        cout << "Lion created with owner " << _owner << " with name " << Animal::_name << endl;
    }
    ~Lion()
    {
        cout << "Destroying Lion object" << endl;
    }
    void speak()
    {
        cout << "Lion Roar" << endl;
    }
    void move()
    {
        cout << "Lion Walk" << endl;
    }
};

int main()
{
    vector<Mammal> zoo;
    int choice = 0, numAnimals = 0;
    string name;
    string owner;
    do
    {
        cout << "Select the animal to send to Zoo:\n"
             << "(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "You have selected to add a Dog - what is his name?" << endl;
            cin >> name;
            cout << "What is it's owner's name?" << endl;
            cin >> owner;
            Dog dog(name, Black, owner);
            zoo.push_back(dog);
            break;
        }
        case 2:
        {
            cout << "You have selected to add a Cat - what is his name?" << endl;
            cin >> name;
            cout << "What is it's owner's name?" << endl;
            cin >> owner;
            Cat cat(name, Black, owner);
            zoo.push_back(cat);
            break;
        }

        case 3:
        {
            cout << "You have selected to add a Lion - what is his name?" << endl;
            cin >> name;
            cout << "What is it's owner's name?" << endl;
            cin >> owner;
            Lion lion(name, Black, owner);
            zoo.push_back(lion);
            break;
        }

        case 4:
        {
            cout << "Moving all animals - Animals will move, speak and eat in order." << endl;
            for (auto mammal : zoo)
            {
                mammal.move();
                mammal.speak();
                mammal.eat();
            }
            cout << "All animals in the zoo have been moved." << endl;
            break;
        }

        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    // // Animal a;
    // // Animal b("Chicken", Brown);
    // Mammal *c;
    // Mammal d("Human", Black);
    // Dog e("Cat", White, "Muthu");
    // // Animal *animalPtr = new Dog("Lassie", White, "Andy");
    // Dog dogi("Lassie", White, "Andy");
    // Mammal *aniPtr = &dogi;
    // Mammal &aniRef = dogi;
    // Mammal aniVal = dogi;
    // aniPtr->speak();
    // aniRef.speak();
    // aniVal.speak();
    // // animalPtr->speak();
    // // a.speak();
    // // b.speak();
    // // c->eat();
    // // d.eat();
    // // e.speak();
    // cout << "Program Exiting..." << endl;
    // delete aniPtr, c;
    return 0;
}