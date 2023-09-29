#include<iostream>
using namespace std;

int generateFibonacciNumbers(int n) {
    if(n <= 0) return 0;
    if(n == 1) return n;
    int sum = generateFibonacciNumbers(n-1) + generateFibonacciNumbers(n-2);
    return sum;
}

int main()
{
    cout << generateFibonacciNumbers(10) << endl;
    return 0;
}