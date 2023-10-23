#include <iostream>
using namespace std;


vector<int> bitManipulation(int num, int i) {
    int op1 = num & (1 << (i-1));
    int op2 = num | (1 << (i-1));
    int op3 = op2 ^ (1 << (i-1));
    return {op1, op2, op3};
}

int main() {
    int N = 28, i = 3;
    vector<int> result = bitManipulation(N, i);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}