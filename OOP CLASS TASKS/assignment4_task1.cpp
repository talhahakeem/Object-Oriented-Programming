#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void move()
    {
        cout << "Animal moves" << endl;
    }
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << endl;
    }
};
class Bird : public Animal
{
public:
    void move() override
    {
        cout << "Bird flies" << endl;
    }
    void makeSound() override
    {
        cout << "Bird chirps" << endl;
    }
};
class Panthera : public Animal
{
public:
    void move() override
    {
        cout << "Panthera walks" << endl;
    }
    void makeSound() override
    {
        cout << "Panthera roars" << endl;
    }
};
int main()
{
    Animal *bird = new Bird();
    Animal *panthera = new Panthera();
    bird->move();
    bird->makeSound();
    panthera->move();
    panthera->makeSound();
    delete bird;
    delete panthera;
    return 0;
}
