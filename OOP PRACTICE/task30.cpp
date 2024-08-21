#include <iostream>
using namespace std;
class MyClass {
private:
 int data;
public:
 MyClass(int data) {
 this->data = data; 
 }
 MyClass(const MyClass &other) {
 this->data = other.data; 
 }
 void display() {
 cout << "Data: " << this->data << endl; 
 }
};
int main() {
 MyClass obj1(10);
 MyClass obj2 = obj1;
 obj1.display();
 obj2.display();
 return 0;
}