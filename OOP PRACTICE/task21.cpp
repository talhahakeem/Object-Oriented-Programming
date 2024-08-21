#include <iostream>
using namespace std;
class Utility {
public:
 static int add(int a, int b) {
 return a + b;
 }
};
int main() {
 cout << "Sum: " << Utility::add(5, 7) << endl;
 return 0;
}
