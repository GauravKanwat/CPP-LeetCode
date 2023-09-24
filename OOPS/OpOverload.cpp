#include<bits/stdc++.h>
using namespace std;

class Complex {
    private:
    int real, imag;
    public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator +(Complex const& obj) {
        Complex C;
        C.real = real + obj.real;
        C.imag = imag + obj.imag;
        return C;
    }
    void print() {
        cout << real << " +i" << imag << endl;
    }

};

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}