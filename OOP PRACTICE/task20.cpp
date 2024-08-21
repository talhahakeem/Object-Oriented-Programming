#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    int area() const {
        // No modification of width here
        return length * width;
    }
};

int main() {
    const Rectangle rect(5, 4);
    cout << "Area of the rectangle: " << rect.area() << endl;
    return 0;
}
