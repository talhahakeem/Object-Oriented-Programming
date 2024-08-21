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
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }
};
class date
{
private:
    int day, month, year;

public:
    void getdate()
    {
        cout << "Enter day, month, and year: ";
        cin >> day >> month >> year;
        cin.ignore();
    }
    void putdate() const
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};
class publication2 : public publication
{
protected:
    date pub_date;

public:
    void getdata()
    {
        publication::getdata();
        pub_date.getdate();
    }
    void putdata() const
    {
        publication::putdata();
        pub_date.putdate();
    }
};
class book : public publication2
{
private:
    int page_count;

public:
    void getdata()
    {
        publication2::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        cin.ignore();
    }
    void putdata() const
    {
        publication2::putdata();
        cout << "Page Count: " << page_count << endl;
    }
};
class tape : public publication2
{
private:
    float playing_time;

public:
    void getdata()
    {
        publication2::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        cin.ignore();
    }
    void putdata() const
    {
        publication2::putdata();
        cout << "Playing Time: " << playing_time << " minutes" << endl;
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
    cout << "\nEnter data for a tape:\n";
    myTape.getdata();
    cout << "\nDisplaying data for the tape:\n";
    myTape.putdata();
    return 0;
}
