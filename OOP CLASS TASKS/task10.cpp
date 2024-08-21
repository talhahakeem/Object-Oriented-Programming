#include<iostream>
using namespace std;
class BS
{
    public:
    void myMythod();   
};
void BS::myMythod(){
    cout<<"Hello Dear Student!";
}
int main()
{
    BS student1;
    student1.myMythod();
    return 0;
}