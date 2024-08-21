#include<iostream>
using namespace std;

class LibraryItem
{
    protected:
     
     string title;
     string author;
     int publicationYear;

 public:
    
    void getData(){
        cout<<"Enter the title of book =";
        cin>>title;

        cout<<"Enter the author name of the book =";
        cin>>author;

        cout<<"Enter the publication Year of the book =";
        cin>>publicationYear;
    }
      

      void displayData(){
        cout<<"\tBook Details :\n";
        cout<<"The Title of book is "<<title<<endl;
        cout<<"The Author name is "<<author<<endl;
        cout<<"The Publication Year of book is "<<publicationYear<<endl;

      }

    void checkout(){

    }

    void returnItem(){

    }
 };

 class book : public LibraryItem{
    private:
     string title;
     string author;
     int publicationYear;
     int isbn;

     public:

       void getData(){
          
        cout<<"Enter the title of book =";
        cin>>title;

        cout<<"Enter the author name of the book =";
        cin>>author;

        cout<<"Enter the publication Year of the book =";
        cin>>publicationYear;
        cout<<"Enter the ISBN of book is "<<isbn<<endl;
        cin>>isbn;
    }
    void displayData(){
        cout<<"\tBook Details :\n";
        cout<<"The Title of book is "<<title<<endl;
        cout<<"The Author name is "<<author<<endl;
        cout<<"The Publication Year of book is "<<publicationYear<<endl;
        cout<<"The ISBN of book is "<<isbn<<endl;  
    }
 };
 class magazine : public LibraryItem{
    private:
     string title;
     string author;
     int publicationYear;
     int issueNumber;
    public:
    void getData(){
        cout<<"Enter the title of book =";
        cin>>title;
        cout<<"Enter the author name of the book =";
        cin>>author;
        cout<<"Enter the publication Year of the book =";
        cin>>publicationYear;
        cout<<"Enter the issue Number of book ";
        cin>>issueNumber;
    }
    void displayData(){
        cout<<"\tBook Details :\n";
        cout<<"The Title of book is "<<title<<endl;
        cout<<"The Author name is "<<author<<endl;
        cout<<"The Publication Year of book is "<<publicationYear<<endl;
        cout<<"The issue Number of the book is "<<issueNumber<<endl;
    }    
 };

int main()
{
    LibraryItem l1;
    l1.getData();
    l1.displayData();
    cout<<endl;
    book b1;
    b1.getData();
    b1.displayData();
    cout<<endl;
    magazine m1;
    m1.getData();
    m1.displayData();
    return 0;
 }