#include<iostream>
using namespace std;

vector<long long> factorialNumbers(long long n) {
    vector<long long> result;
    long long fact = 1;
    for(int i=1; fact*i <= n; i++) {
        fact *= i;
        result.push_back(fact);
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> result;
    result = factorialNumbers(n);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
}