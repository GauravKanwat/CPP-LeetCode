#include<iostream>
using namespace std;

int fib(int n, vector<int> &dp) {
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    cout << fib(n, dp) << endl;
    return 0;
}