#include <iostream>
using namespace std;
class MyClass {
private:
 int *data;
public:
 MyClass(int size) {
 data = new int[size];
 }
 ~MyClass() {
 delete[] data;
 }
 void setData(int index, int value) {
 data[index] = value;
 }
 int getData(int index) {
 return data[index];
 }
};
int main() {
 MyClass obj(5);
 for (int i = 0; i < 5; ++i) {
 obj.setData(i, i * 2);
 }
 for (int i = 0; i < 5; ++i) {
 cout << "Data at index " << i << ": " << obj.getData(i) << endl;
 }
 return 0;
}