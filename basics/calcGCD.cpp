#include<iostream>
using namespace std;

int calcGCD(int n, int m){
    while(n > 0 && m > 0) {
        if(n > m)   n = n%m;
        else   m = m%n;
    }
    if(n == 0)  return m;
    else return n;
}

int main() {
    cout << calcGCD(6, 12);
}