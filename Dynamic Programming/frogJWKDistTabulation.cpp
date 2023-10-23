#include<bits/stdc++.h>
using namespace std;

int minimizeCost(int n, int k, vector<int> height) {
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        if(n-i >= 0) dp[i] = min(dp[i], dp[n-i] + abs(height[n] - height[n-i]));
    }
    return dp[n-1];
}

int main()
{
    int n = 4, k = 2;
    vector<int> height = {10, 40, 30, 10};
    cout << minimizeCost(n-1, k, height) << endl;
    // minimizeCost(n, k, height);
    return 0;
}