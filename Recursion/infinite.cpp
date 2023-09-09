#include<iostream>
using namespace std;
void print(int x) {
    if(x == 0)
        return;
    x--;
    print(x);
    cout << x+1 << " ";
}

int main() {
    print(5);
}