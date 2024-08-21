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
class book : public publication
{
protected:
    int page_count;

public:
    void getdata()
    {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        cin.ignore();
    }
    void putdata() const
    {
        publication::putdata();
        cout << "Page Count: " << page_count << endl;
    }
};
class tape : public publication
{
protected:
    float playing_time;

public:
    void getdata()
    {
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        cin.ignore();
    }
    void putdata() const
    {
        publication::putdata();
        cout << "Playing Time: " << playing_time << " minutes" << endl;
    }
};
class disk : public publication
{
protected:
    enum class DiskType
    {
        CD,
        DVD
    } disk_type;

public:
    void getdata()
    {
        publication::getdata();
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        cin.ignore();
        disk_type = (type == 'c' || type == 'C') ? DiskType::CD : DiskType::DVD;
    }
    void putdata() const
    {
        publication::putdata();
        cout << "Disk Type: " << (disk_type == DiskType::CD ? "CD" : "DVD") << endl;
    }
};
int main()
{
    disk myDisk;
    myDisk.getdata();
    myDisk.putdata();
    return 0;
}