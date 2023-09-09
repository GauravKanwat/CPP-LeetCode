#include<iostream>
#include<vector>
using namespace std;

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    int a = 0, b = 1, sum = 0;
    vector<int> result;
    for(int i=0; i<n; i++) {
        result.push_back(a);
        sum = a + b;
        a = b;
        b = sum;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> result;
    result = generateFibonacciNumbers(n);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
}