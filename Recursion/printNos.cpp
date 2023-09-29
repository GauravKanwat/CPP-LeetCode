#include <iostream>
using namespace std;

void printNos(int x) {
    // Write Your Code Here
    if(x == 0) return;
    printNos(x-1);
    cout << x << " ";
}

int main() {
    int n = 5;
    printNos(n);
    cout << endl;
    return 0;
}