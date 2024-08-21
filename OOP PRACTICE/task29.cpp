#include <iostream>
using namespace std;
class Counter {
private:
 int count;
public:
 Counter() : count(0) {}
 Counter& increment() {
 ++this->count; // Using this pointer to access member variable
 return *this; // Returning a reference to the current object
 }
 void display() {
 cout << "Count: " << this->count << endl; // Using this pointer to access member variable
 }
};
int main() {
 Counter c;
 c.increment().increment().increment().display(); // Chaining member function calls using this pointer
 return 0;
}
