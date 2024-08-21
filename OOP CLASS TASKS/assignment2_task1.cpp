#include <iostream>
using namespace std;
class Publication
{
protected:
    string title;
    float price;
public:
    void getdata()
    {
        cout << "Enter title: ";
        cin>>title;
        cout << "Enter price: ";
        cin >> price;
    }
    void putdata()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};
class Book : public Publication
{
private:
    int pageCount;
public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putdata()
    {
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};
class Tape : public Publication
{
private:
    float playingTime;
public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }
    void putdata()
    {
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};
int main()
{
    Book book;
    Tape tape;
    cout << "Enter data for a book:" << endl;
    book.getdata();
    cout << "Enter data for a tape:" << endl;
    tape.getdata();
    cout << "\nData entered for the book:" << endl;
    book.putdata();
    cout << "Data entered for the tape:" << endl;
    tape.putdata();
    return 0;
}
