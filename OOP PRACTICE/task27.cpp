#include <iostream>
using namespace std;
int main() {
 int size = 3;
 int *arr = new int[size];
 cout << "Enter " << size << " elements:" << endl;
 for (int i = 0; i < size; ++i) {
 cin >> arr[i];
 }
 cout << "Enter new size: ";
 int newSize;
 cin >> newSize;
 int *temp = new int[newSize];
 for (int i = 0; i < size; ++i) {
 temp[i] = arr[i];
 }
 delete[] arr;
 arr = temp;
 cout << "Enter additional " << newSize - size << " elements:" << endl;
 for (int i = size; i < newSize; ++i) {
 cin >> arr[i];
 }
 cout << "Array elements:" << endl;
 for (int i = 0; i < newSize; ++i) {
 cout << arr[i] << " ";
 }
 cout << endl;
 delete[] arr;
 return 0;
}
