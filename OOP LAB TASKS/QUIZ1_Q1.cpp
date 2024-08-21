#include <iostream>
using namespace std;
class MaxValueFinder
{
private:
    int *M;

public:
    MaxValueFinder()
    {
        M = new int;
    }
    ~MaxValueFinder()
    {
        delete[] M;
    }
    void setValue()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter The elements of array: ";
            cin >> M[i];
        }
    }

    int MaxValue()
    {
        int max = M[0];
        for (int i = 1; i < 5; i++)
        {
            if (M[i] > max)
            {
                max = M[i];
            }
        }

        return max;
    }
};

int main()
{
    MaxValueFinder *finder = new MaxValueFinder();

    finder->setValue();
    int maxVal = finder->MaxValue();
    cout << "Maximum Value in the Array is = " << maxVal << endl;
    delete finder;
    return 0;
}
