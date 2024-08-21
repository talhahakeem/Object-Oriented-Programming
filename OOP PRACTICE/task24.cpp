#include <iostream>
using namespace std;
class Person {
private:
 string *name;
 int *age;
public:
 Person(string n, int a) {
 name = new string(n);
 age = new int(a);
 }
 Person(const Person &p) {
 name = new string(*p.name);
 age = new int(*p.age);
 }
 void displayInfo() {
 cout << "Name: " << *name << endl;
 cout << "Age: " << *age << endl;
 }
 ~Person() {
 delete name;
 delete age;
 }
};
int main() {
 Person p1("Alice", 25);
 Person p2 = p1;
 p1.displayInfo();
 p2.displayInfo();
 return 0;
}