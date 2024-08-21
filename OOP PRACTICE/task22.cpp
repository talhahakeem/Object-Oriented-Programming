#include <iostream>
using namespace std;
class Box {
private:
 int length;
public:
 Box(int l) : length(l) {}
 Box(const Box& b) {
 length = b.length;
 }
 int getLength() {
 return length;
 }
};
int main() {
 Box box1(10);
 Box box2 = box1;
 cout << "Length of box2: " << box2.getLength() << endl;
 return 0;
}