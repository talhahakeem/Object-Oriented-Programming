#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    int age;
    string country;

public:
    void setName(const string &n)
    {
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }
    void setCountry(const string &c)
    {
        country = c;
    }
    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }
    string getCountry()
    {
        return country;
    }
};
int main()
{
    Person person;
    person.setName("Muhammad Talha Hakeem");
    person.setAge(20);
    person.setCountry("Pakistan");
    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;
    cout << "Country: " << person.getCountry() << endl;

    return 0;
}
