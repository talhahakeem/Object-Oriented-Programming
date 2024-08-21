#include <iostream>
#include <cmath>
using namespace std;
class NumberConverter {
public:
    void convert(int value)
    {
        int binary[32];
        int index = 0;
        while (value > 0) {
            binary[index++] = value % 2;
            value /= 2;
        }
        cout << "DECIMAL TO BINARY : ";
        for (int i = index - 1; i >= 0; i--) {
            cout << binary[i];
        }
        cout << endl;
    }
    int convert(string binary) {
        int decimal = 0;
        int power = 0;
        for (int i = binary.length() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += pow(2, power);
            }
            power++;
        }
        return decimal;
    }
    void convert(int value, int base) {
        int octal[32];
        int index = 0;
        while (value > 0) {
            octal[index++] = value % base;
            value /= base;
        }
        cout << "DECIMAL TO OCTAL : ";
        for (int i = index - 1; i >= 0; i--) {
            cout << octal[i];
        }
        cout << endl;
    }
    void convert(int value, char hexDigits[]) {
        if (value == 0) {
            cout << "DECIMAL TO HEXADECIMAL : 0" << endl;
            return;
        }
        int hexa[32];
        int index = 0;
        while (value > 0) {
            hexa[index++] = value % 16;
            value /= 16;
        }
        cout << "DECIMAL TO HEXADECIMAL : ";
        for (int i = index - 1; i >= 0; i--) {
            cout << hexDigits[hexa[i]];
        }
        cout << endl;
    }
};
int main() {
    NumberConverter converter;
    converter.convert(15);
    cout << "BINARY TO DECIMAL :";
    cout << converter.convert("1010") << endl;
    converter.convert(40, 8);
    char hexDigits[] = "0123456789ABCDEF";
    converter.convert(50, hexDigits);
    return 0;
}
