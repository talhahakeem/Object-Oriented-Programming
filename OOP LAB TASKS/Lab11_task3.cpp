#include <iostream>
#include <string>
using namespace std;
class Product
{
private:
    int product_ID;
    string name;
    double price;
public:
    Product(int id, string n, double p)
    {
        product_ID=id;
        name=n;
        price=p;
    }
    void updatePrice(double new_Price)
    {
        price = new_Price;
    }
    double getPrice()
    {
        return price;
    }
    void getDetails()
    {
        cout << "Product ID: " << product_ID<<endl;
        cout << "Name: " << name <<endl;
        cout<< "Price: " << price << endl;
    }
};
class Electronics : public Product
{
private:
    string warr_time;
public:
    Electronics(int id, string n, double p, string w_t) : Product(id, n, p), warr_time(w_t) {}
    void getElectronicsDetails()
    {
        Product::getDetails();
        cout << "Warranty TIME: " << warr_time << endl;
    }
};
class Clothing : public Product
{
private:
    string size;
    string type;
public:
    Clothing(int id, string n, double p, string s, string t) : Product(id, n, p), size(s),type(t) {}
    void getClothingDetails()
    {
        Product::getDetails();
        cout << "SIZE: " << size <<endl;
        cout<<"TPYE : " << type << endl;
    }
};
class Food : public Product
{
private:
    string expire_date;
public:
    Food(int id, string n, double p, string ed) : Product(id, n, p), expire_date(ed) {}
    void getFoodDetails()
    {
        Product::getDetails();
        cout << "Expire Date: " << expire_date << endl;
    }
};
int main() {
    Electronics elect(101, "Laptop",80000, "6 months");
    Clothing cloth(102, "T-Shirt",2000, "M", "Cotton");
    Food food(103, "Pizza",30000,"12-06-2024");
    cout << "Electronics Details:" << endl;
    elect.getElectronicsDetails();
    cout << endl;
    cout << "Clothing Details:" << endl;
    cloth.getClothingDetails();
    cout << endl;
    cout << "Food Details:" << endl;
    food.getFoodDetails();
    cout << endl;
    return 0;
}
