#include <iostream>
#include <string>
using namespace std;
class LibraryItem
{
private:
    string title;
    string author;
    int pub_Year;
    bool check;
public:
    LibraryItem(string t, string a, int y)
    {
        title = t;
        author = a;
        pub_Year = y;
        check = false;
    }
    void checkout()
    {
        check = true;
    }
    void returnItem()
    {
        check = false;
    }
    bool CheckedOut()
    {
        return check;
    }
};
class Book : public LibraryItem
{
private:
    string isbn;
public:
    Book(string t, string a, int y, string i) : LibraryItem(t, a, y), isbn(i) {}
};
class Magazine : public LibraryItem
{
private:
    int iss_Num;

public:
    Magazine(string t, string a, int y, int iss) : LibraryItem(t, a, y), iss_Num(iss) {}
};
int main()
{
    Book myBook("OOP LANGUAGE", "Harvey Deitel", 1967, "1234567890");
    Magazine myMagazine("THENEWS", "Mir Shakil-ur-Rahman", 2020, 5);
    myBook.checkout();
    if (myBook.CheckedOut())
    {
        cout << "Book is CHECKED OUT." << endl;
    }
    else
    {
        cout << "Book is NOT CHECKED OUT." << endl;
    }
    myMagazine.CheckedOut();
    if (myMagazine.CheckedOut())
    {
        cout << "Magazine is CHECKED OUT." << endl;
    }
    else
    {
        cout << "Magazine is NOT CHECKED OUT." << endl;
    }
    return 0;
}
