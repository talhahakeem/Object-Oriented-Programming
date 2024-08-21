#include <iostream>
using namespace std;
class Array
{
    private:
        int A[5];
    public:
        void valuesGet()
        {
            cout << "Enter the Elements of Array:" << endl;
            for (int i = 0; i < 5; i++) {
                cin >> A[i];
            }
        }
        int maximum()
        {
            int max = A[0];
            for (int i = 1; i < 5; i++) {
                if (A[i] > max) {
                    max = A[i];
                }
            }
            return max;
        }
};
int main() {
    Array A;
    A.valuesGet();
    int maxValue = A.maximum();
    cout << "The maximum value in the array is: " << maxValue << endl;
    return 0;
}
