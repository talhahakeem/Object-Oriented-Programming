#include <iostream>
using namespace std;
class Mathoperations {
public:
    int sum(int a, int b) {
        return a + b;
    }
    int subtract(int a, int b) {
        return a - b;
    }
    int multiply(int a, int b) {
        return a * b;
    }
    double divis(int a, int b) {
        if (b == 0) {
            cout << "Division by zero is impossible." << endl;
            return 0;
        } else {
            return a/b;
        }
    }
};
class Addition : public Mathoperations {
public:
    int sum(int a, int b, int c) {
        return a + b + c;
    }
    double sum(double a, double b) {
        return a + b;
    }
    double sum(double a, double b, double c) {
        return a + b + c;
    }
};
class Subtraction : public Mathoperations {
public:
    int subtract(int a, int b, int c) {
        return a - b - c;
    }
    double subtract(double a, double b) {
        return a - b;
    }
    double subtract(double a, double b, double c) {
        return a - b - c;
    }
};
class Multiplication : public Mathoperations {
public:
    int multiply(int a, int b, int c) {
        return a * b * c;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double multiply(double a, double b, double c) {
        return a * b * c;
    }
};
class Division : public Mathoperations {
public:
    double divis(double a, double b) {
        if (b == 0) {
            cout << "Division by zero is impossible." << endl;
            return 0;
        } else {
            return a / b;
        }
    }
};
int main() {
    Addition add;
    Subtraction sub;
    Multiplication mul;
    Division div;
    cout << "Addition:" << endl;
    cout << "4 + 5 = " << add.sum(4, 5) << endl;
    cout << "4 + 5 + 6 = " << add.sum(4, 5, 6) << endl;
    cout << "4.5 + 5.5 = " << add.sum(4.50, 5.50) << endl;
    cout << "4.5 + 7.8 + 2.5 = " << add.sum(4.50, 7.80, 2.50) << endl;
    cout << "Subtraction:" << endl;
    cout << "9 - 6 = " << sub.subtract(9, 6) << endl;
    cout << "9 - 8 - 7 = " << sub.subtract(9, 8, 7) << endl;
    cout << "4.5 - 5.5 = " << sub.subtract(4.50, 5.50) << endl;
    cout << "4.5 - 7.8 - 5.6 = " << sub.subtract(4.50, 7.80, 5.60) << endl;
    cout << "Multiplication:" << endl;
    cout << "4 * 5 = " << mul.multiply(4, 5) << endl;
    cout << "9 * 8 * 7 = " << mul.multiply(9, 8, 7) << endl;
    cout << "4.5 * 5.5 = " << mul.multiply(4.50, 5.50) << endl;
    cout << "4.5 * 7.8 * 5.6 = " << mul.multiply(4.50, 7.80, 5.60) << endl;
    cout << "Division:" << endl;
    cout << "10 / 5 = " << div.divis(10, 5) << endl;
    cout << "50.6 / 5.2 = " << div.divis(50.60, 5.20) << endl;
    return 0;
}
