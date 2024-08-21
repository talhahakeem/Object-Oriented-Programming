#include <iostream>
#include <string>
using namespace std;
class Animal
{
protected:
    string species;
    int age;
public:
    Animal(string sp, int ag)
    {
        species = sp;
        age = ag;
    }
    void display()
    {
        cout << "Species: " << species << "\nAge: " << age << endl;
    }
};
class Mammal : public Animal
{
public:
    Mammal(string sp, int ag) : Animal(sp, ag) {}
    void displayInfo() 
    {
        Animal::display();
    }
};
class Dog : public Mammal
{
public:
    Dog(string sp, int ag) : Mammal(sp, ag) {}
    void Display()
    {
        Mammal::displayInfo();
    }
};
int main()
{
    Animal animal("Elephant", 5);
    Mammal mammal("Wolf", 3);
    Dog dog("Husky", 2);
    animal.display();
    cout<<endl;
    mammal.displayInfo();
    cout <<endl;
    dog.Display();
    return 0;
}
