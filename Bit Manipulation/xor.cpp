#include<iostream>
using namespace std;

int XOR(int val) {
    if(val % 4 == 1) return 1;
    if(val % 4 == 2) return val + 1;
    if(val % 4 == 3) return 0;
    if(val % 4 == 0) return val;
    return 0;
}

int main() {
    int a = 3, b = 6;
    cout << (XOR(2) ^ XOR(6)) << endl;
    // cout << (3 ^ 4 ^ 5 ^ 6) << endl;
    return 0;
}