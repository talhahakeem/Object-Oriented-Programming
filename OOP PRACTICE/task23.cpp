#include <iostream>
#include <cstring>
using namespace std;
class Test {
private:
 int *data;
public:
 Test(int val) {
 data = new int;
 *data = val;
 }
 Test(const Test &t) {
 data = new int;
 *data = *t.data;
 }
 int getData() {
 return *data;
 }
 ~Test() {
 delete data;
 }
};
int main() {
 Test t1(5);
 Test t2 = t1;
 cout << "Data in t1: " << t1.getData() << endl;
 cout << "Data in t2: " << t2.getData() << endl;
 return 0;
}