#include <iostream>
using namespace std;
class Marks
{
    int sub[3];

public:
    void in()
    {
        cout << "Enter the Marks Details: \n";
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter the Subject " << i + 1 << " Marks: ";
            cin >> sub[i];
        }
    }
    int sum()
    {
        int result = 0;
        for (int i = 0; i < 3; i++)
        {
            result = result + sub[i];
        }
        return result;
    }
    int Avg()
    {
        int result = sum() / 3;
        return result;
    }
};
int main()
{
    int res1, res2;
    Marks M;
    M.in();
    res1 = M.sum();
    res2 = M.Avg();
    cout<<"Sum of All Subjects is: ";
    cout << res1 << endl;
    cout<<"Average of Marks: ";
    cout << res2;
    return 0;
}