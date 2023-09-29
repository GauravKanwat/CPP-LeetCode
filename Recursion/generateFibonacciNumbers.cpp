#include<iostream>
using namespace std;

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    vector<int> result;
    if(n == 1) {
        result.push_back(0);
        return result;
    }
    if(n == 2) {
        result = generateFibonacciNumbers(n-1);
        result.push_back(1);
        return result;
    }
    result = generateFibonacciNumbers(n-1);
    int sum = result[n-2]+result[n-3];
    result.push_back(sum);
    return result;
}

int main()
{
    int n = 5;
    vector<int> result = generateFibonacciNumbers(n);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}