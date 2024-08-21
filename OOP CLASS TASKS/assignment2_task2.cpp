#include <iostream>
#include <string>
using namespace std;
class publication
{
protected:
    string title;
    float price;

public:
    void getdata()
    {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }
    void putdata() const
    {
        cout << "Title: " << title << "\nPrice: $" << price << endl;
    }
};
class sales
{
protected:
    float salesArray[3];

public:
    void getdata()
    {
        cout << "Enter sales for the last three months:\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << "Month " << (i + 1) << ": ";
            cin >> salesArray[i];
        }
        cin.ignore();
    }
    void putdata() const
    {
        cout << "Sales for the last three months:\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << "Month " << (i + 1) << ": $" << salesArray[i] << endl;
        }
    }
};
class book : public publication, public sales
{
private:
    int pageCount;

public:
    void getdata()
    {
        publication::getdata();
        sales::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore();
    }
    void putdata() const
    {
        publication::putdata();
        sales::putdata();
        cout << "Page count: " << pageCount << endl;
    }
};
class tape : public publication, public sales
{
private:
    float playTime;

public:
    void getdata()
    {
        publication::getdata();
        sales::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playTime;
        cin.ignore();
    }
    void putdata() const
    {
        publication::putdata();
        sales::putdata();
        cout << "Playing time: " << playTime << " minutes" << endl;
    }
};
int main()
{
    book myBook;
    tape myTape;
    cout << "Enter data for a book:\n";
    myBook.getdata();
    cout << "\nDisplaying data for the book:\n";
    myBook.putdata();
    cout << "\n\nEnter data for a tape:\n";
    myTape.getdata();
    cout << "\nDisplaying data for the tape:\n";
    myTape.putdata();
    return 0;
}
