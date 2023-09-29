#include<iostream>
using namespace std;

int recursionSum(int n) {
    if(n == 0) return 0;
    return n + recursionSum(n-1);
}

int main()
{
    int n = 5;
    int result = recursionSum(n);
    cout << result << endl;
    return 0;
}