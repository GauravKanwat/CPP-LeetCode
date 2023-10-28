#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5, k = 5;
    vector<int> height = {10, 40, 50, 20, 60};
    vector<int> dp(n, 0);
    for(int i=1; i<n; i++) {
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) minSteps = min(minSteps, dp[i-j] + abs(height[i] - height[i-j]));
        }
        dp[i] = minSteps;
        // cout << dp[i] << " ";
    }
    cout << dp[n-1] << endl;
    return 0;
}