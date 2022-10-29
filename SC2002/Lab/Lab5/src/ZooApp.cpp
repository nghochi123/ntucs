#include "../headers/childanimal.h"
#include <vector>

int main()
{
    vector<Mammal *> zoo;
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
            zoo.push_back(new Dog(name, Black, owner));
            break;
        }
        case 2:
        {
            cout << "You have selected to add a Cat - what is his name?" << endl;
            cin >> name;
            cout << "What is it's owner's name?" << endl;
            cin >> owner;
            zoo.push_back(new Cat(name, Black, owner));
            break;
        }

        case 3:
        {
            cout << "You have selected to add a Lion - what is his name?" << endl;
            cin >> name;
            cout << "What is it's owner's name?" << endl;
            cin >> owner;
            zoo.push_back(new Lion(name, Black, owner));
            break;
        }

        case 4:
        {
            cout << "Moving all animals - Animals will move, speak and eat in order." << endl;
            for (auto mammal : zoo)
            {
                mammal->move();
                mammal->speak();
                mammal->eat();
            }
            cout << "All animals in the zoo have been moved." << endl;
            break;
        }

        case 5:
            cout << "Exiting..." << endl;
            for (auto mammal : zoo)
            {
                delete mammal;
            }
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}